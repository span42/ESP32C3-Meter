/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *home;
	bool home_del;
	lv_obj_t *home_name;
	lv_obj_t *home_label_3;
	lv_obj_t *sensor;
	bool sensor_del;
	lv_obj_t *sensor_mWh;
	lv_obj_t *sensor_label_2;
	lv_obj_t *sensor_voltage;
	lv_obj_t *sensor_direct;
	lv_obj_t *sensor_watt;
	lv_obj_t *sensor_work_time;
	lv_obj_t *sensor_line_1;
	lv_obj_t *sensor_mAh;
	lv_obj_t *sensor_label_4;
	lv_obj_t *sensor_current;
	lv_obj_t *sensor_temperture;
	lv_obj_t *sensor_line_4;
	lv_obj_t *sensor_line_5;
	lv_obj_t *data;
	bool data_del;
	lv_obj_t *data_label_2;
	lv_obj_t *data_label_3;
	lv_obj_t *data_label_4;
	lv_obj_t *data_label_5;
	lv_obj_t *data_voltage;
	lv_obj_t *data_current;
	lv_obj_t *data_u_max;
	lv_obj_t *data_i_max;
	lv_obj_t *data_w_max;
	lv_obj_t *data_w_avg;
	lv_obj_t *data_i_avg;
	lv_obj_t *data_u_avg;
	lv_obj_t *data_w_min;
	lv_obj_t *data_i_min;
	lv_obj_t *data_u_min;
	lv_obj_t *data_line_1;
	lv_obj_t *data_datetime;
	lv_obj_t *device;
	bool device_del;
	lv_obj_t *device_label_15;
	lv_obj_t *device_label_14;
	lv_obj_t *device_label_1;
	lv_obj_t *device_label_2;
	lv_obj_t *device_cid;
	lv_obj_t *device_freq;
	lv_obj_t *device_heap;
	lv_obj_t *device_sdk;
	lv_obj_t *device_label_16;
	lv_obj_t *device_wifiip;
	lv_obj_t *device_label_17;
	lv_obj_t *device_rssi;
	lv_obj_t *weather;
	bool weather_del;
	lv_obj_t *weather_label_15;
	lv_obj_t *weather_label_14;
	lv_obj_t *weather_label_1;
	lv_obj_t *weather_label_2;
	lv_obj_t *weather_feels;
	lv_obj_t *weather_pressure;
	lv_obj_t *weather_windSpeed;
	lv_obj_t *weather_windDeg;
	lv_obj_t *weather_label_16;
	lv_obj_t *weather_temp;
	lv_obj_t *weather_label_17;
	lv_obj_t *weather_humidity;
	lv_obj_t *weather_label_23;
	lv_obj_t *weather_label_22;
	lv_obj_t *weather_label_21;
	lv_obj_t *weather_label_11;
	lv_obj_t *weather_label_19;
	lv_obj_t *weather_label_18;
	lv_obj_t *weather_city;
	lv_obj_t *weather_pm10;
	lv_obj_t *weather_pm25;
	lv_obj_t *weather_O3_;
	lv_obj_t *weather_visibility;
	lv_obj_t *weather_weather_main;
	lv_obj_t *weather_line_1;
	lv_obj_t *chart;
	bool chart_del;
	lv_obj_t *chart_lineChart;
	lv_chart_series_t *chart_lineChart_0;
	lv_chart_series_t *chart_lineChart_1;
	lv_obj_t *wifiap;
	bool wifiap_del;
	lv_obj_t *wifiap_label_1;
	lv_obj_t *wifiap_label_2;
	lv_obj_t *wifiap_ta_1;
	lv_obj_t *wifiap_ta_2;
	lv_obj_t *wifiap_label_3;
	lv_obj_t *wifiap_qrcode_1;
  int global_language;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_move_animation(void * var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_scale_animation(void * var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
                        uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                        lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_zoom_animation(void * var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
                           uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                           lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_rotate_animation(void * var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
                   lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                   uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;
extern int global_language;


void setup_scr_home(lv_ui *ui);
void setup_scr_sensor(lv_ui *ui);
void setup_scr_data(lv_ui *ui);
void setup_scr_device(lv_ui *ui);
void setup_scr_weather(lv_ui *ui);
void setup_scr_chart(lv_ui *ui);
void setup_scr_wifiap(lv_ui *ui);

LV_FONT_DECLARE(lv_font_CnBold_20)
LV_FONT_DECLARE(lv_font_CnBold_16)
LV_FONT_DECLARE(lv_font_CnBold_50)
LV_FONT_DECLARE(lv_font_freefont_16)
LV_FONT_DECLARE(lv_font_freefont_24)
LV_FONT_DECLARE(lv_font_arial_16)
LV_FONT_DECLARE(lv_font_freefont_44)
LV_FONT_DECLARE(lv_font_freefont_36)
LV_FONT_DECLARE(lv_font_freefont_26)
LV_FONT_DECLARE(lv_font_CnBold_24)
LV_FONT_DECLARE(lv_font_freefont_20)
LV_FONT_DECLARE(lv_font_CnBold_18)
LV_FONT_DECLARE(lv_font_freefont_18)
LV_FONT_DECLARE(lv_font_freefont_12)
LV_FONT_DECLARE(lv_font_arial_12)


#ifdef __cplusplus
}
#endif
#endif
