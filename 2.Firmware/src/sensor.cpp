
#include <Arduino.h>
#include "sensor.h"

static INA226 ina(0x40);

void Sensor_Data::init()
{
	Wire.begin();
	ina.setMaxCurrentShunt(8, 0.01); // 分流电阻值

	ms = millis();
	read();
	u_max = u_min = U;
	i_max = i_min = I;
	w_max = w_min = U * I;
	u_avg_t = U;
	i_avg_t = I;
	w_avg_t = W;
	Wh = 0;
	mAh = 0;
	avg_count = 0;
}

void Sensor_Data::read()
{
	U = ina.getBusVoltage();							// 总线电压V
	float i = ina.getCurrent_mA() / 1000; // 总线电流A

	I = abs(i);
}

void Sensor_Data::calc()
{
	W = U * I;
	// voltage
	if (U > u_max)
	{
		u_max = U;
	}
	if (U < u_min)
	{
		u_min = U;
	}

	// current
	if (I > i_max)
	{
		i_max = I;
	}
	if (I < i_min)
	{
		i_min = I;
	}

	// watt
	if (W > w_max)
	{
		w_max = W;
	}
	if (W < w_min)
	{
		w_min = W;
	}

	// avg
	avg_count++;
	if ((avg_count % 100) == 0)
	{
		u_avg = u_avg_t / 100;
		i_avg = i_avg_t / 100;
		w_avg = w_avg_t / 100;
		avg_count = 0;
		u_avg_t = U;
		i_avg_t = I;
		w_avg_t = W;
	}
	else
	{
		u_avg_t += U;
		i_avg_t += I;
		w_avg_t += W;
	}

	Wh=Wh+(W/3600000)*(millis()-ms);
  mAh=mAh+(I/3600)*(millis()-ms);
	ms = millis();
}
Sensor_Data sensor;