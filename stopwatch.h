#ifndef STOPWATCH_H_
#define STOPWATCH_H_

typedef unsigned char uint8_t;

typedef enum mode_t {
					TIME,
					SETTING,
					ALARM,
					CHRONOMETER
} mode_t;

typedef enum submode_t {
					HOURS,
					MINUTES,
					NO_SUB,
					CHRONO_STOP,
					CHRONO_START
} submode_t;

void stopwatch_init(unsigned char buttons[], mode_t* new_mode, submode_t* new_submode, uint8_t* hour, uint8_t* minute, uint8_t* second, uint8_t* tenth, uint8_t* al_on, uint8_t* notify_alarm);
void stopwatch_step(unsigned char buttons[], mode_t* new_mode, submode_t* new_submode, uint8_t* hour, uint8_t* minute, uint8_t* second, uint8_t* tenth, uint8_t* al_on, uint8_t* notify_alarm);

#endif /* STOPWATCH_H */
