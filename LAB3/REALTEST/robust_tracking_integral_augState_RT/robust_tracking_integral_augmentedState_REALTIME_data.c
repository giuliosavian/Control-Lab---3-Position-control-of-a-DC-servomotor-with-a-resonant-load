/*
 * robust_tracking_integral_augmentedState_REALTIME_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "robust_tracking_integral_augmentedState_REALTIME".
 *
 * Model version              : 1.6
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon May 17 11:36:20 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "robust_tracking_integral_augmentedState_REALTIME.h"
#include "robust_tracking_integral_augmentedState_REALTIME_private.h"

/* Block parameters (default storage) */
P_robust_tracking_integral_augmentedState_REALTIME_T
  robust_tracking_integral_augmentedState_REALTIME_P = {
  /* Variable: sens
   * Referenced by:
   *   '<Root>/pulse2deg'
   *   '<S1>/volt2deg'
   */
  {
    {
      0.5
    },

    {
      2000.0,
      0.087890625,
      0.0031415926535897933,
      5.5555555555555554,
      318.3098861837907
    },

    {
      {
        10000.0,
        5.0,
        345.0,
        6.0213859193804371
      },
      0.014492753623188406,
      0.83037361613162786,
      69.0,
      1.2042771838760873
    },

    {
      {
        10000.0,
        5.0,
        340.0,
        5.9341194567807207
      },
      0.014705882352941176,
      0.84258499283944588,
      68.0,
      1.1868238913561442,

      {
        3.5e-7
      }
    }
  },

  /* Variable: ctrl
   * Referenced by: '<S4>/K_w'
   */
  {
    4.0,
    9.86262802627925,
    0.68225121111354625,
    0.010139285364260639,
    0.16999999999999998,

    { -0.079458890840918533, -0.025683247405589631 },
    11.9751079915269,
    0.369623895805272,
    11.166348532928719,
    0.074009626034035977,
    0.29603850413614391,
    37.719243871714312,
    0.82641727908776075,
    0.01
  },

  /* Variable: AQ
   * Referenced by: '<S4>/State-Space'
   */
  { 0.0, -1637.9332677890661, 1.0, 0.0 },

  /* Variable: BQ
   * Referenced by: '<S4>/State-Space'
   */
  { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: Ki
   * Referenced by: '<S4>/High-pass filter1'
   */
  31.622776601682489,

  /* Variable: N_u
   * Referenced by: '<S4>/Input feedforward1'
   */
  0.0,

  /* Variable: N_x
   * Referenced by: '<S4>/State feedforward	1'
   */
  { 1.0, -0.0, -0.0, 0.0, -0.0, -0.0 },

  /* Variable: deg2rad
   * Referenced by:
   *   '<S4>/deg2rad1'
   *   '<S4>/deg2rad2'
   *   '<S4>/deg2rad3'
   *   '<S4>/deg2rads1'
   */
  0.017453292519943295,

  /* Variable: degs2rpm
   * Referenced by:
   *   '<S3>/degs2rpm'
   *   '<S3>/degs2rpm1'
   */
  0.16666666666666666,

  /* Variable: rpm2rads
   * Referenced by:
   *   '<S4>/rpm2rads'
   *   '<S4>/rpm2rads2'
   */
  0.10471975511965977,

  /* Variable: step_size
   * Referenced by: '<Root>/Step1'
   */
  50.0,

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: IntervalTest_lowlimit
   * Referenced by: '<S7>/Lower Limit'
   */
  0.2,

  /* Mask Parameter: IntervalTest_lowlimit_o
   * Referenced by: '<S8>/Lower Limit'
   */
  0.7,

  /* Mask Parameter: IntervalTest_uplimit
   * Referenced by: '<S7>/Upper Limit'
   */
  0.7,

  /* Mask Parameter: IntervalTest_uplimit_m
   * Referenced by: '<S8>/Upper Limit'
   */
  60.0,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  0,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<Root>/Analog Input'
   */
  { 2, 3 },

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<Root>/Analog Input'
   */
  1,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Computed Parameter: Out_Y0
   * Referenced by: '<S6>/Out'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  0.002,

  /* Expression: 0
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: uV_Y0
   * Referenced by: '<S4>/u[V]'
   */
  0.0,

  /* Expression: eye(2)
   * Referenced by: '<S4>/State-Space'
   */
  { 1.0, 0.0, 0.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S4>/State-Space'
   */
  0.0,

  /* Expression: [KE(2),KE(3),KE(4),KE(5),KE(6), KE(7)].'
   * Referenced by: '<S4>/State feedback1'
   */
  { 116.82494536193985, -108.87422845594537, 7.5066674825054562,
    3.6237067657220843, 3350.2641637013949, -4046.2921267554107 },

  /* Expression: [1 0]
   * Referenced by: '<S4>/High-pass filter1'
   */
  { 1.0, 0.0 },

  /* Expression: 10
   * Referenced by: '<S4>/Saturation1'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S4>/Saturation1'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<S4>/Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step1'
   */
  0.0,

  /* Computed Parameter: Highpassfilter_A
   * Referenced by: '<S3>/High-pass filter'
   */
  { -444.2882938158366, -98696.044010893587 },

  /* Computed Parameter: Highpassfilter_C
   * Referenced by: '<S3>/High-pass filter'
   */
  { 98696.044010893587, 0.0 },

  /* Computed Parameter: Highpassfilter1_A
   * Referenced by: '<S3>/High-pass filter1'
   */
  { -444.2882938158366, -98696.044010893587 },

  /* Computed Parameter: Highpassfilter1_C
   * Referenced by: '<S3>/High-pass filter1'
   */
  { 98696.044010893587, 0.0 }
};
