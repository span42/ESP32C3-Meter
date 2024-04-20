#include "button.h"
#include <lvgl.h>
#include "gui_guider.h"
#include <wifi_bt.h>
#include <display.h>
#include <config.h>

// button
#define BTN1_PIN 4 // 按键1
// #define BTN2_PIN 5												// 按键2
static OneButton button1(BTN1_PIN, true); // 实例化一个OneButton对象1
// static OneButton button2(BTN2_PIN, true); // 实例化一个OneButton对象2
extern lv_ui guider_ui;

void Button::init()
{
	button1.reset();				// 清除按钮状态机的状态
	button1.setClickMs(50); // 设置单击时间
	// button1.setDebounceTicks(400);	 // 设置双击时间
	// button1.setDebounceMs(50);			 // 设置双击时间
	button1.attachClick(click1); // 绑定单击事件到函数
	button1.attachDoubleClick(doubleClick1);
	button1.setLongPressIntervalMs(1000);
	button1.attachLongPressStop(longPressStop1);

	// button2.setClickMs(50);	 // 设置单击时间
	// button2.attachClick(click2); // 绑定单击事件到函数
}

void Button::monitor()
{
	button1.tick(); // 监视按钮1
									// button2.tick(); // 监视按钮2
}

void Button::click1()
{ // 按钮1函数
	if (config.rotation == "1")
	{
		tft.setRotation(3);
		config.rotation = "3";
		config.saveRotation();
	}
	else
	{
		tft.setRotation(1);
		config.rotation = "1";
		config.saveRotation();
	}
}

void Button::click2()
{ // 按钮2函数
}

void Button::doubleClick1()
{ // 按钮1函数
	Serial.println("doubleClick1");
}
void Button::longPressStop1()
{ // 按钮1函数
	Serial.println("longPressStop1");
	ESP.restart();
}

Button button;