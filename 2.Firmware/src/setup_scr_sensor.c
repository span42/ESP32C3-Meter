/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_sensor(lv_ui *ui)
{
	//Write codes sensor
	ui->sensor = lv_obj_create(NULL);
	lv_obj_set_size(ui->sensor, 240, 135);
	lv_obj_set_scrollbar_mode(ui->sensor, LV_SCROLLBAR_MODE_OFF);

	//Write style for sensor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->sensor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->sensor, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->sensor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sensor_mWh
	ui->sensor_mWh = lv_label_create(ui->sensor);
	lv_label_set_text(ui->sensor_mWh, "0.0000");
	lv_label_set_long_mode(ui->sensor_mWh, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sensor_mWh, 155, 47);
	lv_obj_set_size(ui->sensor_mWh, 81, 19);

	//Write style for sensor_mWh, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sensor_mWh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sensor_mWh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sensor_mWh, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sensor_mWh, &lv_font_freefont_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->sensor_mWh, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sensor_mWh, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sensor_mWh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sensor_mWh, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sensor_mWh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sensor_mWh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sensor_mWh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sensor_mWh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sensor_mWh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sensor_mWh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sensor_label_2
	ui->sensor_label_2 = lv_label_create(ui->sensor);
	lv_label_set_text(ui->sensor_label_2, "mAh");
	lv_label_set_long_mode(ui->sensor_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sensor_label_2, 155, 20);
	lv_obj_set_size(ui->sensor_label_2, 82, 19);

	//Write style for sensor_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sensor_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sensor_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sensor_label_2, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sensor_label_2, &lv_font_freefont_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->sensor_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sensor_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sensor_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sensor_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sensor_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sensor_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sensor_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sensor_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sensor_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sensor_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sensor_voltage
	ui->sensor_voltage = lv_label_create(ui->sensor);
	lv_label_set_text(ui->sensor_voltage, "00.0000V");
	lv_label_set_long_mode(ui->sensor_voltage, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sensor_voltage, -1, 0);
	lv_obj_set_size(ui->sensor_voltage, 150, 36);

	//Write style for sensor_voltage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sensor_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sensor_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sensor_voltage, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sensor_voltage, &lv_font_freefont_44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->sensor_voltage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sensor_voltage, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sensor_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sensor_voltage, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sensor_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sensor_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sensor_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sensor_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sensor_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sensor_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sensor_direct
	ui->sensor_direct = lv_label_create(ui->sensor);
	lv_label_set_text(ui->sensor_direct, "⮕⬅");
	lv_label_set_long_mode(ui->sensor_direct, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sensor_direct, 156, 117);
	lv_obj_set_size(ui->sensor_direct, 82, 13);

	//Write style for sensor_direct, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sensor_direct, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sensor_direct, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sensor_direct, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sensor_direct, &lv_font_CnBold_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->sensor_direct, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sensor_direct, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sensor_direct, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sensor_direct, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sensor_direct, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sensor_direct, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sensor_direct, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sensor_direct, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sensor_direct, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sensor_direct, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sensor_watt
	ui->sensor_watt = lv_label_create(ui->sensor);
	lv_label_set_text(ui->sensor_watt, "00.0000W");
	lv_label_set_long_mode(ui->sensor_watt, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sensor_watt, -5, 68);
	lv_obj_set_size(ui->sensor_watt, 154, 36);

	//Write style for sensor_watt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sensor_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sensor_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sensor_watt, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sensor_watt, &lv_font_freefont_44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->sensor_watt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sensor_watt, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sensor_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sensor_watt, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sensor_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sensor_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sensor_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sensor_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sensor_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sensor_watt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sensor_work_time
	ui->sensor_work_time = lv_label_create(ui->sensor);
	lv_label_set_text(ui->sensor_work_time, "00:00:00\n");
	lv_label_set_long_mode(ui->sensor_work_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sensor_work_time, 11, 103);
	lv_obj_set_size(ui->sensor_work_time, 136, 30);

	//Write style for sensor_work_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sensor_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sensor_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sensor_work_time, lv_color_hex(0xD01FBB), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sensor_work_time, &lv_font_freefont_36, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->sensor_work_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sensor_work_time, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sensor_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sensor_work_time, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sensor_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sensor_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sensor_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sensor_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sensor_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sensor_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sensor_line_1
	ui->sensor_line_1 = lv_line_create(ui->sensor);
	static lv_point_t sensor_line_1[] ={{0, 0},{0, 135},};
	lv_line_set_points(ui->sensor_line_1, sensor_line_1, 2);
	lv_obj_set_pos(ui->sensor_line_1, 152, 2);
	lv_obj_set_size(ui->sensor_line_1, 1, 130);

	//Write style for sensor_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->sensor_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->sensor_line_1, lv_color_hex(0x00ff47), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->sensor_line_1, 154, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->sensor_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sensor_mAh
	ui->sensor_mAh = lv_label_create(ui->sensor);
	lv_label_set_text(ui->sensor_mAh, "0.0000");
	lv_label_set_long_mode(ui->sensor_mAh, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sensor_mAh, 154, 2);
	lv_obj_set_size(ui->sensor_mAh, 82, 19);

	//Write style for sensor_mAh, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sensor_mAh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sensor_mAh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sensor_mAh, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sensor_mAh, &lv_font_freefont_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->sensor_mAh, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sensor_mAh, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sensor_mAh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sensor_mAh, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sensor_mAh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sensor_mAh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sensor_mAh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sensor_mAh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sensor_mAh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sensor_mAh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sensor_label_4
	ui->sensor_label_4 = lv_label_create(ui->sensor);
	lv_label_set_text(ui->sensor_label_4, "mWh");
	lv_label_set_long_mode(ui->sensor_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sensor_label_4, 155, 68);
	lv_obj_set_size(ui->sensor_label_4, 81, 20);

	//Write style for sensor_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sensor_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sensor_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sensor_label_4, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sensor_label_4, &lv_font_freefont_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->sensor_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sensor_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sensor_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sensor_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sensor_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sensor_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sensor_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sensor_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sensor_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sensor_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sensor_current
	ui->sensor_current = lv_label_create(ui->sensor);
	lv_label_set_text(ui->sensor_current, "00.0000A");
	lv_label_set_long_mode(ui->sensor_current, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sensor_current, -2, 34);
	lv_obj_set_size(ui->sensor_current, 151, 36);

	//Write style for sensor_current, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sensor_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sensor_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sensor_current, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sensor_current, &lv_font_freefont_44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->sensor_current, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sensor_current, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sensor_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sensor_current, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sensor_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sensor_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sensor_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sensor_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sensor_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sensor_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sensor_temperture
	ui->sensor_temperture = lv_label_create(ui->sensor);
	lv_label_set_text(ui->sensor_temperture, "21.0℃");
	lv_label_set_long_mode(ui->sensor_temperture, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sensor_temperture, 158, 95);
	lv_obj_set_size(ui->sensor_temperture, 82, 26);

	//Write style for sensor_temperture, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sensor_temperture, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sensor_temperture, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sensor_temperture, lv_color_hex(0xd7f130), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sensor_temperture, &lv_font_freefont_26, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->sensor_temperture, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sensor_temperture, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sensor_temperture, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sensor_temperture, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sensor_temperture, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sensor_temperture, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sensor_temperture, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sensor_temperture, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sensor_temperture, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sensor_temperture, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sensor_line_4
	ui->sensor_line_4 = lv_line_create(ui->sensor);
	static lv_point_t sensor_line_4[] ={{0, 0},{100, 0},};
	lv_line_set_points(ui->sensor_line_4, sensor_line_4, 2);
	lv_obj_set_pos(ui->sensor_line_4, 155, 44);
	lv_obj_set_size(ui->sensor_line_4, 80, 3);

	//Write style for sensor_line_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->sensor_line_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->sensor_line_4, lv_color_hex(0x00ff47), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->sensor_line_4, 143, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->sensor_line_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sensor_line_5
	ui->sensor_line_5 = lv_line_create(ui->sensor);
	static lv_point_t sensor_line_5[] ={{0, 0},{100, 0},};
	lv_line_set_points(ui->sensor_line_5, sensor_line_5, 2);
	lv_obj_set_pos(ui->sensor_line_5, 156, 92);
	lv_obj_set_size(ui->sensor_line_5, 80, 3);

	//Write style for sensor_line_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->sensor_line_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->sensor_line_5, lv_color_hex(0x00ff47), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->sensor_line_5, 143, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->sensor_line_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of sensor.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->sensor);

	//Init events for screen.
	events_init_sensor(ui);
}
