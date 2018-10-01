#ifndef __c1_Simulink_1_h__
#define __c1_Simulink_1_h__

/* Type Definitions */
#ifndef typedef_SFc1_Simulink_1InstanceStruct
#define typedef_SFc1_Simulink_1InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_Simulink_1;
  real32_T c1_videoframe[921600];
  real32_T c1_I[921600];
  real32_T c1_X[921600];
  real32_T c1_outputImage[921600];
  boolean_T c1_BW[307200];
  boolean_T c1_bv1[307200];
  boolean_T c1_bv2[307200];
  boolean_T c1_bv3[307200];
  boolean_T c1_bv4[307200];
  boolean_T c1_bv5[307200];
  boolean_T c1_bv6[307200];
  real32_T c1_y[921600];
  real32_T c1_fv0[921600];
  real32_T c1_u[921600];
  boolean_T c1_b_y[307200];
  boolean_T c1_bv7[307200];
  boolean_T c1_bv0[307200];
  boolean_T c1_b_u[307200];
  void *c1_fEmlrtCtx;
  real32_T (*c1_b_videoframe)[921600];
  boolean_T (*c1_b_BW)[307200];
} SFc1_Simulink_1InstanceStruct;

#endif                                 /*typedef_SFc1_Simulink_1InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_Simulink_1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_Simulink_1_get_check_sum(mxArray *plhs[]);
extern void c1_Simulink_1_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
