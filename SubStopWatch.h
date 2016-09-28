/*
 * File: SubStopWatch.h
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

#ifndef RTW_HEADER_SubStopWatch_h_
#define RTW_HEADER_SubStopWatch_h_
#include <stddef.h>
#include <string.h>
#ifndef SubStopWatch_COMMON_INCLUDES_
# define SubStopWatch_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#endif                                 /* SubStopWatch_COMMON_INCLUDES_ */

#include "SubStopWatch_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ((rtm)->ModelData.paramIsMalloced)
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ((rtm)->ModelData.paramIsMalloced = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

#define SubStopWatch_M_TYPE            RT_MODEL_SubStopWatch_T

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T sfEvent;                     /* '<S1>/Stopwatch ' */
  uint8_T Output_DSTATE;               /* '<S2>/Output' */
  uint8_T is_active_c3_SubStopWatch;   /* '<S1>/Stopwatch ' */
  uint8_T is_WorkingMode;              /* '<S1>/Stopwatch ' */
  uint8_T is_active_WorkingMode;       /* '<S1>/Stopwatch ' */
  uint8_T is_TimeCount;                /* '<S1>/Stopwatch ' */
  uint8_T is_active_TimeCount;         /* '<S1>/Stopwatch ' */
  uint8_T is_Chrono;                   /* '<S1>/Stopwatch ' */
  uint8_T is_Setting;                  /* '<S1>/Stopwatch ' */
  uint8_T is_AlarmCheck;               /* '<S1>/Stopwatch ' */
  uint8_T is_active_AlarmCheck;        /* '<S1>/Stopwatch ' */
  uint8_T is_Alarm;                    /* '<S1>/Stopwatch ' */
  uint8_T tTenths;                     /* '<S1>/Stopwatch ' */
  uint8_T tSeconds;                    /* '<S1>/Stopwatch ' */
  uint8_T tMinutes;                    /* '<S1>/Stopwatch ' */
  uint8_T tHours;                      /* '<S1>/Stopwatch ' */
  uint8_T aHours;                      /* '<S1>/Stopwatch ' */
  uint8_T aMinutes;                    /* '<S1>/Stopwatch ' */
} DW_SubStopWatch_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Stopwatch_Trig_ZCE[10];   /* '<S1>/Stopwatch ' */
} PrevZCX_SubStopWatch_T;

/* Parameters (auto storage) */
struct P_SubStopWatch_T_ {
  uint8_T CounterLimited_uplimit;      /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S5>/FixPt Switch'
                                        */
  uint8_T Output_InitialCondition;     /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S2>/Output'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S4>/FixPt Constant'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S5>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SubStopWatch_T {
  const char_T *errorStatus;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    P_SubStopWatch_T *defaultParam;
    PrevZCX_SubStopWatch_T *prevZCSigState;
    boolean_T paramIsMalloced;
    DW_SubStopWatch_T *dwork;
  } ModelData;
};

extern P_SubStopWatch_T SubStopWatch_P;/* parameters */

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Model entry point functions */
extern RT_MODEL_SubStopWatch_T *SubStopWatch(boolean_T *SubStopWatch_U_mode_time,
  boolean_T *SubStopWatch_U_mode_alarm, boolean_T *SubStopWatch_U_mode_swatch,
  boolean_T *SubStopWatch_U_mode_setting, boolean_T
  *SubStopWatch_U_submode_plus_start, boolean_T
  *SubStopWatch_U_submode_minus_stop, boolean_T
  *SubStopWatch_U_submode_switch_reset, boolean_T
  *SubStopWatch_U_submode_alon_conf, boolean_T *SubStopWatch_U_submode_alarm_off,
  uint8_T *SubStopWatch_Y_submode, boolean_T *SubStopWatch_Y_alarm_on, boolean_T
  *SubStopWatch_Y_notify_alarm, uint8_T *SubStopWatch_Y_hours, uint8_T
  *SubStopWatch_Y_minutes, uint8_T *SubStopWatch_Y_seconds, uint8_T
  *SubStopWatch_Y_tenths, uint8_T *SubStopWatch_Y_mode);
extern void SubStopWatch_initialize(RT_MODEL_SubStopWatch_T *const
  SubStopWatch_M, boolean_T *SubStopWatch_U_mode_time, boolean_T
  *SubStopWatch_U_mode_alarm, boolean_T *SubStopWatch_U_mode_swatch, boolean_T
  *SubStopWatch_U_mode_setting, boolean_T *SubStopWatch_U_submode_plus_start,
  boolean_T *SubStopWatch_U_submode_minus_stop, boolean_T
  *SubStopWatch_U_submode_switch_reset, boolean_T
  *SubStopWatch_U_submode_alon_conf, boolean_T *SubStopWatch_U_submode_alarm_off,
  uint8_T *SubStopWatch_Y_submode, boolean_T *SubStopWatch_Y_alarm_on, boolean_T
  *SubStopWatch_Y_notify_alarm, uint8_T *SubStopWatch_Y_hours, uint8_T
  *SubStopWatch_Y_minutes, uint8_T *SubStopWatch_Y_seconds, uint8_T
  *SubStopWatch_Y_tenths, uint8_T *SubStopWatch_Y_mode);
extern void SubStopWatch_step(RT_MODEL_SubStopWatch_T *const SubStopWatch_M,
  boolean_T SubStopWatch_U_mode_time, boolean_T SubStopWatch_U_mode_alarm,
  boolean_T SubStopWatch_U_mode_swatch, boolean_T SubStopWatch_U_mode_setting,
  boolean_T SubStopWatch_U_submode_plus_start, boolean_T
  SubStopWatch_U_submode_minus_stop, boolean_T
  SubStopWatch_U_submode_switch_reset, boolean_T
  SubStopWatch_U_submode_alon_conf, boolean_T SubStopWatch_U_submode_alarm_off,
  uint8_T *SubStopWatch_Y_submode, boolean_T *SubStopWatch_Y_alarm_on, boolean_T
  *SubStopWatch_Y_notify_alarm, uint8_T *SubStopWatch_Y_hours, uint8_T
  *SubStopWatch_Y_minutes, uint8_T *SubStopWatch_Y_seconds, uint8_T
  *SubStopWatch_Y_tenths, uint8_T *SubStopWatch_Y_mode);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('stopwatch/SubStopWatch')    - opens subsystem stopwatch/SubStopWatch
 * hilite_system('stopwatch/SubStopWatch/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'stopwatch'
 * '<S1>'   : 'stopwatch/SubStopWatch'
 * '<S2>'   : 'stopwatch/SubStopWatch/Counter Limited'
 * '<S3>'   : 'stopwatch/SubStopWatch/Stopwatch '
 * '<S4>'   : 'stopwatch/SubStopWatch/Counter Limited/Increment Real World'
 * '<S5>'   : 'stopwatch/SubStopWatch/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_SubStopWatch_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
