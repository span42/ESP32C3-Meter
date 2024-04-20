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
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

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

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

float V_val = 0;
void update_sensor_data(lv_timer_t *tmr)
{
 //    lv_label_set_text_fmt(guider_ui.sensor_mAh, "%.3f", V_val + 11);
	// lv_label_set_text_fmt(guider_ui.sensor_mWh, "%.2f", V_val + 111);
	// lv_label_set_text_fmt(guider_ui.sensor_direct, "<<<<<<");
	// V_val += 0.001;
	// if (V_val > 99.999)
	// {
	// 	V_val = 0;
	// }
}

void update_data_page_data(lv_timer_t *tmr)
{
  
}

void update_device_data(lv_timer_t *tmr)
{
  
}

void update_weather(lv_timer_t *tmr)
{

}


void update_chart(lv_timer_t *tmr){
  
}
