/* Include files */

#include "Simulink_1_sfun.h"
#include "c4_Simulink_1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Simulink_1_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[4] = { "nargin", "nargout", "BW", "Im"
};

/* Function Declarations */
static void initialize_c4_Simulink_1(SFc4_Simulink_1InstanceStruct
  *chartInstance);
static void initialize_params_c4_Simulink_1(SFc4_Simulink_1InstanceStruct
  *chartInstance);
static void enable_c4_Simulink_1(SFc4_Simulink_1InstanceStruct *chartInstance);
static void disable_c4_Simulink_1(SFc4_Simulink_1InstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_Simulink_1(SFc4_Simulink_1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_Simulink_1(SFc4_Simulink_1InstanceStruct *
  chartInstance);
static void set_sim_state_c4_Simulink_1(SFc4_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_Simulink_1(SFc4_Simulink_1InstanceStruct *chartInstance);
static void sf_gateway_c4_Simulink_1(SFc4_Simulink_1InstanceStruct
  *chartInstance);
static void mdl_start_c4_Simulink_1(SFc4_Simulink_1InstanceStruct *chartInstance);
static void initSimStructsc4_Simulink_1(SFc4_Simulink_1InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_Simulink_1InstanceStruct *chartInstance,
  const mxArray *c4_c_Im, const char_T *c4_identifier, boolean_T c4_b_y[307200]);
static void c4_b_emlrt_marshallIn(SFc4_Simulink_1InstanceStruct *chartInstance,
  const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId, boolean_T
  c4_b_y[307200]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_Simulink_1InstanceStruct *chartInstance,
  const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_imopen(SFc4_Simulink_1InstanceStruct *chartInstance, boolean_T
                      c4_d_A[307200],
                      c4_images_internal_coder_strel_StructuringElementHelper
                      *c4_se_, boolean_T c4_B[307200]);
static void c4_imerode(SFc4_Simulink_1InstanceStruct *chartInstance, boolean_T
  c4_d_A[307200], c4_images_internal_coder_strel_StructuringElementHelper *c4_se,
  boolean_T c4_B[307200]);
static void c4_padarray(SFc4_Simulink_1InstanceStruct *chartInstance, boolean_T
  c4_varargin_1[307200], boolean_T c4_b[309444]);
static void c4_bwpack(SFc4_Simulink_1InstanceStruct *chartInstance, boolean_T
                      c4_varargin_1[311696], uint32_T c4_BWP[10304]);
static void c4_bwunpack(SFc4_Simulink_1InstanceStruct *chartInstance, uint32_T
  c4_varargin_1[10304], boolean_T c4_d_BW[311696]);
static void c4_b_padarray(SFc4_Simulink_1InstanceStruct *chartInstance,
  boolean_T c4_varargin_1[307200], boolean_T c4_b[309444]);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_d_emlrt_marshallIn(SFc4_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_e_emlrt_marshallIn(SFc4_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_Simulink_1, const char_T
  *c4_identifier);
static uint8_T c4_f_emlrt_marshallIn(SFc4_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_Simulink_1InstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_Simulink_1InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_Simulink_1(SFc4_Simulink_1InstanceStruct
  *chartInstance)
{
  emlrtLicenseCheckR2012b(chartInstance->c4_fEmlrtCtx, "Image_Toolbox", 2);
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc4_Simulink_1(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_Simulink_1 = 0U;
}

static void initialize_params_c4_Simulink_1(SFc4_Simulink_1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_Simulink_1(SFc4_Simulink_1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_Simulink_1(SFc4_Simulink_1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_Simulink_1(SFc4_Simulink_1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_Simulink_1(SFc4_Simulink_1InstanceStruct *
  chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  uint8_T c4_hoistedGlobal;
  const mxArray *c4_d_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_createcellmatrix(2, 1), false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", *chartInstance->c4_b_Im, 11, 0U, 1U,
    0U, 2, 480, 640), false);
  sf_mex_setcell(c4_b_y, 0, c4_c_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_Simulink_1;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_b_y, 1, c4_d_y);
  sf_mex_assign(&c4_st, c4_b_y, false);
  return c4_st;
}

static void set_sim_state_c4_Simulink_1(SFc4_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_b_u;
  int32_T c4_i0;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_b_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_b_u, 0)), "Im",
                      chartInstance->c4_bv0);
  for (c4_i0 = 0; c4_i0 < 307200; c4_i0++) {
    (*chartInstance->c4_b_Im)[c4_i0] = chartInstance->c4_bv0[c4_i0];
  }

  chartInstance->c4_is_active_c4_Simulink_1 = c4_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_b_u, 1)),
     "is_active_c4_Simulink_1");
  sf_mex_destroy(&c4_b_u);
  c4_update_debugger_state_c4_Simulink_1(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_Simulink_1(SFc4_Simulink_1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_Simulink_1(SFc4_Simulink_1InstanceStruct
  *chartInstance)
{
  int32_T c4_i1;
  int32_T c4_i2;
  uint32_T c4_debug_family_var_map[4];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  c4_images_internal_coder_strel_StructuringElementHelper c4_diskElem;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i1 = 0; c4_i1 < 307200; c4_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_c_BW)[c4_i1], 0U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i2 = 0; c4_i2 < 307200; c4_i2++) {
    chartInstance->c4_BW[c4_i2] = (*chartInstance->c4_c_BW)[c4_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c4_BW, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c4_Im, 3U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  c4_diskElem.matlabCodegenIsDeleted = false;
  for (c4_i3 = 0; c4_i3 < 25; c4_i3++) {
    c4_diskElem.Neighborhood[c4_i3] = true;
  }

  c4_diskElem.Dimensionality = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  for (c4_i4 = 0; c4_i4 < 307200; c4_i4++) {
    chartInstance->c4_b_BW[c4_i4] = chartInstance->c4_BW[c4_i4];
  }

  c4_imopen(chartInstance, chartInstance->c4_b_BW, &c4_diskElem,
            chartInstance->c4_bv1);
  for (c4_i5 = 0; c4_i5 < 307200; c4_i5++) {
    chartInstance->c4_Im[c4_i5] = chartInstance->c4_bv1[c4_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i6 = 0; c4_i6 < 307200; c4_i6++) {
    (*chartInstance->c4_b_Im)[c4_i6] = chartInstance->c4_Im[c4_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Simulink_1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c4_i7 = 0; c4_i7 < 307200; c4_i7++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_b_Im)[c4_i7], 1U);
  }
}

static void mdl_start_c4_Simulink_1(SFc4_Simulink_1InstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc4_Simulink_1(SFc4_Simulink_1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)(c4_machineNumber);
  (void)(c4_chartNumber);
  (void)(c4_instanceNumber);
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i8;
  int32_T c4_i9;
  const mxArray *c4_b_y = NULL;
  int32_T c4_i10;
  SFc4_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc4_Simulink_1InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_i8 = 0;
  for (c4_i9 = 0; c4_i9 < 640; c4_i9++) {
    for (c4_i10 = 0; c4_i10 < 480; c4_i10++) {
      chartInstance->c4_u[c4_i10 + c4_i8] = (*(boolean_T (*)[307200])c4_inData)
        [c4_i10 + c4_i8];
    }

    c4_i8 += 480;
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", chartInstance->c4_u, 11, 0U, 1U, 0U,
    2, 480, 640), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_b_y, false);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_Simulink_1InstanceStruct *chartInstance,
  const mxArray *c4_c_Im, const char_T *c4_identifier, boolean_T c4_b_y[307200])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_c_Im), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_c_Im);
}

static void c4_b_emlrt_marshallIn(SFc4_Simulink_1InstanceStruct *chartInstance,
  const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId, boolean_T
  c4_b_y[307200])
{
  int32_T c4_i11;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_b_u), chartInstance->c4_bv2, 1, 11,
                0U, 1, 0U, 2, 480, 640);
  for (c4_i11 = 0; c4_i11 < 307200; c4_i11++) {
    c4_b_y[c4_i11] = chartInstance->c4_bv2[c4_i11];
  }

  sf_mex_destroy(&c4_b_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_c_Im;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  SFc4_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc4_Simulink_1InstanceStruct *)chartInstanceVoid;
  c4_c_Im = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_c_Im), &c4_thisId,
                        chartInstance->c4_y);
  sf_mex_destroy(&c4_c_Im);
  c4_i12 = 0;
  for (c4_i13 = 0; c4_i13 < 640; c4_i13++) {
    for (c4_i14 = 0; c4_i14 < 480; c4_i14++) {
      (*(boolean_T (*)[307200])c4_outData)[c4_i14 + c4_i12] =
        chartInstance->c4_y[c4_i14 + c4_i12];
    }

    c4_i12 += 480;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  SFc4_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc4_Simulink_1InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_b_u = *(real_T *)c4_inData;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_b_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_Simulink_1InstanceStruct *chartInstance,
  const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_b_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_b_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_b_y = c4_d0;
  sf_mex_destroy(&c4_b_u);
  return c4_b_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_b_y;
  SFc4_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc4_Simulink_1InstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout),
    &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_b_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_Simulink_1_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static void c4_imopen(SFc4_Simulink_1InstanceStruct *chartInstance, boolean_T
                      c4_d_A[307200],
                      c4_images_internal_coder_strel_StructuringElementHelper
                      *c4_se_, boolean_T c4_B[307200])
{
  int32_T c4_i15;
  int32_T c4_j;
  int32_T c4_b_j;
  int32_T c4_i;
  int32_T c4_c_j;
  int32_T c4_b_i;
  uint32_T c4_Apadpack[10304];
  int32_T c4_c_i;
  int32_T c4_i16;
  int32_T c4_i17;
  real_T c4_asize[2];
  int32_T c4_i18;
  boolean_T c4_nhood[3];
  real_T c4_nsize[2];
  uint32_T c4_b_B[10304];
  int32_T c4_i19;
  int32_T c4_i20;
  boolean_T c4_b_nhood;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  boolean_T c4_c_nhood;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i40;
  for (c4_i15 = 0; c4_i15 < 307200; c4_i15++) {
    chartInstance->c4_A[c4_i15] = c4_d_A[c4_i15];
  }

  c4_imerode(chartInstance, chartInstance->c4_A, c4_se_, chartInstance->c4_b_A);
  c4_b_padarray(chartInstance, chartInstance->c4_b_A, chartInstance->c4_Apadpre);
  for (c4_j = 0; c4_j < 2; c4_j++) {
    for (c4_i = 0; c4_i < 484; c4_i++) {
      chartInstance->c4_Apad[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c4_i), 1, 484) + 484 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c4_j +
        643)), 1, 644) - 1)) - 1] = false;
    }
  }

  for (c4_b_j = 0; c4_b_j < 642; c4_b_j++) {
    for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
      chartInstance->c4_Apad[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c4_b_i
        + 483)), 1, 484) + 484 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c4_b_j), 1, 644) - 1)) - 1] = false;
    }
  }

  for (c4_c_j = 0; c4_c_j < 642; c4_c_j++) {
    for (c4_c_i = 0; c4_c_i < 482; c4_c_i++) {
      chartInstance->c4_Apad[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c4_c_i), 1, 484) + 484 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c4_c_j), 1, 644) - 1)) - 1] = chartInstance->c4_Apadpre
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
           (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c4_c_i), 1, 482) + 482 *
          (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
            (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c4_c_j), 1, 642) - 1))
        - 1];
    }
  }

  c4_bwpack(chartInstance, chartInstance->c4_Apad, c4_Apadpack);
  for (c4_i16 = 0; c4_i16 < 2; c4_i16++) {
    c4_asize[c4_i16] = 16.0 + 628.0 * (real_T)c4_i16;
  }

  for (c4_i17 = 0; c4_i17 < 3; c4_i17++) {
    c4_nhood[c4_i17] = true;
  }

  for (c4_i18 = 0; c4_i18 < 2; c4_i18++) {
    c4_nsize[c4_i18] = 3.0 + -2.0 * (real_T)c4_i18;
  }

  dilate_packed_uint32(c4_Apadpack, c4_asize, 2.0, c4_nhood, c4_nsize, 2.0,
                       c4_b_B);
  for (c4_i19 = 0; c4_i19 < 10304; c4_i19++) {
    c4_Apadpack[c4_i19] = c4_b_B[c4_i19];
  }

  for (c4_i20 = 0; c4_i20 < 2; c4_i20++) {
    c4_asize[c4_i20] = 16.0 + 628.0 * (real_T)c4_i20;
  }

  c4_b_nhood = true;
  for (c4_i21 = 0; c4_i21 < 2; c4_i21++) {
    c4_nsize[c4_i21] = 1.0;
  }

  dilate_packed_uint32(c4_Apadpack, c4_asize, 2.0, &c4_b_nhood, c4_nsize, 2.0,
                       c4_b_B);
  for (c4_i22 = 0; c4_i22 < 10304; c4_i22++) {
    c4_Apadpack[c4_i22] = c4_b_B[c4_i22];
  }

  for (c4_i23 = 0; c4_i23 < 2; c4_i23++) {
    c4_asize[c4_i23] = 16.0 + 628.0 * (real_T)c4_i23;
  }

  for (c4_i24 = 0; c4_i24 < 3; c4_i24++) {
    c4_nhood[c4_i24] = true;
  }

  for (c4_i25 = 0; c4_i25 < 2; c4_i25++) {
    c4_nsize[c4_i25] = 1.0 + 2.0 * (real_T)c4_i25;
  }

  dilate_packed_uint32(c4_Apadpack, c4_asize, 2.0, c4_nhood, c4_nsize, 2.0,
                       c4_b_B);
  for (c4_i26 = 0; c4_i26 < 10304; c4_i26++) {
    c4_Apadpack[c4_i26] = c4_b_B[c4_i26];
  }

  for (c4_i27 = 0; c4_i27 < 2; c4_i27++) {
    c4_asize[c4_i27] = 16.0 + 628.0 * (real_T)c4_i27;
  }

  c4_c_nhood = true;
  for (c4_i28 = 0; c4_i28 < 2; c4_i28++) {
    c4_nsize[c4_i28] = 1.0;
  }

  dilate_packed_uint32(c4_Apadpack, c4_asize, 2.0, &c4_c_nhood, c4_nsize, 2.0,
                       c4_b_B);
  for (c4_i29 = 0; c4_i29 < 10304; c4_i29++) {
    c4_Apadpack[c4_i29] = c4_b_B[c4_i29];
  }

  for (c4_i30 = 0; c4_i30 < 2; c4_i30++) {
    c4_asize[c4_i30] = 16.0 + 628.0 * (real_T)c4_i30;
  }

  for (c4_i31 = 0; c4_i31 < 3; c4_i31++) {
    c4_nhood[c4_i31] = true;
  }

  for (c4_i32 = 0; c4_i32 < 2; c4_i32++) {
    c4_nsize[c4_i32] = 1.0 + 2.0 * (real_T)c4_i32;
  }

  dilate_packed_uint32(c4_Apadpack, c4_asize, 2.0, c4_nhood, c4_nsize, 2.0,
                       c4_b_B);
  for (c4_i33 = 0; c4_i33 < 10304; c4_i33++) {
    c4_Apadpack[c4_i33] = c4_b_B[c4_i33];
  }

  for (c4_i34 = 0; c4_i34 < 2; c4_i34++) {
    c4_asize[c4_i34] = 16.0 + 628.0 * (real_T)c4_i34;
  }

  for (c4_i35 = 0; c4_i35 < 3; c4_i35++) {
    c4_nhood[c4_i35] = true;
  }

  for (c4_i36 = 0; c4_i36 < 2; c4_i36++) {
    c4_nsize[c4_i36] = 3.0 + -2.0 * (real_T)c4_i36;
  }

  dilate_packed_uint32(c4_Apadpack, c4_asize, 2.0, c4_nhood, c4_nsize, 2.0,
                       c4_b_B);
  c4_bwunpack(chartInstance, c4_b_B, chartInstance->c4_Apad);
  c4_i37 = 0;
  c4_i38 = 0;
  for (c4_i39 = 0; c4_i39 < 640; c4_i39++) {
    for (c4_i40 = 0; c4_i40 < 480; c4_i40++) {
      c4_B[c4_i40 + c4_i37] = chartInstance->c4_Apad[(c4_i40 + c4_i38) + 970];
    }

    c4_i37 += 480;
    c4_i38 += 484;
  }
}

static void c4_imerode(SFc4_Simulink_1InstanceStruct *chartInstance, boolean_T
  c4_d_A[307200], c4_images_internal_coder_strel_StructuringElementHelper *c4_se,
  boolean_T c4_B[307200])
{
  int32_T c4_i41;
  int32_T c4_j;
  int32_T c4_b_j;
  int32_T c4_i;
  int32_T c4_c_j;
  int32_T c4_b_i;
  uint32_T c4_Apadpack[10304];
  int32_T c4_c_i;
  int32_T c4_i42;
  int32_T c4_i43;
  real_T c4_asize[2];
  int32_T c4_i44;
  boolean_T c4_nhood[3];
  real_T c4_nsize[2];
  uint32_T c4_b_B[10304];
  int32_T c4_i45;
  int32_T c4_i46;
  boolean_T c4_b_nhood;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  boolean_T c4_c_nhood;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i60;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  (void)c4_se;
  for (c4_i41 = 0; c4_i41 < 307200; c4_i41++) {
    chartInstance->c4_c_A[c4_i41] = c4_d_A[c4_i41];
  }

  c4_padarray(chartInstance, chartInstance->c4_c_A, chartInstance->c4_b_Apadpre);
  for (c4_j = 0; c4_j < 2; c4_j++) {
    for (c4_i = 0; c4_i < 484; c4_i++) {
      chartInstance->c4_b_Apad[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c4_i), 1, 484) + 484 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c4_j +
        643)), 1, 644) - 1)) - 1] = true;
    }
  }

  for (c4_b_j = 0; c4_b_j < 642; c4_b_j++) {
    for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
      chartInstance->c4_b_Apad[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c4_b_i
        + 483)), 1, 484) + 484 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c4_b_j), 1, 644) - 1)) - 1] = true;
    }
  }

  for (c4_c_j = 0; c4_c_j < 642; c4_c_j++) {
    for (c4_c_i = 0; c4_c_i < 482; c4_c_i++) {
      chartInstance->c4_b_Apad[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c4_c_i), 1, 484) + 484 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c4_c_j), 1, 644) - 1)) - 1] = chartInstance->c4_b_Apadpre
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
           (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c4_c_i), 1, 482) + 482 *
          (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
            (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c4_c_j), 1, 642) - 1))
        - 1];
    }
  }

  c4_bwpack(chartInstance, chartInstance->c4_b_Apad, c4_Apadpack);
  for (c4_i42 = 0; c4_i42 < 2; c4_i42++) {
    c4_asize[c4_i42] = 16.0 + 628.0 * (real_T)c4_i42;
  }

  for (c4_i43 = 0; c4_i43 < 3; c4_i43++) {
    c4_nhood[c4_i43] = true;
  }

  for (c4_i44 = 0; c4_i44 < 2; c4_i44++) {
    c4_nsize[c4_i44] = 3.0 + -2.0 * (real_T)c4_i44;
  }

  erode_packed_uint32(c4_Apadpack, c4_asize, 2.0, c4_nhood, c4_nsize, 2.0, 484.0,
                      c4_b_B);
  for (c4_i45 = 0; c4_i45 < 10304; c4_i45++) {
    c4_Apadpack[c4_i45] = c4_b_B[c4_i45];
  }

  for (c4_i46 = 0; c4_i46 < 2; c4_i46++) {
    c4_asize[c4_i46] = 16.0 + 628.0 * (real_T)c4_i46;
  }

  c4_b_nhood = true;
  for (c4_i47 = 0; c4_i47 < 2; c4_i47++) {
    c4_nsize[c4_i47] = 1.0;
  }

  erode_packed_uint32(c4_Apadpack, c4_asize, 2.0, &c4_b_nhood, c4_nsize, 2.0,
                      484.0, c4_b_B);
  for (c4_i48 = 0; c4_i48 < 10304; c4_i48++) {
    c4_Apadpack[c4_i48] = c4_b_B[c4_i48];
  }

  for (c4_i49 = 0; c4_i49 < 2; c4_i49++) {
    c4_asize[c4_i49] = 16.0 + 628.0 * (real_T)c4_i49;
  }

  for (c4_i50 = 0; c4_i50 < 3; c4_i50++) {
    c4_nhood[c4_i50] = true;
  }

  for (c4_i51 = 0; c4_i51 < 2; c4_i51++) {
    c4_nsize[c4_i51] = 1.0 + 2.0 * (real_T)c4_i51;
  }

  erode_packed_uint32(c4_Apadpack, c4_asize, 2.0, c4_nhood, c4_nsize, 2.0, 484.0,
                      c4_b_B);
  for (c4_i52 = 0; c4_i52 < 10304; c4_i52++) {
    c4_Apadpack[c4_i52] = c4_b_B[c4_i52];
  }

  for (c4_i53 = 0; c4_i53 < 2; c4_i53++) {
    c4_asize[c4_i53] = 16.0 + 628.0 * (real_T)c4_i53;
  }

  c4_c_nhood = true;
  for (c4_i54 = 0; c4_i54 < 2; c4_i54++) {
    c4_nsize[c4_i54] = 1.0;
  }

  erode_packed_uint32(c4_Apadpack, c4_asize, 2.0, &c4_c_nhood, c4_nsize, 2.0,
                      484.0, c4_b_B);
  for (c4_i55 = 0; c4_i55 < 10304; c4_i55++) {
    c4_Apadpack[c4_i55] = c4_b_B[c4_i55];
  }

  for (c4_i56 = 0; c4_i56 < 2; c4_i56++) {
    c4_asize[c4_i56] = 16.0 + 628.0 * (real_T)c4_i56;
  }

  for (c4_i57 = 0; c4_i57 < 3; c4_i57++) {
    c4_nhood[c4_i57] = true;
  }

  for (c4_i58 = 0; c4_i58 < 2; c4_i58++) {
    c4_nsize[c4_i58] = 1.0 + 2.0 * (real_T)c4_i58;
  }

  erode_packed_uint32(c4_Apadpack, c4_asize, 2.0, c4_nhood, c4_nsize, 2.0, 484.0,
                      c4_b_B);
  for (c4_i59 = 0; c4_i59 < 10304; c4_i59++) {
    c4_Apadpack[c4_i59] = c4_b_B[c4_i59];
  }

  for (c4_i60 = 0; c4_i60 < 2; c4_i60++) {
    c4_asize[c4_i60] = 16.0 + 628.0 * (real_T)c4_i60;
  }

  for (c4_i61 = 0; c4_i61 < 3; c4_i61++) {
    c4_nhood[c4_i61] = true;
  }

  for (c4_i62 = 0; c4_i62 < 2; c4_i62++) {
    c4_nsize[c4_i62] = 3.0 + -2.0 * (real_T)c4_i62;
  }

  erode_packed_uint32(c4_Apadpack, c4_asize, 2.0, c4_nhood, c4_nsize, 2.0, 484.0,
                      c4_b_B);
  c4_bwunpack(chartInstance, c4_b_B, chartInstance->c4_b_Apad);
  c4_i63 = 0;
  c4_i64 = 0;
  for (c4_i65 = 0; c4_i65 < 640; c4_i65++) {
    for (c4_i66 = 0; c4_i66 < 480; c4_i66++) {
      c4_B[c4_i66 + c4_i63] = chartInstance->c4_b_Apad[(c4_i66 + c4_i64) + 970];
    }

    c4_i63 += 480;
    c4_i64 += 484;
  }
}

static void c4_padarray(SFc4_Simulink_1InstanceStruct *chartInstance, boolean_T
  c4_varargin_1[307200], boolean_T c4_b[309444])
{
  int32_T c4_j;
  int32_T c4_b_j;
  int32_T c4_i;
  int32_T c4_c_j;
  int32_T c4_b_i;
  int32_T c4_c_i;
  for (c4_j = 0; c4_j < 2; c4_j++) {
    for (c4_i = 0; c4_i < 482; c4_i++) {
      c4_b[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c4_i), 1, 482) + 482 *
            (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
              sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c4_j),
              1, 642) - 1)) - 1] = true;
    }
  }

  for (c4_b_j = 0; c4_b_j < 640; c4_b_j++) {
    for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
      c4_b[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c4_b_i), 1, 482) + 482
            * (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
              sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c4_b_j + 3)),
              1, 642) - 1)) - 1] = true;
    }
  }

  for (c4_c_j = 0; c4_c_j < 640; c4_c_j++) {
    for (c4_c_i = 0; c4_c_i < 480; c4_c_i++) {
      c4_b[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, (real_T)(c4_c_i + 3)), 1, 482) + 482
            * (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
              sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c4_c_j + 3)),
              1, 642) - 1)) - 1] = c4_varargin_1[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c4_c_i), 1, 480) + 480 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c4_c_j), 1, 640) - 1)) - 1];
    }
  }
}

static void c4_bwpack(SFc4_Simulink_1InstanceStruct *chartInstance, boolean_T
                      c4_varargin_1[311696], uint32_T c4_BWP[10304])
{
  int32_T c4_i67;
  int32_T c4_i68;
  real_T c4_dv0[2];
  real_T c4_dv1[2];
  (void)chartInstance;
  for (c4_i67 = 0; c4_i67 < 2; c4_i67++) {
    c4_dv0[c4_i67] = 484.0 + 160.0 * (real_T)c4_i67;
  }

  for (c4_i68 = 0; c4_i68 < 2; c4_i68++) {
    c4_dv1[c4_i68] = 16.0 + 628.0 * (real_T)c4_i68;
  }

  bwPackingtbb(c4_varargin_1, c4_dv0, c4_BWP, c4_dv1);
}

static void c4_bwunpack(SFc4_Simulink_1InstanceStruct *chartInstance, uint32_T
  c4_varargin_1[10304], boolean_T c4_d_BW[311696])
{
  int32_T c4_i69;
  int32_T c4_i70;
  real_T c4_dv2[2];
  real_T c4_dv3[2];
  (void)chartInstance;
  for (c4_i69 = 0; c4_i69 < 2; c4_i69++) {
    c4_dv2[c4_i69] = 16.0 + 628.0 * (real_T)c4_i69;
  }

  for (c4_i70 = 0; c4_i70 < 2; c4_i70++) {
    c4_dv3[c4_i70] = 484.0 + 160.0 * (real_T)c4_i70;
  }

  bwUnpackingtbb(c4_varargin_1, c4_dv2, c4_d_BW, c4_dv3);
}

static void c4_b_padarray(SFc4_Simulink_1InstanceStruct *chartInstance,
  boolean_T c4_varargin_1[307200], boolean_T c4_b[309444])
{
  int32_T c4_j;
  int32_T c4_b_j;
  int32_T c4_i;
  int32_T c4_c_j;
  int32_T c4_b_i;
  int32_T c4_c_i;
  for (c4_j = 0; c4_j < 2; c4_j++) {
    for (c4_i = 0; c4_i < 482; c4_i++) {
      c4_b[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c4_i), 1, 482) + 482 *
            (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
              sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c4_j),
              1, 642) - 1)) - 1] = false;
    }
  }

  for (c4_b_j = 0; c4_b_j < 640; c4_b_j++) {
    for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
      c4_b[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c4_b_i), 1, 482) + 482
            * (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
              sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c4_b_j + 3)),
              1, 642) - 1)) - 1] = false;
    }
  }

  for (c4_c_j = 0; c4_c_j < 640; c4_c_j++) {
    for (c4_c_i = 0; c4_c_i < 480; c4_c_i++) {
      c4_b[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, (real_T)(c4_c_i + 3)), 1, 482) + 482
            * (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
              sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c4_c_j + 3)),
              1, 642) - 1)) - 1] = c4_varargin_1[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c4_c_i), 1, 480) + 480 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c4_c_j), 1, 640) - 1)) - 1];
    }
  }
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  SFc4_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc4_Simulink_1InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_b_u = *(int32_T *)c4_inData;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_b_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_d_emlrt_marshallIn(SFc4_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_b_y;
  int32_T c4_i71;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_b_u), &c4_i71, 1, 6, 0U, 0, 0U, 0);
  c4_b_y = c4_i71;
  sf_mex_destroy(&c4_b_u);
  return c4_b_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_b_y;
  SFc4_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc4_Simulink_1InstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_b_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_Simulink_1, const char_T
  *c4_identifier)
{
  uint8_T c4_b_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_Simulink_1), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_Simulink_1);
  return c4_b_y;
}

static uint8_T c4_f_emlrt_marshallIn(SFc4_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_b_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_b_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_b_y = c4_u0;
  sf_mex_destroy(&c4_b_u);
  return c4_b_y;
}

static void init_dsm_address_info(SFc4_Simulink_1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_Simulink_1InstanceStruct
  *chartInstance)
{
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_c_BW = (boolean_T (*)[307200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_b_Im = (boolean_T (*)[307200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c4_Simulink_1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1911090102U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3637103676U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3674173118U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(363949365U);
}

mxArray* sf_c4_Simulink_1_get_post_codegen_info(void);
mxArray *sf_c4_Simulink_1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("6we08beQDEXC1PWFYQZsqH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c4_Simulink_1_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_Simulink_1_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,3);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.BwpacktbbBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.Morphop_packed_Buildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.BwunpacktbbBuildable"));
  return(mxcell3p);
}

mxArray *sf_c4_Simulink_1_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("bwPackingtbb");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_Simulink_1_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_Simulink_1_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c4_Simulink_1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Im\",},{M[8],M[0],T\"is_active_c4_Simulink_1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_Simulink_1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_Simulink_1InstanceStruct *chartInstance =
      (SFc4_Simulink_1InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Simulink_1MachineNumber_,
           4,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Simulink_1MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Simulink_1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Simulink_1MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"BW");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Im");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,79);

        {
          unsigned int dimVector[2];
          dimVector[0]= 480U;
          dimVector[1]= 640U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 480U;
          dimVector[1]= 640U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Simulink_1MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_Simulink_1InstanceStruct *chartInstance =
      (SFc4_Simulink_1InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c4_c_BW);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c4_b_Im);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sa0vPifsfqgvjeVhsf8r5LG";
}

static void sf_opaque_initialize_c4_Simulink_1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_Simulink_1InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c4_Simulink_1((SFc4_Simulink_1InstanceStruct*)
    chartInstanceVar);
  initialize_c4_Simulink_1((SFc4_Simulink_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_Simulink_1(void *chartInstanceVar)
{
  enable_c4_Simulink_1((SFc4_Simulink_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_Simulink_1(void *chartInstanceVar)
{
  disable_c4_Simulink_1((SFc4_Simulink_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_Simulink_1(void *chartInstanceVar)
{
  sf_gateway_c4_Simulink_1((SFc4_Simulink_1InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_Simulink_1(SimStruct* S)
{
  return get_sim_state_c4_Simulink_1((SFc4_Simulink_1InstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_Simulink_1(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c4_Simulink_1((SFc4_Simulink_1InstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c4_Simulink_1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_Simulink_1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Simulink_1_optimization_info();
    }

    finalize_c4_Simulink_1((SFc4_Simulink_1InstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_Simulink_1((SFc4_Simulink_1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_Simulink_1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_Simulink_1((SFc4_Simulink_1InstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c4_Simulink_1(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Simulink_1_optimization_info(sim_mode_is_rtw_gen
      (S), sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 4);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2165609220U));
  ssSetChecksum1(S,(1273818006U));
  ssSetChecksum2(S,(3549555149U));
  ssSetChecksum3(S,(3834154730U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_Simulink_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_Simulink_1(SimStruct *S)
{
  SFc4_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc4_Simulink_1InstanceStruct *)utMalloc(sizeof
    (SFc4_Simulink_1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_Simulink_1InstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_Simulink_1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_Simulink_1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_Simulink_1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_Simulink_1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_Simulink_1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_Simulink_1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_Simulink_1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_Simulink_1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_Simulink_1;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_Simulink_1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_Simulink_1;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c4_Simulink_1(chartInstance);
}

void c4_Simulink_1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_Simulink_1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_Simulink_1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_Simulink_1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_Simulink_1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
