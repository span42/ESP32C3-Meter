#ifndef UI_H
#define UI_H

// #ifdef __cplusplus
// extern "C" {
// #endif

#include <Wire.h>
#include <INA226.h>

class Sensor_Data
{
public:
	float U, I, W;
	float u_max, i_max, w_max;
	float u_avg, i_avg, w_avg;
	float u_avg_t, i_avg_t, w_avg_t;
	int avg_count;
	float u_min, i_min, w_min;
	float Wh = 0;	 // 电量
	float mAh = 0; // 电量
	struct tm timeinfo;
	uint32_t ms;

public:
	void init();
	void read();
	void calc();
};

extern Sensor_Data sensor;
// #ifdef __cplusplus
// } /* extern "C" */
// #endif

#endif