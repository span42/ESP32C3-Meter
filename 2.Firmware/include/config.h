#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
// 变量
#define SSID_SIZE 32
#define PASSWORD_SIZE 64
#define IP_SIZE 16
#define PORT_SIZE 6
#define ROTATION_SIZE 2
#define APIKEY_SIZE 40
#define CITYID_SIZE 10

// 地址偏移

class Config
{
private:
	int ssid_offset;
	int password_offset;
	int ip_offset;
	int port_offset;
	int rotation_offset;
	int apikey_offset;
	int cityid_offset;

public:
	String ssid;
	String password;
	String ip;
	String port;
	String ap_ssid;
	String ap_password;
	IPAddress ap_ip;
	String rotation;
	String weatherApiKey;
	String cityid;

	Config()
	{
		ssid_offset = 0;
		password_offset = ssid_offset + SSID_SIZE;
		ip_offset = password_offset + PASSWORD_SIZE;
		port_offset = ip_offset + IP_SIZE;
		rotation_offset = port_offset + PORT_SIZE;
		apikey_offset = rotation_offset + ROTATION_SIZE;
		cityid_offset = apikey_offset + APIKEY_SIZE;

		ap_ssid = "ESP32-C3";
		ap_password = "88888888";
		ap_ip = IPAddress(192, 168, 1, 1);
	}

	void init();
	void read();
	void save();
	void saveRotation();
	String readFromEEPROM(int offset, int size);
	void saveToEEPROM(int offset, String data);
};

extern Config config;

#endif