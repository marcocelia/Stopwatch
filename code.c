/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2013  Evidence Srl
 *
 * This file is part of ERIKA Enterprise.
 *
 * ERIKA Enterprise is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation,
 * (with a special exception described below).
 *
 * Linking this code statically or dynamically with other modules is
 * making a combined work based on this code.  Thus, the terms and
 * conditions of the GNU General Public License cover the whole
 * combination.
 *
 * As a special exception, the copyright holders of this library give you
 * permission to link this code with independent modules to produce an
 * executable, regardless of the license terms of these independent
 * modules, and to copy and distribute the resulting executable under
 * terms of your choice, provided that you also meet, for each linked
 * independent module, the terms and conditions of the license of that
 * module.  An independent module is a module which is not derived from
 * or based on this library.  If you modify this code, you may extend
 * this exception to your version of the code, but you are not
 * obligated to do so.  If you do not wish to do so, delete this
 * exception statement from your version.
 *
 * ERIKA Enterprise is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License version 2 for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with ERIKA Enterprise; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 * ###*E*### */
#include "ee.h"
#include "ee_irq.h"
#include "stm32f4xx_conf.h"
#include "stm32f4_discovery.h"
#include "stm32f4_discovery_lcd.h"
#include "LCD_Touch_Calibration.h"
#include "STMPE811QTR.h"

#include "ScreenManager.h"
#include "TouchEvents.h"

/***************** Stopwatch hand_coded version: **************/
#include "stopwatch.h"
/**************************************************************/
/*********** Stopwatch generated from simulink version: *******/
//#include "SubStopwatch.h"

//RT_MODEL_SubStopWatch_T * RT_Model;
/**************************************************************/

unsigned char buttons[9];
mode_t mode;
submode_t submode;
uint8_t hours;
uint8_t minutes;
uint8_t seconds;
uint8_t tenths;
uint8_t alarm_on;
uint8_t notify_alarm;

ISR2(systick_handler)
{
	CounterTick(myCounter);
}

void screen_blink_stop(){
	STM_EVAL_LEDOn(LED3);
}

void screen_blink(){
	STM_EVAL_LEDToggle(LED3);
}

TASK(Task1)
{
	TouchEvt t_evt = getEvt(mode);
	decodeEvt(t_evt, buttons);

	/***************** Stopwatch hand_coded version: **************/
	stopwatch_step(buttons, &mode, &submode, &hours, &minutes, &seconds, &tenths, &alarm_on, &notify_alarm);
	/**************************************************************/
	/*********** Stopwatch generated from simulink version: *******/
	//SubStopWatch_step(RT_Model, buttons[0], buttons[1], buttons[2], buttons[3], buttons[4], buttons[5], buttons[6], buttons[7], buttons[8], &submode, &alarm_on, &notify_alarm, &hours, &minutes, &seconds, &tenths, &mode);
	/**************************************************************/

	drawScreen();
	if (notify_alarm) screen_blink();
	else screen_blink_stop();
}

int main(void)
{

	SystemInit();
  /*Initializes Erika related stuffs*/
	EE_system_init();

	STM_EVAL_LEDInit(LED3);
	STM_EVAL_LEDOn(LED3);

	/*Initialize systick */
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, SystemCoreClock));
	EE_systick_enable_int();
	EE_systick_start();

	IOE_Config();

	/* Initialize the LCD */
	STM32f4_Discovery_LCD_Init();

	/* Clear the LCD */
	LCD_Clear(Black);

	/* Set the LCD Text size */
	LCD_SetFont(&Font12x12);

	Lcd_Touch_Auto_Calibration();

	SetRelAlarm(AlarmTask1, 10, 100);

	/*********** Stopwatch generated from simulink version: *******/
	//RT_Model = SubStopWatch(buttons[0], buttons[1], buttons[2], buttons[3], buttons[4], buttons[5], buttons[6], buttons[7], buttons[8], &submode, &alarm_on, &notify_alarm, &hours, &minutes, &seconds, &tenths, &mode);
	//SubStopWatch_initialize(RT_Model, buttons[0], buttons[1], buttons[2], buttons[3], buttons[4], buttons[5], buttons[6], buttons[7], buttons[8], &submode, &alarm_on, &notify_alarm, &hours, &minutes, &seconds, &tenths, &mode);
	/**************************************************************/
	/***************** Stopwatch hand_coded version: **************/
	stopwatch_init(buttons, &mode, &submode, &hours, &minutes, &seconds, &tenths, &alarm_on, &notify_alarm);
	/**************************************************************/
	reset_interface();

	for (;;) { 
	}

}


