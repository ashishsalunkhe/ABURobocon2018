/* Include files */

#include "Simulink_1_sfun.h"
#include "c3_Simulink_1.h"
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
static const char * c3_debug_family_names[4] = { "nargin", "nargout", "BW", "Im"
};

/* Function Declarations */
static void initialize_c3_Simulink_1(SFc3_Simulink_1InstanceStruct
  *chartInstance);
static void initialize_params_c3_Simulink_1(SFc3_Simulink_1InstanceStruct
  *chartInstance);
static void enable_c3_Simulink_1(SFc3_Simulink_1InstanceStruct *chartInstance);
static void disable_c3_Simulink_1(SFc3_Simulink_1InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Simulink_1(SFc3_Simulink_1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_Simulink_1(SFc3_Simulink_1InstanceStruct *
  chartInstance);
static void set_sim_state_c3_Simulink_1(SFc3_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_Simulink_1(SFc3_Simulink_1InstanceStruct *chartInstance);
static void sf_gateway_c3_Simulink_1(SFc3_Simulink_1InstanceStruct
  *chartInstance);
static void mdl_start_c3_Simulink_1(SFc3_Simulink_1InstanceStruct *chartInstance);
static void initSimStructsc3_Simulink_1(SFc3_Simulink_1InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_Simulink_1InstanceStruct *chartInstance,
  const mxArray *c3_c_Im, const char_T *c3_identifier, boolean_T c3_b_y[307200]);
static void c3_b_emlrt_marshallIn(SFc3_Simulink_1InstanceStruct *chartInstance,
  const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId, boolean_T
  c3_b_y[307200]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_Simulink_1InstanceStruct *chartInstance,
  const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_imopen(SFc3_Simulink_1InstanceStruct *chartInstance, boolean_T
                      c3_d_A[307200],
                      c3_images_internal_coder_strel_StructuringElementHelper
                      *c3_se_, boolean_T c3_B[307200]);
static void c3_imerode(SFc3_Simulink_1InstanceStruct *chartInstance, boolean_T
  c3_d_A[307200], c3_images_internal_coder_strel_StructuringElementHelper *c3_se,
  boolean_T c3_B[307200]);
static void c3_padarray(SFc3_Simulink_1InstanceStruct *chartInstance, boolean_T
  c3_varargin_1[307200], boolean_T c3_b[309444]);
static void c3_bwpack(SFc3_Simulink_1InstanceStruct *chartInstance, boolean_T
                      c3_varargin_1[311696], uint32_T c3_BWP[10304]);
static void c3_bwunpack(SFc3_Simulink_1InstanceStruct *chartInstance, uint32_T
  c3_varargin_1[10304], boolean_T c3_d_BW[311696]);
static void c3_b_padarray(SFc3_Simulink_1InstanceStruct *chartInstance,
  boolean_T c3_varargin_1[307200], boolean_T c3_b[309444]);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_e_emlrt_marshallIn(SFc3_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_Simulink_1, const char_T
  *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_Simulink_1InstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_Simulink_1InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_Simulink_1(SFc3_Simulink_1InstanceStruct
  *chartInstance)
{
  emlrtLicenseCheckR2012b(chartInstance->c3_fEmlrtCtx, "Image_Toolbox", 2);
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_Simulink_1(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_Simulink_1 = 0U;
}

static void initialize_params_c3_Simulink_1(SFc3_Simulink_1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_Simulink_1(SFc3_Simulink_1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_Simulink_1(SFc3_Simulink_1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_Simulink_1(SFc3_Simulink_1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_Simulink_1(SFc3_Simulink_1InstanceStruct *
  chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createcellmatrix(2, 1), false);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", *chartInstance->c3_b_Im, 11, 0U, 1U,
    0U, 2, 480, 640), false);
  sf_mex_setcell(c3_b_y, 0, c3_c_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_Simulink_1;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_b_y, 1, c3_d_y);
  sf_mex_assign(&c3_st, c3_b_y, false);
  return c3_st;
}

static void set_sim_state_c3_Simulink_1(SFc3_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_b_u;
  int32_T c3_i0;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_b_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 0)), "Im",
                      chartInstance->c3_bv0);
  for (c3_i0 = 0; c3_i0 < 307200; c3_i0++) {
    (*chartInstance->c3_b_Im)[c3_i0] = chartInstance->c3_bv0[c3_i0];
  }

  chartInstance->c3_is_active_c3_Simulink_1 = c3_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 1)),
     "is_active_c3_Simulink_1");
  sf_mex_destroy(&c3_b_u);
  c3_update_debugger_state_c3_Simulink_1(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_Simulink_1(SFc3_Simulink_1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_Simulink_1(SFc3_Simulink_1InstanceStruct
  *chartInstance)
{
  int32_T c3_i1;
  int32_T c3_i2;
  uint32_T c3_debug_family_var_map[4];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  c3_images_internal_coder_strel_StructuringElementHelper c3_diskElem;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i1 = 0; c3_i1 < 307200; c3_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c3_c_BW)[c3_i1], 0U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i2 = 0; c3_i2 < 307200; c3_i2++) {
    chartInstance->c3_BW[c3_i2] = (*chartInstance->c3_c_BW)[c3_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c3_BW, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c3_Im, 3U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_diskElem.matlabCodegenIsDeleted = false;
  for (c3_i3 = 0; c3_i3 < 25; c3_i3++) {
    c3_diskElem.Neighborhood[c3_i3] = true;
  }

  c3_diskElem.Dimensionality = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  for (c3_i4 = 0; c3_i4 < 307200; c3_i4++) {
    chartInstance->c3_b_BW[c3_i4] = chartInstance->c3_BW[c3_i4];
  }

  c3_imopen(chartInstance, chartInstance->c3_b_BW, &c3_diskElem,
            chartInstance->c3_bv1);
  for (c3_i5 = 0; c3_i5 < 307200; c3_i5++) {
    chartInstance->c3_Im[c3_i5] = chartInstance->c3_bv1[c3_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i6 = 0; c3_i6 < 307200; c3_i6++) {
    (*chartInstance->c3_b_Im)[c3_i6] = chartInstance->c3_Im[c3_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Simulink_1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c3_i7 = 0; c3_i7 < 307200; c3_i7++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c3_b_Im)[c3_i7], 1U);
  }
}

static void mdl_start_c3_Simulink_1(SFc3_Simulink_1InstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc3_Simulink_1(SFc3_Simulink_1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)(c3_machineNumber);
  (void)(c3_chartNumber);
  (void)(c3_instanceNumber);
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i8;
  int32_T c3_i9;
  const mxArray *c3_b_y = NULL;
  int32_T c3_i10;
  SFc3_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Simulink_1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_i8 = 0;
  for (c3_i9 = 0; c3_i9 < 640; c3_i9++) {
    for (c3_i10 = 0; c3_i10 < 480; c3_i10++) {
      chartInstance->c3_u[c3_i10 + c3_i8] = (*(boolean_T (*)[307200])c3_inData)
        [c3_i10 + c3_i8];
    }

    c3_i8 += 480;
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", chartInstance->c3_u, 11, 0U, 1U, 0U,
    2, 480, 640), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_Simulink_1InstanceStruct *chartInstance,
  const mxArray *c3_c_Im, const char_T *c3_identifier, boolean_T c3_b_y[307200])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_c_Im), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_c_Im);
}

static void c3_b_emlrt_marshallIn(SFc3_Simulink_1InstanceStruct *chartInstance,
  const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId, boolean_T
  c3_b_y[307200])
{
  int32_T c3_i11;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), chartInstance->c3_bv2, 1, 11,
                0U, 1, 0U, 2, 480, 640);
  for (c3_i11 = 0; c3_i11 < 307200; c3_i11++) {
    c3_b_y[c3_i11] = chartInstance->c3_bv2[c3_i11];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_c_Im;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  SFc3_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Simulink_1InstanceStruct *)chartInstanceVoid;
  c3_c_Im = sf_mex_dup(c3_mxArrayInData);
  c3_thisId.fIdentifier = (const char *)c3_varName;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_c_Im), &c3_thisId,
                        chartInstance->c3_y);
  sf_mex_destroy(&c3_c_Im);
  c3_i12 = 0;
  for (c3_i13 = 0; c3_i13 < 640; c3_i13++) {
    for (c3_i14 = 0; c3_i14 < 480; c3_i14++) {
      (*(boolean_T (*)[307200])c3_outData)[c3_i14 + c3_i12] =
        chartInstance->c3_y[c3_i14 + c3_i12];
    }

    c3_i12 += 480;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Simulink_1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_b_u = *(real_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_Simulink_1InstanceStruct *chartInstance,
  const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_b_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_b_y = c3_d0;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y;
  SFc3_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Simulink_1InstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_thisId.fIdentifier = (const char *)c3_varName;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout),
    &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_Simulink_1_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static void c3_imopen(SFc3_Simulink_1InstanceStruct *chartInstance, boolean_T
                      c3_d_A[307200],
                      c3_images_internal_coder_strel_StructuringElementHelper
                      *c3_se_, boolean_T c3_B[307200])
{
  int32_T c3_i15;
  int32_T c3_j;
  int32_T c3_b_j;
  int32_T c3_i;
  int32_T c3_c_j;
  int32_T c3_b_i;
  uint32_T c3_Apadpack[10304];
  int32_T c3_c_i;
  int32_T c3_i16;
  int32_T c3_i17;
  real_T c3_asize[2];
  int32_T c3_i18;
  boolean_T c3_nhood[3];
  real_T c3_nsize[2];
  uint32_T c3_b_B[10304];
  int32_T c3_i19;
  int32_T c3_i20;
  boolean_T c3_b_nhood;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  boolean_T c3_c_nhood;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i40;
  for (c3_i15 = 0; c3_i15 < 307200; c3_i15++) {
    chartInstance->c3_A[c3_i15] = c3_d_A[c3_i15];
  }

  c3_imerode(chartInstance, chartInstance->c3_A, c3_se_, chartInstance->c3_b_A);
  c3_b_padarray(chartInstance, chartInstance->c3_b_A, chartInstance->c3_Apadpre);
  for (c3_j = 0; c3_j < 2; c3_j++) {
    for (c3_i = 0; c3_i < 484; c3_i++) {
      chartInstance->c3_Apad[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c3_i), 1, 484) + 484 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c3_j +
        643)), 1, 644) - 1)) - 1] = false;
    }
  }

  for (c3_b_j = 0; c3_b_j < 642; c3_b_j++) {
    for (c3_b_i = 0; c3_b_i < 2; c3_b_i++) {
      chartInstance->c3_Apad[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c3_b_i
        + 483)), 1, 484) + 484 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c3_b_j), 1, 644) - 1)) - 1] = false;
    }
  }

  for (c3_c_j = 0; c3_c_j < 642; c3_c_j++) {
    for (c3_c_i = 0; c3_c_i < 482; c3_c_i++) {
      chartInstance->c3_Apad[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c3_c_i), 1, 484) + 484 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c3_c_j), 1, 644) - 1)) - 1] = chartInstance->c3_Apadpre
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
           (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c3_c_i), 1, 482) + 482 *
          (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
            (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c3_c_j), 1, 642) - 1))
        - 1];
    }
  }

  c3_bwpack(chartInstance, chartInstance->c3_Apad, c3_Apadpack);
  for (c3_i16 = 0; c3_i16 < 2; c3_i16++) {
    c3_asize[c3_i16] = 16.0 + 628.0 * (real_T)c3_i16;
  }

  for (c3_i17 = 0; c3_i17 < 3; c3_i17++) {
    c3_nhood[c3_i17] = true;
  }

  for (c3_i18 = 0; c3_i18 < 2; c3_i18++) {
    c3_nsize[c3_i18] = 3.0 + -2.0 * (real_T)c3_i18;
  }

  dilate_packed_uint32(c3_Apadpack, c3_asize, 2.0, c3_nhood, c3_nsize, 2.0,
                       c3_b_B);
  for (c3_i19 = 0; c3_i19 < 10304; c3_i19++) {
    c3_Apadpack[c3_i19] = c3_b_B[c3_i19];
  }

  for (c3_i20 = 0; c3_i20 < 2; c3_i20++) {
    c3_asize[c3_i20] = 16.0 + 628.0 * (real_T)c3_i20;
  }

  c3_b_nhood = true;
  for (c3_i21 = 0; c3_i21 < 2; c3_i21++) {
    c3_nsize[c3_i21] = 1.0;
  }

  dilate_packed_uint32(c3_Apadpack, c3_asize, 2.0, &c3_b_nhood, c3_nsize, 2.0,
                       c3_b_B);
  for (c3_i22 = 0; c3_i22 < 10304; c3_i22++) {
    c3_Apadpack[c3_i22] = c3_b_B[c3_i22];
  }

  for (c3_i23 = 0; c3_i23 < 2; c3_i23++) {
    c3_asize[c3_i23] = 16.0 + 628.0 * (real_T)c3_i23;
  }

  for (c3_i24 = 0; c3_i24 < 3; c3_i24++) {
    c3_nhood[c3_i24] = true;
  }

  for (c3_i25 = 0; c3_i25 < 2; c3_i25++) {
    c3_nsize[c3_i25] = 1.0 + 2.0 * (real_T)c3_i25;
  }

  dilate_packed_uint32(c3_Apadpack, c3_asize, 2.0, c3_nhood, c3_nsize, 2.0,
                       c3_b_B);
  for (c3_i26 = 0; c3_i26 < 10304; c3_i26++) {
    c3_Apadpack[c3_i26] = c3_b_B[c3_i26];
  }

  for (c3_i27 = 0; c3_i27 < 2; c3_i27++) {
    c3_asize[c3_i27] = 16.0 + 628.0 * (real_T)c3_i27;
  }

  c3_c_nhood = true;
  for (c3_i28 = 0; c3_i28 < 2; c3_i28++) {
    c3_nsize[c3_i28] = 1.0;
  }

  dilate_packed_uint32(c3_Apadpack, c3_asize, 2.0, &c3_c_nhood, c3_nsize, 2.0,
                       c3_b_B);
  for (c3_i29 = 0; c3_i29 < 10304; c3_i29++) {
    c3_Apadpack[c3_i29] = c3_b_B[c3_i29];
  }

  for (c3_i30 = 0; c3_i30 < 2; c3_i30++) {
    c3_asize[c3_i30] = 16.0 + 628.0 * (real_T)c3_i30;
  }

  for (c3_i31 = 0; c3_i31 < 3; c3_i31++) {
    c3_nhood[c3_i31] = true;
  }

  for (c3_i32 = 0; c3_i32 < 2; c3_i32++) {
    c3_nsize[c3_i32] = 1.0 + 2.0 * (real_T)c3_i32;
  }

  dilate_packed_uint32(c3_Apadpack, c3_asize, 2.0, c3_nhood, c3_nsize, 2.0,
                       c3_b_B);
  for (c3_i33 = 0; c3_i33 < 10304; c3_i33++) {
    c3_Apadpack[c3_i33] = c3_b_B[c3_i33];
  }

  for (c3_i34 = 0; c3_i34 < 2; c3_i34++) {
    c3_asize[c3_i34] = 16.0 + 628.0 * (real_T)c3_i34;
  }

  for (c3_i35 = 0; c3_i35 < 3; c3_i35++) {
    c3_nhood[c3_i35] = true;
  }

  for (c3_i36 = 0; c3_i36 < 2; c3_i36++) {
    c3_nsize[c3_i36] = 3.0 + -2.0 * (real_T)c3_i36;
  }

  dilate_packed_uint32(c3_Apadpack, c3_asize, 2.0, c3_nhood, c3_nsize, 2.0,
                       c3_b_B);
  c3_bwunpack(chartInstance, c3_b_B, chartInstance->c3_Apad);
  c3_i37 = 0;
  c3_i38 = 0;
  for (c3_i39 = 0; c3_i39 < 640; c3_i39++) {
    for (c3_i40 = 0; c3_i40 < 480; c3_i40++) {
      c3_B[c3_i40 + c3_i37] = chartInstance->c3_Apad[(c3_i40 + c3_i38) + 970];
    }

    c3_i37 += 480;
    c3_i38 += 484;
  }
}

static void c3_imerode(SFc3_Simulink_1InstanceStruct *chartInstance, boolean_T
  c3_d_A[307200], c3_images_internal_coder_strel_StructuringElementHelper *c3_se,
  boolean_T c3_B[307200])
{
  int32_T c3_i41;
  int32_T c3_j;
  int32_T c3_b_j;
  int32_T c3_i;
  int32_T c3_c_j;
  int32_T c3_b_i;
  uint32_T c3_Apadpack[10304];
  int32_T c3_c_i;
  int32_T c3_i42;
  int32_T c3_i43;
  real_T c3_asize[2];
  int32_T c3_i44;
  boolean_T c3_nhood[3];
  real_T c3_nsize[2];
  uint32_T c3_b_B[10304];
  int32_T c3_i45;
  int32_T c3_i46;
  boolean_T c3_b_nhood;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  boolean_T c3_c_nhood;
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  int32_T c3_i57;
  int32_T c3_i58;
  int32_T c3_i59;
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  int32_T c3_i64;
  int32_T c3_i65;
  int32_T c3_i66;
  (void)c3_se;
  for (c3_i41 = 0; c3_i41 < 307200; c3_i41++) {
    chartInstance->c3_c_A[c3_i41] = c3_d_A[c3_i41];
  }

  c3_padarray(chartInstance, chartInstance->c3_c_A, chartInstance->c3_b_Apadpre);
  for (c3_j = 0; c3_j < 2; c3_j++) {
    for (c3_i = 0; c3_i < 484; c3_i++) {
      chartInstance->c3_b_Apad[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c3_i), 1, 484) + 484 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c3_j +
        643)), 1, 644) - 1)) - 1] = true;
    }
  }

  for (c3_b_j = 0; c3_b_j < 642; c3_b_j++) {
    for (c3_b_i = 0; c3_b_i < 2; c3_b_i++) {
      chartInstance->c3_b_Apad[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c3_b_i
        + 483)), 1, 484) + 484 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c3_b_j), 1, 644) - 1)) - 1] = true;
    }
  }

  for (c3_c_j = 0; c3_c_j < 642; c3_c_j++) {
    for (c3_c_i = 0; c3_c_i < 482; c3_c_i++) {
      chartInstance->c3_b_Apad[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c3_c_i), 1, 484) + 484 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c3_c_j), 1, 644) - 1)) - 1] = chartInstance->c3_b_Apadpre
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
           (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c3_c_i), 1, 482) + 482 *
          (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
            (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c3_c_j), 1, 642) - 1))
        - 1];
    }
  }

  c3_bwpack(chartInstance, chartInstance->c3_b_Apad, c3_Apadpack);
  for (c3_i42 = 0; c3_i42 < 2; c3_i42++) {
    c3_asize[c3_i42] = 16.0 + 628.0 * (real_T)c3_i42;
  }

  for (c3_i43 = 0; c3_i43 < 3; c3_i43++) {
    c3_nhood[c3_i43] = true;
  }

  for (c3_i44 = 0; c3_i44 < 2; c3_i44++) {
    c3_nsize[c3_i44] = 3.0 + -2.0 * (real_T)c3_i44;
  }

  erode_packed_uint32(c3_Apadpack, c3_asize, 2.0, c3_nhood, c3_nsize, 2.0, 484.0,
                      c3_b_B);
  for (c3_i45 = 0; c3_i45 < 10304; c3_i45++) {
    c3_Apadpack[c3_i45] = c3_b_B[c3_i45];
  }

  for (c3_i46 = 0; c3_i46 < 2; c3_i46++) {
    c3_asize[c3_i46] = 16.0 + 628.0 * (real_T)c3_i46;
  }

  c3_b_nhood = true;
  for (c3_i47 = 0; c3_i47 < 2; c3_i47++) {
    c3_nsize[c3_i47] = 1.0;
  }

  erode_packed_uint32(c3_Apadpack, c3_asize, 2.0, &c3_b_nhood, c3_nsize, 2.0,
                      484.0, c3_b_B);
  for (c3_i48 = 0; c3_i48 < 10304; c3_i48++) {
    c3_Apadpack[c3_i48] = c3_b_B[c3_i48];
  }

  for (c3_i49 = 0; c3_i49 < 2; c3_i49++) {
    c3_asize[c3_i49] = 16.0 + 628.0 * (real_T)c3_i49;
  }

  for (c3_i50 = 0; c3_i50 < 3; c3_i50++) {
    c3_nhood[c3_i50] = true;
  }

  for (c3_i51 = 0; c3_i51 < 2; c3_i51++) {
    c3_nsize[c3_i51] = 1.0 + 2.0 * (real_T)c3_i51;
  }

  erode_packed_uint32(c3_Apadpack, c3_asize, 2.0, c3_nhood, c3_nsize, 2.0, 484.0,
                      c3_b_B);
  for (c3_i52 = 0; c3_i52 < 10304; c3_i52++) {
    c3_Apadpack[c3_i52] = c3_b_B[c3_i52];
  }

  for (c3_i53 = 0; c3_i53 < 2; c3_i53++) {
    c3_asize[c3_i53] = 16.0 + 628.0 * (real_T)c3_i53;
  }

  c3_c_nhood = true;
  for (c3_i54 = 0; c3_i54 < 2; c3_i54++) {
    c3_nsize[c3_i54] = 1.0;
  }

  erode_packed_uint32(c3_Apadpack, c3_asize, 2.0, &c3_c_nhood, c3_nsize, 2.0,
                      484.0, c3_b_B);
  for (c3_i55 = 0; c3_i55 < 10304; c3_i55++) {
    c3_Apadpack[c3_i55] = c3_b_B[c3_i55];
  }

  for (c3_i56 = 0; c3_i56 < 2; c3_i56++) {
    c3_asize[c3_i56] = 16.0 + 628.0 * (real_T)c3_i56;
  }

  for (c3_i57 = 0; c3_i57 < 3; c3_i57++) {
    c3_nhood[c3_i57] = true;
  }

  for (c3_i58 = 0; c3_i58 < 2; c3_i58++) {
    c3_nsize[c3_i58] = 1.0 + 2.0 * (real_T)c3_i58;
  }

  erode_packed_uint32(c3_Apadpack, c3_asize, 2.0, c3_nhood, c3_nsize, 2.0, 484.0,
                      c3_b_B);
  for (c3_i59 = 0; c3_i59 < 10304; c3_i59++) {
    c3_Apadpack[c3_i59] = c3_b_B[c3_i59];
  }

  for (c3_i60 = 0; c3_i60 < 2; c3_i60++) {
    c3_asize[c3_i60] = 16.0 + 628.0 * (real_T)c3_i60;
  }

  for (c3_i61 = 0; c3_i61 < 3; c3_i61++) {
    c3_nhood[c3_i61] = true;
  }

  for (c3_i62 = 0; c3_i62 < 2; c3_i62++) {
    c3_nsize[c3_i62] = 3.0 + -2.0 * (real_T)c3_i62;
  }

  erode_packed_uint32(c3_Apadpack, c3_asize, 2.0, c3_nhood, c3_nsize, 2.0, 484.0,
                      c3_b_B);
  c3_bwunpack(chartInstance, c3_b_B, chartInstance->c3_b_Apad);
  c3_i63 = 0;
  c3_i64 = 0;
  for (c3_i65 = 0; c3_i65 < 640; c3_i65++) {
    for (c3_i66 = 0; c3_i66 < 480; c3_i66++) {
      c3_B[c3_i66 + c3_i63] = chartInstance->c3_b_Apad[(c3_i66 + c3_i64) + 970];
    }

    c3_i63 += 480;
    c3_i64 += 484;
  }
}

static void c3_padarray(SFc3_Simulink_1InstanceStruct *chartInstance, boolean_T
  c3_varargin_1[307200], boolean_T c3_b[309444])
{
  int32_T c3_j;
  int32_T c3_b_j;
  int32_T c3_i;
  int32_T c3_c_j;
  int32_T c3_b_i;
  int32_T c3_c_i;
  for (c3_j = 0; c3_j < 2; c3_j++) {
    for (c3_i = 0; c3_i < 482; c3_i++) {
      c3_b[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c3_i), 1, 482) + 482 *
            (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
              sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c3_j),
              1, 642) - 1)) - 1] = true;
    }
  }

  for (c3_b_j = 0; c3_b_j < 640; c3_b_j++) {
    for (c3_b_i = 0; c3_b_i < 2; c3_b_i++) {
      c3_b[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c3_b_i), 1, 482) + 482
            * (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
              sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c3_b_j + 3)),
              1, 642) - 1)) - 1] = true;
    }
  }

  for (c3_c_j = 0; c3_c_j < 640; c3_c_j++) {
    for (c3_c_i = 0; c3_c_i < 480; c3_c_i++) {
      c3_b[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, (real_T)(c3_c_i + 3)), 1, 482) + 482
            * (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
              sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c3_c_j + 3)),
              1, 642) - 1)) - 1] = c3_varargin_1[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c3_c_i), 1, 480) + 480 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c3_c_j), 1, 640) - 1)) - 1];
    }
  }
}

static void c3_bwpack(SFc3_Simulink_1InstanceStruct *chartInstance, boolean_T
                      c3_varargin_1[311696], uint32_T c3_BWP[10304])
{
  int32_T c3_i67;
  int32_T c3_i68;
  real_T c3_dv0[2];
  real_T c3_dv1[2];
  (void)chartInstance;
  for (c3_i67 = 0; c3_i67 < 2; c3_i67++) {
    c3_dv0[c3_i67] = 484.0 + 160.0 * (real_T)c3_i67;
  }

  for (c3_i68 = 0; c3_i68 < 2; c3_i68++) {
    c3_dv1[c3_i68] = 16.0 + 628.0 * (real_T)c3_i68;
  }

  bwPackingtbb(c3_varargin_1, c3_dv0, c3_BWP, c3_dv1);
}

static void c3_bwunpack(SFc3_Simulink_1InstanceStruct *chartInstance, uint32_T
  c3_varargin_1[10304], boolean_T c3_d_BW[311696])
{
  int32_T c3_i69;
  int32_T c3_i70;
  real_T c3_dv2[2];
  real_T c3_dv3[2];
  (void)chartInstance;
  for (c3_i69 = 0; c3_i69 < 2; c3_i69++) {
    c3_dv2[c3_i69] = 16.0 + 628.0 * (real_T)c3_i69;
  }

  for (c3_i70 = 0; c3_i70 < 2; c3_i70++) {
    c3_dv3[c3_i70] = 484.0 + 160.0 * (real_T)c3_i70;
  }

  bwUnpackingtbb(c3_varargin_1, c3_dv2, c3_d_BW, c3_dv3);
}

static void c3_b_padarray(SFc3_Simulink_1InstanceStruct *chartInstance,
  boolean_T c3_varargin_1[307200], boolean_T c3_b[309444])
{
  int32_T c3_j;
  int32_T c3_b_j;
  int32_T c3_i;
  int32_T c3_c_j;
  int32_T c3_b_i;
  int32_T c3_c_i;
  for (c3_j = 0; c3_j < 2; c3_j++) {
    for (c3_i = 0; c3_i < 482; c3_i++) {
      c3_b[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c3_i), 1, 482) + 482 *
            (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
              sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c3_j),
              1, 642) - 1)) - 1] = false;
    }
  }

  for (c3_b_j = 0; c3_b_j < 640; c3_b_j++) {
    for (c3_b_i = 0; c3_b_i < 2; c3_b_i++) {
      c3_b[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)c3_b_i), 1, 482) + 482
            * (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
              sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c3_b_j + 3)),
              1, 642) - 1)) - 1] = false;
    }
  }

  for (c3_c_j = 0; c3_c_j < 640; c3_c_j++) {
    for (c3_c_i = 0; c3_c_i < 480; c3_c_i++) {
      c3_b[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, (real_T)(c3_c_i + 3)), 1, 482) + 482
            * (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
              sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c3_c_j + 3)),
              1, 642) - 1)) - 1] = c3_varargin_1[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c3_c_i), 1, 480) + 480 * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 1.0 + (real_T)
        c3_c_j), 1, 640) - 1)) - 1];
    }
  }
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Simulink_1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_b_u = *(int32_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_b_y;
  int32_T c3_i71;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_i71, 1, 6, 0U, 0, 0U, 0);
  c3_b_y = c3_i71;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_b_y;
  SFc3_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Simulink_1InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_thisId.fIdentifier = (const char *)c3_varName;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_Simulink_1, const char_T
  *c3_identifier)
{
  uint8_T c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_Simulink_1), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_Simulink_1);
  return c3_b_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_Simulink_1InstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_b_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_b_y = c3_u0;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void init_dsm_address_info(SFc3_Simulink_1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_Simulink_1InstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_c_BW = (boolean_T (*)[307200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_b_Im = (boolean_T (*)[307200])ssGetOutputPortSignal_wrapper
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

void sf_c3_Simulink_1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1911090102U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3637103676U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3674173118U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(363949365U);
}

mxArray* sf_c3_Simulink_1_get_post_codegen_info(void);
mxArray *sf_c3_Simulink_1_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c3_Simulink_1_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Simulink_1_third_party_uses_info(void)
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

mxArray *sf_c3_Simulink_1_jit_fallback_info(void)
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

mxArray *sf_c3_Simulink_1_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_Simulink_1_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_Simulink_1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Im\",},{M[8],M[0],T\"is_active_c3_Simulink_1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Simulink_1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Simulink_1InstanceStruct *chartInstance =
      (SFc3_Simulink_1InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Simulink_1MachineNumber_,
           3,
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
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 480U;
          dimVector[1]= 640U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
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
    SFc3_Simulink_1InstanceStruct *chartInstance =
      (SFc3_Simulink_1InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c3_c_BW);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c3_b_Im);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sa0vPifsfqgvjeVhsf8r5LG";
}

static void sf_opaque_initialize_c3_Simulink_1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_Simulink_1InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c3_Simulink_1((SFc3_Simulink_1InstanceStruct*)
    chartInstanceVar);
  initialize_c3_Simulink_1((SFc3_Simulink_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_Simulink_1(void *chartInstanceVar)
{
  enable_c3_Simulink_1((SFc3_Simulink_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_Simulink_1(void *chartInstanceVar)
{
  disable_c3_Simulink_1((SFc3_Simulink_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_Simulink_1(void *chartInstanceVar)
{
  sf_gateway_c3_Simulink_1((SFc3_Simulink_1InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_Simulink_1(SimStruct* S)
{
  return get_sim_state_c3_Simulink_1((SFc3_Simulink_1InstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_Simulink_1(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c3_Simulink_1((SFc3_Simulink_1InstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_Simulink_1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_Simulink_1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Simulink_1_optimization_info();
    }

    finalize_c3_Simulink_1((SFc3_Simulink_1InstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Simulink_1((SFc3_Simulink_1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Simulink_1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_Simulink_1((SFc3_Simulink_1InstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_Simulink_1(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
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

static void mdlRTW_c3_Simulink_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_Simulink_1(SimStruct *S)
{
  SFc3_Simulink_1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Simulink_1InstanceStruct *)utMalloc(sizeof
    (SFc3_Simulink_1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_Simulink_1InstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_Simulink_1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_Simulink_1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_Simulink_1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_Simulink_1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_Simulink_1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_Simulink_1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_Simulink_1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_Simulink_1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Simulink_1;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Simulink_1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_Simulink_1;
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
  mdl_start_c3_Simulink_1(chartInstance);
}

void c3_Simulink_1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Simulink_1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Simulink_1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Simulink_1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Simulink_1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
