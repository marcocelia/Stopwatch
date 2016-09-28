/*
 * File: SubStopWatch.c
 *
 * Code generated for Simulink model 'SubStopWatch'.
 *
 * Model version                  : 1.172
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Wed Feb 04 17:05:56 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SubStopWatch.h"
#include "SubStopWatch_private.h"

/* Named constants for Chart: '<S1>/Stopwatch ' */
#define SubS_event_submode_switch_reset (7)
#define SubSto_event_submode_minus_stop (6)
#define SubSto_event_submode_plus_start (5)
#define SubStopWatch_IN_Alarm          ((uint8_T)1U)
#define SubStopWatch_IN_Chrono         ((uint8_T)2U)
#define SubStopWatch_IN_Hours          ((uint8_T)1U)
#define SubStopWatch_IN_Minutes        ((uint8_T)2U)
#define SubStopWatch_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define SubStopWatch_IN_Setting        ((uint8_T)3U)
#define SubStopWatch_IN_Time           ((uint8_T)4U)
#define SubStopWatch_IN_check          ((uint8_T)1U)
#define SubStopWatch_IN_count          ((uint8_T)1U)
#define SubStopWatch_IN_notify         ((uint8_T)2U)
#define SubStopWatch_IN_stop           ((uint8_T)2U)
#define SubStopWatch_event_mode_alarm  (2)
#define SubStopWatch_event_mode_setting (4)
#define SubStopWatch_event_mode_swatch (3)
#define SubStopWatch_event_mode_time   (1)
#define SubStopWatch_event_tick        (0)
#define SubStop_event_submode_alarm_off (9)
#define SubStop_event_submode_alon_conf (8)

/* Forward declaration for local functions */
static void SubStopWatch_WorkingMode(uint8_T *SubStopWatch_Y_submode, boolean_T *
  SubStopWatch_Y_alarm_on, uint8_T *SubStopWatch_Y_hours, uint8_T
  *SubStopWatch_Y_minutes, uint8_T *SubStopWatch_Y_seconds, uint8_T
  *SubStopWatch_Y_tenths, uint8_T *SubStopWatch_Y_mode, DW_SubStopWatch_T
  *SubStopWatch_DW);
static void SubSt_chartstep_c3_SubStopWatch(uint8_T *SubStopWatch_Y_submode,
  boolean_T *SubStopWatch_Y_alarm_on, boolean_T *SubStopWatch_Y_notify_alarm,
  uint8_T *SubStopWatch_Y_hours, uint8_T *SubStopWatch_Y_minutes, uint8_T
  *SubStopWatch_Y_seconds, uint8_T *SubStopWatch_Y_tenths, uint8_T
  *SubStopWatch_Y_mode, DW_SubStopWatch_T *SubStopWatch_DW);

/* Function for Chart: '<S1>/Stopwatch ' */
static void SubStopWatch_WorkingMode(uint8_T *SubStopWatch_Y_submode, boolean_T *
  SubStopWatch_Y_alarm_on, uint8_T *SubStopWatch_Y_hours, uint8_T
  *SubStopWatch_Y_minutes, uint8_T *SubStopWatch_Y_seconds, uint8_T
  *SubStopWatch_Y_tenths, uint8_T *SubStopWatch_Y_mode, DW_SubStopWatch_T
  *SubStopWatch_DW)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int32_T tmp;
  uint32_T qY;

  /* During 'WorkingMode': '<S3>:17' */
  if (SubStopWatch_DW->sfEvent == SubStopWatch_event_mode_time) {
    /* Transition: '<S3>:27' */
    /* Exit Internal 'WorkingMode': '<S3>:17' */
    /* Exit Internal 'Alarm': '<S3>:184' */
    SubStopWatch_DW->is_Alarm = SubStopWatch_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'Chrono': '<S3>:21' */
    SubStopWatch_DW->is_Chrono = SubStopWatch_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'Setting': '<S3>:22' */
    SubStopWatch_DW->is_Setting = SubStopWatch_IN_NO_ACTIVE_CHILD;
    SubStopWatch_DW->is_WorkingMode = SubStopWatch_IN_Time;

    /* Entry 'Time': '<S3>:19' */
    *SubStopWatch_Y_mode = 0U;
  } else if (SubStopWatch_DW->sfEvent == SubStopWatch_event_mode_setting) {
    /* Transition: '<S3>:29' */
    /* Exit Internal 'WorkingMode': '<S3>:17' */
    /* Exit Internal 'Alarm': '<S3>:184' */
    SubStopWatch_DW->is_Alarm = SubStopWatch_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'Chrono': '<S3>:21' */
    SubStopWatch_DW->is_Chrono = SubStopWatch_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'Setting': '<S3>:22' */
    SubStopWatch_DW->is_WorkingMode = SubStopWatch_IN_Setting;

    /* Entry 'Setting': '<S3>:22' */
    *SubStopWatch_Y_mode = 1U;
    *SubStopWatch_Y_submode = 0U;

    /* Entry Internal 'Setting': '<S3>:22' */
    /* Transition: '<S3>:61' */
    SubStopWatch_DW->is_Setting = SubStopWatch_IN_Hours;
  } else if (SubStopWatch_DW->sfEvent == SubStopWatch_event_mode_alarm) {
    /* Transition: '<S3>:28' */
    /* Exit Internal 'WorkingMode': '<S3>:17' */
    /* Exit Internal 'Alarm': '<S3>:184' */
    /* Exit Internal 'Chrono': '<S3>:21' */
    SubStopWatch_DW->is_Chrono = SubStopWatch_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'Setting': '<S3>:22' */
    SubStopWatch_DW->is_Setting = SubStopWatch_IN_NO_ACTIVE_CHILD;
    SubStopWatch_DW->is_WorkingMode = SubStopWatch_IN_Alarm;

    /* Entry 'Alarm': '<S3>:184' */
    *SubStopWatch_Y_mode = 2U;
    *SubStopWatch_Y_submode = 0U;
    *SubStopWatch_Y_hours = SubStopWatch_DW->aHours;
    *SubStopWatch_Y_minutes = SubStopWatch_DW->aMinutes;

    /* Entry Internal 'Alarm': '<S3>:184' */
    /* Transition: '<S3>:197' */
    SubStopWatch_DW->is_Alarm = SubStopWatch_IN_Hours;
  } else if (SubStopWatch_DW->sfEvent == SubStopWatch_event_mode_swatch) {
    /* Transition: '<S3>:30' */
    /* Exit Internal 'WorkingMode': '<S3>:17' */
    /* Exit Internal 'Alarm': '<S3>:184' */
    SubStopWatch_DW->is_Alarm = SubStopWatch_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'Chrono': '<S3>:21' */
    /* Exit Internal 'Setting': '<S3>:22' */
    SubStopWatch_DW->is_Setting = SubStopWatch_IN_NO_ACTIVE_CHILD;
    SubStopWatch_DW->is_WorkingMode = SubStopWatch_IN_Chrono;

    /* Entry 'Chrono': '<S3>:21' */
    *SubStopWatch_Y_mode = 3U;
    *SubStopWatch_Y_submode = 3U;
    *SubStopWatch_Y_hours = 0U;
    *SubStopWatch_Y_minutes = 0U;
    *SubStopWatch_Y_seconds = 0U;
    *SubStopWatch_Y_tenths = 0U;

    /* Entry Internal 'Chrono': '<S3>:21' */
    /* Transition: '<S3>:106' */
    SubStopWatch_DW->is_Chrono = SubStopWatch_IN_stop;
  } else {
    switch (SubStopWatch_DW->is_WorkingMode) {
     case SubStopWatch_IN_Alarm:
      /* During 'Alarm': '<S3>:184' */
      if (SubStopWatch_DW->sfEvent == SubStop_event_submode_alon_conf) {
        /* Transition: '<S3>:188' */
        SubStopWatch_DW->aHours = *SubStopWatch_Y_hours;
        SubStopWatch_DW->aMinutes = *SubStopWatch_Y_minutes;
        *SubStopWatch_Y_alarm_on = true;
      } else {
        if (SubStopWatch_DW->sfEvent == SubStop_event_submode_alarm_off) {
          /* Transition: '<S3>:199' */
          *SubStopWatch_Y_alarm_on = false;
          SubStopWatch_DW->aHours = 0U;
          SubStopWatch_DW->aMinutes = 0U;
        }
      }

      if (SubStopWatch_DW->is_Alarm == SubStopWatch_IN_Hours) {
        /* During 'Hours': '<S3>:186' */
        if (SubStopWatch_DW->sfEvent == SubSto_event_submode_plus_start) {
          /* Transition: '<S3>:189' */
          tmp = (int32_T)(*SubStopWatch_Y_hours + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          *SubStopWatch_Y_hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));
          SubStopWatch_DW->is_Alarm = SubStopWatch_IN_Hours;
        } else if (SubStopWatch_DW->sfEvent == SubS_event_submode_switch_reset)
        {
          /* Transition: '<S3>:194' */
          *SubStopWatch_Y_submode = 1U;
          SubStopWatch_DW->is_Alarm = SubStopWatch_IN_Minutes;
        } else if ((SubStopWatch_DW->sfEvent == SubSto_event_submode_minus_stop)
                   && (*SubStopWatch_Y_hours == 0)) {
          /* Transition: '<S3>:190' */
          *SubStopWatch_Y_hours = 23U;
          SubStopWatch_DW->is_Alarm = SubStopWatch_IN_Hours;
        } else {
          if (SubStopWatch_DW->sfEvent == SubSto_event_submode_minus_stop) {
            /* Transition: '<S3>:191' */
            qY = *SubStopWatch_Y_hours - 1U;
            if (qY > *SubStopWatch_Y_hours) {
              qY = 0U;
            }

            *SubStopWatch_Y_hours = (uint8_T)qY;
            SubStopWatch_DW->is_Alarm = SubStopWatch_IN_Hours;
          }
        }
      } else {
        /* During 'Minutes': '<S3>:187' */
        if ((SubStopWatch_DW->sfEvent == SubSto_event_submode_minus_stop) &&
            (*SubStopWatch_Y_minutes == 0)) {
          /* Transition: '<S3>:196' */
          *SubStopWatch_Y_minutes = 59U;
          SubStopWatch_DW->is_Alarm = SubStopWatch_IN_Minutes;
        } else if (SubStopWatch_DW->sfEvent == SubS_event_submode_switch_reset)
        {
          /* Transition: '<S3>:195' */
          *SubStopWatch_Y_submode = 0U;
          SubStopWatch_DW->is_Alarm = SubStopWatch_IN_Hours;
        } else if (SubStopWatch_DW->sfEvent == SubSto_event_submode_plus_start)
        {
          /* Transition: '<S3>:192' */
          tmp = (int32_T)(*SubStopWatch_Y_minutes + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          *SubStopWatch_Y_minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));
          SubStopWatch_DW->is_Alarm = SubStopWatch_IN_Minutes;
        } else {
          if (SubStopWatch_DW->sfEvent == SubSto_event_submode_minus_stop) {
            /* Transition: '<S3>:185' */
            qY = *SubStopWatch_Y_minutes - 1U;
            if (qY > *SubStopWatch_Y_minutes) {
              qY = 0U;
            }

            *SubStopWatch_Y_minutes = (uint8_T)qY;
            SubStopWatch_DW->is_Alarm = SubStopWatch_IN_Minutes;
          }
        }
      }
      break;

     case SubStopWatch_IN_Chrono:
      /* During 'Chrono': '<S3>:21' */
      if (SubStopWatch_DW->is_Chrono == SubStopWatch_IN_count) {
        /* During 'count': '<S3>:107' */
        if (SubStopWatch_DW->sfEvent == SubStopWatch_event_tick) {
          /* Transition: '<S3>:111' */
          tmp = (int32_T)(*SubStopWatch_Y_tenths + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          *SubStopWatch_Y_tenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 10U * 10U));
          if (*SubStopWatch_Y_tenths == 0) {
            /* Transition: '<S3>:112' */
            tmp = (int32_T)(*SubStopWatch_Y_seconds + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            *SubStopWatch_Y_seconds = (uint8_T)((uint32_T)(uint8_T)tmp -
              (uint8_T)((uint8_T)tmp / 60U * 60U));
            if (*SubStopWatch_Y_seconds == 0) {
              /* Transition: '<S3>:113' */
              tmp = (int32_T)(*SubStopWatch_Y_minutes + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              *SubStopWatch_Y_minutes = (uint8_T)((uint32_T)(uint8_T)tmp -
                (uint8_T)((uint8_T)tmp / 60U * 60U));
              if (*SubStopWatch_Y_hours == 0) {
                /* Transition: '<S3>:114' */
                tmp = (int32_T)(*SubStopWatch_Y_hours + 1U);
                if ((uint32_T)tmp > 255U) {
                  tmp = 255;
                }

                *SubStopWatch_Y_hours = (uint8_T)((uint32_T)(uint8_T)tmp -
                  (uint8_T)((uint8_T)tmp / 24U * 24U));
                SubStopWatch_DW->is_Chrono = SubStopWatch_IN_count;
              } else {
                guard2 = true;
              }
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }
      } else {
        /* During 'stop': '<S3>:105' */
        if (SubStopWatch_DW->sfEvent == SubSto_event_submode_plus_start) {
          /* Transition: '<S3>:115' */
          *SubStopWatch_Y_submode = 4U;
          SubStopWatch_DW->is_Chrono = SubStopWatch_IN_count;
        } else {
          if (SubStopWatch_DW->sfEvent == SubS_event_submode_switch_reset) {
            /* Transition: '<S3>:117' */
            /* Transition: '<S3>:119' */
            *SubStopWatch_Y_hours = 0U;
            *SubStopWatch_Y_minutes = 0U;
            *SubStopWatch_Y_tenths = 0U;
            *SubStopWatch_Y_seconds = 0U;
            SubStopWatch_DW->is_Chrono = SubStopWatch_IN_stop;
          }
        }
      }
      break;

     case SubStopWatch_IN_Setting:
      /* During 'Setting': '<S3>:22' */
      if (SubStopWatch_DW->sfEvent == SubStop_event_submode_alon_conf) {
        /* Transition: '<S3>:76' */
        SubStopWatch_DW->tHours = *SubStopWatch_Y_hours;
        SubStopWatch_DW->tMinutes = *SubStopWatch_Y_minutes;
        *SubStopWatch_Y_alarm_on = true;
      }

      if (SubStopWatch_DW->is_Setting == SubStopWatch_IN_Hours) {
        /* During 'Hours': '<S3>:54' */
        if (SubStopWatch_DW->sfEvent == SubSto_event_submode_plus_start) {
          /* Transition: '<S3>:68' */
          tmp = (int32_T)(*SubStopWatch_Y_hours + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          *SubStopWatch_Y_hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));
          SubStopWatch_DW->is_Setting = SubStopWatch_IN_Hours;
        } else if (SubStopWatch_DW->sfEvent == SubS_event_submode_switch_reset)
        {
          /* Transition: '<S3>:62' */
          *SubStopWatch_Y_submode = 1U;
          SubStopWatch_DW->is_Setting = SubStopWatch_IN_Minutes;
        } else if ((SubStopWatch_DW->sfEvent == SubSto_event_submode_minus_stop)
                   && (*SubStopWatch_Y_hours == 0)) {
          /* Transition: '<S3>:69' */
          *SubStopWatch_Y_hours = 23U;
          SubStopWatch_DW->is_Setting = SubStopWatch_IN_Hours;
        } else {
          if (SubStopWatch_DW->sfEvent == SubSto_event_submode_minus_stop) {
            /* Transition: '<S3>:70' */
            qY = *SubStopWatch_Y_hours - 1U;
            if (qY > *SubStopWatch_Y_hours) {
              qY = 0U;
            }

            *SubStopWatch_Y_hours = (uint8_T)qY;
            SubStopWatch_DW->is_Setting = SubStopWatch_IN_Hours;
          }
        }
      } else {
        /* During 'Minutes': '<S3>:55' */
        if ((SubStopWatch_DW->sfEvent == SubSto_event_submode_minus_stop) &&
            (*SubStopWatch_Y_minutes == 0)) {
          /* Transition: '<S3>:71' */
          *SubStopWatch_Y_minutes = 59U;
          SubStopWatch_DW->is_Setting = SubStopWatch_IN_Minutes;
        } else if (SubStopWatch_DW->sfEvent == SubS_event_submode_switch_reset)
        {
          /* Transition: '<S3>:65' */
          *SubStopWatch_Y_submode = 0U;
          SubStopWatch_DW->is_Setting = SubStopWatch_IN_Hours;
        } else if (SubStopWatch_DW->sfEvent == SubSto_event_submode_plus_start)
        {
          /* Transition: '<S3>:66' */
          tmp = (int32_T)(*SubStopWatch_Y_minutes + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          *SubStopWatch_Y_minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));
          SubStopWatch_DW->is_Setting = SubStopWatch_IN_Minutes;
        } else {
          if (SubStopWatch_DW->sfEvent == SubSto_event_submode_minus_stop) {
            /* Transition: '<S3>:72' */
            qY = *SubStopWatch_Y_minutes - 1U;
            if (qY > *SubStopWatch_Y_minutes) {
              qY = 0U;
            }

            *SubStopWatch_Y_minutes = (uint8_T)qY;
            SubStopWatch_DW->is_Setting = SubStopWatch_IN_Minutes;
          }
        }
      }
      break;

     default:
      /* During 'Time': '<S3>:19' */
      if (SubStopWatch_DW->sfEvent == SubStopWatch_event_tick) {
        /* Transition: '<S3>:31' */
        *SubStopWatch_Y_tenths = SubStopWatch_DW->tTenths;
        *SubStopWatch_Y_seconds = SubStopWatch_DW->tSeconds;
        *SubStopWatch_Y_minutes = SubStopWatch_DW->tMinutes;
        *SubStopWatch_Y_hours = SubStopWatch_DW->tHours;
        SubStopWatch_DW->is_WorkingMode = SubStopWatch_IN_Time;

        /* Entry 'Time': '<S3>:19' */
        *SubStopWatch_Y_mode = 0U;
      }
      break;
    }

    if (guard2) {
      if (SubStopWatch_DW->sfEvent == SubS_event_submode_switch_reset) {
        /* Transition: '<S3>:118' */
        *SubStopWatch_Y_submode = 3U;
        if (SubStopWatch_DW->sfEvent == SubS_event_submode_switch_reset) {
          /* Transition: '<S3>:119' */
          *SubStopWatch_Y_hours = 0U;
          *SubStopWatch_Y_minutes = 0U;
          *SubStopWatch_Y_tenths = 0U;
          *SubStopWatch_Y_seconds = 0U;
          SubStopWatch_DW->is_Chrono = SubStopWatch_IN_stop;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }

    if (guard1 && (SubStopWatch_DW->sfEvent == SubSto_event_submode_minus_stop))
    {
      /* Transition: '<S3>:120' */
      *SubStopWatch_Y_submode = 3U;
      SubStopWatch_DW->is_Chrono = SubStopWatch_IN_stop;
    }
  }
}

/* Function for Chart: '<S1>/Stopwatch ' */
static void SubSt_chartstep_c3_SubStopWatch(uint8_T *SubStopWatch_Y_submode,
  boolean_T *SubStopWatch_Y_alarm_on, boolean_T *SubStopWatch_Y_notify_alarm,
  uint8_T *SubStopWatch_Y_hours, uint8_T *SubStopWatch_Y_minutes, uint8_T
  *SubStopWatch_Y_seconds, uint8_T *SubStopWatch_Y_tenths, uint8_T
  *SubStopWatch_Y_mode, DW_SubStopWatch_T *SubStopWatch_DW)
{
  int32_T tmp;

  /* During: SubStopWatch/Stopwatch
   */
  if (SubStopWatch_DW->is_active_c3_SubStopWatch == 0U) {
    /* Entry: SubStopWatch/Stopwatch
     */
    SubStopWatch_DW->is_active_c3_SubStopWatch = 1U;

    /* Entry Internal: SubStopWatch/Stopwatch
     */
    SubStopWatch_DW->is_active_TimeCount = 1U;

    /* Entry 'TimeCount': '<S3>:18' */
    SubStopWatch_DW->tTenths = 0U;
    SubStopWatch_DW->tSeconds = 0U;
    SubStopWatch_DW->tMinutes = 0U;
    SubStopWatch_DW->tHours = 0U;

    /* Entry Internal 'TimeCount': '<S3>:18' */
    /* Transition: '<S3>:37' */
    SubStopWatch_DW->is_TimeCount = SubStopWatch_IN_count;
    SubStopWatch_DW->is_active_AlarmCheck = 1U;

    /* Entry 'AlarmCheck': '<S3>:77' */
    *SubStopWatch_Y_alarm_on = false;
    SubStopWatch_DW->aHours = 0U;
    SubStopWatch_DW->aMinutes = 0U;

    /* Entry Internal 'AlarmCheck': '<S3>:77' */
    /* Transition: '<S3>:85' */
    SubStopWatch_DW->is_AlarmCheck = SubStopWatch_IN_check;
    SubStopWatch_DW->is_active_WorkingMode = 1U;

    /* Entry Internal 'WorkingMode': '<S3>:17' */
    /* Transition: '<S3>:23' */
    SubStopWatch_DW->is_WorkingMode = SubStopWatch_IN_Time;

    /* Entry 'Time': '<S3>:19' */
    *SubStopWatch_Y_mode = 0U;
  } else {
    /* During 'TimeCount': '<S3>:18' */
    /* During 'count': '<S3>:36' */
    if (SubStopWatch_DW->sfEvent == SubStopWatch_event_tick) {
      /* Transition: '<S3>:42' */
      tmp = (int32_T)(SubStopWatch_DW->tTenths + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      SubStopWatch_DW->tTenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
        ((uint8_T)tmp / 10U * 10U));
      if (SubStopWatch_DW->tTenths == 0) {
        /* Transition: '<S3>:43' */
        tmp = (int32_T)(SubStopWatch_DW->tSeconds + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        SubStopWatch_DW->tSeconds = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 60U * 60U));
        if (SubStopWatch_DW->tSeconds == 0) {
          /* Transition: '<S3>:44' */
          tmp = (int32_T)(SubStopWatch_DW->tMinutes + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SubStopWatch_DW->tMinutes = (uint8_T)((uint32_T)(uint8_T)tmp -
            (uint8_T)((uint8_T)tmp / 60U * 60U));
          if (SubStopWatch_DW->tMinutes == 0) {
            /* Transition: '<S3>:45' */
            tmp = (int32_T)(SubStopWatch_DW->tHours + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            SubStopWatch_DW->tHours = (uint8_T)((uint32_T)(uint8_T)tmp -
              (uint8_T)((uint8_T)tmp / 24U * 24U));
            SubStopWatch_DW->is_TimeCount = SubStopWatch_IN_count;
          }
        }
      }
    }

    /* During 'AlarmCheck': '<S3>:77' */
    if (SubStopWatch_DW->is_AlarmCheck == SubStopWatch_IN_check) {
      /* During 'check': '<S3>:79' */
      if ((*SubStopWatch_Y_alarm_on) && ((SubStopWatch_DW->tHours ==
            SubStopWatch_DW->aHours) && (SubStopWatch_DW->tMinutes ==
            SubStopWatch_DW->aMinutes))) {
        /* Transition: '<S3>:128' */
        /* Transition: '<S3>:129' */
        *SubStopWatch_Y_notify_alarm = true;
        SubStopWatch_DW->is_AlarmCheck = SubStopWatch_IN_notify;
      }
    } else {
      /* During 'notify': '<S3>:80' */
      if ((SubStopWatch_DW->sfEvent == SubStopWatch_event_mode_time) ||
          (SubStopWatch_DW->sfEvent == SubStopWatch_event_mode_alarm) ||
          (SubStopWatch_DW->sfEvent == SubStopWatch_event_mode_swatch) ||
          (SubStopWatch_DW->sfEvent == SubStopWatch_event_mode_setting)) {
        /* Transition: '<S3>:82' */
        *SubStopWatch_Y_alarm_on = false;
        *SubStopWatch_Y_notify_alarm = false;
        SubStopWatch_DW->aHours = 0U;
        SubStopWatch_DW->aMinutes = 0U;
        SubStopWatch_DW->is_AlarmCheck = SubStopWatch_IN_check;
      }
    }

    SubStopWatch_WorkingMode(SubStopWatch_Y_submode, SubStopWatch_Y_alarm_on,
      SubStopWatch_Y_hours, SubStopWatch_Y_minutes, SubStopWatch_Y_seconds,
      SubStopWatch_Y_tenths, SubStopWatch_Y_mode, SubStopWatch_DW);
  }
}

/* Model step function */
void SubStopWatch_step(RT_MODEL_SubStopWatch_T *const SubStopWatch_M, boolean_T
  SubStopWatch_U_mode_time, boolean_T SubStopWatch_U_mode_alarm, boolean_T
  SubStopWatch_U_mode_swatch, boolean_T SubStopWatch_U_mode_setting, boolean_T
  SubStopWatch_U_submode_plus_start, boolean_T SubStopWatch_U_submode_minus_stop,
  boolean_T SubStopWatch_U_submode_switch_reset, boolean_T
  SubStopWatch_U_submode_alon_conf, boolean_T SubStopWatch_U_submode_alarm_off,
  uint8_T *SubStopWatch_Y_submode, boolean_T *SubStopWatch_Y_alarm_on, boolean_T
  *SubStopWatch_Y_notify_alarm, uint8_T *SubStopWatch_Y_hours, uint8_T
  *SubStopWatch_Y_minutes, uint8_T *SubStopWatch_Y_seconds, uint8_T
  *SubStopWatch_Y_tenths, uint8_T *SubStopWatch_Y_mode)
{
  P_SubStopWatch_T *SubStopWatch_P = ((P_SubStopWatch_T *)
    SubStopWatch_M->ModelData.defaultParam);
  DW_SubStopWatch_T *SubStopWatch_DW = ((DW_SubStopWatch_T *)
    SubStopWatch_M->ModelData.dwork);
  PrevZCX_SubStopWatch_T *SubStopWatch_PrevZCX = ((PrevZCX_SubStopWatch_T *)
    SubStopWatch_M->ModelData.prevZCSigState);

  /* local block i/o variables */
  uint8_T rtb_FixPtSwitch;
  uint8_T rtb_Output;
  boolean_T rtb_DataTypeConversion;
  boolean_T zcEvent[10];
  boolean_T tmp;
  int32_T i;
  int8_T rtb_inputevents_idx_1;
  int8_T rtb_inputevents_idx_2;
  int8_T rtb_inputevents_idx_3;
  int8_T rtb_inputevents_idx_4;
  int8_T rtb_inputevents_idx_5;
  int8_T rtb_inputevents_idx_6;
  int8_T rtb_inputevents_idx_7;
  int8_T rtb_inputevents_idx_8;
  int8_T rtb_inputevents_idx_9;

  /* UnitDelay: '<S2>/Output' */
  rtb_Output = SubStopWatch_DW->Output_DSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  rtb_DataTypeConversion = (SubStopWatch_DW->Output_DSTATE != 0);

  /* Chart: '<S1>/Stopwatch ' incorporates:
   *  TriggerPort: '<S3>/ input events '
   */
  zcEvent[0] = (((SubStopWatch_DW->Output_DSTATE != 0) !=
                 (SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[0] == POS_ZCSIG)) &&
                (SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[0] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/buttons0' */
  zcEvent[1] = (((SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[1] == POS_ZCSIG) !=
                 SubStopWatch_U_mode_time) &&
                (SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[1] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/buttons1' */
  zcEvent[2] = (((SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[2] == POS_ZCSIG) !=
                 SubStopWatch_U_mode_alarm) &&
                (SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[2] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/buttons2' */
  zcEvent[3] = (((SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[3] == POS_ZCSIG) !=
                 SubStopWatch_U_mode_swatch) &&
                (SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[3] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/buttons3' */
  zcEvent[4] = (((SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[4] == POS_ZCSIG) !=
                 SubStopWatch_U_mode_setting) &&
                (SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[4] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/buttons4' */
  zcEvent[5] = (((SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[5] == POS_ZCSIG) !=
                 SubStopWatch_U_submode_plus_start) &&
                (SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[5] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/buttons5' */
  zcEvent[6] = (((SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[6] == POS_ZCSIG) !=
                 SubStopWatch_U_submode_minus_stop) &&
                (SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[6] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/buttons6' */
  zcEvent[7] = (((SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[7] == POS_ZCSIG) !=
                 SubStopWatch_U_submode_switch_reset) &&
                (SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[7] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/buttons7' */
  zcEvent[8] = (((SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[8] == POS_ZCSIG) !=
                 SubStopWatch_U_submode_alon_conf) &&
                (SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[8] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/buttons8' */
  zcEvent[9] = (((SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[9] == POS_ZCSIG) !=
                 SubStopWatch_U_submode_alarm_off) &&
                (SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[9] !=
                 UNINITIALIZED_ZCSIG));
  tmp = false;
  for (i = 0; i < 10; i++) {
    tmp = (tmp || zcEvent[i]);
  }

  if (tmp) {
    /* Inport: '<Root>/buttons0' */
    rtb_inputevents_idx_1 = (int8_T)(zcEvent[1] ? SubStopWatch_U_mode_time ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);

    /* Inport: '<Root>/buttons1' */
    rtb_inputevents_idx_2 = (int8_T)(zcEvent[2] ? SubStopWatch_U_mode_alarm ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);

    /* Inport: '<Root>/buttons2' */
    rtb_inputevents_idx_3 = (int8_T)(zcEvent[3] ? SubStopWatch_U_mode_swatch ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);

    /* Inport: '<Root>/buttons3' */
    rtb_inputevents_idx_4 = (int8_T)(zcEvent[4] ? SubStopWatch_U_mode_setting ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);

    /* Inport: '<Root>/buttons4' */
    rtb_inputevents_idx_5 = (int8_T)(zcEvent[5] ?
      SubStopWatch_U_submode_plus_start ? RISING_ZCEVENT : FALLING_ZCEVENT :
      NO_ZCEVENT);

    /* Inport: '<Root>/buttons5' */
    rtb_inputevents_idx_6 = (int8_T)(zcEvent[6] ?
      SubStopWatch_U_submode_minus_stop ? RISING_ZCEVENT : FALLING_ZCEVENT :
      NO_ZCEVENT);

    /* Inport: '<Root>/buttons6' */
    rtb_inputevents_idx_7 = (int8_T)(zcEvent[7] ?
      SubStopWatch_U_submode_switch_reset ? RISING_ZCEVENT : FALLING_ZCEVENT :
      NO_ZCEVENT);

    /* Inport: '<Root>/buttons7' */
    rtb_inputevents_idx_8 = (int8_T)(zcEvent[8] ?
      SubStopWatch_U_submode_alon_conf ? RISING_ZCEVENT : FALLING_ZCEVENT :
      NO_ZCEVENT);

    /* Inport: '<Root>/buttons8' */
    rtb_inputevents_idx_9 = (int8_T)(zcEvent[9] ?
      SubStopWatch_U_submode_alarm_off ? RISING_ZCEVENT : FALLING_ZCEVENT :
      NO_ZCEVENT);

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  UnitDelay: '<S2>/Output'
     */
    /* Gateway: SubStopWatch/Stopwatch
     */
    if ((int8_T)(zcEvent[0] ? SubStopWatch_DW->Output_DSTATE != 0 ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S3>:1' */
      SubStopWatch_DW->sfEvent = SubStopWatch_event_tick;
      SubSt_chartstep_c3_SubStopWatch(SubStopWatch_Y_submode,
        SubStopWatch_Y_alarm_on, SubStopWatch_Y_notify_alarm,
        SubStopWatch_Y_hours, SubStopWatch_Y_minutes, SubStopWatch_Y_seconds,
        SubStopWatch_Y_tenths, SubStopWatch_Y_mode, SubStopWatch_DW);
    }

    if (rtb_inputevents_idx_1 == 1) {
      /* Event: '<S3>:2' */
      SubStopWatch_DW->sfEvent = SubStopWatch_event_mode_time;
      SubSt_chartstep_c3_SubStopWatch(SubStopWatch_Y_submode,
        SubStopWatch_Y_alarm_on, SubStopWatch_Y_notify_alarm,
        SubStopWatch_Y_hours, SubStopWatch_Y_minutes, SubStopWatch_Y_seconds,
        SubStopWatch_Y_tenths, SubStopWatch_Y_mode, SubStopWatch_DW);
    }

    if (rtb_inputevents_idx_2 == 1) {
      /* Event: '<S3>:3' */
      SubStopWatch_DW->sfEvent = SubStopWatch_event_mode_alarm;
      SubSt_chartstep_c3_SubStopWatch(SubStopWatch_Y_submode,
        SubStopWatch_Y_alarm_on, SubStopWatch_Y_notify_alarm,
        SubStopWatch_Y_hours, SubStopWatch_Y_minutes, SubStopWatch_Y_seconds,
        SubStopWatch_Y_tenths, SubStopWatch_Y_mode, SubStopWatch_DW);
    }

    if (rtb_inputevents_idx_3 == 1) {
      /* Event: '<S3>:4' */
      SubStopWatch_DW->sfEvent = SubStopWatch_event_mode_swatch;
      SubSt_chartstep_c3_SubStopWatch(SubStopWatch_Y_submode,
        SubStopWatch_Y_alarm_on, SubStopWatch_Y_notify_alarm,
        SubStopWatch_Y_hours, SubStopWatch_Y_minutes, SubStopWatch_Y_seconds,
        SubStopWatch_Y_tenths, SubStopWatch_Y_mode, SubStopWatch_DW);
    }

    if (rtb_inputevents_idx_4 == 1) {
      /* Event: '<S3>:5' */
      SubStopWatch_DW->sfEvent = SubStopWatch_event_mode_setting;
      SubSt_chartstep_c3_SubStopWatch(SubStopWatch_Y_submode,
        SubStopWatch_Y_alarm_on, SubStopWatch_Y_notify_alarm,
        SubStopWatch_Y_hours, SubStopWatch_Y_minutes, SubStopWatch_Y_seconds,
        SubStopWatch_Y_tenths, SubStopWatch_Y_mode, SubStopWatch_DW);
    }

    if (rtb_inputevents_idx_5 == 1) {
      /* Event: '<S3>:6' */
      SubStopWatch_DW->sfEvent = SubSto_event_submode_plus_start;
      SubSt_chartstep_c3_SubStopWatch(SubStopWatch_Y_submode,
        SubStopWatch_Y_alarm_on, SubStopWatch_Y_notify_alarm,
        SubStopWatch_Y_hours, SubStopWatch_Y_minutes, SubStopWatch_Y_seconds,
        SubStopWatch_Y_tenths, SubStopWatch_Y_mode, SubStopWatch_DW);
    }

    if (rtb_inputevents_idx_6 == 1) {
      /* Event: '<S3>:7' */
      SubStopWatch_DW->sfEvent = SubSto_event_submode_minus_stop;
      SubSt_chartstep_c3_SubStopWatch(SubStopWatch_Y_submode,
        SubStopWatch_Y_alarm_on, SubStopWatch_Y_notify_alarm,
        SubStopWatch_Y_hours, SubStopWatch_Y_minutes, SubStopWatch_Y_seconds,
        SubStopWatch_Y_tenths, SubStopWatch_Y_mode, SubStopWatch_DW);
    }

    if (rtb_inputevents_idx_7 == 1) {
      /* Event: '<S3>:9' */
      SubStopWatch_DW->sfEvent = SubS_event_submode_switch_reset;
      SubSt_chartstep_c3_SubStopWatch(SubStopWatch_Y_submode,
        SubStopWatch_Y_alarm_on, SubStopWatch_Y_notify_alarm,
        SubStopWatch_Y_hours, SubStopWatch_Y_minutes, SubStopWatch_Y_seconds,
        SubStopWatch_Y_tenths, SubStopWatch_Y_mode, SubStopWatch_DW);
    }

    if (rtb_inputevents_idx_8 == 1) {
      /* Event: '<S3>:8' */
      SubStopWatch_DW->sfEvent = SubStop_event_submode_alon_conf;
      SubSt_chartstep_c3_SubStopWatch(SubStopWatch_Y_submode,
        SubStopWatch_Y_alarm_on, SubStopWatch_Y_notify_alarm,
        SubStopWatch_Y_hours, SubStopWatch_Y_minutes, SubStopWatch_Y_seconds,
        SubStopWatch_Y_tenths, SubStopWatch_Y_mode, SubStopWatch_DW);
    }

    if (rtb_inputevents_idx_9 == 1) {
      /* Event: '<S3>:182' */
      SubStopWatch_DW->sfEvent = SubStop_event_submode_alarm_off;
      SubSt_chartstep_c3_SubStopWatch(SubStopWatch_Y_submode,
        SubStopWatch_Y_alarm_on, SubStopWatch_Y_notify_alarm,
        SubStopWatch_Y_hours, SubStopWatch_Y_minutes, SubStopWatch_Y_seconds,
        SubStopWatch_Y_tenths, SubStopWatch_Y_mode, SubStopWatch_DW);
    }
  }

  SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[0] = (uint8_T)(rtb_DataTypeConversion
    ? (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Inport: '<Root>/buttons0' */
  SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[1] = (uint8_T)
    (SubStopWatch_U_mode_time ? (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Inport: '<Root>/buttons1' */
  SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[2] = (uint8_T)
    (SubStopWatch_U_mode_alarm ? (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Inport: '<Root>/buttons2' */
  SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[3] = (uint8_T)
    (SubStopWatch_U_mode_swatch ? (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Inport: '<Root>/buttons3' */
  SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[4] = (uint8_T)
    (SubStopWatch_U_mode_setting ? (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Inport: '<Root>/buttons4' */
  SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[5] = (uint8_T)
    (SubStopWatch_U_submode_plus_start ? (int32_T)POS_ZCSIG : (int32_T)
     ZERO_ZCSIG);

  /* Inport: '<Root>/buttons5' */
  SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[6] = (uint8_T)
    (SubStopWatch_U_submode_minus_stop ? (int32_T)POS_ZCSIG : (int32_T)
     ZERO_ZCSIG);

  /* Inport: '<Root>/buttons6' */
  SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[7] = (uint8_T)
    (SubStopWatch_U_submode_switch_reset ? (int32_T)POS_ZCSIG : (int32_T)
     ZERO_ZCSIG);

  /* Inport: '<Root>/buttons7' */
  SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[8] = (uint8_T)
    (SubStopWatch_U_submode_alon_conf ? (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Inport: '<Root>/buttons8' */
  SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[9] = (uint8_T)
    (SubStopWatch_U_submode_alarm_off ? (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Sum: '<S4>/FixPt Sum1' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   */
  rtb_Output = (uint8_T)((uint32_T)rtb_Output +
    SubStopWatch_P->FixPtConstant_Value);

  /* Switch: '<S5>/FixPt Switch' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (rtb_Output > SubStopWatch_P->CounterLimited_uplimit) {
    rtb_FixPtSwitch = SubStopWatch_P->Constant_Value;
  } else {
    rtb_FixPtSwitch = rtb_Output;
  }

  /* End of Switch: '<S5>/FixPt Switch' */

  /* Update for UnitDelay: '<S2>/Output' */
  SubStopWatch_DW->Output_DSTATE = rtb_FixPtSwitch;
}

/* Model initialize function */
void SubStopWatch_initialize(RT_MODEL_SubStopWatch_T *const SubStopWatch_M,
  boolean_T *SubStopWatch_U_mode_time, boolean_T *SubStopWatch_U_mode_alarm,
  boolean_T *SubStopWatch_U_mode_swatch, boolean_T *SubStopWatch_U_mode_setting,
  boolean_T *SubStopWatch_U_submode_plus_start, boolean_T
  *SubStopWatch_U_submode_minus_stop, boolean_T
  *SubStopWatch_U_submode_switch_reset, boolean_T
  *SubStopWatch_U_submode_alon_conf, boolean_T *SubStopWatch_U_submode_alarm_off,
  uint8_T *SubStopWatch_Y_submode, boolean_T *SubStopWatch_Y_alarm_on, boolean_T
  *SubStopWatch_Y_notify_alarm, uint8_T *SubStopWatch_Y_hours, uint8_T
  *SubStopWatch_Y_minutes, uint8_T *SubStopWatch_Y_seconds, uint8_T
  *SubStopWatch_Y_tenths, uint8_T *SubStopWatch_Y_mode)
{
  P_SubStopWatch_T *SubStopWatch_P = ((P_SubStopWatch_T *)
    SubStopWatch_M->ModelData.defaultParam);
  DW_SubStopWatch_T *SubStopWatch_DW = ((DW_SubStopWatch_T *)
    SubStopWatch_M->ModelData.dwork);

  /* InitializeConditions for UnitDelay: '<S2>/Output' */
  SubStopWatch_DW->Output_DSTATE = SubStopWatch_P->Output_InitialCondition;

  /* InitializeConditions for Chart: '<S1>/Stopwatch ' */
  SubStopWatch_DW->is_active_AlarmCheck = 0U;
  SubStopWatch_DW->is_AlarmCheck = SubStopWatch_IN_NO_ACTIVE_CHILD;
  SubStopWatch_DW->is_active_TimeCount = 0U;
  SubStopWatch_DW->is_TimeCount = SubStopWatch_IN_NO_ACTIVE_CHILD;
  SubStopWatch_DW->is_active_WorkingMode = 0U;
  SubStopWatch_DW->is_WorkingMode = SubStopWatch_IN_NO_ACTIVE_CHILD;
  SubStopWatch_DW->is_Alarm = SubStopWatch_IN_NO_ACTIVE_CHILD;
  SubStopWatch_DW->is_Chrono = SubStopWatch_IN_NO_ACTIVE_CHILD;
  SubStopWatch_DW->is_Setting = SubStopWatch_IN_NO_ACTIVE_CHILD;
  SubStopWatch_DW->is_active_c3_SubStopWatch = 0U;
}

/* Model data allocation function */
RT_MODEL_SubStopWatch_T *SubStopWatch(boolean_T *SubStopWatch_U_mode_time,
  boolean_T *SubStopWatch_U_mode_alarm, boolean_T *SubStopWatch_U_mode_swatch,
  boolean_T *SubStopWatch_U_mode_setting, boolean_T
  *SubStopWatch_U_submode_plus_start, boolean_T
  *SubStopWatch_U_submode_minus_stop, boolean_T
  *SubStopWatch_U_submode_switch_reset, boolean_T
  *SubStopWatch_U_submode_alon_conf, boolean_T *SubStopWatch_U_submode_alarm_off,
  uint8_T *SubStopWatch_Y_submode, boolean_T *SubStopWatch_Y_alarm_on, boolean_T
  *SubStopWatch_Y_notify_alarm, uint8_T *SubStopWatch_Y_hours, uint8_T
  *SubStopWatch_Y_minutes, uint8_T *SubStopWatch_Y_seconds, uint8_T
  *SubStopWatch_Y_tenths, uint8_T *SubStopWatch_Y_mode)
{
  RT_MODEL_SubStopWatch_T *SubStopWatch_M;
  SubStopWatch_M = (RT_MODEL_SubStopWatch_T *) malloc(sizeof
    (RT_MODEL_SubStopWatch_T));
  if (SubStopWatch_M == NULL) {
    return NULL;
  }

  (void) memset((char *)SubStopWatch_M, 0,
                sizeof(RT_MODEL_SubStopWatch_T));

  /* parameters */
  {
    P_SubStopWatch_T *p;
    static int_T pSeen = 0;

    /* only malloc on multiple model instantiation */
    if (pSeen == 1 ) {
      p = (P_SubStopWatch_T *) malloc(sizeof(P_SubStopWatch_T));
      rt_VALIDATE_MEMORY(SubStopWatch_M,p);
      (void) memcpy(p, &SubStopWatch_P,
                    sizeof(P_SubStopWatch_T));
      SubStopWatch_M->ModelData.paramIsMalloced = (true);
    } else {
      p = &SubStopWatch_P;
      SubStopWatch_M->ModelData.paramIsMalloced = (false);
      pSeen = 1;
    }

    SubStopWatch_M->ModelData.defaultParam = (p);
  }

  /* states (dwork) */
  {
    DW_SubStopWatch_T *dwork = (DW_SubStopWatch_T *) malloc(sizeof
      (DW_SubStopWatch_T));
    rt_VALIDATE_MEMORY(SubStopWatch_M,dwork);
    SubStopWatch_M->ModelData.dwork = (dwork);
  }

  /* previous zero-crossing states */
  {
    PrevZCX_SubStopWatch_T *zc = (PrevZCX_SubStopWatch_T *) malloc(sizeof
      (PrevZCX_SubStopWatch_T));
    rt_VALIDATE_MEMORY(SubStopWatch_M,zc);
    SubStopWatch_M->ModelData.prevZCSigState = (zc);
  }

  {
    P_SubStopWatch_T *SubStopWatch_P = ((P_SubStopWatch_T *)
      SubStopWatch_M->ModelData.defaultParam);
    DW_SubStopWatch_T *SubStopWatch_DW = ((DW_SubStopWatch_T *)
      SubStopWatch_M->ModelData.dwork);
    PrevZCX_SubStopWatch_T *SubStopWatch_PrevZCX = ((PrevZCX_SubStopWatch_T *)
      SubStopWatch_M->ModelData.prevZCSigState);

    /* states (dwork) */
    (void) memset((void *)SubStopWatch_DW, 0,
                  sizeof(DW_SubStopWatch_T));

    /* external inputs */
    (*SubStopWatch_U_mode_time) = false;
    (*SubStopWatch_U_mode_alarm) = false;
    (*SubStopWatch_U_mode_swatch) = false;
    (*SubStopWatch_U_mode_setting) = false;
    (*SubStopWatch_U_submode_plus_start) = false;
    (*SubStopWatch_U_submode_minus_stop) = false;
    (*SubStopWatch_U_submode_switch_reset) = false;
    (*SubStopWatch_U_submode_alon_conf) = false;
    (*SubStopWatch_U_submode_alarm_off) = false;

    /* external outputs */
    (*SubStopWatch_Y_submode) = 0U;
    (*SubStopWatch_Y_alarm_on) = false;
    (*SubStopWatch_Y_notify_alarm) = false;
    (*SubStopWatch_Y_hours) = 0U;
    (*SubStopWatch_Y_minutes) = 0U;
    (*SubStopWatch_Y_seconds) = 0U;
    (*SubStopWatch_Y_tenths) = 0U;
    (*SubStopWatch_Y_mode) = 0U;

    /* previous zero-crossing states */
    {
      {
        int_T idx;
        for (idx = 0; idx < 10; idx++) {
          SubStopWatch_PrevZCX->Stopwatch_Trig_ZCE[idx] = UNINITIALIZED_ZCSIG;
        }
      }
    }
  }

  return SubStopWatch_M;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
