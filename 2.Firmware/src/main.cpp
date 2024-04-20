
#include <Arduino.h>
#include <gui_guider.h>
#include <lv_port_indev.h>
#include <freertos/task.h>
#include "display.h"
#include "sensor.h"
#include "button.h"
#include "wifi_bt.h"
#include "http_server.h"
#include <config.h>
#include <LittleFS.h>
#include <OpenWeatherMap.h>
#include <esp_modbus_slave.h>
#include "modbus.h"

#define BTN1_PIN 4 // 按键1

bool getBtn1()
{
	return !digitalRead(BTN1_PIN);
}

void TftTask(void *args)
{
	/*** Init screen ***/
	screen.init();
	screen.setBackLight(0.1);

	/*** Init input ***/
	lv_port_indev_init();

	if (getBtn1())
	{
		init_scr_del_flag(&guider_ui);
		setup_scr_wifiap(&guider_ui);
		lv_scr_load(guider_ui.wifiap);
	}
	else
	{
		setup_ui(&guider_ui);
	}

	while (1)
	{
		screen.routine();
		delay(50);
	}
}

void ButtonTask(void *args)
{
	while ((getBtn1()))
	{
		delay(1000);
	}

	/*** Init key ***/
	Button::init();
	while (1)
	{
		Button::monitor(); // 监视按钮
		delay(10);
	}
}

void SensorTask(void *args)
{
	/*** Init INA226 ***/
	sensor.init();

	while (1)
	{
		sensor.read();
		sensor.calc();
		delay(50);
	}
}

void WifiBtTask(void *args)
{
	if (getBtn1())
	{
		wifi_ap_mode();
		http_init();
		while (1)
		{
			http_routine();
			delay(10);
		}
	}
	else
	{
		wifi_bt_init();
		http_init();
		while (1)
		{
			check_wifi();
			http_routine();
			delay(50);
		}
	}
}

void ModbusTask(void *args)
{
	modbusInit();
	while (1)
	{
		modbusLoop();
	}
}

void setup()
{
	int res;
	Serial.begin(115200);
	delay(500);

	setenv("TZ", "CST-8", 1);

	// 初始化 LittleFS
	while (!LittleFS.begin())
	{
		Serial.println("LittleFS mount err");
		if (LittleFS.format())
			Serial.println("LittleFS format ok");
		delay(500);
	}
	Serial.println("LittleFS mounted ");

	config.init();

	// First set your Key value
	OWOC.setOpenWeatherKey(config.weatherApiKey.c_str());
	OWOC.setLatLon(config.cityid.toInt());

	pinMode(BTN1_PIN, INPUT_PULLUP);

	res = xTaskCreate(WifiBtTask, "WifiBtTask", 8192, NULL, 4, NULL);
	Serial.printf("WifiBtTask %d\n", res);
	xTaskCreate(ButtonTask, "ButtonTask", 4096, NULL, 3, NULL);

	res = xTaskCreate(TftTask, "TftTask", 8192, NULL, 2, NULL);
	Serial.printf("TftTask %d\n", res);

	res = xTaskCreate(SensorTask, "SensorTask", 4096, NULL, 3, NULL);
	Serial.printf("SensorTask %d\n", res);

	// res = xTaskCreate(ModbusTask, "ModbusTask", 20000, NULL, 10, NULL);
	// Serial.printf("ModbusTask %d\n", res);

	Serial.println("setup done");
	// ESP.deepSleep(5000000); // 注时间意单位为：us
}

void loop()
{
	static int counter = 0;
	setClock();
	if (counter % 600 == 0)
	{
		OWOC.parseWeather();
	}
	if (counter++ >= 10000)
	{
		counter = 0;
	}
	delay(100);
}
