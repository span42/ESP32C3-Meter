#ifndef DISPLAY_H
#define DISPLAY_H

#include "gui_guider.h"
#include <TFT_eSPI.h>
// #ifdef __cplusplus
// extern "C" {
// #endif

#define LCD_BL_PIN 1
#define LCD_BL_PWM_CHANNEL 0

class Display
{
private:
public:
	void init();
	void routine();
	void setBackLight(float);
};

// #ifdef __cplusplus
// } /* extern "C" */
// #endif

extern TFT_eSPI tft;
extern TFT_eSprite spr;
extern Display screen;
extern lv_ui guider_ui;

#endif