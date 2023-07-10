/*
 * nominal_tracking_augmentedState_REALTIME.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "nominal_tracking_augmentedState_REALTIME".
 *
 * Model version              : 1.8
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon May 17 11:50:16 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "nominal_tracking_augmentedState_REALTIME.h"
#include "nominal_tracking_augmentedState_REALTIME_private.h"
#include "nominal_tracking_augmentedState_REALTIME_dt.h"

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
B_nominal_tracking_augmentedState_REALTIME_T
  nominal_tracking_augmentedState_REALTIME_B;

/* Continuous states */
X_nominal_tracking_augmentedState_REALTIME_T
  nominal_tracking_augmentedState_REALTIME_X;

/* Block states (default storage) */
DW_nominal_tracking_augmentedState_REALTIME_T
  nominal_tracking_augmentedState_REALTIME_DW;

/* Real-time model */
static RT_MODEL_nominal_tracking_augmentedState_REALTIME_T
  nominal_tracking_augmentedState_REALTIME_M_;
RT_MODEL_nominal_tracking_augmentedState_REALTIME_T *const
  nominal_tracking_augmentedState_REALTIME_M =
  &nominal_tracking_augmentedState_REALTIME_M_;

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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  nominal_tracking_augmentedState_REALTIME_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  nominal_tracking_augmentedState_REALTIME_output();
  nominal_tracking_augmentedState_REALTIME_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  nominal_tracking_augmentedState_REALTIME_output();
  nominal_tracking_augmentedState_REALTIME_derivatives();

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
void nominal_tracking_augmentedState_REALTIME_output(void)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput[2];
  real_T rtb_deg2rad;
  real_T tmp[6];
  real_T rtb_rpm2rads;
  real_T rtb_thl_ref;
  real_T tmp_0;
  int32_T i;
  if (rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
    /* set solver stop time */
    if (!(nominal_tracking_augmentedState_REALTIME_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime
        (&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
         ((nominal_tracking_augmentedState_REALTIME_M->Timing.clockTickH0 + 1) *
          nominal_tracking_augmentedState_REALTIME_M->Timing.stepSize0 *
          4294967296.0));
    } else {
      rtsiSetSolverStopTime
        (&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
         ((nominal_tracking_augmentedState_REALTIME_M->Timing.clockTick0 + 1) *
          nominal_tracking_augmentedState_REALTIME_M->Timing.stepSize0 +
          nominal_tracking_augmentedState_REALTIME_M->Timing.clockTickH0 *
          nominal_tracking_augmentedState_REALTIME_M->Timing.stepSize0 *
          4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
    nominal_tracking_augmentedState_REALTIME_M->Timing.t[0] = rtsiGetT
      (&nominal_tracking_augmentedState_REALTIME_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(nominal_tracking_augmentedState_REALTIME_DW.Average_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (nominal_tracking_augmentedState_REALTIME_DW.StatespaceController_SubsysRanBC);
  if (rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
    /* Step: '<Root>/Step' */
    if (nominal_tracking_augmentedState_REALTIME_M->Timing.t[1] <
        nominal_tracking_augmentedState_REALTIME_P.Step_Time) {
      rtb_thl_ref = nominal_tracking_augmentedState_REALTIME_P.Step_Y0;
    } else {
      rtb_thl_ref = nominal_tracking_augmentedState_REALTIME_P.step_size;
    }

    /* End of Step: '<Root>/Step' */

    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter =
        nominal_tracking_augmentedState_REALTIME_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &nominal_tracking_augmentedState_REALTIME_P.EncoderInput_Channels,
                     &rtb_deg2rad, &parm);
    }

    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        nominal_tracking_augmentedState_REALTIME_P.AnalogInput_RangeMode;
      parm.rangeidx =
        nominal_tracking_augmentedState_REALTIME_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                     nominal_tracking_augmentedState_REALTIME_P.AnalogInput_Channels,
                     &rtb_AnalogInput[0], &parm);
    }

    /* Gain: '<Root>/pulse2deg' */
    nominal_tracking_augmentedState_REALTIME_B.th_h =
      nominal_tracking_augmentedState_REALTIME_P.sens.enc.pulse2deg *
      rtb_deg2rad;

    /* Gain: '<S5>/deg2rad' incorporates:
     *  Sum: '<S1>/Subtract'
     */
    rtb_deg2rad = rtb_AnalogInput[0] - rtb_AnalogInput[1];

    /* Gain: '<S1>/volt2deg' */
    nominal_tracking_augmentedState_REALTIME_B.volt2deg =
      nominal_tracking_augmentedState_REALTIME_P.sens.pot2.V2deg * rtb_deg2rad;
  }

  /* Clock: '<S6>/Clock' incorporates:
   *  Clock: '<S3>/Clock'
   */
  rtb_rpm2rads = nominal_tracking_augmentedState_REALTIME_M->Timing.t[0];

  /* Outputs for Enabled SubSystem: '<S6>/Average' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
    /* Logic: '<S8>/AND' incorporates:
     *  Clock: '<S6>/Clock'
     *  Constant: '<S8>/Lower Limit'
     *  Constant: '<S8>/Upper Limit'
     *  RelationalOperator: '<S8>/Lower Test'
     *  RelationalOperator: '<S8>/Upper Test'
     */
    nominal_tracking_augmentedState_REALTIME_DW.Average_MODE =
      ((nominal_tracking_augmentedState_REALTIME_P.IntervalTest_lowlimit <=
        rtb_rpm2rads) && (rtb_rpm2rads <=
                          nominal_tracking_augmentedState_REALTIME_P.IntervalTest_uplimit));
  }

  if (nominal_tracking_augmentedState_REALTIME_DW.Average_MODE) {
    if (rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
      /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
      nominal_tracking_augmentedState_REALTIME_B.DiscreteTimeIntegrator =
        nominal_tracking_augmentedState_REALTIME_DW.DiscreteTimeIntegrator_DSTATE;
    }

    if (rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
      srUpdateBC(nominal_tracking_augmentedState_REALTIME_DW.Average_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S6>/Average' */

  /* Gain: '<S4>/degs2rpm' incorporates:
   *  TransferFcn: '<S4>/High-pass filter'
   */
  nominal_tracking_augmentedState_REALTIME_B.degs2rpm =
    (nominal_tracking_augmentedState_REALTIME_P.Highpassfilter_C[0] *
     nominal_tracking_augmentedState_REALTIME_X.Highpassfilter_CSTATE[0] +
     nominal_tracking_augmentedState_REALTIME_P.Highpassfilter_C[1] *
     nominal_tracking_augmentedState_REALTIME_X.Highpassfilter_CSTATE[1]) *
    nominal_tracking_augmentedState_REALTIME_P.degs2rpm;

  /* Gain: '<S4>/degs2rpm1' incorporates:
   *  TransferFcn: '<S4>/High-pass filter1'
   */
  nominal_tracking_augmentedState_REALTIME_B.degs2rpm1 =
    (nominal_tracking_augmentedState_REALTIME_P.Highpassfilter1_C[0] *
     nominal_tracking_augmentedState_REALTIME_X.Highpassfilter1_CSTATE[0] +
     nominal_tracking_augmentedState_REALTIME_P.Highpassfilter1_C[1] *
     nominal_tracking_augmentedState_REALTIME_X.Highpassfilter1_CSTATE[1]) *
    nominal_tracking_augmentedState_REALTIME_P.degs2rpm;

  /* Logic: '<S10>/AND' incorporates:
   *  Constant: '<S10>/Lower Limit'
   *  Constant: '<S10>/Upper Limit'
   *  RelationalOperator: '<S10>/Lower Test'
   *  RelationalOperator: '<S10>/Upper Test'
   */
  nominal_tracking_augmentedState_REALTIME_B.AND_l =
    ((nominal_tracking_augmentedState_REALTIME_P.IntervalTest_lowlimit_k <=
      rtb_rpm2rads) && (rtb_rpm2rads <=
                        nominal_tracking_augmentedState_REALTIME_P.IntervalTest_uplimit_o));
  if (rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
    /* Sum: '<S1>/Sum' */
    nominal_tracking_augmentedState_REALTIME_B.Sum =
      nominal_tracking_augmentedState_REALTIME_B.volt2deg -
      nominal_tracking_augmentedState_REALTIME_B.DiscreteTimeIntegrator;

    /* SignalConversion generated from: '<S5>/Enable' */
    nominal_tracking_augmentedState_REALTIME_B.HiddenBuf_InsertedFor_StatespaceController_at_inport_5
      = nominal_tracking_augmentedState_REALTIME_B.AND_l;

    /* Outputs for Enabled SubSystem: '<Root>/State-space Controller' incorporates:
     *  EnablePort: '<S5>/Enable'
     */
    if (rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
      nominal_tracking_augmentedState_REALTIME_DW.StatespaceController_MODE =
        nominal_tracking_augmentedState_REALTIME_B.HiddenBuf_InsertedFor_StatespaceController_at_inport_5;
    }

    /* End of Outputs for SubSystem: '<Root>/State-space Controller' */
  }

  /* Outputs for Enabled SubSystem: '<Root>/State-space Controller' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (nominal_tracking_augmentedState_REALTIME_DW.StatespaceController_MODE) {
    if (rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
      /* Gain: '<S5>/deg2rad' */
      rtb_deg2rad = nominal_tracking_augmentedState_REALTIME_P.deg2rad *
        rtb_thl_ref;

      /* Gain: '<S5>/Input feedforward' */
      nominal_tracking_augmentedState_REALTIME_B.Inputfeedforward =
        nominal_tracking_augmentedState_REALTIME_P.N_u * rtb_deg2rad;
      for (i = 0; i < 6; i++) {
        /* Gain: '<S5>/State feedforward	' */
        nominal_tracking_augmentedState_REALTIME_B.Statefeedforward[i] =
          rtb_deg2rad * nominal_tracking_augmentedState_REALTIME_P.N_x[i];
      }

      /* Gain: '<S5>/deg2rad1' */
      nominal_tracking_augmentedState_REALTIME_B.deg2rad1 =
        nominal_tracking_augmentedState_REALTIME_P.deg2rad *
        nominal_tracking_augmentedState_REALTIME_B.th_h;

      /* Gain: '<S5>/deg2rad2' */
      nominal_tracking_augmentedState_REALTIME_B.deg2rad2 =
        nominal_tracking_augmentedState_REALTIME_P.deg2rad *
        nominal_tracking_augmentedState_REALTIME_B.Sum;
    }

    /* Gain: '<S5>/rpm2rads' */
    rtb_rpm2rads = nominal_tracking_augmentedState_REALTIME_P.rpm2rads *
      nominal_tracking_augmentedState_REALTIME_B.degs2rpm;

    /* Gain: '<S5>/rpm2rads2' */
    rtb_thl_ref = nominal_tracking_augmentedState_REALTIME_P.rpm2rads *
      nominal_tracking_augmentedState_REALTIME_B.degs2rpm1;

    /* Sum: '<S5>/Sum2' incorporates:
     *  StateSpace: '<S5>/State-Space'
     */
    tmp[0] = nominal_tracking_augmentedState_REALTIME_B.deg2rad1;
    tmp[1] = nominal_tracking_augmentedState_REALTIME_B.deg2rad2;
    tmp[2] = rtb_rpm2rads;
    tmp[3] = rtb_thl_ref;
    tmp[4] = nominal_tracking_augmentedState_REALTIME_P.StateSpace_C[0] *
      nominal_tracking_augmentedState_REALTIME_X.StateSpace_CSTATE[0] +
      nominal_tracking_augmentedState_REALTIME_P.StateSpace_C[2] *
      nominal_tracking_augmentedState_REALTIME_X.StateSpace_CSTATE[1];
    tmp[5] = nominal_tracking_augmentedState_REALTIME_P.StateSpace_C[1] *
      nominal_tracking_augmentedState_REALTIME_X.StateSpace_CSTATE[0] +
      nominal_tracking_augmentedState_REALTIME_P.StateSpace_C[3] *
      nominal_tracking_augmentedState_REALTIME_X.StateSpace_CSTATE[1];

    /* Gain: '<S5>/State feedback' incorporates:
     *  Gain: '<S5>/State feedforward	'
     *  Sum: '<S5>/Sum2'
     */
    tmp_0 = 0.0;
    for (i = 0; i < 6; i++) {
      tmp_0 += (nominal_tracking_augmentedState_REALTIME_B.Statefeedforward[i] -
                tmp[i]) *
        nominal_tracking_augmentedState_REALTIME_P.Statefeedback_Gain[i];
    }

    /* Sum: '<S5>/Sum' incorporates:
     *  Gain: '<S5>/State feedback'
     */
    nominal_tracking_augmentedState_REALTIME_B.Sum_a =
      nominal_tracking_augmentedState_REALTIME_B.Inputfeedforward + tmp_0;

    /* Saturate: '<S5>/Saturation' */
    if (nominal_tracking_augmentedState_REALTIME_B.Sum_a >
        nominal_tracking_augmentedState_REALTIME_P.Saturation_UpperSat) {
      /* Saturate: '<S5>/Saturation' */
      nominal_tracking_augmentedState_REALTIME_B.Saturation =
        nominal_tracking_augmentedState_REALTIME_P.Saturation_UpperSat;
    } else if (nominal_tracking_augmentedState_REALTIME_B.Sum_a <
               nominal_tracking_augmentedState_REALTIME_P.Saturation_LowerSat) {
      /* Saturate: '<S5>/Saturation' */
      nominal_tracking_augmentedState_REALTIME_B.Saturation =
        nominal_tracking_augmentedState_REALTIME_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S5>/Saturation' */
      nominal_tracking_augmentedState_REALTIME_B.Saturation =
        nominal_tracking_augmentedState_REALTIME_B.Sum_a;
    }

    /* End of Saturate: '<S5>/Saturation' */
    if (rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
    }

    /* SignalConversion generated from: '<S5>/State-Space' */
    nominal_tracking_augmentedState_REALTIME_B.x[0] =
      nominal_tracking_augmentedState_REALTIME_B.deg2rad1;
    nominal_tracking_augmentedState_REALTIME_B.x[1] =
      nominal_tracking_augmentedState_REALTIME_B.deg2rad2;
    nominal_tracking_augmentedState_REALTIME_B.x[2] = rtb_rpm2rads;
    nominal_tracking_augmentedState_REALTIME_B.x[3] = rtb_thl_ref;
    if (rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
      srUpdateBC
        (nominal_tracking_augmentedState_REALTIME_DW.StatespaceController_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/State-space Controller' */
  if (rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_RangeMode;
        parm.rangeidx =
          nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_Channels,
                       ((real_T*)
                        (&nominal_tracking_augmentedState_REALTIME_B.Saturation)),
                       &parm);
      }
    }

    /* Sum: '<Root>/Sum' */
    nominal_tracking_augmentedState_REALTIME_B.th_b =
      nominal_tracking_augmentedState_REALTIME_B.th_h +
      nominal_tracking_augmentedState_REALTIME_B.Sum;

    /* ToAsyncQueueBlock generated from: '<Root>/Sum' */
    if (rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
      {
        double time = nominal_tracking_augmentedState_REALTIME_M->Timing.t[1];
        void *pData = (void *)&nominal_tracking_augmentedState_REALTIME_B.th_b;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1971359627U, time, pData, size);
      }
    }
  }
}

/* Model update function */
void nominal_tracking_augmentedState_REALTIME_update(void)
{
  /* Update for Enabled SubSystem: '<S6>/Average' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (nominal_tracking_augmentedState_REALTIME_DW.Average_MODE &&
      rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    nominal_tracking_augmentedState_REALTIME_DW.DiscreteTimeIntegrator_DSTATE +=
      nominal_tracking_augmentedState_REALTIME_P.DiscreteTimeIntegrator_gainval *
      nominal_tracking_augmentedState_REALTIME_B.volt2deg;
  }

  /* End of Update for SubSystem: '<S6>/Average' */
  if (rtmIsMajorTimeStep(nominal_tracking_augmentedState_REALTIME_M)) {
    rt_ertODEUpdateContinuousStates
      (&nominal_tracking_augmentedState_REALTIME_M->solverInfo);
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
  if (!(++nominal_tracking_augmentedState_REALTIME_M->Timing.clockTick0)) {
    ++nominal_tracking_augmentedState_REALTIME_M->Timing.clockTickH0;
  }

  nominal_tracking_augmentedState_REALTIME_M->Timing.t[0] =
    rtsiGetSolverStopTime
    (&nominal_tracking_augmentedState_REALTIME_M->solverInfo);

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
    if (!(++nominal_tracking_augmentedState_REALTIME_M->Timing.clockTick1)) {
      ++nominal_tracking_augmentedState_REALTIME_M->Timing.clockTickH1;
    }

    nominal_tracking_augmentedState_REALTIME_M->Timing.t[1] =
      nominal_tracking_augmentedState_REALTIME_M->Timing.clockTick1 *
      nominal_tracking_augmentedState_REALTIME_M->Timing.stepSize1 +
      nominal_tracking_augmentedState_REALTIME_M->Timing.clockTickH1 *
      nominal_tracking_augmentedState_REALTIME_M->Timing.stepSize1 *
      4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void nominal_tracking_augmentedState_REALTIME_derivatives(void)
{
  XDot_nominal_tracking_augmentedState_REALTIME_T *_rtXdot;
  int_T ri;
  _rtXdot = ((XDot_nominal_tracking_augmentedState_REALTIME_T *)
             nominal_tracking_augmentedState_REALTIME_M->derivs);

  /* Derivatives for TransferFcn: '<S4>/High-pass filter' */
  _rtXdot->Highpassfilter_CSTATE[0] = 0.0;
  _rtXdot->Highpassfilter_CSTATE[0] +=
    nominal_tracking_augmentedState_REALTIME_P.Highpassfilter_A[0] *
    nominal_tracking_augmentedState_REALTIME_X.Highpassfilter_CSTATE[0];

  /* Derivatives for TransferFcn: '<S4>/High-pass filter1' */
  _rtXdot->Highpassfilter1_CSTATE[0] = 0.0;
  _rtXdot->Highpassfilter1_CSTATE[0] +=
    nominal_tracking_augmentedState_REALTIME_P.Highpassfilter1_A[0] *
    nominal_tracking_augmentedState_REALTIME_X.Highpassfilter1_CSTATE[0];

  /* Derivatives for TransferFcn: '<S4>/High-pass filter' */
  _rtXdot->Highpassfilter_CSTATE[1] = 0.0;
  _rtXdot->Highpassfilter_CSTATE[0] +=
    nominal_tracking_augmentedState_REALTIME_P.Highpassfilter_A[1] *
    nominal_tracking_augmentedState_REALTIME_X.Highpassfilter_CSTATE[1];

  /* Derivatives for TransferFcn: '<S4>/High-pass filter1' */
  _rtXdot->Highpassfilter1_CSTATE[1] = 0.0;
  _rtXdot->Highpassfilter1_CSTATE[0] +=
    nominal_tracking_augmentedState_REALTIME_P.Highpassfilter1_A[1] *
    nominal_tracking_augmentedState_REALTIME_X.Highpassfilter1_CSTATE[1];

  /* Derivatives for TransferFcn: '<S4>/High-pass filter' */
  _rtXdot->Highpassfilter_CSTATE[1] +=
    nominal_tracking_augmentedState_REALTIME_X.Highpassfilter_CSTATE[0];
  _rtXdot->Highpassfilter_CSTATE[0] +=
    nominal_tracking_augmentedState_REALTIME_B.th_h;

  /* Derivatives for TransferFcn: '<S4>/High-pass filter1' */
  _rtXdot->Highpassfilter1_CSTATE[1] +=
    nominal_tracking_augmentedState_REALTIME_X.Highpassfilter1_CSTATE[0];
  _rtXdot->Highpassfilter1_CSTATE[0] +=
    nominal_tracking_augmentedState_REALTIME_B.Sum;

  /* Derivatives for Enabled SubSystem: '<Root>/State-space Controller' */
  if (nominal_tracking_augmentedState_REALTIME_DW.StatespaceController_MODE) {
    /* Derivatives for StateSpace: '<S5>/State-Space' */
    _rtXdot->StateSpace_CSTATE[0] = 0.0;
    _rtXdot->StateSpace_CSTATE[1] = 0.0;
    _rtXdot->StateSpace_CSTATE[0] +=
      nominal_tracking_augmentedState_REALTIME_P.AQ[0] *
      nominal_tracking_augmentedState_REALTIME_X.StateSpace_CSTATE[0];
    _rtXdot->StateSpace_CSTATE[1] +=
      nominal_tracking_augmentedState_REALTIME_P.AQ[1] *
      nominal_tracking_augmentedState_REALTIME_X.StateSpace_CSTATE[0];
    _rtXdot->StateSpace_CSTATE[0] +=
      nominal_tracking_augmentedState_REALTIME_P.AQ[2] *
      nominal_tracking_augmentedState_REALTIME_X.StateSpace_CSTATE[1];
    _rtXdot->StateSpace_CSTATE[1] +=
      nominal_tracking_augmentedState_REALTIME_P.AQ[3] *
      nominal_tracking_augmentedState_REALTIME_X.StateSpace_CSTATE[1];
    for (ri = 0; ri < 2; ri++) {
      _rtXdot->StateSpace_CSTATE[ri] +=
        nominal_tracking_augmentedState_REALTIME_P.BQ[ri] *
        nominal_tracking_augmentedState_REALTIME_B.x[0];
      _rtXdot->StateSpace_CSTATE[ri] +=
        nominal_tracking_augmentedState_REALTIME_P.BQ[ri + 2] *
        nominal_tracking_augmentedState_REALTIME_B.x[1];
      _rtXdot->StateSpace_CSTATE[ri] +=
        nominal_tracking_augmentedState_REALTIME_P.BQ[ri + 4] *
        nominal_tracking_augmentedState_REALTIME_B.x[2];
      _rtXdot->StateSpace_CSTATE[ri] +=
        nominal_tracking_augmentedState_REALTIME_P.BQ[ri + 6] *
        nominal_tracking_augmentedState_REALTIME_B.x[3];
    }

    /* End of Derivatives for StateSpace: '<S5>/State-Space' */
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot_nominal_tracking_augmentedState_REALTIME_T *)
              nominal_tracking_augmentedState_REALTIME_M->derivs)
             ->StateSpace_CSTATE[0]);
      for (i=0; i < 2; i++) {
        dx[i] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<Root>/State-space Controller' */
}

/* Model initialize function */
void nominal_tracking_augmentedState_REALTIME_initialize(void)
{
  /* Start for Enabled SubSystem: '<S6>/Average' */
  nominal_tracking_augmentedState_REALTIME_DW.Average_MODE = false;

  /* End of Start for SubSystem: '<S6>/Average' */

  /* Start for Enabled SubSystem: '<Root>/State-space Controller' */
  nominal_tracking_augmentedState_REALTIME_DW.StatespaceController_MODE = false;

  /* End of Start for SubSystem: '<Root>/State-space Controller' */

  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_RangeMode;
      parm.rangeidx =
        nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_Channels,
                     &nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_InitialValue,
                     &parm);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter =
      nominal_tracking_augmentedState_REALTIME_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &nominal_tracking_augmentedState_REALTIME_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* SystemInitialize for Enabled SubSystem: '<S6>/Average' */
  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  nominal_tracking_augmentedState_REALTIME_DW.DiscreteTimeIntegrator_DSTATE =
    nominal_tracking_augmentedState_REALTIME_P.DiscreteTimeIntegrator_IC;

  /* SystemInitialize for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  Outport: '<S7>/Out'
   */
  nominal_tracking_augmentedState_REALTIME_B.DiscreteTimeIntegrator =
    nominal_tracking_augmentedState_REALTIME_P.Out_Y0;

  /* End of SystemInitialize for SubSystem: '<S6>/Average' */

  /* InitializeConditions for TransferFcn: '<S4>/High-pass filter' */
  nominal_tracking_augmentedState_REALTIME_X.Highpassfilter_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/High-pass filter1' */
  nominal_tracking_augmentedState_REALTIME_X.Highpassfilter1_CSTATE[0] = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<Root>/State-space Controller' */
  /* InitializeConditions for StateSpace: '<S5>/State-Space' */
  nominal_tracking_augmentedState_REALTIME_X.StateSpace_CSTATE[0] =
    nominal_tracking_augmentedState_REALTIME_P.StateSpace_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<Root>/State-space Controller' */

  /* InitializeConditions for TransferFcn: '<S4>/High-pass filter' */
  nominal_tracking_augmentedState_REALTIME_X.Highpassfilter_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/High-pass filter1' */
  nominal_tracking_augmentedState_REALTIME_X.Highpassfilter1_CSTATE[1] = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<Root>/State-space Controller' */
  /* InitializeConditions for StateSpace: '<S5>/State-Space' */
  nominal_tracking_augmentedState_REALTIME_X.StateSpace_CSTATE[1] =
    nominal_tracking_augmentedState_REALTIME_P.StateSpace_InitialCondition;

  /* SystemInitialize for Saturate: '<S5>/Saturation' incorporates:
   *  Outport: '<S5>/u[V]'
   */
  nominal_tracking_augmentedState_REALTIME_B.Saturation =
    nominal_tracking_augmentedState_REALTIME_P.uV_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/State-space Controller' */
}

/* Model terminate function */
void nominal_tracking_augmentedState_REALTIME_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_RangeMode;
      parm.rangeidx =
        nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_Channels,
                     &nominal_tracking_augmentedState_REALTIME_P.AnalogOutput_FinalValue,
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
  nominal_tracking_augmentedState_REALTIME_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  nominal_tracking_augmentedState_REALTIME_update();
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
  nominal_tracking_augmentedState_REALTIME_initialize();
}

void MdlTerminate(void)
{
  nominal_tracking_augmentedState_REALTIME_terminate();
}

/* Registration function */
RT_MODEL_nominal_tracking_augmentedState_REALTIME_T
  *nominal_tracking_augmentedState_REALTIME(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  nominal_tracking_augmentedState_REALTIME_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)nominal_tracking_augmentedState_REALTIME_M, 0,
                sizeof(RT_MODEL_nominal_tracking_augmentedState_REALTIME_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr
      (&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
       &nominal_tracking_augmentedState_REALTIME_M->Timing.simTimeStep);
    rtsiSetTPtr(&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
                &rtmGetTPtr(nominal_tracking_augmentedState_REALTIME_M));
    rtsiSetStepSizePtr(&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
                       &nominal_tracking_augmentedState_REALTIME_M->Timing.stepSize0);
    rtsiSetdXPtr(&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
                 &nominal_tracking_augmentedState_REALTIME_M->derivs);
    rtsiSetContStatesPtr(&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
                         (real_T **)
                         &nominal_tracking_augmentedState_REALTIME_M->contStates);
    rtsiSetNumContStatesPtr
      (&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
       &nominal_tracking_augmentedState_REALTIME_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr
      (&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
       &nominal_tracking_augmentedState_REALTIME_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
       &nominal_tracking_augmentedState_REALTIME_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
       &nominal_tracking_augmentedState_REALTIME_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr
      (&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
       (&rtmGetErrorStatus(nominal_tracking_augmentedState_REALTIME_M)));
    rtsiSetRTModelPtr(&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
                      nominal_tracking_augmentedState_REALTIME_M);
  }

  rtsiSetSimTimeStep(&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
                     MAJOR_TIME_STEP);
  nominal_tracking_augmentedState_REALTIME_M->intgData.y =
    nominal_tracking_augmentedState_REALTIME_M->odeY;
  nominal_tracking_augmentedState_REALTIME_M->intgData.f[0] =
    nominal_tracking_augmentedState_REALTIME_M->odeF[0];
  nominal_tracking_augmentedState_REALTIME_M->intgData.f[1] =
    nominal_tracking_augmentedState_REALTIME_M->odeF[1];
  nominal_tracking_augmentedState_REALTIME_M->intgData.f[2] =
    nominal_tracking_augmentedState_REALTIME_M->odeF[2];
  nominal_tracking_augmentedState_REALTIME_M->contStates = ((real_T *)
    &nominal_tracking_augmentedState_REALTIME_X);
  rtsiSetSolverData(&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
                    (void *)
                    &nominal_tracking_augmentedState_REALTIME_M->intgData);
  rtsiSetSolverName(&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
                    "ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      nominal_tracking_augmentedState_REALTIME_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    nominal_tracking_augmentedState_REALTIME_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    nominal_tracking_augmentedState_REALTIME_M->Timing.sampleTimes =
      (&nominal_tracking_augmentedState_REALTIME_M->Timing.sampleTimesArray[0]);
    nominal_tracking_augmentedState_REALTIME_M->Timing.offsetTimes =
      (&nominal_tracking_augmentedState_REALTIME_M->Timing.offsetTimesArray[0]);

    /* task periods */
    nominal_tracking_augmentedState_REALTIME_M->Timing.sampleTimes[0] = (0.0);
    nominal_tracking_augmentedState_REALTIME_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    nominal_tracking_augmentedState_REALTIME_M->Timing.offsetTimes[0] = (0.0);
    nominal_tracking_augmentedState_REALTIME_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(nominal_tracking_augmentedState_REALTIME_M,
             &nominal_tracking_augmentedState_REALTIME_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      nominal_tracking_augmentedState_REALTIME_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    nominal_tracking_augmentedState_REALTIME_M->Timing.sampleHits =
      (&mdlSampleHits[0]);
  }

  rtmSetTFinal(nominal_tracking_augmentedState_REALTIME_M, 5.0);
  nominal_tracking_augmentedState_REALTIME_M->Timing.stepSize0 = 0.001;
  nominal_tracking_augmentedState_REALTIME_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  nominal_tracking_augmentedState_REALTIME_M->Sizes.checksums[0] = (38320141U);
  nominal_tracking_augmentedState_REALTIME_M->Sizes.checksums[1] = (2484223919U);
  nominal_tracking_augmentedState_REALTIME_M->Sizes.checksums[2] = (160616621U);
  nominal_tracking_augmentedState_REALTIME_M->Sizes.checksums[3] = (389575484U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    nominal_tracking_augmentedState_REALTIME_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &nominal_tracking_augmentedState_REALTIME_DW.Average_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &nominal_tracking_augmentedState_REALTIME_DW.StatespaceController_SubsysRanBC;
    rteiSetModelMappingInfoPtr
      (nominal_tracking_augmentedState_REALTIME_M->extModeInfo,
       &nominal_tracking_augmentedState_REALTIME_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(nominal_tracking_augmentedState_REALTIME_M->extModeInfo,
                        nominal_tracking_augmentedState_REALTIME_M->Sizes.checksums);
    rteiSetTPtr(nominal_tracking_augmentedState_REALTIME_M->extModeInfo,
                rtmGetTPtr(nominal_tracking_augmentedState_REALTIME_M));
  }

  nominal_tracking_augmentedState_REALTIME_M->solverInfoPtr =
    (&nominal_tracking_augmentedState_REALTIME_M->solverInfo);
  nominal_tracking_augmentedState_REALTIME_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
                       0.001);
  rtsiSetSolverMode(&nominal_tracking_augmentedState_REALTIME_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  nominal_tracking_augmentedState_REALTIME_M->blockIO = ((void *)
    &nominal_tracking_augmentedState_REALTIME_B);
  (void) memset(((void *) &nominal_tracking_augmentedState_REALTIME_B), 0,
                sizeof(B_nominal_tracking_augmentedState_REALTIME_T));

  /* parameters */
  nominal_tracking_augmentedState_REALTIME_M->defaultParam = ((real_T *)
    &nominal_tracking_augmentedState_REALTIME_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &nominal_tracking_augmentedState_REALTIME_X;
    nominal_tracking_augmentedState_REALTIME_M->contStates = (x);
    (void) memset((void *)&nominal_tracking_augmentedState_REALTIME_X, 0,
                  sizeof(X_nominal_tracking_augmentedState_REALTIME_T));
  }

  /* states (dwork) */
  nominal_tracking_augmentedState_REALTIME_M->dwork = ((void *)
    &nominal_tracking_augmentedState_REALTIME_DW);
  (void) memset((void *)&nominal_tracking_augmentedState_REALTIME_DW, 0,
                sizeof(DW_nominal_tracking_augmentedState_REALTIME_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    nominal_tracking_augmentedState_REALTIME_M->SpecialInfo.mappingInfo =
      (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  nominal_tracking_augmentedState_REALTIME_M->Sizes.numContStates = (6);/* Number of continuous states */
  nominal_tracking_augmentedState_REALTIME_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  nominal_tracking_augmentedState_REALTIME_M->Sizes.numY = (0);/* Number of model outputs */
  nominal_tracking_augmentedState_REALTIME_M->Sizes.numU = (0);/* Number of model inputs */
  nominal_tracking_augmentedState_REALTIME_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  nominal_tracking_augmentedState_REALTIME_M->Sizes.numSampTimes = (2);/* Number of sample times */
  nominal_tracking_augmentedState_REALTIME_M->Sizes.numBlocks = (45);/* Number of blocks */
  nominal_tracking_augmentedState_REALTIME_M->Sizes.numBlockIO = (17);/* Number of block outputs */
  nominal_tracking_augmentedState_REALTIME_M->Sizes.numBlockPrms = (72);/* Sum of parameter "widths" */
  return nominal_tracking_augmentedState_REALTIME_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
