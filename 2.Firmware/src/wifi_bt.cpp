
#include <WiFi.h>
#include <PubSubClient.h>
#include "wifi_bt.h"
#include <config.h>
#include <esp_wifi.h>
#include <sensor.h>

void printWifiStatus()
{
	Serial.print("SSID: ");
	Serial.println(WiFi.SSID());

	IPAddress ip = WiFi.localIP();
	Serial.print("IP Address: ");
	Serial.println(ip);

	long rssi = WiFi.RSSI();
	Serial.print("signal strength (RSSI):");
	Serial.print(rssi);
	Serial.println(" dBm");
}

// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const char *topic = "esp32/test1";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
const int mqtt_port = 1883;
// for our data output loop
char buff[50];
int car_speed = 10;
WiFiClient espClient;
PubSubClient client(espClient);

static const byte DNS_PORT = 53;

#define NTP1 "ntp1.aliyun.com"
#define NTP2 "ntp2.aliyun.com"
#define NTP3 "ntp3.aliyun.com"

void setClock()
{
	
	if (!getLocalTime(&sensor.timeinfo))
	{  
		Serial.println("Failed to obtain time");
		if (WiFi.status() == WL_CONNECTED)
		{
			configTime(8 * 3600, 0, NTP1, NTP2, NTP3);
		}
		delay(5000);
		return;
	}
	
	// Serial.println(&sensor.timeinfo, "%F %T %A"); // 格式化输出:2021-10-24 23:00:44 Sunday
																				 // Serial.print(asctime(&timeinfo));			 // 默认打印格式：Mon Oct 25 11:13:29 2021
																				 // WiFi.disconnect(true);//断开网络连接，关闭网络
}

void wifi_ap_mode()
{
	// AP模式
	WiFi.mode(WIFI_AP);
	WiFi.setTxPower(WIFI_POWER_5dBm);
	WiFi.softAPConfig(config.ap_ip, config.ap_ip, IPAddress(255, 255, 255, 0));
	WiFi.softAP(config.ap_ssid, config.ap_password, 6);
	WiFi.softAPsetHostname(config.ap_ssid.c_str());
}

void wifi_ap_info()
{
	Serial.print("AP IP address: ");
	Serial.println(WiFi.softAPIP());

	Serial.print("softAP Broadcast IP: ");
	Serial.println(WiFi.softAPBroadcastIP());

	Serial.print("softAP NetworkID: ");
	Serial.println(WiFi.softAPNetworkID());

	Serial.print("softAP SubnetCIDR: ");
	Serial.println(WiFi.softAPSubnetCIDR());

	Serial.print("softAP Hostname: ");
	Serial.println(WiFi.softAPgetHostname());

	Serial.print("softAP macAddress: ");
	Serial.println(WiFi.softAPmacAddress());

	Serial.print("softAP txPower: ");
	Serial.printf("%ddbm \n", WiFi.getTxPower());

	Serial.print("softAP StationNum: ");
	Serial.println(WiFi.softAPgetStationNum());
}

// MQTT消息回调函数，该函数会在PubSubClient对象的loop方法中被调用
void mqtt_callback(char *topic, byte *payload, unsigned int length)
{
    Serial.printf("Message arrived in topic %s, length %d\n", topic, length);
    Serial.print("Message:");
    for (int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }
    Serial.println("\n----------------END----------------");
}

void wifi_bt_init()
{
	// STA模式 
	WiFi.mode(WIFI_STA);
	WiFi.disconnect();
	delay(100);
	WiFi.setTxPower(WIFI_POWER_5dBm);
	WiFi.begin(config.ssid, config.password);

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}

	Serial.println("");
	Serial.println("Connected to WiFi");

	setClock();

	client.setServer(mqtt_broker, mqtt_port);
	while (!client.connected())
	{
		String client_id = "esp32-client-";
		client_id += String(WiFi.macAddress());
		Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
		if (client.connect(client_id.c_str(), mqtt_username, mqtt_password))
		{
			Serial.println("Public emqx mqtt broker connected");
		}
		else
		{
			Serial.print("failed with state ");
			Serial.print(client.state());
			delay(2000);
		}
	}

	client.setCallback(mqtt_callback);
	// publish and subscribe
	client.publish(topic, "Hi EMQ X I'm ESP32C3 ^^");
	client.subscribe("Amobbs/span42/#");
}

void check_wifi()
{
	if (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	else
	{
		client.loop();
		return;
	}

	// retry STA模式
	WiFi.begin(config.ssid, config.password);

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}

	Serial.println("");
	Serial.println("Connected to WiFi");
}