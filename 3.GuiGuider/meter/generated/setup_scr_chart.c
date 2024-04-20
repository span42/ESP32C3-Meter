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



void setup_scr_chart(lv_ui *ui)
{
	//Write codes chart
	ui->chart = lv_obj_create(NULL);
	lv_obj_set_size(ui->chart, 240, 135);
	lv_obj_set_scrollbar_mode(ui->chart, LV_SCROLLBAR_MODE_OFF);

	//Write style for chart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->chart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->chart, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->chart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes chart_lineChart
	ui->chart_lineChart = lv_chart_create(ui->chart);
	lv_chart_set_type(ui->chart_lineChart, LV_CHART_TYPE_LINE);
	lv_chart_set_div_line_count(ui->chart_lineChart, 10, 10);
	lv_chart_set_point_count(ui->chart_lineChart, 1);
	lv_chart_set_range(ui->chart_lineChart, LV_CHART_AXIS_PRIMARY_Y, 0, 25);
	lv_chart_set_axis_tick(ui->chart_lineChart, LV_CHART_AXIS_PRIMARY_Y, 5, 3, 5, 5, true, 18);
	lv_chart_set_range(ui->chart_lineChart, LV_CHART_AXIS_SECONDARY_Y, 0, 5);
	lv_chart_set_axis_tick(ui->chart_lineChart, LV_CHART_AXIS_SECONDARY_Y, 5, 3, 5, 5, true, 12);
	lv_chart_set_zoom_x(ui->chart_lineChart, 256);
	lv_chart_set_zoom_y(ui->chart_lineChart, 256);
	ui->chart_lineChart_0 = lv_chart_add_series(ui->chart_lineChart, lv_color_hex(0x00ff78), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
	lv_chart_set_next_value(ui->chart_lineChart, ui->chart_lineChart_0, 5);
#endif
	ui->chart_lineChart_1 = lv_chart_add_series(ui->chart_lineChart, lv_color_hex(0xffbf00), LV_CHART_AXIS_SECONDARY_Y);
#if LV_USE_FREEMASTER == 0
	lv_chart_set_next_value(ui->chart_lineChart, ui->chart_lineChart_1, 0);
#endif
	lv_obj_set_pos(ui->chart_lineChart, 23, 0);
	lv_obj_set_size(ui->chart_lineChart, 196, 135);
	lv_obj_set_scrollbar_mode(ui->chart_lineChart, LV_SCROLLBAR_MODE_OFF);

	//Write style for chart_lineChart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->chart_lineChart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->chart_lineChart, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->chart_lineChart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->chart_lineChart, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->chart_lineChart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->chart_lineChart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_width(ui->chart_lineChart, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->chart_lineChart, lv_color_hex(0xbca600), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->chart_lineChart, 131, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->chart_lineChart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for chart_lineChart, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->chart_lineChart, lv_color_hex(0x151212), LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->chart_lineChart, &lv_font_freefont_12, LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->chart_lineChart, 255, LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_line_width(ui->chart_lineChart, 2, LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->chart_lineChart, lv_color_hex(0xe8e8e8), LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->chart_lineChart, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

	//The custom code of chart.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->chart);

	//Init events for screen.
	events_init_chart(ui);
}
