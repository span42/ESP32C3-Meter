/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


#include "custom.h"
lv_timer_t *sensor_timer = NULL;
#include "custom.h"
lv_timer_t *data_timer = NULL;
#include "custom.h"
lv_timer_t *device_timer = NULL;
lv_timer_t *weather_timer = NULL;
lv_timer_t *chart_timer = NULL;
static void home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.sensor, guider_ui.sensor_del, &guider_ui.home_del, setup_scr_sensor, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 2000, false, true);
		break;
	}
	default:
		break;
	}
}
void events_init_home(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->home, home_event_handler, LV_EVENT_ALL, ui);
}
static void sensor_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.data, guider_ui.data_del, &guider_ui.sensor_del, setup_scr_data, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
		break;
	}
	case LV_EVENT_SCREEN_LOADED:
	{
		update_sensor_data(NULL);
	sensor_timer = lv_timer_create(update_sensor_data, 200, 0);
		break;
	}
	case LV_EVENT_SCREEN_UNLOADED:
	{
		lv_timer_del(sensor_timer);
		break;
	}
	default:
		break;
	}
}
void events_init_sensor(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->sensor, sensor_event_handler, LV_EVENT_ALL, ui);
}
static void data_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.device, guider_ui.device_del, &guider_ui.data_del, setup_scr_device, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
		break;
	}
	case LV_EVENT_SCREEN_LOADED:
	{
		update_data_page_data(NULL);
	data_timer = lv_timer_create(update_data_page_data, 200, 0);
		break;
	}
	case LV_EVENT_SCREEN_UNLOADED:
	{
		lv_timer_del(data_timer);
		break;
	}
	default:
		break;
	}
}
void events_init_data(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->data, data_event_handler, LV_EVENT_ALL, ui);
}
static void device_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.weather, guider_ui.weather_del, &guider_ui.device_del, setup_scr_weather, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
		break;
	}
	case LV_EVENT_SCREEN_LOADED:
	{
		update_device_data(NULL);
	device_timer = lv_timer_create(update_device_data, 2000, 0);
		break;
	}
	case LV_EVENT_SCREEN_UNLOADED:
	{
		lv_timer_del(device_timer);
		break;
	}
	default:
		break;
	}
}
void events_init_device(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->device, device_event_handler, LV_EVENT_ALL, ui);
}
static void weather_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.chart, guider_ui.chart_del, &guider_ui.weather_del, setup_scr_chart, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	case LV_EVENT_SCREEN_LOADED:
	{
		update_weather(NULL);
	weather_timer = lv_timer_create(update_weather, 2000, 0);
		break;
	}
	case LV_EVENT_SCREEN_UNLOADED:
	{
		lv_timer_del(weather_timer);
		break;
	}
	default:
		break;
	}
}
void events_init_weather(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->weather, weather_event_handler, LV_EVENT_ALL, ui);
}
static void chart_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.sensor, guider_ui.sensor_del, &guider_ui.chart_del, setup_scr_sensor, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	case LV_EVENT_SCREEN_LOADED:
	{
		chart_timer = lv_timer_create(update_chart, 200, 0);
		break;
	}
	case LV_EVENT_SCREEN_UNLOADED:
	{
		lv_timer_del(chart_timer);
		break;
	}
	default:
		break;
	}
}
static void chart_lineChart_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.sensor, guider_ui.sensor_del, &guider_ui.chart_del, setup_scr_sensor, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
void events_init_chart(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->chart, chart_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->chart_lineChart, chart_lineChart_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{

}
