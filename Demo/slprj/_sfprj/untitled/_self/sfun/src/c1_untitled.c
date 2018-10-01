/* Include files */

#include "untitled_sfun.h"
#include "c1_untitled.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "untitled_sfun_debug_macros.h"
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
static const char * c1_debug_family_names[11] = { "I", "channel1Min",
  "channel1Max", "channel2Min", "channel2Max", "channel3Min", "channel3Max",
  "nargin", "nargout", "videoframe", "BW" };

/* Function Declarations */
static void initialize_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void initialize_params_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance);
static void enable_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void disable_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance);
static void set_sim_state_c1_untitled(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_st);
static void finalize_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void sf_gateway_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void mdl_start_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void c1_chartstep_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void initSimStructsc1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_c_BW, const char_T *c1_identifier, boolean_T c1_c_y[307200]);
static void c1_b_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId, boolean_T
  c1_c_y[307200]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_d_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId, real32_T c1_c_y
  [921600]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_e_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_f_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_untitled, const char_T *c1_identifier);
static uint8_T c1_g_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_untitledInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc1_untitledInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_untitled(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_untitled = 0U;
}

static void initialize_params_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  uint8_T c1_hoistedGlobal;
  const mxArray *c1_e_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_createcellmatrix(2, 1), false);
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", *chartInstance->c1_b_BW, 11, 0U, 1U,
    0U, 2, 480, 640), false);
  sf_mex_setcell(c1_c_y, 0, c1_d_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_untitled;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_c_y, 1, c1_e_y);
  sf_mex_assign(&c1_st, c1_c_y, false);
  return c1_st;
}

static void set_sim_state_c1_untitled(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_st)
{
  const mxArray *c1_c_u;
  int32_T c1_i0;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_c_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_c_u, 0)), "BW",
                      chartInstance->c1_bv0);
  for (c1_i0 = 0; c1_i0 < 307200; c1_i0++) {
    (*chartInstance->c1_b_BW)[c1_i0] = chartInstance->c1_bv0[c1_i0];
  }

  chartInstance->c1_is_active_c1_untitled = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_c_u, 1)), "is_active_c1_untitled");
  sf_mex_destroy(&c1_c_u);
  c1_update_debugger_state_c1_untitled(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  int32_T c1_i1;
  int32_T c1_i2;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i1 = 0; c1_i1 < 921600; c1_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_b_videoframe)[c1_i1], 0U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_untitled(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_untitledMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c1_i2 = 0; c1_i2 < 307200; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_b_BW)[c1_i2], 1U);
  }
}

static void mdl_start_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void c1_chartstep_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  int32_T c1_i3;
  uint32_T c1_debug_family_var_map[11];
  real_T c1_channel1Min;
  real_T c1_channel1Max;
  real_T c1_channel2Min;
  real_T c1_channel2Max;
  real_T c1_channel3Min;
  real_T c1_channel3Max;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i3 = 0; c1_i3 < 921600; c1_i3++) {
    chartInstance->c1_videoframe[c1_i3] = (*chartInstance->c1_b_videoframe)
      [c1_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c1_I, 0U,
    c1_b_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_channel1Min, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_channel1Max, 2U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_channel2Min, 3U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_channel2Max, 4U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_channel3Min, 5U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_channel3Max, 6U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 7U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 8U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c1_videoframe, 9U,
    c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c1_BW, 10U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  for (c1_i4 = 0; c1_i4 < 921600; c1_i4++) {
    chartInstance->c1_X[c1_i4] = chartInstance->c1_videoframe[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 921600; c1_i5++) {
    chartInstance->c1_outputImage[c1_i5] = chartInstance->c1_I[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 921600; c1_i6++) {
    chartInstance->c1_I[c1_i6] = chartInstance->c1_outputImage[c1_i6];
  }

  rgb2hsv_tbb_real32(chartInstance->c1_X, 307200.0, chartInstance->c1_I);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_channel1Min = 0.476;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_channel1Max = 0.535;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_channel2Min = 0.486;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_channel2Max = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_channel3Min = 0.257;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  c1_channel3Max = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_i7 = 0;
  for (c1_i8 = 0; c1_i8 < 640; c1_i8++) {
    for (c1_i10 = 0; c1_i10 < 480; c1_i10++) {
      chartInstance->c1_bv1[c1_i10 + c1_i7] = ((real_T)chartInstance->
        c1_I[c1_i10 + c1_i7] >= c1_channel1Min);
    }

    c1_i7 += 480;
  }

  c1_i9 = 0;
  for (c1_i11 = 0; c1_i11 < 640; c1_i11++) {
    for (c1_i13 = 0; c1_i13 < 480; c1_i13++) {
      chartInstance->c1_bv2[c1_i13 + c1_i9] = ((real_T)chartInstance->
        c1_I[c1_i13 + c1_i9] <= c1_channel1Max);
    }

    c1_i9 += 480;
  }

  c1_i12 = 0;
  for (c1_i14 = 0; c1_i14 < 640; c1_i14++) {
    for (c1_i16 = 0; c1_i16 < 480; c1_i16++) {
      chartInstance->c1_bv3[c1_i16 + c1_i12] = ((real_T)chartInstance->c1_I
        [(c1_i16 + c1_i12) + 307200] >= c1_channel2Min);
    }

    c1_i12 += 480;
  }

  c1_i15 = 0;
  for (c1_i17 = 0; c1_i17 < 640; c1_i17++) {
    for (c1_i19 = 0; c1_i19 < 480; c1_i19++) {
      chartInstance->c1_bv4[c1_i19 + c1_i15] = ((real_T)chartInstance->c1_I
        [(c1_i19 + c1_i15) + 307200] <= c1_channel2Max);
    }

    c1_i15 += 480;
  }

  c1_i18 = 0;
  for (c1_i20 = 0; c1_i20 < 640; c1_i20++) {
    for (c1_i22 = 0; c1_i22 < 480; c1_i22++) {
      chartInstance->c1_bv5[c1_i22 + c1_i18] = ((real_T)chartInstance->c1_I
        [(c1_i22 + c1_i18) + 614400] >= c1_channel3Min);
    }

    c1_i18 += 480;
  }

  c1_i21 = 0;
  for (c1_i23 = 0; c1_i23 < 640; c1_i23++) {
    for (c1_i25 = 0; c1_i25 < 480; c1_i25++) {
      chartInstance->c1_bv6[c1_i25 + c1_i21] = ((real_T)chartInstance->c1_I
        [(c1_i25 + c1_i21) + 614400] <= c1_channel3Max);
    }

    c1_i21 += 480;
  }

  for (c1_i24 = 0; c1_i24 < 307200; c1_i24++) {
    chartInstance->c1_BW[c1_i24] = (chartInstance->c1_bv1[c1_i24] &&
      chartInstance->c1_bv2[c1_i24] && chartInstance->c1_bv3[c1_i24] &&
      chartInstance->c1_bv4[c1_i24] && chartInstance->c1_bv5[c1_i24] &&
      chartInstance->c1_bv6[c1_i24]);
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i26 = 0; c1_i26 < 307200; c1_i26++) {
    (*chartInstance->c1_b_BW)[c1_i26] = chartInstance->c1_BW[c1_i26];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)(c1_machineNumber);
  (void)(c1_chartNumber);
  (void)(c1_instanceNumber);
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i27;
  int32_T c1_i28;
  const mxArray *c1_c_y = NULL;
  int32_T c1_i29;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i27 = 0;
  for (c1_i28 = 0; c1_i28 < 640; c1_i28++) {
    for (c1_i29 = 0; c1_i29 < 480; c1_i29++) {
      chartInstance->c1_b_u[c1_i29 + c1_i27] = (*(boolean_T (*)[307200])
        c1_inData)[c1_i29 + c1_i27];
    }

    c1_i27 += 480;
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", chartInstance->c1_b_u, 11, 0U, 1U,
    0U, 2, 480, 640), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_c_y, false);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_c_BW, const char_T *c1_identifier, boolean_T c1_c_y[307200])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_c_BW), &c1_thisId, c1_c_y);
  sf_mex_destroy(&c1_c_BW);
}

static void c1_b_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId, boolean_T
  c1_c_y[307200])
{
  int32_T c1_i30;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_c_u), chartInstance->c1_bv7, 1, 11,
                0U, 1, 0U, 2, 480, 640);
  for (c1_i30 = 0; c1_i30 < 307200; c1_i30++) {
    c1_c_y[c1_i30] = chartInstance->c1_bv7[c1_i30];
  }

  sf_mex_destroy(&c1_c_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_c_BW;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_c_BW = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_c_BW), &c1_thisId,
                        chartInstance->c1_b_y);
  sf_mex_destroy(&c1_c_BW);
  c1_i31 = 0;
  for (c1_i32 = 0; c1_i32 < 640; c1_i32++) {
    for (c1_i33 = 0; c1_i33 < 480; c1_i33++) {
      (*(boolean_T (*)[307200])c1_outData)[c1_i33 + c1_i31] =
        chartInstance->c1_b_y[c1_i33 + c1_i31];
    }

    c1_i31 += 480;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i34;
  int32_T c1_i35;
  const mxArray *c1_c_y = NULL;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i34 = 0;
  for (c1_i35 = 0; c1_i35 < 3; c1_i35++) {
    c1_i36 = 0;
    for (c1_i37 = 0; c1_i37 < 640; c1_i37++) {
      for (c1_i38 = 0; c1_i38 < 480; c1_i38++) {
        chartInstance->c1_u[(c1_i38 + c1_i36) + c1_i34] = (*(real32_T (*)[921600])
          c1_inData)[(c1_i38 + c1_i36) + c1_i34];
      }

      c1_i36 += 480;
    }

    c1_i34 += 307200;
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", chartInstance->c1_u, 1, 0U, 1U, 0U,
    3, 480, 640, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_c_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_c_u = *(real_T *)c1_inData;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_c_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_c_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_c_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_c_y = c1_d0;
  sf_mex_destroy(&c1_c_u);
  return c1_c_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_c_y;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_c_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout),
    &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_c_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_d_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId, real32_T c1_c_y
  [921600])
{
  int32_T c1_i39;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_c_u), chartInstance->c1_fv0, 1, 1, 0U,
                1, 0U, 3, 480, 640, 3);
  for (c1_i39 = 0; c1_i39 < 921600; c1_i39++) {
    c1_c_y[c1_i39] = chartInstance->c1_fv0[c1_i39];
  }

  sf_mex_destroy(&c1_c_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_I;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_b_I = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_I), &c1_thisId,
                        chartInstance->c1_y);
  sf_mex_destroy(&c1_b_I);
  c1_i40 = 0;
  for (c1_i41 = 0; c1_i41 < 3; c1_i41++) {
    c1_i42 = 0;
    for (c1_i43 = 0; c1_i43 < 640; c1_i43++) {
      for (c1_i44 = 0; c1_i44 < 480; c1_i44++) {
        (*(real32_T (*)[921600])c1_outData)[(c1_i44 + c1_i42) + c1_i40] =
          chartInstance->c1_y[(c1_i44 + c1_i42) + c1_i40];
      }

      c1_i42 += 480;
    }

    c1_i40 += 307200;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_untitled_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_c_u = *(int32_T *)c1_inData;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_c_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_e_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_c_y;
  int32_T c1_i45;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_c_u), &c1_i45, 1, 6, 0U, 0, 0U, 0);
  c1_c_y = c1_i45;
  sf_mex_destroy(&c1_c_u);
  return c1_c_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_c_y;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_c_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_c_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_untitled, const char_T *c1_identifier)
{
  uint8_T c1_c_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_c_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_untitled), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_untitled);
  return c1_c_y;
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_c_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_c_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_c_y = c1_u0;
  sf_mex_destroy(&c1_c_u);
  return c1_c_y;
}

static void init_dsm_address_info(SFc1_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_untitledInstanceStruct *chartInstance)
{
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_b_videoframe = (real32_T (*)[921600])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c1_b_BW = (boolean_T (*)[307200])ssGetOutputPortSignal_wrapper
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

void sf_c1_untitled_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2892028499U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2203963176U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(953056326U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4290969386U);
}

mxArray* sf_c1_untitled_get_post_codegen_info(void);
mxArray *sf_c1_untitled_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("XvHl266Sll8Fkd214egJEC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      pr[2] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
    mxArray* mxPostCodegenInfo = sf_c1_untitled_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_untitled_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2hsvBuildable"));
  return(mxcell3p);
}

mxArray *sf_c1_untitled_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("rgb2hsv_tbb_real32");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_untitled_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_untitled_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_untitled(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"BW\",},{M[8],M[0],T\"is_active_c1_untitled\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_untitled_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_untitledInstanceStruct *chartInstance = (SFc1_untitledInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _untitledMachineNumber_,
           1,
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
        init_script_number_translation(_untitledMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_untitledMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _untitledMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"videoframe");
          _SFD_SET_DATA_PROPS(1,2,0,1,"BW");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,683);

        {
          unsigned int dimVector[3];
          dimVector[0]= 480U;
          dimVector[1]= 640U;
          dimVector[2]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 480U;
          dimVector[1]= 640U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _untitledMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_untitledInstanceStruct *chartInstance = (SFc1_untitledInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c1_b_videoframe);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c1_b_BW);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "seUH5W6AsDTzUqgGI45gvHD";
}

static void sf_opaque_initialize_c1_untitled(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_untitledInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
  initialize_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_untitled(void *chartInstanceVar)
{
  enable_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_untitled(void *chartInstanceVar)
{
  disable_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_untitled(void *chartInstanceVar)
{
  sf_gateway_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_untitled(SimStruct* S)
{
  return get_sim_state_c1_untitled((SFc1_untitledInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_untitled(SimStruct* S, const mxArray *st)
{
  set_sim_state_c1_untitled((SFc1_untitledInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_untitled(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_untitledInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_untitled_optimization_info();
    }

    finalize_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_untitled(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_untitled((SFc1_untitledInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_untitled(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_untitled_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(305114985U));
  ssSetChecksum1(S,(581360406U));
  ssSetChecksum2(S,(1155981724U));
  ssSetChecksum3(S,(108958716U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_untitled(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_untitled(SimStruct *S)
{
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)utMalloc(sizeof
    (SFc1_untitledInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_untitledInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_untitled;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_untitled;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_untitled;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_untitled;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_untitled;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_untitled;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_untitled;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_untitled;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_untitled;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_untitled;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_untitled;
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
  mdl_start_c1_untitled(chartInstance);
}

void c1_untitled_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_untitled(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_untitled(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_untitled(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_untitled_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
