/*
 * ScreenManager.c
 *
 *  Created on: 26/gen/2015
 *      Author: Marco Emanuele Celia
 */

#include "ScreenManager.h"

extern mode_t mode;
extern submode_t submode;
extern uint8_t hours;
extern uint8_t minutes;
extern uint8_t seconds;
extern uint8_t tenths;
extern uint8_t alarm_on;
mode_t old_mode = TIME;
submode_t old_submode = NO_SUB;


uint8_t* decode(unsigned char number){
	switch(number){
		case 0:
			return (uint8_t*)zero;
		case 1:
			return (uint8_t*)one;
		case 2:
			return (uint8_t*)two;
		case 3:
			return (uint8_t*)three;
		case 4:
			return (uint8_t*)four;
		case 5:
			return (uint8_t*)five;
		case 6:
			return (uint8_t*)six;
		case 7:
			return (uint8_t*)seven;
		case 8:
			return (uint8_t*)eight;
		case 9:
			return (uint8_t*)nine;
	}
}
void print_message(uint8_t* mess){
	LCD_SetFont(&Font8x12);
	LCD_SetBackColor(ScreenColor);
	LCD_SetTextColor(Black);
	LCD_ClearLineRegion(LINE(8), 2, 26);
	LCD_DisplayStringLine(LINE(8), mess, 2);
	LCD_SetFont(&Font12x12);
}
void draw_cursor(submode_t submode){
	LCD_SetBackColor(ScreenColor);
	LCD_SetTextColor(ScreenColor);
	LCD_DrawFullRect(50, 73, 180, 5);
	LCD_SetBackColor(Black);
	LCD_SetTextColor(Black);
	switch (submode){
		case HOURS:
			LCD_DrawFullRect(50, 73, 60, 5);
			break;
		case MINUTES:
			LCD_DrawFullRect(120, 73, 60, 5);
			break;
	}
	LCD_SetBackColor(ScreenColor);
}
void draw_alarm_onoff(uint8_t alarmon){
	switch(alarmon){
	case 1:
		LCD_DrawPicture(255, 10, 50, 50, (uint8_t*)ImageAlarmOff);
		print_message("Alarm on");
		break;
	case 0:
		LCD_DrawPicture(255, 10, 50, 50, (uint8_t*)ImageAlarmOn);
		print_message("Alarm off");
		break;
	}
}
void draw_chrono_startstop(submode_t submode){
	switch (submode){
	case CHRONO_START:
		LCD_DrawPicture(250, 10, 60, 60, (uint8_t*)ImageChronoStop);
		break;
	case CHRONO_STOP:
		LCD_DrawPicture(250, 10, 60, 60, (uint8_t*)ImageChronoStart);
		break;
	}
}
void draw_plus_minus_switch(mode_t mode){
	unsigned short plus_y_pos, minus_y_pos;
	switch (mode){
		case ALARM:
			plus_y_pos = 65;
			minus_y_pos = 115;
			break;
		case SETTING:
			plus_y_pos = 10;
			minus_y_pos = 60;
			break;
	}
	LCD_DrawPicture(260, plus_y_pos, 40, 40, (uint8_t*)ImageAlarmPlus);
	LCD_DrawPicture(260, minus_y_pos, 40, 40, (uint8_t*)ImageAlarmMinus);
	LCD_DrawPicture(125, 125, 30, 30, (uint8_t*)ImageRight);
	LCD_DrawPicture(65, 125, 30, 30, (uint8_t*)ImageLeft);
}
void display_timeHM(){
	uint8_t first_digit, second_digit;

	LCD_SetFont(&Font16x24);
	LCD_DisplayStringLine(LINE(2), ":", 7);
	LCD_SetFont(&Font12x12);
	first_digit = hours/10;
	second_digit = hours - first_digit*10;
	LCD_DrawPicture(50, 40, 30, 30, decode(first_digit));
	LCD_DrawPicture(80, 40, 30, 30, decode(second_digit));
	first_digit = minutes/10;
	second_digit = minutes - first_digit*10;
	LCD_DrawPicture(120, 40, 30, 30, decode(first_digit));
	LCD_DrawPicture(150, 40, 30, 30, decode(second_digit));
}
void display_timeHMS(){
	uint8_t first_digit, second_digit;

	LCD_SetFont(&Font16x24);
	LCD_DisplayStringLine(LINE(2), ":", 5);
	LCD_DisplayStringLine(LINE(2), ":", 9);
	LCD_SetFont(&Font12x12);
	first_digit = hours/10;
	second_digit = hours - first_digit*10;
	LCD_DrawPicture(20, 40, 30, 30, decode(first_digit));
	LCD_DrawPicture(50, 40, 30, 30, decode(second_digit));
	first_digit = minutes/10;
	second_digit = minutes - first_digit*10;
	LCD_DrawPicture(90, 40, 30, 30, decode(first_digit));
	LCD_DrawPicture(120, 40, 30, 30, decode(second_digit));
	first_digit = seconds/10;
	second_digit = seconds - first_digit*10;
	LCD_DrawPicture(160, 40, 30, 30, decode(first_digit));
	LCD_DrawPicture(190, 40, 30, 30, decode(second_digit));
}
void display_timeHMST(){
	uint8_t first_digit, second_digit;

	LCD_SetFont(&Font16x24);
	LCD_DisplayStringLine(LINE(2), ":", 5);
	LCD_DisplayStringLine(LINE(2), ":", 9);
	LCD_SetFont(&Font12x12);
	first_digit = hours/10;
	second_digit = hours - first_digit*10;
	LCD_DrawPicture(20, 40, 30, 30, decode(first_digit));
	LCD_DrawPicture(50, 40, 30, 30, decode(second_digit));
	first_digit = minutes/10;
	second_digit = minutes - first_digit*10;
	LCD_DrawPicture(90, 40, 30, 30, decode(first_digit));
	LCD_DrawPicture(120, 40, 30, 30, decode(second_digit));
	first_digit = seconds/10;
	second_digit = seconds - first_digit*10;
	LCD_DrawPicture(160, 40, 30, 30, decode(first_digit));
	LCD_DrawPicture(190, 40, 30, 30, decode(second_digit));
	LCD_DrawPicture(160, 80, 30, 30, (uint8_t*)zero);
	LCD_DrawPicture(190, 80, 30, 30, decode(tenths));
}
void clear_screen(){
	LCD_SetBackColor(ScreenColor);
	LCD_SetTextColor(ScreenColor);
	LCD_DrawFullRect(0, 0, 240, 115);
	LCD_SetTextColor(Black);
}
void clear_right(){
	LCD_SetTextColor(Gray);
	LCD_SetBackColor(Gray);
	LCD_DrawFullRect(240, 0, 80, 160);
}
void clearScreenMode(mode_t mode){
	switch (mode){
	case TIME:
		LCD_DrawPicture(15, 180, 50, 50, (uint8_t*)ImageClockReleased);
		break;
	case ALARM:
		LCD_DrawPicture(95, 173, 50, 57, (uint8_t*)ImageAlarmReleased);
		break;
	case CHRONOMETER:
		LCD_DrawPicture(175, 170, 50, 60, (uint8_t*)ImageChronoReleased);
		break;
	case SETTING:
		LCD_DrawPicture(255, 180, 50, 50, (uint8_t*)ImageSettingReleased);
		break;
	}
	clear_screen();
	clear_right();
	LCD_SetBackColor(Black);
	LCD_SetTextColor(Black);
	LCD_DrawFullRect(0, 120, 200, 35);
	LCD_SetBackColor(ScreenColor);
}
void initScreenMode(mode_t mode){
	switch(mode){
	case TIME:
		LCD_DrawPicture(15, 180, 50, 50,(uint8_t*)ImageClockPressed);
		LCD_SetFont(&Font12x12);
		LCD_DisplayStringLine(LINE(1), "Time: ", 1);
		display_timeHMS();
		break;
	case  ALARM:
		LCD_DisplayStringLine(LINE(1), "Alarm: ", 1);
		LCD_DrawPicture(95, 173, 50, 57,(uint8_t*)ImageAlarmPressed);
		draw_alarm_onoff(alarm_on);
		draw_plus_minus_switch(ALARM);
		display_timeHM();
		draw_cursor(submode);
		break;
	case CHRONOMETER:
		LCD_DisplayStringLine(LINE(1), "Stopwatch: ", 1);
		LCD_DrawPicture(175, 170, 50, 60,(uint8_t*)ImageChronoPressed);
		draw_chrono_startstop(submode);
		LCD_DrawPicture(250, 90, 60, 60, (uint8_t*)ImageChronoReset);
		display_timeHMST();
		break;
	case SETTING:
		LCD_DisplayStringLine(LINE(1), "Setting: ", 1);
		LCD_DrawPicture(255, 180, 50, 50,(uint8_t*)ImageSettingPressed);
		LCD_DrawPicture(260, 110, 40, 40, (uint8_t*)ImageSettingConfirm);
		draw_plus_minus_switch(SETTING);
		display_timeHM();
		draw_cursor(submode);
		break;
	}
}
void reset_interface(){
	LCD_DrawPicture(95, 173, 50, 57,(uint8_t*)ImageAlarmReleased);
	LCD_DrawPicture(175, 170, 50, 60, (uint8_t*)ImageChronoReleased);
	LCD_DrawPicture(255, 180, 50, 50, (uint8_t*)ImageSettingReleased);
	LCD_SetBackColor(Gray);
	LCD_SetTextColor(Gray);
	LCD_DrawFullRect(240, 0, 80, 160);
	LCD_DrawLine(0, 160, 320, LCD_DIR_HORIZONTAL);
	LCD_SetBackColor(ScreenColor);
	LCD_SetTextColor(ScreenColor);
	LCD_DrawFullRect(0, 0, 240, 115);
	LCD_SetTextColor(Black);
	initScreenMode(TIME);
}
void drawScreen(){
	if (old_mode != mode){
		clearScreenMode(old_mode);
		initScreenMode(mode);
	} else {
		switch (mode){
		case TIME:
			display_timeHMS();
			break;
		case ALARM:
			display_timeHM();
			if (old_submode != submode) draw_cursor(submode);
			draw_alarm_onoff(alarm_on);
			break;
		case CHRONOMETER:
			display_timeHMST();
			if (old_submode != submode) draw_chrono_startstop(submode);
			break;
		case SETTING:
			display_timeHM();
			if (old_submode != submode) draw_cursor(submode);
			break;
		}
	}
	old_mode = mode;
	old_submode = submode;
}
