/*
 * robust_tracking_integral_REALTIME.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "robust_tracking_integral_REALTIME".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon May 17 11:47:37 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "robust_tracking_integral_REALTIME.h"
#include "robust_tracking_integral_REALTIME_private.h"
#include "robust_tracking_integral_REALTIME_dt.h"

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
B_robust_tracking_integral_REALTIME_T robust_tracking_integral_REALTIME_B;

/* Continuous states */
X_robust_tracking_integral_REALTIME_T robust_tracking_integral_REALTIME_X;

/* Block states (default storage) */
DW_robust_tracking_integral_REALTIME_T robust_tracking_integral_REALTIME_DW;

/* Real-time model */
static RT_MODEL_robust_tracking_integral_REALTIME_T
  robust_tracking_integral_REALTIME_M_;
RT_MODEL_robust_tracking_integral_REALTIME_T *const
  robust_tracking_integral_REALTIME_M = &robust_tracking_integral_REALTIME_M_;

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
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  robust_tracking_integral_REALTIME_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  robust_tracking_integral_REALTIME_output();
  robust_tracking_integral_REALTIME_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  robust_tracking_integral_REALTIME_output();
  robust_tracking_integral_REALTIME_derivatives();

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
void robust_tracking_integral_REALTIME_output(void)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput[2];
  real_T rtb_deg2rad3;
  real_T rtb_Highpassfilter1_tmp;
  real_T rtb_deg2rad4;
  real_T rtb_deg2rad5;
  real_T rtb_thl_ref;
  if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
    /* set solver stop time */
    if (!(robust_tracking_integral_REALTIME_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&robust_tracking_integral_REALTIME_M->solverInfo,
                            ((robust_tracking_integral_REALTIME_M->Timing.clockTickH0
        + 1) * robust_tracking_integral_REALTIME_M->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&robust_tracking_integral_REALTIME_M->solverInfo,
                            ((robust_tracking_integral_REALTIME_M->Timing.clockTick0
        + 1) * robust_tracking_integral_REALTIME_M->Timing.stepSize0 +
        robust_tracking_integral_REALTIME_M->Timing.clockTickH0 *
        robust_tracking_integral_REALTIME_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(robust_tracking_integral_REALTIME_M)) {
    robust_tracking_integral_REALTIME_M->Timing.t[0] = rtsiGetT
      (&robust_tracking_integral_REALTIME_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(robust_tracking_integral_REALTIME_DW.Average_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (robust_tracking_integral_REALTIME_DW.StatespaceController1_SubsysRanBC);
  if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
    /* Step: '<Root>/Step1' */
    if (robust_tracking_integral_REALTIME_M->Timing.t[1] <
        robust_tracking_integral_REALTIME_P.Step1_Time) {
      rtb_thl_ref = robust_tracking_integral_REALTIME_P.Step1_Y0;
    } else {
      rtb_thl_ref = robust_tracking_integral_REALTIME_P.step_size;
    }

    /* End of Step: '<Root>/Step1' */

    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter =
        robust_tracking_integral_REALTIME_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &robust_tracking_integral_REALTIME_P.EncoderInput_Channels,
                     &rtb_deg2rad3, &parm);
    }

    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        robust_tracking_integral_REALTIME_P.AnalogInput_RangeMode;
      parm.rangeidx = robust_tracking_integral_REALTIME_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                     robust_tracking_integral_REALTIME_P.AnalogInput_Channels,
                     &rtb_AnalogInput[0], &parm);
    }

    /* Gain: '<Root>/pulse2deg' */
    robust_tracking_integral_REALTIME_B.th_h =
      robust_tracking_integral_REALTIME_P.sens.enc.pulse2deg * rtb_deg2rad3;

    /* Gain: '<S4>/deg2rad3' incorporates:
     *  Sum: '<S1>/Subtract'
     */
    rtb_deg2rad3 = rtb_AnalogInput[0] - rtb_AnalogInput[1];

    /* Gain: '<S1>/volt2deg' */
    robust_tracking_integral_REALTIME_B.volt2deg =
      robust_tracking_integral_REALTIME_P.sens.pot2.V2deg * rtb_deg2rad3;
  }

  /* Clock: '<S5>/Clock' incorporates:
   *  Clock: '<S2>/Clock'
   */
  rtb_Highpassfilter1_tmp = robust_tracking_integral_REALTIME_M->Timing.t[0];

  /* Outputs for Enabled SubSystem: '<S5>/Average' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
    /* Logic: '<S7>/AND' incorporates:
     *  Clock: '<S5>/Clock'
     *  Constant: '<S7>/Lower Limit'
     *  Constant: '<S7>/Upper Limit'
     *  RelationalOperator: '<S7>/Lower Test'
     *  RelationalOperator: '<S7>/Upper Test'
     */
    robust_tracking_integral_REALTIME_DW.Average_MODE =
      ((robust_tracking_integral_REALTIME_P.IntervalTest_lowlimit <=
        rtb_Highpassfilter1_tmp) && (rtb_Highpassfilter1_tmp <=
        robust_tracking_integral_REALTIME_P.IntervalTest_uplimit));
  }

  if (robust_tracking_integral_REALTIME_DW.Average_MODE) {
    if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
      /* DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
      robust_tracking_integral_REALTIME_B.DiscreteTimeIntegrator =
        robust_tracking_integral_REALTIME_DW.DiscreteTimeIntegrator_DSTATE;
    }

    if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
      srUpdateBC(robust_tracking_integral_REALTIME_DW.Average_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S5>/Average' */

  /* Gain: '<S3>/degs2rpm' incorporates:
   *  TransferFcn: '<S3>/High-pass filter'
   */
  robust_tracking_integral_REALTIME_B.degs2rpm =
    (robust_tracking_integral_REALTIME_P.Highpassfilter_C[0] *
     robust_tracking_integral_REALTIME_X.Highpassfilter_CSTATE[0] +
     robust_tracking_integral_REALTIME_P.Highpassfilter_C[1] *
     robust_tracking_integral_REALTIME_X.Highpassfilter_CSTATE[1]) *
    robust_tracking_integral_REALTIME_P.degs2rpm;

  /* Gain: '<S3>/degs2rpm1' incorporates:
   *  TransferFcn: '<S3>/High-pass filter1'
   */
  robust_tracking_integral_REALTIME_B.degs2rpm1 =
    (robust_tracking_integral_REALTIME_P.Highpassfilter1_C[0] *
     robust_tracking_integral_REALTIME_X.Highpassfilter1_CSTATE[0] +
     robust_tracking_integral_REALTIME_P.Highpassfilter1_C[1] *
     robust_tracking_integral_REALTIME_X.Highpassfilter1_CSTATE[1]) *
    robust_tracking_integral_REALTIME_P.degs2rpm;

  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Lower Limit'
   *  Constant: '<S8>/Upper Limit'
   *  RelationalOperator: '<S8>/Lower Test'
   *  RelationalOperator: '<S8>/Upper Test'
   */
  robust_tracking_integral_REALTIME_B.AND_e =
    ((robust_tracking_integral_REALTIME_P.IntervalTest_lowlimit_l <=
      rtb_Highpassfilter1_tmp) && (rtb_Highpassfilter1_tmp <=
      robust_tracking_integral_REALTIME_P.IntervalTest_uplimit_k));
  if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
    /* Sum: '<S1>/Sum' */
    robust_tracking_integral_REALTIME_B.Sum =
      robust_tracking_integral_REALTIME_B.volt2deg -
      robust_tracking_integral_REALTIME_B.DiscreteTimeIntegrator;

    /* SignalConversion generated from: '<S4>/Enable' */
    robust_tracking_integral_REALTIME_B.HiddenBuf_InsertedFor_StatespaceController1_at_inport_6
      = robust_tracking_integral_REALTIME_B.AND_e;

    /* Outputs for Enabled SubSystem: '<Root>/State-space Controller1' incorporates:
     *  EnablePort: '<S4>/Enable'
     */
    if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
      robust_tracking_integral_REALTIME_DW.StatespaceController1_MODE =
        robust_tracking_integral_REALTIME_B.HiddenBuf_InsertedFor_StatespaceController1_at_inport_6;
    }

    /* End of Outputs for SubSystem: '<Root>/State-space Controller1' */
  }

  /* Outputs for Enabled SubSystem: '<Root>/State-space Controller1' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (robust_tracking_integral_REALTIME_DW.StatespaceController1_MODE) {
    if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
      /* Gain: '<S4>/deg2rad3' */
      rtb_deg2rad3 = robust_tracking_integral_REALTIME_P.deg2rad * rtb_thl_ref;

      /* Gain: '<S4>/Input feedforward1' */
      robust_tracking_integral_REALTIME_B.Inputfeedforward1 =
        robust_tracking_integral_REALTIME_P.N_u * rtb_deg2rad3;

      /* Gain: '<S4>/State feedback1' incorporates:
       *  Delay: '<S4>/Delay1'
       *  Gain: '<S4>/State feedforward	1'
       *  Sum: '<S4>/Sum4'
       */
      robust_tracking_integral_REALTIME_B.Statefeedback1 = (((rtb_deg2rad3 *
        robust_tracking_integral_REALTIME_P.N_x[0] -
        robust_tracking_integral_REALTIME_DW.Delay1_DSTATE[0]) *
        robust_tracking_integral_REALTIME_P.Statefeedback1_Gain[0] +
        (rtb_deg2rad3 * robust_tracking_integral_REALTIME_P.N_x[1] -
         robust_tracking_integral_REALTIME_DW.Delay1_DSTATE[1]) *
        robust_tracking_integral_REALTIME_P.Statefeedback1_Gain[1]) +
        (rtb_deg2rad3 * robust_tracking_integral_REALTIME_P.N_x[2] -
         robust_tracking_integral_REALTIME_DW.Delay1_DSTATE[2]) *
        robust_tracking_integral_REALTIME_P.Statefeedback1_Gain[2]) +
        (rtb_deg2rad3 * robust_tracking_integral_REALTIME_P.N_x[3] -
         robust_tracking_integral_REALTIME_DW.Delay1_DSTATE[3]) *
        robust_tracking_integral_REALTIME_P.Statefeedback1_Gain[3];
    }

    /* Sum: '<S4>/Sum1' incorporates:
     *  TransferFcn: '<S4>/High-pass filter1'
     */
    robust_tracking_integral_REALTIME_B.Sum1 =
      robust_tracking_integral_REALTIME_P.Ki /
      robust_tracking_integral_REALTIME_P.Highpassfilter1_Denominator[0] *
      robust_tracking_integral_REALTIME_X.Highpassfilter1_CSTATE_k +
      (robust_tracking_integral_REALTIME_B.Inputfeedforward1 +
       robust_tracking_integral_REALTIME_B.Statefeedback1);

    /* Saturate: '<S4>/Saturation1' */
    if (robust_tracking_integral_REALTIME_B.Sum1 >
        robust_tracking_integral_REALTIME_P.Saturation1_UpperSat) {
      /* Saturate: '<S4>/Saturation1' */
      robust_tracking_integral_REALTIME_B.Saturation1 =
        robust_tracking_integral_REALTIME_P.Saturation1_UpperSat;
    } else if (robust_tracking_integral_REALTIME_B.Sum1 <
               robust_tracking_integral_REALTIME_P.Saturation1_LowerSat) {
      /* Saturate: '<S4>/Saturation1' */
      robust_tracking_integral_REALTIME_B.Saturation1 =
        robust_tracking_integral_REALTIME_P.Saturation1_LowerSat;
    } else {
      /* Saturate: '<S4>/Saturation1' */
      robust_tracking_integral_REALTIME_B.Saturation1 =
        robust_tracking_integral_REALTIME_B.Sum1;
    }

    /* End of Saturate: '<S4>/Saturation1' */
    if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
      /* Delay: '<S4>/Delay' */
      rtb_thl_ref = robust_tracking_integral_REALTIME_DW.Delay_DSTATE;

      /* Gain: '<S4>/deg2rads1' incorporates:
       *  Gain: '<S4>/deg2rad4'
       */
      rtb_deg2rad4 = robust_tracking_integral_REALTIME_P.deg2rad *
        robust_tracking_integral_REALTIME_B.th_h;

      /* Sum: '<S4>/Sum6' incorporates:
       *  Gain: '<S4>/deg2rads1'
       *  Sum: '<S4>/Sum3'
       */
      robust_tracking_integral_REALTIME_B.Sum6 = (rtb_deg2rad3 - rtb_deg2rad4) -
        rtb_thl_ref;

      /* Gain: '<S4>/deg2rad5' */
      rtb_deg2rad5 = robust_tracking_integral_REALTIME_P.deg2rad *
        robust_tracking_integral_REALTIME_B.Sum;
    }

    /* Gain: '<S4>/K_w' incorporates:
     *  Sum: '<S4>/Sum5'
     */
    robust_tracking_integral_REALTIME_B.K_w =
      (robust_tracking_integral_REALTIME_B.Sum1 -
       robust_tracking_integral_REALTIME_B.Saturation1) *
      robust_tracking_integral_REALTIME_P.ctrl.Kw;

    /* Gain: '<S4>/rpm2rads1' */
    robust_tracking_integral_REALTIME_B.rpm2rads1 =
      robust_tracking_integral_REALTIME_P.rpm2rads *
      robust_tracking_integral_REALTIME_B.degs2rpm;

    /* Gain: '<S4>/rpm2rads3' */
    robust_tracking_integral_REALTIME_B.rpm2rads3 =
      robust_tracking_integral_REALTIME_P.rpm2rads *
      robust_tracking_integral_REALTIME_B.degs2rpm1;
    if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
      /* SignalConversion generated from: '<S4>/Delay1' */
      robust_tracking_integral_REALTIME_B.TmpSignalConversionAtDelay1Inport1[0] =
        rtb_deg2rad4;
      robust_tracking_integral_REALTIME_B.TmpSignalConversionAtDelay1Inport1[1] =
        rtb_deg2rad5;
      robust_tracking_integral_REALTIME_B.TmpSignalConversionAtDelay1Inport1[2] =
        robust_tracking_integral_REALTIME_B.rpm2rads1;
      robust_tracking_integral_REALTIME_B.TmpSignalConversionAtDelay1Inport1[3] =
        robust_tracking_integral_REALTIME_B.rpm2rads3;
    }

    if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
      srUpdateBC
        (robust_tracking_integral_REALTIME_DW.StatespaceController1_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/State-space Controller1' */
  if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          robust_tracking_integral_REALTIME_P.AnalogOutput_RangeMode;
        parm.rangeidx =
          robust_tracking_integral_REALTIME_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &robust_tracking_integral_REALTIME_P.AnalogOutput_Channels,
                       ((real_T*)
                        (&robust_tracking_integral_REALTIME_B.Saturation1)),
                       &parm);
      }
    }

    /* Sum: '<Root>/Sum' */
    robust_tracking_integral_REALTIME_B.th_b =
      robust_tracking_integral_REALTIME_B.th_h +
      robust_tracking_integral_REALTIME_B.Sum;

    /* ToAsyncQueueBlock generated from: '<Root>/Sum' */
    if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
      {
        double time = robust_tracking_integral_REALTIME_M->Timing.t[1];
        void *pData = (void *)&robust_tracking_integral_REALTIME_B.th_b;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4237046450U, time, pData, size);
      }
    }
  }
}

/* Model update function */
void robust_tracking_integral_REALTIME_update(void)
{
  /* Update for Enabled SubSystem: '<S5>/Average' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (robust_tracking_integral_REALTIME_DW.Average_MODE && rtmIsMajorTimeStep
      (robust_tracking_integral_REALTIME_M)) {
    /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
    robust_tracking_integral_REALTIME_DW.DiscreteTimeIntegrator_DSTATE +=
      robust_tracking_integral_REALTIME_P.DiscreteTimeIntegrator_gainval *
      robust_tracking_integral_REALTIME_B.volt2deg;
  }

  /* End of Update for SubSystem: '<S5>/Average' */

  /* Update for Enabled SubSystem: '<Root>/State-space Controller1' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (robust_tracking_integral_REALTIME_DW.StatespaceController1_MODE &&
      rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
    /* Update for Delay: '<S4>/Delay1' */
    robust_tracking_integral_REALTIME_DW.Delay1_DSTATE[0] =
      robust_tracking_integral_REALTIME_B.TmpSignalConversionAtDelay1Inport1[0];
    robust_tracking_integral_REALTIME_DW.Delay1_DSTATE[1] =
      robust_tracking_integral_REALTIME_B.TmpSignalConversionAtDelay1Inport1[1];
    robust_tracking_integral_REALTIME_DW.Delay1_DSTATE[2] =
      robust_tracking_integral_REALTIME_B.TmpSignalConversionAtDelay1Inport1[2];
    robust_tracking_integral_REALTIME_DW.Delay1_DSTATE[3] =
      robust_tracking_integral_REALTIME_B.TmpSignalConversionAtDelay1Inport1[3];

    /* Update for Delay: '<S4>/Delay' */
    robust_tracking_integral_REALTIME_DW.Delay_DSTATE =
      robust_tracking_integral_REALTIME_B.K_w;
  }

  /* End of Update for SubSystem: '<Root>/State-space Controller1' */
  if (rtmIsMajorTimeStep(robust_tracking_integral_REALTIME_M)) {
    rt_ertODEUpdateContinuousStates
      (&robust_tracking_integral_REALTIME_M->solverInfo);
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
  if (!(++robust_tracking_integral_REALTIME_M->Timing.clockTick0)) {
    ++robust_tracking_integral_REALTIME_M->Timing.clockTickH0;
  }

  robust_tracking_integral_REALTIME_M->Timing.t[0] = rtsiGetSolverStopTime
    (&robust_tracking_integral_REALTIME_M->solverInfo);

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
    if (!(++robust_tracking_integral_REALTIME_M->Timing.clockTick1)) {
      ++robust_tracking_integral_REALTIME_M->Timing.clockTickH1;
    }

    robust_tracking_integral_REALTIME_M->Timing.t[1] =
      robust_tracking_integral_REALTIME_M->Timing.clockTick1 *
      robust_tracking_integral_REALTIME_M->Timing.stepSize1 +
      robust_tracking_integral_REALTIME_M->Timing.clockTickH1 *
      robust_tracking_integral_REALTIME_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void robust_tracking_integral_REALTIME_derivatives(void)
{
  XDot_robust_tracking_integral_REALTIME_T *_rtXdot;
  _rtXdot = ((XDot_robust_tracking_integral_REALTIME_T *)
             robust_tracking_integral_REALTIME_M->derivs);

  /* Derivatives for TransferFcn: '<S3>/High-pass filter' */
  _rtXdot->Highpassfilter_CSTATE[0] = 0.0;
  _rtXdot->Highpassfilter_CSTATE[0] +=
    robust_tracking_integral_REALTIME_P.Highpassfilter_A[0] *
    robust_tracking_integral_REALTIME_X.Highpassfilter_CSTATE[0];
  _rtXdot->Highpassfilter_CSTATE[1] = 0.0;
  _rtXdot->Highpassfilter_CSTATE[0] +=
    robust_tracking_integral_REALTIME_P.Highpassfilter_A[1] *
    robust_tracking_integral_REALTIME_X.Highpassfilter_CSTATE[1];
  _rtXdot->Highpassfilter_CSTATE[1] +=
    robust_tracking_integral_REALTIME_X.Highpassfilter_CSTATE[0];
  _rtXdot->Highpassfilter_CSTATE[0] += robust_tracking_integral_REALTIME_B.th_h;

  /* Derivatives for TransferFcn: '<S3>/High-pass filter1' */
  _rtXdot->Highpassfilter1_CSTATE[0] = 0.0;
  _rtXdot->Highpassfilter1_CSTATE[0] +=
    robust_tracking_integral_REALTIME_P.Highpassfilter1_A[0] *
    robust_tracking_integral_REALTIME_X.Highpassfilter1_CSTATE[0];
  _rtXdot->Highpassfilter1_CSTATE[1] = 0.0;
  _rtXdot->Highpassfilter1_CSTATE[0] +=
    robust_tracking_integral_REALTIME_P.Highpassfilter1_A[1] *
    robust_tracking_integral_REALTIME_X.Highpassfilter1_CSTATE[1];
  _rtXdot->Highpassfilter1_CSTATE[1] +=
    robust_tracking_integral_REALTIME_X.Highpassfilter1_CSTATE[0];
  _rtXdot->Highpassfilter1_CSTATE[0] += robust_tracking_integral_REALTIME_B.Sum;

  /* Derivatives for Enabled SubSystem: '<Root>/State-space Controller1' */
  if (robust_tracking_integral_REALTIME_DW.StatespaceController1_MODE) {
    /* Derivatives for TransferFcn: '<S4>/High-pass filter1' */
    _rtXdot->Highpassfilter1_CSTATE_k = 0.0;
    _rtXdot->Highpassfilter1_CSTATE_k +=
      -robust_tracking_integral_REALTIME_P.Highpassfilter1_Denominator[1] /
      robust_tracking_integral_REALTIME_P.Highpassfilter1_Denominator[0] *
      robust_tracking_integral_REALTIME_X.Highpassfilter1_CSTATE_k;
    _rtXdot->Highpassfilter1_CSTATE_k +=
      robust_tracking_integral_REALTIME_B.Sum6;
  } else {
    ((XDot_robust_tracking_integral_REALTIME_T *)
      robust_tracking_integral_REALTIME_M->derivs)->Highpassfilter1_CSTATE_k =
      0.0;
  }

  /* End of Derivatives for SubSystem: '<Root>/State-space Controller1' */
}

/* Model initialize function */
void robust_tracking_integral_REALTIME_initialize(void)
{
  /* Start for Enabled SubSystem: '<S5>/Average' */
  robust_tracking_integral_REALTIME_DW.Average_MODE = false;

  /* End of Start for SubSystem: '<S5>/Average' */

  /* Start for Enabled SubSystem: '<Root>/State-space Controller1' */
  robust_tracking_integral_REALTIME_DW.StatespaceController1_MODE = false;

  /* End of Start for SubSystem: '<Root>/State-space Controller1' */

  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        robust_tracking_integral_REALTIME_P.AnalogOutput_RangeMode;
      parm.rangeidx = robust_tracking_integral_REALTIME_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &robust_tracking_integral_REALTIME_P.AnalogOutput_Channels,
                     &robust_tracking_integral_REALTIME_P.AnalogOutput_InitialValue,
                     &parm);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = robust_tracking_integral_REALTIME_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &robust_tracking_integral_REALTIME_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for TransferFcn: '<S3>/High-pass filter' */
  robust_tracking_integral_REALTIME_X.Highpassfilter_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/High-pass filter1' */
  robust_tracking_integral_REALTIME_X.Highpassfilter1_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/High-pass filter' */
  robust_tracking_integral_REALTIME_X.Highpassfilter_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/High-pass filter1' */
  robust_tracking_integral_REALTIME_X.Highpassfilter1_CSTATE[1] = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S5>/Average' */
  /* InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  robust_tracking_integral_REALTIME_DW.DiscreteTimeIntegrator_DSTATE =
    robust_tracking_integral_REALTIME_P.DiscreteTimeIntegrator_IC;

  /* SystemInitialize for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' incorporates:
   *  Outport: '<S6>/Out'
   */
  robust_tracking_integral_REALTIME_B.DiscreteTimeIntegrator =
    robust_tracking_integral_REALTIME_P.Out_Y0;

  /* End of SystemInitialize for SubSystem: '<S5>/Average' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/State-space Controller1' */
  /* InitializeConditions for Delay: '<S4>/Delay1' */
  robust_tracking_integral_REALTIME_DW.Delay1_DSTATE[0] =
    robust_tracking_integral_REALTIME_P.Delay1_InitialCondition;
  robust_tracking_integral_REALTIME_DW.Delay1_DSTATE[1] =
    robust_tracking_integral_REALTIME_P.Delay1_InitialCondition;
  robust_tracking_integral_REALTIME_DW.Delay1_DSTATE[2] =
    robust_tracking_integral_REALTIME_P.Delay1_InitialCondition;
  robust_tracking_integral_REALTIME_DW.Delay1_DSTATE[3] =
    robust_tracking_integral_REALTIME_P.Delay1_InitialCondition;

  /* InitializeConditions for TransferFcn: '<S4>/High-pass filter1' */
  robust_tracking_integral_REALTIME_X.Highpassfilter1_CSTATE_k = 0.0;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  robust_tracking_integral_REALTIME_DW.Delay_DSTATE =
    robust_tracking_integral_REALTIME_P.Delay_InitialCondition;

  /* SystemInitialize for Saturate: '<S4>/Saturation1' incorporates:
   *  Outport: '<S4>/u[V]'
   */
  robust_tracking_integral_REALTIME_B.Saturation1 =
    robust_tracking_integral_REALTIME_P.uV_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/State-space Controller1' */
}

/* Model terminate function */
void robust_tracking_integral_REALTIME_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        robust_tracking_integral_REALTIME_P.AnalogOutput_RangeMode;
      parm.rangeidx = robust_tracking_integral_REALTIME_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &robust_tracking_integral_REALTIME_P.AnalogOutput_Channels,
                     &robust_tracking_integral_REALTIME_P.AnalogOutput_FinalValue,
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
  robust_tracking_integral_REALTIME_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  robust_tracking_integral_REALTIME_update();
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
  robust_tracking_integral_REALTIME_initialize();
}

void MdlTerminate(void)
{
  robust_tracking_integral_REALTIME_terminate();
}

/* Registration function */
RT_MODEL_robust_tracking_integral_REALTIME_T *robust_tracking_integral_REALTIME
  (void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  robust_tracking_integral_REALTIME_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)robust_tracking_integral_REALTIME_M, 0,
                sizeof(RT_MODEL_robust_tracking_integral_REALTIME_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&robust_tracking_integral_REALTIME_M->solverInfo,
                          &robust_tracking_integral_REALTIME_M->Timing.simTimeStep);
    rtsiSetTPtr(&robust_tracking_integral_REALTIME_M->solverInfo, &rtmGetTPtr
                (robust_tracking_integral_REALTIME_M));
    rtsiSetStepSizePtr(&robust_tracking_integral_REALTIME_M->solverInfo,
                       &robust_tracking_integral_REALTIME_M->Timing.stepSize0);
    rtsiSetdXPtr(&robust_tracking_integral_REALTIME_M->solverInfo,
                 &robust_tracking_integral_REALTIME_M->derivs);
    rtsiSetContStatesPtr(&robust_tracking_integral_REALTIME_M->solverInfo,
                         (real_T **)
                         &robust_tracking_integral_REALTIME_M->contStates);
    rtsiSetNumContStatesPtr(&robust_tracking_integral_REALTIME_M->solverInfo,
      &robust_tracking_integral_REALTIME_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr
      (&robust_tracking_integral_REALTIME_M->solverInfo,
       &robust_tracking_integral_REALTIME_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&robust_tracking_integral_REALTIME_M->solverInfo,
       &robust_tracking_integral_REALTIME_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&robust_tracking_integral_REALTIME_M->solverInfo,
       &robust_tracking_integral_REALTIME_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&robust_tracking_integral_REALTIME_M->solverInfo,
                          (&rtmGetErrorStatus
      (robust_tracking_integral_REALTIME_M)));
    rtsiSetRTModelPtr(&robust_tracking_integral_REALTIME_M->solverInfo,
                      robust_tracking_integral_REALTIME_M);
  }

  rtsiSetSimTimeStep(&robust_tracking_integral_REALTIME_M->solverInfo,
                     MAJOR_TIME_STEP);
  robust_tracking_integral_REALTIME_M->intgData.y =
    robust_tracking_integral_REALTIME_M->odeY;
  robust_tracking_integral_REALTIME_M->intgData.f[0] =
    robust_tracking_integral_REALTIME_M->odeF[0];
  robust_tracking_integral_REALTIME_M->intgData.f[1] =
    robust_tracking_integral_REALTIME_M->odeF[1];
  robust_tracking_integral_REALTIME_M->intgData.f[2] =
    robust_tracking_integral_REALTIME_M->odeF[2];
  robust_tracking_integral_REALTIME_M->contStates = ((real_T *)
    &robust_tracking_integral_REALTIME_X);
  rtsiSetSolverData(&robust_tracking_integral_REALTIME_M->solverInfo, (void *)
                    &robust_tracking_integral_REALTIME_M->intgData);
  rtsiSetSolverName(&robust_tracking_integral_REALTIME_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      robust_tracking_integral_REALTIME_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    robust_tracking_integral_REALTIME_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    robust_tracking_integral_REALTIME_M->Timing.sampleTimes =
      (&robust_tracking_integral_REALTIME_M->Timing.sampleTimesArray[0]);
    robust_tracking_integral_REALTIME_M->Timing.offsetTimes =
      (&robust_tracking_integral_REALTIME_M->Timing.offsetTimesArray[0]);

    /* task periods */
    robust_tracking_integral_REALTIME_M->Timing.sampleTimes[0] = (0.0);
    robust_tracking_integral_REALTIME_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    robust_tracking_integral_REALTIME_M->Timing.offsetTimes[0] = (0.0);
    robust_tracking_integral_REALTIME_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(robust_tracking_integral_REALTIME_M,
             &robust_tracking_integral_REALTIME_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      robust_tracking_integral_REALTIME_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    robust_tracking_integral_REALTIME_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(robust_tracking_integral_REALTIME_M, 5.0);
  robust_tracking_integral_REALTIME_M->Timing.stepSize0 = 0.001;
  robust_tracking_integral_REALTIME_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  robust_tracking_integral_REALTIME_M->Sizes.checksums[0] = (158781812U);
  robust_tracking_integral_REALTIME_M->Sizes.checksums[1] = (3675784289U);
  robust_tracking_integral_REALTIME_M->Sizes.checksums[2] = (3896140806U);
  robust_tracking_integral_REALTIME_M->Sizes.checksums[3] = (2839796566U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    robust_tracking_integral_REALTIME_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &robust_tracking_integral_REALTIME_DW.Average_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &robust_tracking_integral_REALTIME_DW.StatespaceController1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(robust_tracking_integral_REALTIME_M->extModeInfo,
      &robust_tracking_integral_REALTIME_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(robust_tracking_integral_REALTIME_M->extModeInfo,
                        robust_tracking_integral_REALTIME_M->Sizes.checksums);
    rteiSetTPtr(robust_tracking_integral_REALTIME_M->extModeInfo, rtmGetTPtr
                (robust_tracking_integral_REALTIME_M));
  }

  robust_tracking_integral_REALTIME_M->solverInfoPtr =
    (&robust_tracking_integral_REALTIME_M->solverInfo);
  robust_tracking_integral_REALTIME_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&robust_tracking_integral_REALTIME_M->solverInfo, 0.001);
  rtsiSetSolverMode(&robust_tracking_integral_REALTIME_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  robust_tracking_integral_REALTIME_M->blockIO = ((void *)
    &robust_tracking_integral_REALTIME_B);
  (void) memset(((void *) &robust_tracking_integral_REALTIME_B), 0,
                sizeof(B_robust_tracking_integral_REALTIME_T));

  /* parameters */
  robust_tracking_integral_REALTIME_M->defaultParam = ((real_T *)
    &robust_tracking_integral_REALTIME_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &robust_tracking_integral_REALTIME_X;
    robust_tracking_integral_REALTIME_M->contStates = (x);
    (void) memset((void *)&robust_tracking_integral_REALTIME_X, 0,
                  sizeof(X_robust_tracking_integral_REALTIME_T));
  }

  /* states (dwork) */
  robust_tracking_integral_REALTIME_M->dwork = ((void *)
    &robust_tracking_integral_REALTIME_DW);
  (void) memset((void *)&robust_tracking_integral_REALTIME_DW, 0,
                sizeof(DW_robust_tracking_integral_REALTIME_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    robust_tracking_integral_REALTIME_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  robust_tracking_integral_REALTIME_M->Sizes.numContStates = (5);/* Number of continuous states */
  robust_tracking_integral_REALTIME_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  robust_tracking_integral_REALTIME_M->Sizes.numY = (0);/* Number of model outputs */
  robust_tracking_integral_REALTIME_M->Sizes.numU = (0);/* Number of model inputs */
  robust_tracking_integral_REALTIME_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  robust_tracking_integral_REALTIME_M->Sizes.numSampTimes = (2);/* Number of sample times */
  robust_tracking_integral_REALTIME_M->Sizes.numBlocks = (52);/* Number of blocks */
  robust_tracking_integral_REALTIME_M->Sizes.numBlockIO = (19);/* Number of block outputs */
  robust_tracking_integral_REALTIME_M->Sizes.numBlockPrms = (57);/* Sum of parameter "widths" */
  return robust_tracking_integral_REALTIME_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
