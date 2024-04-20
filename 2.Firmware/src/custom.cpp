/*
 * Copyright 2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

/*********************
 *      INCLUDES
 *********************/
#include <Arduino.h>
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "sensor.h"
#include <WiFi.h>
#include "OpenWeatherMap.h"
#include <config.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

extern Sensor_Data ui;
/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
	/* Add your codes here */
}

byte wd = 0; // NTC采样
float V_val = 0;
void update_sensor_data(lv_timer_t *tmr)
{
	uint32_t t = millis();
	uint16_t h, m, s;
	s = (t / 1000) % 60;
	m = (t / 1000) % 3600 / 60;
	h = (t / 1000) / 3600;

	lv_label_set_text_fmt(guider_ui.sensor_voltage, "%.3fV", sensor.U);
	lv_label_set_text_fmt(guider_ui.sensor_current, "%.4fA", sensor.I);
	lv_label_set_text_fmt(guider_ui.sensor_watt, "%.3fW", sensor.W);

	lv_label_set_text_fmt(guider_ui.sensor_work_time, "%02d:%02d:%02d", h, m, s);

	float v = map(analogRead(wd), 0, 4095, 0, 3300);
	float ntc = (3300 - v) * 10000 / v;
	float C = (3450 * 298.15) / (3450 + (298.15 * log(ntc / 7000))) - 273.15;
	lv_label_set_text_fmt(guider_ui.sensor_temperture, "%.1f℃", C);

	lv_label_set_text_fmt(guider_ui.sensor_mAh, "%.3f", sensor.mAh);
	lv_label_set_text_fmt(guider_ui.sensor_mWh, "%.2f", sensor.Wh * 1000);
	if (config.rotation == "1")
	{
		lv_label_set_text_fmt(guider_ui.sensor_direct, "⬅");
	}
	else
	{
		lv_label_set_text_fmt(guider_ui.sensor_direct, "⮕");
	}

	V_val += 0.001;
	if (V_val > 99.999)
	{
		V_val = 0;
	}
}

void update_data_page_data(lv_timer_t *tmr)
{
	char buf[64];
	size_t written = strftime(buf, 64, "%F %T", &sensor.timeinfo);
	lv_label_set_text_fmt(guider_ui.data_datetime, "%s", buf);
	lv_label_set_text_fmt(guider_ui.data_voltage, "%.2fV", sensor.U);
	lv_label_set_text_fmt(guider_ui.data_current, "%.2fA", sensor.I);

	lv_label_set_text_fmt(guider_ui.data_u_max, "%.2fV", sensor.u_max);
	lv_label_set_text_fmt(guider_ui.data_u_avg, "%.2fV", sensor.u_avg);
	lv_label_set_text_fmt(guider_ui.data_u_min, "%.2fV", sensor.u_min);

	lv_label_set_text_fmt(guider_ui.data_i_max, "%.2fA", sensor.i_max);
	lv_label_set_text_fmt(guider_ui.data_i_avg, "%.2fA", sensor.i_avg);
	lv_label_set_text_fmt(guider_ui.data_i_min, "%.2fA", sensor.i_min);

	lv_label_set_text_fmt(guider_ui.data_w_max, "%.2fW", sensor.w_max);
	lv_label_set_text_fmt(guider_ui.data_w_avg, "%.2fW", sensor.w_avg);
	lv_label_set_text_fmt(guider_ui.data_w_min, "%.2fW", sensor.w_min);
}

void update_device_data(lv_timer_t *tmr)
{
	lv_label_set_text_fmt(guider_ui.device_wifiip, "%s", WiFi.localIP().toString().c_str());
	lv_label_set_text_fmt(guider_ui.device_rssi, "%ddBm", WiFi.RSSI());
	uint64_t chipid = ESP.getEfuseMac();
	lv_label_set_text_fmt(guider_ui.device_cid, "%04X", (uint16_t)(chipid >> 32));
	lv_label_set_text_fmt(guider_ui.device_freq, "%uMHz", ESP.getCpuFreqMHz());
	lv_label_set_text_fmt(guider_ui.device_heap, "%u", ESP.getFreeHeap());
	lv_label_set_text_fmt(guider_ui.device_sdk, "%s", ESP.getSdkVersion());
}

void update_weather(lv_timer_t *tmr)
{
	if (OWOC.quality)
	{
		lv_label_set_text_fmt(guider_ui.weather_O3_, "% .1f", OWOC.quality->o3);
		lv_label_set_text_fmt(guider_ui.weather_pm25, "% .1f", OWOC.quality->pm2_5);
		lv_label_set_text_fmt(guider_ui.weather_pm10, "% .1f", OWOC.quality->pm10);
	}

	if (OWOC.current)
	{
		lv_label_set_text_fmt(guider_ui.weather_temp, "% .1f℃", OWOC.current->temperature);
		lv_label_set_text_fmt(guider_ui.weather_humidity, "% .1f", OWOC.current->humidity);
		lv_label_set_text_fmt(guider_ui.weather_feels, "% .1f℃", OWOC.current->apparentTemperature);
		lv_label_set_text_fmt(guider_ui.weather_pressure, "%.0f", OWOC.current->pressure);
		lv_label_set_text_fmt(guider_ui.weather_windSpeed, "%.0fm/s", OWOC.current->windSpeed);
		lv_label_set_text_fmt(guider_ui.weather_windDeg, "%.0f°", OWOC.current->windBearing);

		if (!strcmp(OWOC.current->icon, "01d") || !strcmp(OWOC.current->icon, "01n"))
		{
			lv_label_set_text_fmt(guider_ui.weather_weather_main, "%s", "☀");
		}
		else if (!strcmp(OWOC.current->icon, "02d") || !strcmp(OWOC.current->icon, "02n"))
		{
			lv_label_set_text_fmt(guider_ui.weather_weather_main, "%s", "☁☀");
		}
		else if (!strcmp(OWOC.current->icon, "03d") || !strcmp(OWOC.current->icon, "03n"))
		{
			lv_label_set_text_fmt(guider_ui.weather_weather_main, "%s", "☁");
		}
		else if (!strcmp(OWOC.current->icon, "04d") || !strcmp(OWOC.current->icon, "04n"))
		{
			lv_label_set_text_fmt(guider_ui.weather_weather_main, "%s", "☁");
		}
		else if (!strcmp(OWOC.current->icon, "09d") || !strcmp(OWOC.current->icon, "09n"))
		{
			lv_label_set_text_fmt(guider_ui.weather_weather_main, "%s", "☂");
		}
		else if (!strcmp(OWOC.current->icon, "10d") || !strcmp(OWOC.current->icon, "10n"))
		{
			lv_label_set_text_fmt(guider_ui.weather_weather_main, "%s", "☁☂☀");
		}
		else if (!strcmp(OWOC.current->icon, "11d") || !strcmp(OWOC.current->icon, "11n"))
		{
			lv_label_set_text_fmt(guider_ui.weather_weather_main, "%s", "☁"); // 打雷
		}
		else if (!strcmp(OWOC.current->icon, "13d") || !strcmp(OWOC.current->icon, "13n"))
		{
			lv_label_set_text_fmt(guider_ui.weather_weather_main, "%s", "☁⁂");
		}
		else if (!strcmp(OWOC.current->icon, "50d") || !strcmp(OWOC.current->icon, "50n"))
		{
			lv_label_set_text_fmt(guider_ui.weather_weather_main, "%s", "▓");
		}
		else if (!strcmp(OWOC.current->icon, "1232n"))
		{
			lv_label_set_text_fmt(guider_ui.weather_weather_main, "%s", "☀");
		}
		else
		{
			lv_label_set_text_fmt(guider_ui.weather_weather_main, "%s", OWOC.current->icon);
		}

		lv_label_set_text_fmt(guider_ui.weather_visibility, "%.0f", OWOC.current->visibility);
		lv_label_set_text_fmt(guider_ui.weather_city, "%s", OWOC.current->cityName);
	}
}

void update_chart(lv_timer_t *tmr)
{
	lv_chart_set_point_count(guider_ui.chart_lineChart, 50);
	lv_chart_set_range(guider_ui.chart_lineChart, LV_CHART_AXIS_PRIMARY_Y, 0, 25);
	lv_chart_set_range(guider_ui.chart_lineChart, LV_CHART_AXIS_SECONDARY_Y, 0, 10);
	lv_obj_set_style_width(guider_ui.chart_lineChart, 1, LV_PART_INDICATOR);
	lv_obj_set_style_height(guider_ui.chart_lineChart, 1, LV_PART_INDICATOR);

	int range1 = rand() % 25;
	int range2 = rand() % 10;
	lv_chart_set_next_value(guider_ui.chart_lineChart, guider_ui.chart_lineChart_0, range1);
	lv_chart_set_next_value(guider_ui.chart_lineChart, guider_ui.chart_lineChart_1, range2);

	lv_chart_refresh(guider_ui.chart_lineChart);
}
