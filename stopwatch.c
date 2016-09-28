#include "stopwatch.h"

mode_t mode;
submode_t submode;

uint8_t alarm_on = 0;
uint8_t notify_alarm = 0;

uint8_t d_hours = 0;
uint8_t d_minutes = 0;
uint8_t d_seconds = 0;
uint8_t d_tenths = 0;

uint8_t t_hours = 0;
uint8_t t_minutes = 0;
uint8_t t_seconds = 0;
uint8_t t_tenths = 0;

uint8_t a_hours = 0;
uint8_t a_minutes = 0;


void stopwatch_init(unsigned char buttons[], mode_t* new_mode,
											 submode_t* new_submode,
											 uint8_t* hour,
											 uint8_t* minute,
											 uint8_t* second,
											 uint8_t* tenth,
											 uint8_t* al_on,
		 	 	 	 	 	 	 	 	 	 uint8_t* not_al)
{
	int i;

	for (i = 0; i < 9; i++)
		buttons[i] = 0;
	mode = TIME;
	submode = NO_SUB;
	*new_mode = mode;
	*new_submode = submode;
	*hour = d_hours;
	*minute = d_minutes;
	*second = d_seconds;
	*tenth = d_tenths;
	*al_on = alarm_on;
	*not_al = notify_alarm;
}

void time_count(){
	t_tenths = (t_tenths + 1)%10;
	if (0 == t_tenths){
		t_seconds = (t_seconds + 1)%60;
		if (0 == t_seconds){
			t_minutes = (t_minutes + 1)%60;
			if (0 == t_minutes)
				t_hours = (t_hours + 1)%24;
		}
	}
}

void chrono_count(){
	d_tenths = (d_tenths + 1)%10;
	if (0 == d_tenths){
		d_seconds = (d_seconds + 1)%60;
		if (0 == d_seconds){
			d_minutes = (d_minutes + 1)%60;
			if (0 == d_minutes)
				d_hours = (d_hours + 1)%24;
		}
	}
}

void enter_time(){
	if (notify_alarm){
		notify_alarm = 0;
		alarm_on = 0;
	}
}

void enter_chrono(){
	if (notify_alarm){
		notify_alarm = 0;
		alarm_on = 0;
	}
	d_hours = 0;
	d_minutes = 0;
	d_seconds = 0;
	d_tenths = 0;
}

void enter_alarm(){
	if (notify_alarm){
		notify_alarm = 0;
		alarm_on = 0;
	}
	d_hours = a_hours;
	d_minutes = a_minutes;
}

void enter_setting(){
	if (notify_alarm){
		notify_alarm = 0;
		alarm_on = 0;
	}
	d_hours = t_hours;
	d_minutes = t_minutes;
}

void while_time(unsigned char i){
	switch (i){
		case 1:								/* alarm button */
			mode = ALARM;
			submode = HOURS;
			enter_alarm();
			break;
		case 2:								/* chrono button */
			mode = CHRONOMETER;
			submode = CHRONO_STOP;
			enter_chrono();
			break;
		case 3:								/* setting button */
			mode = SETTING;
			submode = HOURS;
			enter_setting();
			break;
	}
}

void while_alarm(unsigned char i){
	switch (i){
		case 0:										/* clock button */
			mode = TIME;
			submode = NO_SUB;
			enter_time();
			break;
		case 2:										/* chrono button */
			mode = CHRONOMETER;
			submode = CHRONO_STOP;
			enter_chrono();
			break;
		case 3:										/* setting button */
			mode = SETTING;
			submode = HOURS;
			enter_setting();
			break;
		case 6:										/* switch button */
			switch (submode){
			case HOURS:
				submode = MINUTES;
				break;
			case MINUTES:
				submode = HOURS;
				break;
			}
			break;
		case 7:										/* on button */
			alarm_on = 1;
			a_hours = d_hours;
			a_minutes = d_minutes;
			break;
		case 8:										/* off button */
			alarm_on = 0;
			a_hours = 0;
			a_minutes = 0;
			break;
		case 4:										/* plus button */
			switch (submode){
			case HOURS:
				d_hours = (d_hours+1)%24;
				break;
			case MINUTES:
				d_minutes = (d_minutes + 1)%60;
				break;
			}
			break;
		case 5:										/* minus button */
			switch (submode){
			case HOURS:
				if (d_hours == 0) d_hours = 23;
				else d_hours--;
				break;
			case MINUTES:
				if (d_minutes == 0) d_minutes = 59;
				else d_minutes--;
				break;
			}
			break;
	}
}

void while_chrono(unsigned char i){

	switch (i){
		case 0:										/* clock button */
			mode = TIME;
			submode = NO_SUB;
			enter_time();
			break;
		case 1:										/* alarm button */
			mode = ALARM;
			submode = HOURS;
			enter_alarm();
			break;
		case 3:										/* setting button */
			mode = SETTING;
			submode = HOURS;
			enter_setting();
			break;
		case 4:										/* stop button */
			submode = CHRONO_STOP;
			break;
		case 5:										/* start button */
			submode = CHRONO_START;
			break;
		case 6:										/* reset button */
			submode = CHRONO_STOP;
			d_tenths = 0;
			d_seconds = 0;
			d_minutes = 0;
			d_hours = 0;
		break;
	}
}

void while_setting(unsigned char i){

	switch (i){
		case 0:										/* clock button */
			mode = TIME;
			submode = NO_SUB;
			enter_time();
			break;
		case 1:										/* alarm button */
			mode = ALARM;
			submode = HOURS;
			enter_alarm();
			break;
		case 2:										/* chrono button */
			mode = CHRONOMETER;
			submode = CHRONO_STOP;
			enter_chrono();
			break;
		case 6:										/* right button */
			switch (submode){
			case HOURS:
				submode = MINUTES;
				break;
			case MINUTES:
				submode = HOURS;
				break;
			}
			break;
		case 4:										/* plus button */
			switch(submode){
			case HOURS:
				d_hours = (d_hours+1)%24;
				break;
			case MINUTES:
				d_minutes = (d_minutes + 1)%60;
				break;
			}
			break;
		case 5:										/* minus button */
			switch (submode){
			case HOURS:
				if (d_hours == 0) d_hours = 23;
				else d_hours--;
				break;
			case MINUTES:
				if (d_minutes == 0) d_minutes = 59;
				else d_minutes--;
				break;
			}
			break;
		case 7:										/* confirm button */
			t_hours = d_hours;
			t_minutes = d_minutes;
			break;
	}
}

void dispatch(unsigned char i){
	switch(mode){
	case TIME:
		while_time(i);
		break;
	case ALARM:
		while_alarm(i);
		break;
	case CHRONOMETER:
		while_chrono(i);
		break;
	case SETTING:
		while_setting(i);
		break;
	}
}

unsigned char check_alarm(){
	return (alarm_on && t_hours == a_hours && t_minutes == a_minutes);
}

void stopwatch_step(unsigned char buttons[], mode_t* new_mode,
		 	 	 	 	 	 	 	 	 	 submode_t* new_submode,
		 	 	 	 	 	 	 	 	 	 uint8_t* hour,
		 	 	 	 	 	 	 	 	 	 uint8_t* minute,
		 	 	 	 	 	 	 	 	 	 uint8_t* second,
		 	 	 	 	 	 	 	 	 	 uint8_t* tenth,
		 	 	 	 	 	 	 	 	 	 uint8_t* al_on,
		 	 	 	 	 	 	 	 	 	 uint8_t* not_al)
{
	unsigned char i = 0;

	time_count();
	notify_alarm = check_alarm();
	if (mode == CHRONOMETER && submode == CHRONO_START) chrono_count();
	while (buttons[i] == 0)i++;
	if (i < 9) dispatch(i);
	*new_mode = mode;
	*new_submode = submode;
	if (mode == TIME){
			d_hours = t_hours;
			d_minutes = t_minutes;
			d_seconds = t_seconds;
	}
	*hour = d_hours;
	*minute = d_minutes;
	*second = d_seconds;
	*tenth = d_tenths;
	*al_on = alarm_on;
	*not_al = notify_alarm;
}
