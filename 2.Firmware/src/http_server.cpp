
#include <WebServer.h>
#include "http_server.h"
#include <config.h>
#include <LittleFS.h>

extern void vTaskList(char *pcWriteBuffer);

// web server
WebServer server(80); // 声明WebServer对象

// home页
String webHomePage = R"delimiter(
			<html>
				<head>
				<title>ESP32-C3</title>
				<meta charset="utf-8">
				</head>
				<body>
				<h1>ESP32-C3</h1>
				<ul>
					<li>
					<a href="setWifi">setWifi</a>
					</li>
					<li>
					<a href="info">info</a>
					</li> 
				</ul></body>
				</html>
			)delimiter";

String setWifiPage = R"delimiter(
			<html>
				<head>
				<title>ESP32-C3</title>
				<meta charset="utf-8">
				</head>
				<body>
				<h1>setWifi</h1>
				<form name="form" method="post" action="do">
					<div>
						<label for="SSID">SSID:</label>
						<input id="SSID" type="text" name="SSID" />
					</div>
					<div>
						<label for="Password">Password:</label>
						<input id="Password" type="text" name="Password" />
					</div>
					<div>
						<input type="submit" value="保存并重启" />
					</div>
				</form>
				</body>
			</html>
			)delimiter";

void handleRoot() // 回调函数
{
	server.send(200, "text/html", webHomePage); // ！！！注意返回网页需要用"text/html" ！！！
}

void handleSetWifi() // 回调函数
{
	server.send(200, "text/html", setWifiPage); // ！！！注意返回网页需要用"text/html" ！！！
}

void handleInfo() // 回调函数
{
	uint64_t chipid = ESP.getEfuseMac();
	String info = "\n";
	info += "ESP32 Chip ID: " + String(chipid) + "\n";
	info += "ChipRevision: " + String(ESP.getChipRevision()) + "\n";
	info += "ChipModel: " + String(ESP.getChipModel()) + "\n";
	info += "ChipCores: " + String(ESP.getChipCores()) + "\n";
	info += "CpuFreqMHz: " + String(ESP.getCpuFreqMHz()) + "MHz\n";
	info += "CycleCount: " + String(ESP.getCycleCount()) + "\n";
	info += "SdkVersion: " + String(ESP.getSdkVersion()) + "\n";

	info += "\n\n";
	info += "TotalHeapSize: " + String(ESP.getHeapSize() / 1024) + "KB\n";
	info += "FreeHeapSize: " + String(ESP.getFreeHeap() / 1024) + "KB\n";
	info += "MinFreeHeap: " + String(ESP.getMinFreeHeap() / 1024) + "KB\n";
	info += "MaxAllocHeap: " + String(ESP.getMaxAllocHeap() / 1024) + "KB\n";
	info += "PsramSize: " + String(ESP.getPsramSize()) + "\n";
	info += "FreePsram: " + String(ESP.getFreePsram()) + "\n";
	info += "MinFreePsram: " + String(ESP.getMinFreePsram()) + "\n";
	info += "MaxAllocPsram: " + String(ESP.getMaxAllocPsram()) + "\n";

	info += "\n\n";
	info += "FlashChipSize: " + String(ESP.getFlashChipSize() / 1024) + "KB\n";
	info += "FlashChipSpeed: " + String(ESP.getFlashChipSpeed() / 1000000) + "MHz\n";
	info += "FlashChipMode: " + String(ESP.getFlashChipMode()) + "\n";
	info += "SketchSize: " + String(ESP.getSketchSize() / 1024) + "KB\n";
	info += "FreeSketchSpace: " + String(ESP.getFreeSketchSpace() / 1024) + "KB\n";

	info += "\n\n";
	info += "AP IP address: " + String(WiFi.softAPIP().toString()) + "\n";
	info += "AP Broadcast IP: " + String(WiFi.softAPBroadcastIP().toString()) + "\n";
	info += "AP NetworkID: " + String(WiFi.softAPNetworkID().toString()) + "\n";
	info += "AP SubnetCIDR: " + String(WiFi.softAPSubnetCIDR()) + "\n";
	info += "AP Hostname: " + String(WiFi.softAPgetHostname()) + "\n";
	info += "AP MacAddress: " + String(WiFi.softAPmacAddress()) + "\n";
	info += "AP StationNum: " + String(WiFi.softAPgetStationNum()) + "\n";
	info += "Wifi TxPower: " + String(WiFi.getTxPower()) + "\n";

	info += "\n";
	info += "Wifi SSID: " + String(WiFi.SSID()) + "\n";
	info += "Wifi LocalIP: " + WiFi.localIP().toString() + "\n";
	info += "Wifi RSSI: " + String(WiFi.RSSI()) + "\n";
	info += "Wifi MacAddress: " + String(WiFi.macAddress()) + "\n";
	info += "Wifi GatewayIP: " + String(WiFi.gatewayIP().toString()) + "\n";
	info += "Wifi DnsIP: " + String(WiFi.dnsIP().toString()) + "\n";

	server.send(200, "text/plain", info); // ！！！注意返回网页需要用"text/html" ！！！
}

// void handleAjax() // 回调函数
// {
// 	String message = "随机数据：";
// 	message += String(random(10000));				 // 取得随机数
// 	server.send(200, "text/plain", message); // 将消息发送回页面
// }

void handleDo() // 回调函数
{
	String ssid = "";
	String pwd = "";
	String apikey = "";
	String cityid = "";
	for (int i = 0; i < server.args(); i++)
	{
		if (server.argName(i) == "SSID")
			ssid = server.arg(i);
		if (server.argName(i) == "Password")
			pwd = server.arg(i);

		if (server.argName(i) == "ApiKey")
			apikey = server.arg(i);

		if (server.argName(i) == "CityID")
			cityid = server.arg(i);	
	}
	if (ssid != "")
	{
		config.ssid = ssid;
		config.password = pwd;
	}
	if (apikey != "")
	{
		config.weatherApiKey = apikey;
	}
	if (cityid != "")
	{
		config.cityid = cityid;
	}

	// save eeprom
	config.save();

	server.send(200, "text/plain", "reboot...");
	delay(200);
	ESP.restart();
}

void http_init()
{
	// server.on("/p2", []() { // 注册链接"/p2"，对应回调函数通过内联函数声明
	// 	server.send(200, "text/plain", "这是P2页面，由内联函数声明");
	// });
	server.serveStatic("/", LittleFS, "/index.html");
	server.serveStatic("/config", LittleFS, "/config.html");
	server.on("/info", handleInfo);
	server.on("/do", HTTP_POST, handleDo);
	// server.on("/getRandomData", HTTP_GET, handleAjax); // 注册网页中ajax发送的get方法的请求和回调函数

	server.begin(); // 启动服务器
}

void http_routine()
{
	server.handleClient(); // 处理来自客户端的请求
}