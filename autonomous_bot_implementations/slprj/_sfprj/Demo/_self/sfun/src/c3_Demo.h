#ifndef __c3_Demo_h__
#define __c3_Demo_h__

/* Type Definitions */
#ifndef typedef_c3_images_internal_coder_strel_StructuringElementHelper
#define typedef_c3_images_internal_coder_strel_StructuringElementHelper

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  boolean_T Neighborhood[25];
  real_T Dimensionality;
} c3_images_internal_coder_strel_StructuringElementHelper;

#endif                                 /*typedef_c3_images_internal_coder_strel_StructuringElementHelper*/

#ifndef typedef_SFc3_DemoInstanceStruct
#define typedef_SFc3_DemoInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_Demo;
  boolean_T c3_BW[307200];
  boolean_T c3_Im[307200];
  boolean_T c3_b_BW[307200];
  boolean_T c3_bv1[307200];
  boolean_T c3_Apad[311696];
  boolean_T c3_Apadpre[309444];
  boolean_T c3_A[307200];
  boolean_T c3_b_A[307200];
  boolean_T c3_b_Apad[311696];
  boolean_T c3_b_Apadpre[309444];
  boolean_T c3_c_A[307200];
  boolean_T c3_y[307200];
  boolean_T c3_bv2[307200];
  boolean_T c3_bv0[307200];
  boolean_T c3_u[307200];
  void *c3_fEmlrtCtx;
  boolean_T (*c3_c_BW)[307200];
  boolean_T (*c3_b_Im)[307200];
} SFc3_DemoInstanceStruct;

#endif                                 /*typedef_SFc3_DemoInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_Demo_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_Demo_get_check_sum(mxArray *plhs[]);
extern void c3_Demo_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
