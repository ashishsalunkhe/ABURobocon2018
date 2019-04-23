#ifndef __c2_untitled_h__
#define __c2_untitled_h__

/* Type Definitions */
#ifndef typedef_SFc2_untitledInstanceStruct
#define typedef_SFc2_untitledInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_untitled;
  real32_T c2_videoframe[921600];
  real32_T c2_I[921600];
  real32_T c2_X[921600];
  real32_T c2_outputImage[921600];
  boolean_T c2_BW[307200];
  boolean_T c2_bv1[307200];
  boolean_T c2_bv2[307200];
  boolean_T c2_bv3[307200];
  boolean_T c2_bv4[307200];
  boolean_T c2_bv5[307200];
  boolean_T c2_bv6[307200];
  real32_T c2_y[921600];
  real32_T c2_fv0[921600];
  real32_T c2_u[921600];
  boolean_T c2_b_y[307200];
  boolean_T c2_bv7[307200];
  boolean_T c2_bv0[307200];
  boolean_T c2_b_u[307200];
  void *c2_fEmlrtCtx;
  real32_T (*c2_b_videoframe)[921600];
  boolean_T (*c2_b_BW)[307200];
} SFc2_untitledInstanceStruct;

#endif                                 /*typedef_SFc2_untitledInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_untitled_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_untitled_get_check_sum(mxArray *plhs[]);
extern void c2_untitled_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
