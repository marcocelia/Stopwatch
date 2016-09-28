/*
 * TouchEvents.c
 *
 *  Created on: 26/gen/2015
 *      Author: Marco Emanuele Celia
 */

#include "TouchEvents.h"

TouchEvt getEvt(mode_t mode)
{
	unsigned int x, y;
	static unsigned char start_stop = 0;
	static unsigned char alarm_on_off = 0;
	TouchEvt ev = EVT_NOEVT;

	if (GetTouch_SC_async (&x, &y)){
		switch (mode){
		case TIME:
			if ((x >= 15 && x <= 65) && (y >= 180 && y <= 230)) return EVT_CH_TIME;
			if ((x >= 95 && x <= 145) && (y >= 173 && y <= 230)) return EVT_CH_ALARM;
			if ((x >= 175 && x <= 225) && (y >= 170 && y <= 230)) return EVT_CH_CHRONO;
			if ((x >= 255 && x <= 305) && (y >= 180 && y <= 230)) return EVT_CH_SETTING;
			break;
		case ALARM:
			if ((x >= 15 && x <= 65) && (y >= 180 && y <= 230)) return EVT_CH_TIME;
			if ((x >= 95 && x <= 145) && (y >= 173 && y <= 230)) return EVT_CH_ALARM;
			if ((x >= 175 && x <= 225) && (y >= 170 && y <= 230)) return EVT_CH_CHRONO;
			if ((x >= 255 && x <= 305) && (y >= 180 && y <= 230)) return EVT_CH_SETTING;
			if ((x >= 125 && x <= 175) && (y >= 125 && y <= 155)) return EVT_SWITCH;
			if ((x >= 65 && x <= 115) && (y >= 125 && y <= 155)) return EVT_SWITCH;
			if ((x >= 255 && x <= 305) && (y >= 10 && y <= 60)){
				alarm_on_off = (alarm_on_off + 1)%2;
				if (alarm_on_off)
					return EVT_ALARM_ON;
				else
					return EVT_ALARM_OFF;
			}
			if ((x >= 260 && x <= 300) && (y >= 65) && (y <= 105)) return EVT_PLUS;
			if ((x >= 260 && x <= 300) && (y >= 115) && (y <= 155)) return EVT_MINUS;
			break;
		case CHRONOMETER:
			if ((x >= 15 && x <= 65) && (y >= 180 && y <= 230)) return EVT_CH_TIME;
			if ((x >= 95 && x <= 145) && (y >= 173 && y <= 230)) return EVT_CH_ALARM;
			if ((x >= 175 && x <= 225) && (y >= 170 && y <= 230)) return EVT_CH_CHRONO;
			if ((x >= 255 && x <= 305) && (y >= 180 && y <= 230)) return EVT_CH_SETTING;
			if ((x >= 250 && x <= 310) && (y >= 10 && y <= 70)) {
				start_stop = (start_stop + 1)%2;
				if (start_stop)
					return EVT_START;
				else
					return EVT_STOP;
			}
			if ((x >= 250 && x <= 310) && (y >= 90 && y <= 150)) return EVT_RESET;
			break;
		case SETTING:
			if ((x >= 15 && x <= 65) && (y >= 180 && y <= 230)) return EVT_CH_TIME;
			if ((x >= 95 && x <= 145) && (y >= 173 && y <= 230)) return EVT_CH_ALARM;
			if ((x >= 175 && x <= 225) && (y >= 170 && y <= 230)) return EVT_CH_CHRONO;
			if ((x >= 255 && x <= 305) && (y >= 180 && y <= 230)) return EVT_CH_SETTING;
			if ((x >= 125 && x <= 175) && (y >= 125 && y <= 155)) return EVT_SWITCH;
			if ((x >= 65 && x <= 115) && (y >= 125 && y <= 155)) return EVT_SWITCH;
			if ((x >= 250 && x <= 300) && (y >= 5 && y <= 45)) return EVT_PLUS;
			if ((x >= 250 && x <= 300) && (y >= 50 && y <= 100)) return EVT_MINUS;
			if ((x >= 250 && x <= 300) && (y >= 110 && y <= 150)) return EVT_CONFIRM;
			break;
		}

	}
	return ev;
}

void decodeEvt(TouchEvt ev, unsigned char buttons[]){
	int i;
	for (i=0; i < 9; i++)
		buttons[i] = 0;

	switch (ev){
		case EVT_CH_TIME:
			buttons[0] = 1;
		break;
		case EVT_CH_ALARM:
			buttons[1] = 1;
		break;
		case EVT_CH_CHRONO:
			buttons[2] = 1;
		break;
		case EVT_CH_SETTING:
			buttons[3] = 1;
		break;
		case EVT_SWITCH:
			buttons[6] = 1;
		break;
		case EVT_ALARM_ON:
			buttons[7] = 1;
		break;
		case EVT_ALARM_OFF:
			buttons[8] = 1;
		break;
		case EVT_PLUS:
			buttons[4] = 1;
		break;
		case EVT_MINUS:
			buttons[5] = 1;
		break;
		case EVT_START:
			buttons[4] = 1;
		break;
		case EVT_STOP:
			buttons[5] = 1;
		break;
		case EVT_RESET:
			buttons[6] = 1;
		break;
		case EVT_CONFIRM:
			buttons[7] = 1;
		break;
	}
}
