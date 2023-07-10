/*
 * robust_tracking_integral_augmentedState_REALTIME_types.h
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

#ifndef RTW_HEADER_robust_tracking_integral_augmentedState_REALTIME_types_h_
#define RTW_HEADER_robust_tracking_integral_augmentedState_REALTIME_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_struct_vHPMdAr9HfDgWNbG6U3SfC_
#define DEFINED_TYPEDEF_FOR_struct_vHPMdAr9HfDgWNbG6U3SfC_

typedef struct {
  real_T Rs;
} struct_vHPMdAr9HfDgWNbG6U3SfC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nZqFUEOh71pPhzsMP64FWD_
#define DEFINED_TYPEDEF_FOR_struct_nZqFUEOh71pPhzsMP64FWD_

typedef struct {
  real_T ppr;
  real_T pulse2deg;
  real_T pulse2rad;
  real_T deg2pulse;
  real_T rad2pulse;
} struct_nZqFUEOh71pPhzsMP64FWD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_DqRrFctOcoTwJhkxMXTGZG_
#define DEFINED_TYPEDEF_FOR_struct_DqRrFctOcoTwJhkxMXTGZG_

typedef struct {
  real_T R;
  real_T V;
  real_T th_deg;
  real_T th;
} struct_DqRrFctOcoTwJhkxMXTGZG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_t4jfYKvXkqvqbOrnXV9flF_
#define DEFINED_TYPEDEF_FOR_struct_t4jfYKvXkqvqbOrnXV9flF_

typedef struct {
  struct_DqRrFctOcoTwJhkxMXTGZG range;
  real_T deg2V;
  real_T rad2V;
  real_T V2deg;
  real_T V2rad;
} struct_t4jfYKvXkqvqbOrnXV9flF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_i7ZlkOl9k9qbhxQhPErSIE_
#define DEFINED_TYPEDEF_FOR_struct_i7ZlkOl9k9qbhxQhPErSIE_

typedef struct {
  real_T var;
} struct_i7ZlkOl9k9qbhxQhPErSIE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nhbocl71hD6FRzHagkwJFB_
#define DEFINED_TYPEDEF_FOR_struct_nhbocl71hD6FRzHagkwJFB_

typedef struct {
  struct_DqRrFctOcoTwJhkxMXTGZG range;
  real_T deg2V;
  real_T rad2V;
  real_T V2deg;
  real_T V2rad;
  struct_i7ZlkOl9k9qbhxQhPErSIE noise;
} struct_nhbocl71hD6FRzHagkwJFB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_4jr0aBoeUcVnCi5PWU4anE_
#define DEFINED_TYPEDEF_FOR_struct_4jr0aBoeUcVnCi5PWU4anE_

typedef struct {
  struct_vHPMdAr9HfDgWNbG6U3SfC curr;
  struct_nZqFUEOh71pPhzsMP64FWD enc;
  struct_t4jfYKvXkqvqbOrnXV9flF pot1;
  struct_nhbocl71hD6FRzHagkwJFB pot2;
} struct_4jr0aBoeUcVnCi5PWU4anE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Y5WeR8jYtwJAEL46WtehnF_
#define DEFINED_TYPEDEF_FOR_struct_Y5WeR8jYtwJAEL46WtehnF_

typedef struct {
  real_T alpha;
  real_T w_gc;
  real_T phi_m;
  real_T T_L;
  real_T T_w;
  creal_T frq_resp;
  real_T Delta_K;
  real_T Delta_phi;
  real_T Kp;
  real_T Td;
  real_T Ti;
  real_T Ki;
  real_T Kd;
  real_T Kw;
} struct_Y5WeR8jYtwJAEL46WtehnF;

#endif

/* Parameters (default storage) */
typedef struct P_robust_tracking_integral_augmentedState_REALTIME_T_
  P_robust_tracking_integral_augmentedState_REALTIME_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_robust_tracking_integral_augmentedState_REALTIME_T
  RT_MODEL_robust_tracking_integral_augmentedState_REALTIME_T;

#endif
      /* RTW_HEADER_robust_tracking_integral_augmentedState_REALTIME_types_h_ */
