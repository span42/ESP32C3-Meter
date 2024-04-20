#include <EEPROM.h>
#include "config.h"

void Config::init()
{
	// 初始化
	EEPROM.begin(512);
	read();
}
void Config::read()
{
	// 读取保存的配置信息
	ssid = readFromEEPROM(ssid_offset, SSID_SIZE);
	password = readFromEEPROM(password_offset, PASSWORD_SIZE);
	ip = readFromEEPROM(ip_offset, IP_SIZE);
	port = readFromEEPROM(port_offset, PORT_SIZE);
	rotation = readFromEEPROM(rotation_offset, ROTATION_SIZE);
	weatherApiKey = readFromEEPROM(apikey_offset, APIKEY_SIZE);
	cityid = readFromEEPROM(cityid_offset, CITYID_SIZE);

	if (ssid == "") 
	{
		ssid = "";
		password = "";
		ip = "";
		port = "";
	}
}
void Config::save()
{
	// 保存配置
	if (ssid != "")
	{
		saveToEEPROM(ssid_offset, ssid);
		saveToEEPROM(password_offset, password);
		saveToEEPROM(ip_offset, ip);
		saveToEEPROM(port_offset, port);
	}
	if (weatherApiKey != "")
	{
		saveToEEPROM(apikey_offset, weatherApiKey);
	}
	if (cityid != "")
	{
		saveToEEPROM(cityid_offset, cityid);
	}
}

void Config::saveRotation()
{
	saveToEEPROM(rotation_offset, rotation);
}

String Config::readFromEEPROM(int offset, int size)
{
	String data = "";
	for (int i = offset; i < offset + size; i++)
	{
		char c = EEPROM.read(i);
		if (c == '\0')
		{
			break;
		}
		data += c;
	}
	return data;
}

void Config::saveToEEPROM(int offset, String data)
{
	for (int i = offset; i < offset + data.length(); i++)
	{
		EEPROM.write(i, data[i - offset]);
	}
	EEPROM.write(offset + data.length(), '\0');
	EEPROM.commit();
}

Config config;