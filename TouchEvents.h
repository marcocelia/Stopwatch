/*
 * TouchEvents.h
 *
 *  Created on: 26/gen/2015
 *      Author: Marco Emanuele Celia
 */

#ifndef TOUCHEVENTS_H_
#define TOUCHEVENTS_H_

#include "stopwatch.h"

typedef enum TouchEvt{
			EVT_NOEVT,
			EVT_CH_TIME,
			EVT_CH_ALARM,
			EVT_CH_CHRONO,
			EVT_CH_SETTING,
			EVT_SWITCH,
			EVT_ALARM_ON,
			EVT_ALARM_OFF,
			EVT_PLUS,
			EVT_MINUS,
			EVT_START,
			EVT_STOP,
			EVT_RESET,
			EVT_CONFIRM
} TouchEvt;

TouchEvt getEvt(mode_t mode);
void decodeEvt(TouchEvt ev, unsigned char buttons[]);

#endif /* TOUCHEVENTS_H_ */
