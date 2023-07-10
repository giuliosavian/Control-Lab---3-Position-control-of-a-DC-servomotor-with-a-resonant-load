/*
 * PositionPIDcontrol_REALTIME.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PositionPIDcontrol_REALTIME".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon May 17 12:01:08 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PositionPIDcontrol_REALTIME.h"
#include "PositionPIDcontrol_REALTIME_private.h"
#include "PositionPIDcontrol_REALTIME_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  2.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-6221", 4294967295U, 5, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_PositionPIDcontrol_REALTIME_T PositionPIDcontrol_REALTIME_B;

/* Continuous states */
X_PositionPIDcontrol_REALTIME_T PositionPIDcontrol_REALTIME_X;

/* Block states (default storage) */
DW_PositionPIDcontrol_REALTIME_T PositionPIDcontrol_REALTIME_DW;

/* Real-time model */
static RT_MODEL_PositionPIDcontrol_REALTIME_T PositionPIDcontrol_REALTIME_M_;
RT_MODEL_PositionPIDcontrol_REALTIME_T *const PositionPIDcontrol_REALTIME_M =
  &PositionPIDcontrol_REALTIME_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  PositionPIDcontrol_REALTIME_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  PositionPIDcontrol_REALTIME_output();
  PositionPIDcontrol_REALTIME_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  PositionPIDcontrol_REALTIME_output();
  PositionPIDcontrol_REALTIME_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void PositionPIDcontrol_REALTIME_output(void)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput[2];
  real_T rtb_Subtract;
  real_T rtb_Clock_tmp;
  real_T rtb_Sum1;
  if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
    /* set solver stop time */
    if (!(PositionPIDcontrol_REALTIME_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PositionPIDcontrol_REALTIME_M->solverInfo,
                            ((PositionPIDcontrol_REALTIME_M->Timing.clockTickH0
        + 1) * PositionPIDcontrol_REALTIME_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PositionPIDcontrol_REALTIME_M->solverInfo,
                            ((PositionPIDcontrol_REALTIME_M->Timing.clockTick0 +
        1) * PositionPIDcontrol_REALTIME_M->Timing.stepSize0 +
        PositionPIDcontrol_REALTIME_M->Timing.clockTickH0 *
        PositionPIDcontrol_REALTIME_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PositionPIDcontrol_REALTIME_M)) {
    PositionPIDcontrol_REALTIME_M->Timing.t[0] = rtsiGetT
      (&PositionPIDcontrol_REALTIME_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(PositionPIDcontrol_REALTIME_DW.Average_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PositionPIDcontrol_REALTIME_DW.PIDController_SubsysRanBC);
  if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = PositionPIDcontrol_REALTIME_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &PositionPIDcontrol_REALTIME_P.EncoderInput_Channels,
                     &rtb_Subtract, &parm);
    }

    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        PositionPIDcontrol_REALTIME_P.AnalogInput_RangeMode;
      parm.rangeidx = PositionPIDcontrol_REALTIME_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                     PositionPIDcontrol_REALTIME_P.AnalogInput_Channels,
                     &rtb_AnalogInput[0], &parm);
    }

    /* Gain: '<Root>/pulse2deg' */
    PositionPIDcontrol_REALTIME_B.th_h =
      PositionPIDcontrol_REALTIME_P.sens.enc.pulse2deg * rtb_Subtract;

    /* Step: '<Root>/Step' */
    if (PositionPIDcontrol_REALTIME_M->Timing.t[1] <
        PositionPIDcontrol_REALTIME_P.Step_Time) {
      rtb_Sum1 = PositionPIDcontrol_REALTIME_P.Step_Y0;
    } else {
      rtb_Sum1 = PositionPIDcontrol_REALTIME_P.step_size;
    }

    /* End of Step: '<Root>/Step' */

    /* Sum: '<Root>/Sum1' */
    rtb_Sum1 -= PositionPIDcontrol_REALTIME_B.th_h;
  }

  /* Clock: '<S2>/Clock' incorporates:
   *  Clock: '<S4>/Clock'
   */
  rtb_Clock_tmp = PositionPIDcontrol_REALTIME_M->Timing.t[0];

  /* Logic: '<S7>/AND' incorporates:
   *  Clock: '<S2>/Clock'
   *  Constant: '<S7>/Lower Limit'
   *  Constant: '<S7>/Upper Limit'
   *  RelationalOperator: '<S7>/Lower Test'
   *  RelationalOperator: '<S7>/Upper Test'
   */
  PositionPIDcontrol_REALTIME_B.AND =
    ((PositionPIDcontrol_REALTIME_P.IntervalTest_lowlimit <= rtb_Clock_tmp) &&
     (rtb_Clock_tmp <= PositionPIDcontrol_REALTIME_P.IntervalTest_uplimit));
  if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
    /* SignalConversion generated from: '<S3>/Enable' */
    PositionPIDcontrol_REALTIME_B.HiddenBuf_InsertedFor_PIDController_at_inport_1
      = PositionPIDcontrol_REALTIME_B.AND;

    /* Outputs for Enabled SubSystem: '<Root>/PID Controller' incorporates:
     *  EnablePort: '<S3>/Enable'
     */
    if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
      if (PositionPIDcontrol_REALTIME_B.HiddenBuf_InsertedFor_PIDController_at_inport_1)
      {
        if (!PositionPIDcontrol_REALTIME_DW.PIDController_MODE) {
          /* InitializeConditions for TransferFcn: '<S3>/Real Derivative' */
          PositionPIDcontrol_REALTIME_X.RealDerivative_CSTATE = 0.0;

          /* InitializeConditions for Integrator: '<S3>/Integrator' */
          PositionPIDcontrol_REALTIME_X.Integrator_CSTATE =
            PositionPIDcontrol_REALTIME_P.Integrator_IC;
          PositionPIDcontrol_REALTIME_DW.PIDController_MODE = true;
        }
      } else {
        PositionPIDcontrol_REALTIME_DW.PIDController_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<Root>/PID Controller' */
  }

  /* Outputs for Enabled SubSystem: '<Root>/PID Controller' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (PositionPIDcontrol_REALTIME_DW.PIDController_MODE) {
    if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
      /* Sum: '<S1>/Subtract' incorporates:
       *  Gain: '<S3>/deg2rad'
       */
      rtb_Subtract = PositionPIDcontrol_REALTIME_P.deg2rad * rtb_Sum1;

      /* Gain: '<S3>/proportional gain' */
      PositionPIDcontrol_REALTIME_B.proportionalgain =
        PositionPIDcontrol_REALTIME_P.ctrl.Kp * rtb_Subtract;

      /* Gain: '<S3>/derivative gain' */
      PositionPIDcontrol_REALTIME_B.derivativegain =
        PositionPIDcontrol_REALTIME_P.ctrl.Kd * rtb_Subtract;
    }

    /* Sum: '<S3>/Sum' incorporates:
     *  Integrator: '<S3>/Integrator'
     *  TransferFcn: '<S3>/Real Derivative'
     */
    PositionPIDcontrol_REALTIME_B.pid_no_saturation =
      ((PositionPIDcontrol_REALTIME_P.RealDerivative_C *
        PositionPIDcontrol_REALTIME_X.RealDerivative_CSTATE +
        PositionPIDcontrol_REALTIME_P.RealDerivative_D *
        PositionPIDcontrol_REALTIME_B.derivativegain) +
       PositionPIDcontrol_REALTIME_B.proportionalgain) +
      PositionPIDcontrol_REALTIME_X.Integrator_CSTATE;

    /* Saturate: '<S3>/Saturation' */
    if (PositionPIDcontrol_REALTIME_B.pid_no_saturation >
        PositionPIDcontrol_REALTIME_P.Saturation_UpperSat) {
      /* Saturate: '<S3>/Saturation' */
      PositionPIDcontrol_REALTIME_B.pid_output =
        PositionPIDcontrol_REALTIME_P.Saturation_UpperSat;
    } else if (PositionPIDcontrol_REALTIME_B.pid_no_saturation <
               PositionPIDcontrol_REALTIME_P.Saturation_LowerSat) {
      /* Saturate: '<S3>/Saturation' */
      PositionPIDcontrol_REALTIME_B.pid_output =
        PositionPIDcontrol_REALTIME_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S3>/Saturation' */
      PositionPIDcontrol_REALTIME_B.pid_output =
        PositionPIDcontrol_REALTIME_B.pid_no_saturation;
    }

    /* End of Saturate: '<S3>/Saturation' */
    if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
    }

    /* Sum: '<S3>/Sum1' */
    PositionPIDcontrol_REALTIME_B.Sum1 =
      PositionPIDcontrol_REALTIME_B.pid_no_saturation -
      PositionPIDcontrol_REALTIME_B.pid_output;

    /* Gain: '<S3>/K_w' */
    PositionPIDcontrol_REALTIME_B.K_w = PositionPIDcontrol_REALTIME_P.ctrl.Kw *
      PositionPIDcontrol_REALTIME_B.Sum1;
    if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
      /* ToAsyncQueueBlock generated from: '<S3>/Saturation' */
      if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
        {
          double time = PositionPIDcontrol_REALTIME_M->Timing.t[1];
          void *pData = (void *)&PositionPIDcontrol_REALTIME_B.pid_output;
          int32_T size = 1*sizeof(real_T);
          sendToAsyncQueueTgtAppSvc(456673230U, time, pData, size);
        }
      }

      /* ToAsyncQueueBlock generated from: '<S3>/Sum' */
      if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
        {
          double time = PositionPIDcontrol_REALTIME_M->Timing.t[1];
          void *pData = (void *)&PositionPIDcontrol_REALTIME_B.pid_no_saturation;
          int32_T size = 1*sizeof(real_T);
          sendToAsyncQueueTgtAppSvc(2792403109U, time, pData, size);
        }
      }

      /* Gain: '<S3>/integral gain' */
      PositionPIDcontrol_REALTIME_B.integralgain =
        PositionPIDcontrol_REALTIME_P.ctrl.Ki * rtb_Subtract;
    }

    /* Sum: '<S3>/Sum3' */
    PositionPIDcontrol_REALTIME_B.Sum3 =
      PositionPIDcontrol_REALTIME_B.integralgain -
      PositionPIDcontrol_REALTIME_B.K_w;
    if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
      srUpdateBC(PositionPIDcontrol_REALTIME_DW.PIDController_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/PID Controller' */
  if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          PositionPIDcontrol_REALTIME_P.AnalogOutput_RangeMode;
        parm.rangeidx = PositionPIDcontrol_REALTIME_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &PositionPIDcontrol_REALTIME_P.AnalogOutput_Channels,
                       ((real_T*) (&PositionPIDcontrol_REALTIME_B.pid_output)),
                       &parm);
      }
    }

    /* Sum: '<S1>/Subtract' */
    rtb_Subtract = rtb_AnalogInput[0] - rtb_AnalogInput[1];

    /* Gain: '<S1>/volt2deg' */
    PositionPIDcontrol_REALTIME_B.volt2deg =
      PositionPIDcontrol_REALTIME_P.sens.pot2.V2deg * rtb_Subtract;
  }

  /* Outputs for Enabled SubSystem: '<S4>/Average' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
    /* Logic: '<S6>/AND' incorporates:
     *  Constant: '<S6>/Lower Limit'
     *  Constant: '<S6>/Upper Limit'
     *  RelationalOperator: '<S6>/Lower Test'
     *  RelationalOperator: '<S6>/Upper Test'
     */
    PositionPIDcontrol_REALTIME_DW.Average_MODE =
      ((PositionPIDcontrol_REALTIME_P.IntervalTest_lowlimit_i <= rtb_Clock_tmp) &&
       (rtb_Clock_tmp <= PositionPIDcontrol_REALTIME_P.IntervalTest_uplimit_n));
  }

  if (PositionPIDcontrol_REALTIME_DW.Average_MODE) {
    if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
      /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
      PositionPIDcontrol_REALTIME_B.DiscreteTimeIntegrator =
        PositionPIDcontrol_REALTIME_DW.DiscreteTimeIntegrator_DSTATE;
    }

    if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
      srUpdateBC(PositionPIDcontrol_REALTIME_DW.Average_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S4>/Average' */
  if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
    /* Sum: '<Root>/Sum' incorporates:
     *  Sum: '<S1>/Sum'
     */
    PositionPIDcontrol_REALTIME_B.th_b = (PositionPIDcontrol_REALTIME_B.volt2deg
      - PositionPIDcontrol_REALTIME_B.DiscreteTimeIntegrator) +
      PositionPIDcontrol_REALTIME_B.th_h;

    /* ToAsyncQueueBlock generated from: '<Root>/Sum' */
    if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
      {
        double time = PositionPIDcontrol_REALTIME_M->Timing.t[1];
        void *pData = (void *)&PositionPIDcontrol_REALTIME_B.th_b;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3046535352U, time, pData, size);
      }
    }
  }
}

/* Model update function */
void PositionPIDcontrol_REALTIME_update(void)
{
  /* Update for Enabled SubSystem: '<S4>/Average' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (PositionPIDcontrol_REALTIME_DW.Average_MODE && rtmIsMajorTimeStep
      (PositionPIDcontrol_REALTIME_M)) {
    /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    PositionPIDcontrol_REALTIME_DW.DiscreteTimeIntegrator_DSTATE +=
      PositionPIDcontrol_REALTIME_P.DiscreteTimeIntegrator_gainval *
      PositionPIDcontrol_REALTIME_B.volt2deg;
  }

  /* End of Update for SubSystem: '<S4>/Average' */
  if (rtmIsMajorTimeStep(PositionPIDcontrol_REALTIME_M)) {
    rt_ertODEUpdateContinuousStates(&PositionPIDcontrol_REALTIME_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PositionPIDcontrol_REALTIME_M->Timing.clockTick0)) {
    ++PositionPIDcontrol_REALTIME_M->Timing.clockTickH0;
  }

  PositionPIDcontrol_REALTIME_M->Timing.t[0] = rtsiGetSolverStopTime
    (&PositionPIDcontrol_REALTIME_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++PositionPIDcontrol_REALTIME_M->Timing.clockTick1)) {
      ++PositionPIDcontrol_REALTIME_M->Timing.clockTickH1;
    }

    PositionPIDcontrol_REALTIME_M->Timing.t[1] =
      PositionPIDcontrol_REALTIME_M->Timing.clockTick1 *
      PositionPIDcontrol_REALTIME_M->Timing.stepSize1 +
      PositionPIDcontrol_REALTIME_M->Timing.clockTickH1 *
      PositionPIDcontrol_REALTIME_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void PositionPIDcontrol_REALTIME_derivatives(void)
{
  XDot_PositionPIDcontrol_REALTIME_T *_rtXdot;
  _rtXdot = ((XDot_PositionPIDcontrol_REALTIME_T *)
             PositionPIDcontrol_REALTIME_M->derivs);

  /* Derivatives for Enabled SubSystem: '<Root>/PID Controller' */
  if (PositionPIDcontrol_REALTIME_DW.PIDController_MODE) {
    /* Derivatives for TransferFcn: '<S3>/Real Derivative' */
    _rtXdot->RealDerivative_CSTATE = 0.0;
    _rtXdot->RealDerivative_CSTATE +=
      PositionPIDcontrol_REALTIME_P.RealDerivative_A *
      PositionPIDcontrol_REALTIME_X.RealDerivative_CSTATE;
    _rtXdot->RealDerivative_CSTATE +=
      PositionPIDcontrol_REALTIME_B.derivativegain;

    /* Derivatives for Integrator: '<S3>/Integrator' */
    _rtXdot->Integrator_CSTATE = PositionPIDcontrol_REALTIME_B.Sum3;
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot_PositionPIDcontrol_REALTIME_T *)
              PositionPIDcontrol_REALTIME_M->derivs)->RealDerivative_CSTATE);
      for (i=0; i < 2; i++) {
        dx[i] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<Root>/PID Controller' */
}

/* Model initialize function */
void PositionPIDcontrol_REALTIME_initialize(void)
{
  /* Start for Enabled SubSystem: '<Root>/PID Controller' */
  PositionPIDcontrol_REALTIME_DW.PIDController_MODE = false;

  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        PositionPIDcontrol_REALTIME_P.AnalogOutput_RangeMode;
      parm.rangeidx = PositionPIDcontrol_REALTIME_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &PositionPIDcontrol_REALTIME_P.AnalogOutput_Channels,
                     &PositionPIDcontrol_REALTIME_P.AnalogOutput_InitialValue,
                     &parm);
    }
  }

  /* Start for Enabled SubSystem: '<S4>/Average' */
  PositionPIDcontrol_REALTIME_DW.Average_MODE = false;

  /* End of Start for SubSystem: '<S4>/Average' */

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = PositionPIDcontrol_REALTIME_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &PositionPIDcontrol_REALTIME_P.EncoderInput_Channels, NULL,
                   &parm);
  }

  /* SystemInitialize for Enabled SubSystem: '<Root>/PID Controller' */
  /* InitializeConditions for TransferFcn: '<S3>/Real Derivative' */
  PositionPIDcontrol_REALTIME_X.RealDerivative_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  PositionPIDcontrol_REALTIME_X.Integrator_CSTATE =
    PositionPIDcontrol_REALTIME_P.Integrator_IC;

  /* SystemInitialize for Saturate: '<S3>/Saturation' incorporates:
   *  Outport: '<S3>/u[V]'
   */
  PositionPIDcontrol_REALTIME_B.pid_output = PositionPIDcontrol_REALTIME_P.uV_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/PID Controller' */

  /* SystemInitialize for Enabled SubSystem: '<S4>/Average' */
  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  PositionPIDcontrol_REALTIME_DW.DiscreteTimeIntegrator_DSTATE =
    PositionPIDcontrol_REALTIME_P.DiscreteTimeIntegrator_IC;

  /* SystemInitialize for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
   *  Outport: '<S5>/Out'
   */
  PositionPIDcontrol_REALTIME_B.DiscreteTimeIntegrator =
    PositionPIDcontrol_REALTIME_P.Out_Y0;

  /* End of SystemInitialize for SubSystem: '<S4>/Average' */
}

/* Model terminate function */
void PositionPIDcontrol_REALTIME_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        PositionPIDcontrol_REALTIME_P.AnalogOutput_RangeMode;
      parm.rangeidx = PositionPIDcontrol_REALTIME_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &PositionPIDcontrol_REALTIME_P.AnalogOutput_Channels,
                     &PositionPIDcontrol_REALTIME_P.AnalogOutput_FinalValue,
                     &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  PositionPIDcontrol_REALTIME_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  PositionPIDcontrol_REALTIME_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  PositionPIDcontrol_REALTIME_initialize();
}

void MdlTerminate(void)
{
  PositionPIDcontrol_REALTIME_terminate();
}

/* Registration function */
RT_MODEL_PositionPIDcontrol_REALTIME_T *PositionPIDcontrol_REALTIME(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  PositionPIDcontrol_REALTIME_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)PositionPIDcontrol_REALTIME_M, 0,
                sizeof(RT_MODEL_PositionPIDcontrol_REALTIME_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PositionPIDcontrol_REALTIME_M->solverInfo,
                          &PositionPIDcontrol_REALTIME_M->Timing.simTimeStep);
    rtsiSetTPtr(&PositionPIDcontrol_REALTIME_M->solverInfo, &rtmGetTPtr
                (PositionPIDcontrol_REALTIME_M));
    rtsiSetStepSizePtr(&PositionPIDcontrol_REALTIME_M->solverInfo,
                       &PositionPIDcontrol_REALTIME_M->Timing.stepSize0);
    rtsiSetdXPtr(&PositionPIDcontrol_REALTIME_M->solverInfo,
                 &PositionPIDcontrol_REALTIME_M->derivs);
    rtsiSetContStatesPtr(&PositionPIDcontrol_REALTIME_M->solverInfo, (real_T **)
                         &PositionPIDcontrol_REALTIME_M->contStates);
    rtsiSetNumContStatesPtr(&PositionPIDcontrol_REALTIME_M->solverInfo,
      &PositionPIDcontrol_REALTIME_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PositionPIDcontrol_REALTIME_M->solverInfo,
      &PositionPIDcontrol_REALTIME_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&PositionPIDcontrol_REALTIME_M->solverInfo,
       &PositionPIDcontrol_REALTIME_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PositionPIDcontrol_REALTIME_M->solverInfo,
      &PositionPIDcontrol_REALTIME_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PositionPIDcontrol_REALTIME_M->solverInfo,
                          (&rtmGetErrorStatus(PositionPIDcontrol_REALTIME_M)));
    rtsiSetRTModelPtr(&PositionPIDcontrol_REALTIME_M->solverInfo,
                      PositionPIDcontrol_REALTIME_M);
  }

  rtsiSetSimTimeStep(&PositionPIDcontrol_REALTIME_M->solverInfo, MAJOR_TIME_STEP);
  PositionPIDcontrol_REALTIME_M->intgData.y =
    PositionPIDcontrol_REALTIME_M->odeY;
  PositionPIDcontrol_REALTIME_M->intgData.f[0] =
    PositionPIDcontrol_REALTIME_M->odeF[0];
  PositionPIDcontrol_REALTIME_M->intgData.f[1] =
    PositionPIDcontrol_REALTIME_M->odeF[1];
  PositionPIDcontrol_REALTIME_M->intgData.f[2] =
    PositionPIDcontrol_REALTIME_M->odeF[2];
  PositionPIDcontrol_REALTIME_M->contStates = ((real_T *)
    &PositionPIDcontrol_REALTIME_X);
  rtsiSetSolverData(&PositionPIDcontrol_REALTIME_M->solverInfo, (void *)
                    &PositionPIDcontrol_REALTIME_M->intgData);
  rtsiSetSolverName(&PositionPIDcontrol_REALTIME_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      PositionPIDcontrol_REALTIME_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    PositionPIDcontrol_REALTIME_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    PositionPIDcontrol_REALTIME_M->Timing.sampleTimes =
      (&PositionPIDcontrol_REALTIME_M->Timing.sampleTimesArray[0]);
    PositionPIDcontrol_REALTIME_M->Timing.offsetTimes =
      (&PositionPIDcontrol_REALTIME_M->Timing.offsetTimesArray[0]);

    /* task periods */
    PositionPIDcontrol_REALTIME_M->Timing.sampleTimes[0] = (0.0);
    PositionPIDcontrol_REALTIME_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    PositionPIDcontrol_REALTIME_M->Timing.offsetTimes[0] = (0.0);
    PositionPIDcontrol_REALTIME_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(PositionPIDcontrol_REALTIME_M,
             &PositionPIDcontrol_REALTIME_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = PositionPIDcontrol_REALTIME_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    PositionPIDcontrol_REALTIME_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(PositionPIDcontrol_REALTIME_M, 5.0);
  PositionPIDcontrol_REALTIME_M->Timing.stepSize0 = 0.001;
  PositionPIDcontrol_REALTIME_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  PositionPIDcontrol_REALTIME_M->Sizes.checksums[0] = (1050986377U);
  PositionPIDcontrol_REALTIME_M->Sizes.checksums[1] = (443537420U);
  PositionPIDcontrol_REALTIME_M->Sizes.checksums[2] = (1195580798U);
  PositionPIDcontrol_REALTIME_M->Sizes.checksums[3] = (213891046U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    PositionPIDcontrol_REALTIME_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &PositionPIDcontrol_REALTIME_DW.Average_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &PositionPIDcontrol_REALTIME_DW.PIDController_SubsysRanBC;
    rteiSetModelMappingInfoPtr(PositionPIDcontrol_REALTIME_M->extModeInfo,
      &PositionPIDcontrol_REALTIME_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PositionPIDcontrol_REALTIME_M->extModeInfo,
                        PositionPIDcontrol_REALTIME_M->Sizes.checksums);
    rteiSetTPtr(PositionPIDcontrol_REALTIME_M->extModeInfo, rtmGetTPtr
                (PositionPIDcontrol_REALTIME_M));
  }

  PositionPIDcontrol_REALTIME_M->solverInfoPtr =
    (&PositionPIDcontrol_REALTIME_M->solverInfo);
  PositionPIDcontrol_REALTIME_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&PositionPIDcontrol_REALTIME_M->solverInfo, 0.001);
  rtsiSetSolverMode(&PositionPIDcontrol_REALTIME_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  PositionPIDcontrol_REALTIME_M->blockIO = ((void *)
    &PositionPIDcontrol_REALTIME_B);
  (void) memset(((void *) &PositionPIDcontrol_REALTIME_B), 0,
                sizeof(B_PositionPIDcontrol_REALTIME_T));

  /* parameters */
  PositionPIDcontrol_REALTIME_M->defaultParam = ((real_T *)
    &PositionPIDcontrol_REALTIME_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &PositionPIDcontrol_REALTIME_X;
    PositionPIDcontrol_REALTIME_M->contStates = (x);
    (void) memset((void *)&PositionPIDcontrol_REALTIME_X, 0,
                  sizeof(X_PositionPIDcontrol_REALTIME_T));
  }

  /* states (dwork) */
  PositionPIDcontrol_REALTIME_M->dwork = ((void *)
    &PositionPIDcontrol_REALTIME_DW);
  (void) memset((void *)&PositionPIDcontrol_REALTIME_DW, 0,
                sizeof(DW_PositionPIDcontrol_REALTIME_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    PositionPIDcontrol_REALTIME_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  PositionPIDcontrol_REALTIME_M->Sizes.numContStates = (2);/* Number of continuous states */
  PositionPIDcontrol_REALTIME_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  PositionPIDcontrol_REALTIME_M->Sizes.numY = (0);/* Number of model outputs */
  PositionPIDcontrol_REALTIME_M->Sizes.numU = (0);/* Number of model inputs */
  PositionPIDcontrol_REALTIME_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  PositionPIDcontrol_REALTIME_M->Sizes.numSampTimes = (2);/* Number of sample times */
  PositionPIDcontrol_REALTIME_M->Sizes.numBlocks = (43);/* Number of blocks */
  PositionPIDcontrol_REALTIME_M->Sizes.numBlockIO = (15);/* Number of block outputs */
  PositionPIDcontrol_REALTIME_M->Sizes.numBlockPrms = (37);/* Sum of parameter "widths" */
  return PositionPIDcontrol_REALTIME_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
