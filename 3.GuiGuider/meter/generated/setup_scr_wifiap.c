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



void setup_scr_wifiap(lv_ui *ui)
{
	//Write codes wifiap
	ui->wifiap = lv_obj_create(NULL);
	lv_obj_set_size(ui->wifiap, 240, 135);
	lv_obj_set_scrollbar_mode(ui->wifiap, LV_SCROLLBAR_MODE_OFF);

	//Write style for wifiap, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->wifiap, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->wifiap, lv_color_hex(0x17476b), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->wifiap, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifiap_label_1
	ui->wifiap_label_1 = lv_label_create(ui->wifiap);
	lv_label_set_text(ui->wifiap_label_1, "AP模式");
	lv_label_set_long_mode(ui->wifiap_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->wifiap_label_1, 64, 11);
	lv_obj_set_size(ui->wifiap_label_1, 100, 23);

	//Write style for wifiap_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->wifiap_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifiap_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->wifiap_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifiap_label_1, &lv_font_CnBold_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifiap_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifiap_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->wifiap_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifiap_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifiap_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifiap_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifiap_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->wifiap_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifiap_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifiap_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifiap_label_2
	ui->wifiap_label_2 = lv_label_create(ui->wifiap);
	lv_label_set_text(ui->wifiap_label_2, "SSID");
	lv_label_set_long_mode(ui->wifiap_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->wifiap_label_2, -7, 43);
	lv_obj_set_size(ui->wifiap_label_2, 58, 20);

	//Write style for wifiap_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->wifiap_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifiap_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->wifiap_label_2, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifiap_label_2, &lv_font_freefont_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifiap_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifiap_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->wifiap_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifiap_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifiap_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifiap_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifiap_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->wifiap_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifiap_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifiap_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifiap_ta_1
	ui->wifiap_ta_1 = lv_textarea_create(ui->wifiap);
	lv_textarea_set_text(ui->wifiap_ta_1, "ESP32-C3");
	lv_textarea_set_placeholder_text(ui->wifiap_ta_1, "");
	lv_textarea_set_password_bullet(ui->wifiap_ta_1, "*");
	lv_textarea_set_password_mode(ui->wifiap_ta_1, false);
	lv_textarea_set_one_line(ui->wifiap_ta_1, false);
	lv_textarea_set_accepted_chars(ui->wifiap_ta_1, "");
	lv_textarea_set_max_length(ui->wifiap_ta_1, 32);
	lv_obj_set_pos(ui->wifiap_ta_1, 44, 39);
	lv_obj_set_size(ui->wifiap_ta_1, 95, 29);

	//Write style for wifiap_ta_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->wifiap_ta_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifiap_ta_1, &lv_font_freefont_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifiap_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifiap_ta_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifiap_ta_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifiap_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->wifiap_ta_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->wifiap_ta_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->wifiap_ta_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->wifiap_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->wifiap_ta_1, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->wifiap_ta_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifiap_ta_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifiap_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifiap_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifiap_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifiap_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for wifiap_ta_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->wifiap_ta_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->wifiap_ta_1, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->wifiap_ta_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifiap_ta_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes wifiap_ta_2
	ui->wifiap_ta_2 = lv_textarea_create(ui->wifiap);
	lv_textarea_set_text(ui->wifiap_ta_2, "88888888");
	lv_textarea_set_placeholder_text(ui->wifiap_ta_2, "");
	lv_textarea_set_password_bullet(ui->wifiap_ta_2, "*");
	lv_textarea_set_password_mode(ui->wifiap_ta_2, false);
	lv_textarea_set_one_line(ui->wifiap_ta_2, false);
	lv_textarea_set_accepted_chars(ui->wifiap_ta_2, "");
	lv_textarea_set_max_length(ui->wifiap_ta_2, 32);
	lv_obj_set_pos(ui->wifiap_ta_2, 44, 80);
	lv_obj_set_size(ui->wifiap_ta_2, 95, 29);

	//Write style for wifiap_ta_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->wifiap_ta_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifiap_ta_2, &lv_font_freefont_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifiap_ta_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifiap_ta_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifiap_ta_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifiap_ta_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->wifiap_ta_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->wifiap_ta_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->wifiap_ta_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->wifiap_ta_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->wifiap_ta_2, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->wifiap_ta_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifiap_ta_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifiap_ta_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifiap_ta_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifiap_ta_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifiap_ta_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for wifiap_ta_2, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->wifiap_ta_2, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->wifiap_ta_2, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->wifiap_ta_2, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifiap_ta_2, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes wifiap_label_3
	ui->wifiap_label_3 = lv_label_create(ui->wifiap);
	lv_label_set_text(ui->wifiap_label_3, "PWD");
	lv_label_set_long_mode(ui->wifiap_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->wifiap_label_3, -7, 89);
	lv_obj_set_size(ui->wifiap_label_3, 58, 20);

	//Write style for wifiap_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->wifiap_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifiap_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->wifiap_label_3, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifiap_label_3, &lv_font_freefont_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifiap_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifiap_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->wifiap_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifiap_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifiap_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifiap_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifiap_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->wifiap_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifiap_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifiap_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifiap_qrcode_1
	ui->wifiap_qrcode_1 = lv_qrcode_create(ui->wifiap, 85, lv_color_hex(0x2C3224), lv_color_hex(0xffffff));
	const char * wifiap_qrcode_1_data = "http://192.168.1.1/config";
	lv_qrcode_update(ui->wifiap_qrcode_1, wifiap_qrcode_1_data, strlen(wifiap_qrcode_1_data));
	lv_obj_set_pos(ui->wifiap_qrcode_1, 147, 34);
	lv_obj_set_size(ui->wifiap_qrcode_1, 85, 85);

	//The custom code of wifiap.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->wifiap);

}
