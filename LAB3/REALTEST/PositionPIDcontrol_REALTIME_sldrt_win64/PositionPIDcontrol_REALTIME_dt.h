/*
 * PositionPIDcontrol_REALTIME_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(struct_vHPMdAr9HfDgWNbG6U3SfC),
  sizeof(struct_nZqFUEOh71pPhzsMP64FWD),
  sizeof(struct_DqRrFctOcoTwJhkxMXTGZG),
  sizeof(struct_t4jfYKvXkqvqbOrnXV9flF),
  sizeof(struct_i7ZlkOl9k9qbhxQhPErSIE),
  sizeof(struct_nhbocl71hD6FRzHagkwJFB),
  sizeof(struct_4jr0aBoeUcVnCi5PWU4anE),
  sizeof(struct_Y5WeR8jYtwJAEL46WtehnF)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "struct_vHPMdAr9HfDgWNbG6U3SfC",
  "struct_nZqFUEOh71pPhzsMP64FWD",
  "struct_DqRrFctOcoTwJhkxMXTGZG",
  "struct_t4jfYKvXkqvqbOrnXV9flF",
  "struct_i7ZlkOl9k9qbhxQhPErSIE",
  "struct_nhbocl71hD6FRzHagkwJFB",
  "struct_4jr0aBoeUcVnCi5PWU4anE",
  "struct_Y5WeR8jYtwJAEL46WtehnF"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&PositionPIDcontrol_REALTIME_B.th_h), 0, 0, 12 },

  { (char_T *)(&PositionPIDcontrol_REALTIME_B.AND), 8, 0, 2 }
  ,

  { (char_T *)(&PositionPIDcontrol_REALTIME_DW.DiscreteTimeIntegrator_DSTATE), 0,
    0, 1 },

  { (char_T *)(&PositionPIDcontrol_REALTIME_DW.EncoderInput_PWORK), 11, 0, 12 },

  { (char_T *)(&PositionPIDcontrol_REALTIME_DW.PIDController_SubsysRanBC), 2, 0,
    2 },

  { (char_T *)(&PositionPIDcontrol_REALTIME_DW.PIDController_MODE), 8, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&PositionPIDcontrol_REALTIME_P.sens), 20, 0, 1 },

  { (char_T *)(&PositionPIDcontrol_REALTIME_P.ctrl), 21, 0, 1 },

  { (char_T *)(&PositionPIDcontrol_REALTIME_P.deg2rad), 0, 0, 15 },

  { (char_T *)(&PositionPIDcontrol_REALTIME_P.EncoderInput_Channels), 6, 0, 8 },

  { (char_T *)(&PositionPIDcontrol_REALTIME_P.Out_Y0), 0, 0, 12 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] PositionPIDcontrol_REALTIME_dt.h */
