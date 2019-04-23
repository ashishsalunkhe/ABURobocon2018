#ifndef __c4_untitled_h__
#define __c4_untitled_h__

/* Type Definitions */
#ifndef typedef_c4_images_internal_coder_strel_StructuringElementHelper
#define typedef_c4_images_internal_coder_strel_StructuringElementHelper

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  boolean_T Neighborhood[25];
  real_T Dimensionality;
} c4_images_internal_coder_strel_StructuringElementHelper;

#endif                                 /*typedef_c4_images_internal_coder_strel_StructuringElementHelper*/

#ifndef typedef_SFc4_untitledInstanceStruct
#define typedef_SFc4_untitledInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_untitled;
  boolean_T c4_BW[307200];
  boolean_T c4_Im[307200];
  boolean_T c4_b_BW[307200];
  boolean_T c4_bv1[307200];
  boolean_T c4_Apad[311696];
  boolean_T c4_Apadpre[309444];
  boolean_T c4_A[307200];
  boolean_T c4_b_A[307200];
  boolean_T c4_b_Apad[311696];
  boolean_T c4_b_Apadpre[309444];
  boolean_T c4_c_A[307200];
  boolean_T c4_y[307200];
  boolean_T c4_bv2[307200];
  boolean_T c4_bv0[307200];
  boolean_T c4_u[307200];
  void *c4_fEmlrtCtx;
  boolean_T (*c4_c_BW)[307200];
  boolean_T (*c4_b_Im)[307200];
} SFc4_untitledInstanceStruct;

#endif                                 /*typedef_SFc4_untitledInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_untitled_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_untitled_get_check_sum(mxArray *plhs[]);
extern void c4_untitled_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
