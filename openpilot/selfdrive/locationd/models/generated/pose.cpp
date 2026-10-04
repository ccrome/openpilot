#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_849063694558529375) {
   out_849063694558529375[0] = delta_x[0] + nom_x[0];
   out_849063694558529375[1] = delta_x[1] + nom_x[1];
   out_849063694558529375[2] = delta_x[2] + nom_x[2];
   out_849063694558529375[3] = delta_x[3] + nom_x[3];
   out_849063694558529375[4] = delta_x[4] + nom_x[4];
   out_849063694558529375[5] = delta_x[5] + nom_x[5];
   out_849063694558529375[6] = delta_x[6] + nom_x[6];
   out_849063694558529375[7] = delta_x[7] + nom_x[7];
   out_849063694558529375[8] = delta_x[8] + nom_x[8];
   out_849063694558529375[9] = delta_x[9] + nom_x[9];
   out_849063694558529375[10] = delta_x[10] + nom_x[10];
   out_849063694558529375[11] = delta_x[11] + nom_x[11];
   out_849063694558529375[12] = delta_x[12] + nom_x[12];
   out_849063694558529375[13] = delta_x[13] + nom_x[13];
   out_849063694558529375[14] = delta_x[14] + nom_x[14];
   out_849063694558529375[15] = delta_x[15] + nom_x[15];
   out_849063694558529375[16] = delta_x[16] + nom_x[16];
   out_849063694558529375[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5536998468017687086) {
   out_5536998468017687086[0] = -nom_x[0] + true_x[0];
   out_5536998468017687086[1] = -nom_x[1] + true_x[1];
   out_5536998468017687086[2] = -nom_x[2] + true_x[2];
   out_5536998468017687086[3] = -nom_x[3] + true_x[3];
   out_5536998468017687086[4] = -nom_x[4] + true_x[4];
   out_5536998468017687086[5] = -nom_x[5] + true_x[5];
   out_5536998468017687086[6] = -nom_x[6] + true_x[6];
   out_5536998468017687086[7] = -nom_x[7] + true_x[7];
   out_5536998468017687086[8] = -nom_x[8] + true_x[8];
   out_5536998468017687086[9] = -nom_x[9] + true_x[9];
   out_5536998468017687086[10] = -nom_x[10] + true_x[10];
   out_5536998468017687086[11] = -nom_x[11] + true_x[11];
   out_5536998468017687086[12] = -nom_x[12] + true_x[12];
   out_5536998468017687086[13] = -nom_x[13] + true_x[13];
   out_5536998468017687086[14] = -nom_x[14] + true_x[14];
   out_5536998468017687086[15] = -nom_x[15] + true_x[15];
   out_5536998468017687086[16] = -nom_x[16] + true_x[16];
   out_5536998468017687086[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_8675581923907159569) {
   out_8675581923907159569[0] = 1.0;
   out_8675581923907159569[1] = 0.0;
   out_8675581923907159569[2] = 0.0;
   out_8675581923907159569[3] = 0.0;
   out_8675581923907159569[4] = 0.0;
   out_8675581923907159569[5] = 0.0;
   out_8675581923907159569[6] = 0.0;
   out_8675581923907159569[7] = 0.0;
   out_8675581923907159569[8] = 0.0;
   out_8675581923907159569[9] = 0.0;
   out_8675581923907159569[10] = 0.0;
   out_8675581923907159569[11] = 0.0;
   out_8675581923907159569[12] = 0.0;
   out_8675581923907159569[13] = 0.0;
   out_8675581923907159569[14] = 0.0;
   out_8675581923907159569[15] = 0.0;
   out_8675581923907159569[16] = 0.0;
   out_8675581923907159569[17] = 0.0;
   out_8675581923907159569[18] = 0.0;
   out_8675581923907159569[19] = 1.0;
   out_8675581923907159569[20] = 0.0;
   out_8675581923907159569[21] = 0.0;
   out_8675581923907159569[22] = 0.0;
   out_8675581923907159569[23] = 0.0;
   out_8675581923907159569[24] = 0.0;
   out_8675581923907159569[25] = 0.0;
   out_8675581923907159569[26] = 0.0;
   out_8675581923907159569[27] = 0.0;
   out_8675581923907159569[28] = 0.0;
   out_8675581923907159569[29] = 0.0;
   out_8675581923907159569[30] = 0.0;
   out_8675581923907159569[31] = 0.0;
   out_8675581923907159569[32] = 0.0;
   out_8675581923907159569[33] = 0.0;
   out_8675581923907159569[34] = 0.0;
   out_8675581923907159569[35] = 0.0;
   out_8675581923907159569[36] = 0.0;
   out_8675581923907159569[37] = 0.0;
   out_8675581923907159569[38] = 1.0;
   out_8675581923907159569[39] = 0.0;
   out_8675581923907159569[40] = 0.0;
   out_8675581923907159569[41] = 0.0;
   out_8675581923907159569[42] = 0.0;
   out_8675581923907159569[43] = 0.0;
   out_8675581923907159569[44] = 0.0;
   out_8675581923907159569[45] = 0.0;
   out_8675581923907159569[46] = 0.0;
   out_8675581923907159569[47] = 0.0;
   out_8675581923907159569[48] = 0.0;
   out_8675581923907159569[49] = 0.0;
   out_8675581923907159569[50] = 0.0;
   out_8675581923907159569[51] = 0.0;
   out_8675581923907159569[52] = 0.0;
   out_8675581923907159569[53] = 0.0;
   out_8675581923907159569[54] = 0.0;
   out_8675581923907159569[55] = 0.0;
   out_8675581923907159569[56] = 0.0;
   out_8675581923907159569[57] = 1.0;
   out_8675581923907159569[58] = 0.0;
   out_8675581923907159569[59] = 0.0;
   out_8675581923907159569[60] = 0.0;
   out_8675581923907159569[61] = 0.0;
   out_8675581923907159569[62] = 0.0;
   out_8675581923907159569[63] = 0.0;
   out_8675581923907159569[64] = 0.0;
   out_8675581923907159569[65] = 0.0;
   out_8675581923907159569[66] = 0.0;
   out_8675581923907159569[67] = 0.0;
   out_8675581923907159569[68] = 0.0;
   out_8675581923907159569[69] = 0.0;
   out_8675581923907159569[70] = 0.0;
   out_8675581923907159569[71] = 0.0;
   out_8675581923907159569[72] = 0.0;
   out_8675581923907159569[73] = 0.0;
   out_8675581923907159569[74] = 0.0;
   out_8675581923907159569[75] = 0.0;
   out_8675581923907159569[76] = 1.0;
   out_8675581923907159569[77] = 0.0;
   out_8675581923907159569[78] = 0.0;
   out_8675581923907159569[79] = 0.0;
   out_8675581923907159569[80] = 0.0;
   out_8675581923907159569[81] = 0.0;
   out_8675581923907159569[82] = 0.0;
   out_8675581923907159569[83] = 0.0;
   out_8675581923907159569[84] = 0.0;
   out_8675581923907159569[85] = 0.0;
   out_8675581923907159569[86] = 0.0;
   out_8675581923907159569[87] = 0.0;
   out_8675581923907159569[88] = 0.0;
   out_8675581923907159569[89] = 0.0;
   out_8675581923907159569[90] = 0.0;
   out_8675581923907159569[91] = 0.0;
   out_8675581923907159569[92] = 0.0;
   out_8675581923907159569[93] = 0.0;
   out_8675581923907159569[94] = 0.0;
   out_8675581923907159569[95] = 1.0;
   out_8675581923907159569[96] = 0.0;
   out_8675581923907159569[97] = 0.0;
   out_8675581923907159569[98] = 0.0;
   out_8675581923907159569[99] = 0.0;
   out_8675581923907159569[100] = 0.0;
   out_8675581923907159569[101] = 0.0;
   out_8675581923907159569[102] = 0.0;
   out_8675581923907159569[103] = 0.0;
   out_8675581923907159569[104] = 0.0;
   out_8675581923907159569[105] = 0.0;
   out_8675581923907159569[106] = 0.0;
   out_8675581923907159569[107] = 0.0;
   out_8675581923907159569[108] = 0.0;
   out_8675581923907159569[109] = 0.0;
   out_8675581923907159569[110] = 0.0;
   out_8675581923907159569[111] = 0.0;
   out_8675581923907159569[112] = 0.0;
   out_8675581923907159569[113] = 0.0;
   out_8675581923907159569[114] = 1.0;
   out_8675581923907159569[115] = 0.0;
   out_8675581923907159569[116] = 0.0;
   out_8675581923907159569[117] = 0.0;
   out_8675581923907159569[118] = 0.0;
   out_8675581923907159569[119] = 0.0;
   out_8675581923907159569[120] = 0.0;
   out_8675581923907159569[121] = 0.0;
   out_8675581923907159569[122] = 0.0;
   out_8675581923907159569[123] = 0.0;
   out_8675581923907159569[124] = 0.0;
   out_8675581923907159569[125] = 0.0;
   out_8675581923907159569[126] = 0.0;
   out_8675581923907159569[127] = 0.0;
   out_8675581923907159569[128] = 0.0;
   out_8675581923907159569[129] = 0.0;
   out_8675581923907159569[130] = 0.0;
   out_8675581923907159569[131] = 0.0;
   out_8675581923907159569[132] = 0.0;
   out_8675581923907159569[133] = 1.0;
   out_8675581923907159569[134] = 0.0;
   out_8675581923907159569[135] = 0.0;
   out_8675581923907159569[136] = 0.0;
   out_8675581923907159569[137] = 0.0;
   out_8675581923907159569[138] = 0.0;
   out_8675581923907159569[139] = 0.0;
   out_8675581923907159569[140] = 0.0;
   out_8675581923907159569[141] = 0.0;
   out_8675581923907159569[142] = 0.0;
   out_8675581923907159569[143] = 0.0;
   out_8675581923907159569[144] = 0.0;
   out_8675581923907159569[145] = 0.0;
   out_8675581923907159569[146] = 0.0;
   out_8675581923907159569[147] = 0.0;
   out_8675581923907159569[148] = 0.0;
   out_8675581923907159569[149] = 0.0;
   out_8675581923907159569[150] = 0.0;
   out_8675581923907159569[151] = 0.0;
   out_8675581923907159569[152] = 1.0;
   out_8675581923907159569[153] = 0.0;
   out_8675581923907159569[154] = 0.0;
   out_8675581923907159569[155] = 0.0;
   out_8675581923907159569[156] = 0.0;
   out_8675581923907159569[157] = 0.0;
   out_8675581923907159569[158] = 0.0;
   out_8675581923907159569[159] = 0.0;
   out_8675581923907159569[160] = 0.0;
   out_8675581923907159569[161] = 0.0;
   out_8675581923907159569[162] = 0.0;
   out_8675581923907159569[163] = 0.0;
   out_8675581923907159569[164] = 0.0;
   out_8675581923907159569[165] = 0.0;
   out_8675581923907159569[166] = 0.0;
   out_8675581923907159569[167] = 0.0;
   out_8675581923907159569[168] = 0.0;
   out_8675581923907159569[169] = 0.0;
   out_8675581923907159569[170] = 0.0;
   out_8675581923907159569[171] = 1.0;
   out_8675581923907159569[172] = 0.0;
   out_8675581923907159569[173] = 0.0;
   out_8675581923907159569[174] = 0.0;
   out_8675581923907159569[175] = 0.0;
   out_8675581923907159569[176] = 0.0;
   out_8675581923907159569[177] = 0.0;
   out_8675581923907159569[178] = 0.0;
   out_8675581923907159569[179] = 0.0;
   out_8675581923907159569[180] = 0.0;
   out_8675581923907159569[181] = 0.0;
   out_8675581923907159569[182] = 0.0;
   out_8675581923907159569[183] = 0.0;
   out_8675581923907159569[184] = 0.0;
   out_8675581923907159569[185] = 0.0;
   out_8675581923907159569[186] = 0.0;
   out_8675581923907159569[187] = 0.0;
   out_8675581923907159569[188] = 0.0;
   out_8675581923907159569[189] = 0.0;
   out_8675581923907159569[190] = 1.0;
   out_8675581923907159569[191] = 0.0;
   out_8675581923907159569[192] = 0.0;
   out_8675581923907159569[193] = 0.0;
   out_8675581923907159569[194] = 0.0;
   out_8675581923907159569[195] = 0.0;
   out_8675581923907159569[196] = 0.0;
   out_8675581923907159569[197] = 0.0;
   out_8675581923907159569[198] = 0.0;
   out_8675581923907159569[199] = 0.0;
   out_8675581923907159569[200] = 0.0;
   out_8675581923907159569[201] = 0.0;
   out_8675581923907159569[202] = 0.0;
   out_8675581923907159569[203] = 0.0;
   out_8675581923907159569[204] = 0.0;
   out_8675581923907159569[205] = 0.0;
   out_8675581923907159569[206] = 0.0;
   out_8675581923907159569[207] = 0.0;
   out_8675581923907159569[208] = 0.0;
   out_8675581923907159569[209] = 1.0;
   out_8675581923907159569[210] = 0.0;
   out_8675581923907159569[211] = 0.0;
   out_8675581923907159569[212] = 0.0;
   out_8675581923907159569[213] = 0.0;
   out_8675581923907159569[214] = 0.0;
   out_8675581923907159569[215] = 0.0;
   out_8675581923907159569[216] = 0.0;
   out_8675581923907159569[217] = 0.0;
   out_8675581923907159569[218] = 0.0;
   out_8675581923907159569[219] = 0.0;
   out_8675581923907159569[220] = 0.0;
   out_8675581923907159569[221] = 0.0;
   out_8675581923907159569[222] = 0.0;
   out_8675581923907159569[223] = 0.0;
   out_8675581923907159569[224] = 0.0;
   out_8675581923907159569[225] = 0.0;
   out_8675581923907159569[226] = 0.0;
   out_8675581923907159569[227] = 0.0;
   out_8675581923907159569[228] = 1.0;
   out_8675581923907159569[229] = 0.0;
   out_8675581923907159569[230] = 0.0;
   out_8675581923907159569[231] = 0.0;
   out_8675581923907159569[232] = 0.0;
   out_8675581923907159569[233] = 0.0;
   out_8675581923907159569[234] = 0.0;
   out_8675581923907159569[235] = 0.0;
   out_8675581923907159569[236] = 0.0;
   out_8675581923907159569[237] = 0.0;
   out_8675581923907159569[238] = 0.0;
   out_8675581923907159569[239] = 0.0;
   out_8675581923907159569[240] = 0.0;
   out_8675581923907159569[241] = 0.0;
   out_8675581923907159569[242] = 0.0;
   out_8675581923907159569[243] = 0.0;
   out_8675581923907159569[244] = 0.0;
   out_8675581923907159569[245] = 0.0;
   out_8675581923907159569[246] = 0.0;
   out_8675581923907159569[247] = 1.0;
   out_8675581923907159569[248] = 0.0;
   out_8675581923907159569[249] = 0.0;
   out_8675581923907159569[250] = 0.0;
   out_8675581923907159569[251] = 0.0;
   out_8675581923907159569[252] = 0.0;
   out_8675581923907159569[253] = 0.0;
   out_8675581923907159569[254] = 0.0;
   out_8675581923907159569[255] = 0.0;
   out_8675581923907159569[256] = 0.0;
   out_8675581923907159569[257] = 0.0;
   out_8675581923907159569[258] = 0.0;
   out_8675581923907159569[259] = 0.0;
   out_8675581923907159569[260] = 0.0;
   out_8675581923907159569[261] = 0.0;
   out_8675581923907159569[262] = 0.0;
   out_8675581923907159569[263] = 0.0;
   out_8675581923907159569[264] = 0.0;
   out_8675581923907159569[265] = 0.0;
   out_8675581923907159569[266] = 1.0;
   out_8675581923907159569[267] = 0.0;
   out_8675581923907159569[268] = 0.0;
   out_8675581923907159569[269] = 0.0;
   out_8675581923907159569[270] = 0.0;
   out_8675581923907159569[271] = 0.0;
   out_8675581923907159569[272] = 0.0;
   out_8675581923907159569[273] = 0.0;
   out_8675581923907159569[274] = 0.0;
   out_8675581923907159569[275] = 0.0;
   out_8675581923907159569[276] = 0.0;
   out_8675581923907159569[277] = 0.0;
   out_8675581923907159569[278] = 0.0;
   out_8675581923907159569[279] = 0.0;
   out_8675581923907159569[280] = 0.0;
   out_8675581923907159569[281] = 0.0;
   out_8675581923907159569[282] = 0.0;
   out_8675581923907159569[283] = 0.0;
   out_8675581923907159569[284] = 0.0;
   out_8675581923907159569[285] = 1.0;
   out_8675581923907159569[286] = 0.0;
   out_8675581923907159569[287] = 0.0;
   out_8675581923907159569[288] = 0.0;
   out_8675581923907159569[289] = 0.0;
   out_8675581923907159569[290] = 0.0;
   out_8675581923907159569[291] = 0.0;
   out_8675581923907159569[292] = 0.0;
   out_8675581923907159569[293] = 0.0;
   out_8675581923907159569[294] = 0.0;
   out_8675581923907159569[295] = 0.0;
   out_8675581923907159569[296] = 0.0;
   out_8675581923907159569[297] = 0.0;
   out_8675581923907159569[298] = 0.0;
   out_8675581923907159569[299] = 0.0;
   out_8675581923907159569[300] = 0.0;
   out_8675581923907159569[301] = 0.0;
   out_8675581923907159569[302] = 0.0;
   out_8675581923907159569[303] = 0.0;
   out_8675581923907159569[304] = 1.0;
   out_8675581923907159569[305] = 0.0;
   out_8675581923907159569[306] = 0.0;
   out_8675581923907159569[307] = 0.0;
   out_8675581923907159569[308] = 0.0;
   out_8675581923907159569[309] = 0.0;
   out_8675581923907159569[310] = 0.0;
   out_8675581923907159569[311] = 0.0;
   out_8675581923907159569[312] = 0.0;
   out_8675581923907159569[313] = 0.0;
   out_8675581923907159569[314] = 0.0;
   out_8675581923907159569[315] = 0.0;
   out_8675581923907159569[316] = 0.0;
   out_8675581923907159569[317] = 0.0;
   out_8675581923907159569[318] = 0.0;
   out_8675581923907159569[319] = 0.0;
   out_8675581923907159569[320] = 0.0;
   out_8675581923907159569[321] = 0.0;
   out_8675581923907159569[322] = 0.0;
   out_8675581923907159569[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5828399727577413921) {
   out_5828399727577413921[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5828399727577413921[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5828399727577413921[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5828399727577413921[3] = dt*state[12] + state[3];
   out_5828399727577413921[4] = dt*state[13] + state[4];
   out_5828399727577413921[5] = dt*state[14] + state[5];
   out_5828399727577413921[6] = state[6];
   out_5828399727577413921[7] = state[7];
   out_5828399727577413921[8] = state[8];
   out_5828399727577413921[9] = state[9];
   out_5828399727577413921[10] = state[10];
   out_5828399727577413921[11] = state[11];
   out_5828399727577413921[12] = state[12];
   out_5828399727577413921[13] = state[13];
   out_5828399727577413921[14] = state[14];
   out_5828399727577413921[15] = state[15];
   out_5828399727577413921[16] = state[16];
   out_5828399727577413921[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6448424330139796371) {
   out_6448424330139796371[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6448424330139796371[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6448424330139796371[2] = 0;
   out_6448424330139796371[3] = 0;
   out_6448424330139796371[4] = 0;
   out_6448424330139796371[5] = 0;
   out_6448424330139796371[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6448424330139796371[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6448424330139796371[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6448424330139796371[9] = 0;
   out_6448424330139796371[10] = 0;
   out_6448424330139796371[11] = 0;
   out_6448424330139796371[12] = 0;
   out_6448424330139796371[13] = 0;
   out_6448424330139796371[14] = 0;
   out_6448424330139796371[15] = 0;
   out_6448424330139796371[16] = 0;
   out_6448424330139796371[17] = 0;
   out_6448424330139796371[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6448424330139796371[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6448424330139796371[20] = 0;
   out_6448424330139796371[21] = 0;
   out_6448424330139796371[22] = 0;
   out_6448424330139796371[23] = 0;
   out_6448424330139796371[24] = 0;
   out_6448424330139796371[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6448424330139796371[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6448424330139796371[27] = 0;
   out_6448424330139796371[28] = 0;
   out_6448424330139796371[29] = 0;
   out_6448424330139796371[30] = 0;
   out_6448424330139796371[31] = 0;
   out_6448424330139796371[32] = 0;
   out_6448424330139796371[33] = 0;
   out_6448424330139796371[34] = 0;
   out_6448424330139796371[35] = 0;
   out_6448424330139796371[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6448424330139796371[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6448424330139796371[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6448424330139796371[39] = 0;
   out_6448424330139796371[40] = 0;
   out_6448424330139796371[41] = 0;
   out_6448424330139796371[42] = 0;
   out_6448424330139796371[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6448424330139796371[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6448424330139796371[45] = 0;
   out_6448424330139796371[46] = 0;
   out_6448424330139796371[47] = 0;
   out_6448424330139796371[48] = 0;
   out_6448424330139796371[49] = 0;
   out_6448424330139796371[50] = 0;
   out_6448424330139796371[51] = 0;
   out_6448424330139796371[52] = 0;
   out_6448424330139796371[53] = 0;
   out_6448424330139796371[54] = 0;
   out_6448424330139796371[55] = 0;
   out_6448424330139796371[56] = 0;
   out_6448424330139796371[57] = 1;
   out_6448424330139796371[58] = 0;
   out_6448424330139796371[59] = 0;
   out_6448424330139796371[60] = 0;
   out_6448424330139796371[61] = 0;
   out_6448424330139796371[62] = 0;
   out_6448424330139796371[63] = 0;
   out_6448424330139796371[64] = 0;
   out_6448424330139796371[65] = 0;
   out_6448424330139796371[66] = dt;
   out_6448424330139796371[67] = 0;
   out_6448424330139796371[68] = 0;
   out_6448424330139796371[69] = 0;
   out_6448424330139796371[70] = 0;
   out_6448424330139796371[71] = 0;
   out_6448424330139796371[72] = 0;
   out_6448424330139796371[73] = 0;
   out_6448424330139796371[74] = 0;
   out_6448424330139796371[75] = 0;
   out_6448424330139796371[76] = 1;
   out_6448424330139796371[77] = 0;
   out_6448424330139796371[78] = 0;
   out_6448424330139796371[79] = 0;
   out_6448424330139796371[80] = 0;
   out_6448424330139796371[81] = 0;
   out_6448424330139796371[82] = 0;
   out_6448424330139796371[83] = 0;
   out_6448424330139796371[84] = 0;
   out_6448424330139796371[85] = dt;
   out_6448424330139796371[86] = 0;
   out_6448424330139796371[87] = 0;
   out_6448424330139796371[88] = 0;
   out_6448424330139796371[89] = 0;
   out_6448424330139796371[90] = 0;
   out_6448424330139796371[91] = 0;
   out_6448424330139796371[92] = 0;
   out_6448424330139796371[93] = 0;
   out_6448424330139796371[94] = 0;
   out_6448424330139796371[95] = 1;
   out_6448424330139796371[96] = 0;
   out_6448424330139796371[97] = 0;
   out_6448424330139796371[98] = 0;
   out_6448424330139796371[99] = 0;
   out_6448424330139796371[100] = 0;
   out_6448424330139796371[101] = 0;
   out_6448424330139796371[102] = 0;
   out_6448424330139796371[103] = 0;
   out_6448424330139796371[104] = dt;
   out_6448424330139796371[105] = 0;
   out_6448424330139796371[106] = 0;
   out_6448424330139796371[107] = 0;
   out_6448424330139796371[108] = 0;
   out_6448424330139796371[109] = 0;
   out_6448424330139796371[110] = 0;
   out_6448424330139796371[111] = 0;
   out_6448424330139796371[112] = 0;
   out_6448424330139796371[113] = 0;
   out_6448424330139796371[114] = 1;
   out_6448424330139796371[115] = 0;
   out_6448424330139796371[116] = 0;
   out_6448424330139796371[117] = 0;
   out_6448424330139796371[118] = 0;
   out_6448424330139796371[119] = 0;
   out_6448424330139796371[120] = 0;
   out_6448424330139796371[121] = 0;
   out_6448424330139796371[122] = 0;
   out_6448424330139796371[123] = 0;
   out_6448424330139796371[124] = 0;
   out_6448424330139796371[125] = 0;
   out_6448424330139796371[126] = 0;
   out_6448424330139796371[127] = 0;
   out_6448424330139796371[128] = 0;
   out_6448424330139796371[129] = 0;
   out_6448424330139796371[130] = 0;
   out_6448424330139796371[131] = 0;
   out_6448424330139796371[132] = 0;
   out_6448424330139796371[133] = 1;
   out_6448424330139796371[134] = 0;
   out_6448424330139796371[135] = 0;
   out_6448424330139796371[136] = 0;
   out_6448424330139796371[137] = 0;
   out_6448424330139796371[138] = 0;
   out_6448424330139796371[139] = 0;
   out_6448424330139796371[140] = 0;
   out_6448424330139796371[141] = 0;
   out_6448424330139796371[142] = 0;
   out_6448424330139796371[143] = 0;
   out_6448424330139796371[144] = 0;
   out_6448424330139796371[145] = 0;
   out_6448424330139796371[146] = 0;
   out_6448424330139796371[147] = 0;
   out_6448424330139796371[148] = 0;
   out_6448424330139796371[149] = 0;
   out_6448424330139796371[150] = 0;
   out_6448424330139796371[151] = 0;
   out_6448424330139796371[152] = 1;
   out_6448424330139796371[153] = 0;
   out_6448424330139796371[154] = 0;
   out_6448424330139796371[155] = 0;
   out_6448424330139796371[156] = 0;
   out_6448424330139796371[157] = 0;
   out_6448424330139796371[158] = 0;
   out_6448424330139796371[159] = 0;
   out_6448424330139796371[160] = 0;
   out_6448424330139796371[161] = 0;
   out_6448424330139796371[162] = 0;
   out_6448424330139796371[163] = 0;
   out_6448424330139796371[164] = 0;
   out_6448424330139796371[165] = 0;
   out_6448424330139796371[166] = 0;
   out_6448424330139796371[167] = 0;
   out_6448424330139796371[168] = 0;
   out_6448424330139796371[169] = 0;
   out_6448424330139796371[170] = 0;
   out_6448424330139796371[171] = 1;
   out_6448424330139796371[172] = 0;
   out_6448424330139796371[173] = 0;
   out_6448424330139796371[174] = 0;
   out_6448424330139796371[175] = 0;
   out_6448424330139796371[176] = 0;
   out_6448424330139796371[177] = 0;
   out_6448424330139796371[178] = 0;
   out_6448424330139796371[179] = 0;
   out_6448424330139796371[180] = 0;
   out_6448424330139796371[181] = 0;
   out_6448424330139796371[182] = 0;
   out_6448424330139796371[183] = 0;
   out_6448424330139796371[184] = 0;
   out_6448424330139796371[185] = 0;
   out_6448424330139796371[186] = 0;
   out_6448424330139796371[187] = 0;
   out_6448424330139796371[188] = 0;
   out_6448424330139796371[189] = 0;
   out_6448424330139796371[190] = 1;
   out_6448424330139796371[191] = 0;
   out_6448424330139796371[192] = 0;
   out_6448424330139796371[193] = 0;
   out_6448424330139796371[194] = 0;
   out_6448424330139796371[195] = 0;
   out_6448424330139796371[196] = 0;
   out_6448424330139796371[197] = 0;
   out_6448424330139796371[198] = 0;
   out_6448424330139796371[199] = 0;
   out_6448424330139796371[200] = 0;
   out_6448424330139796371[201] = 0;
   out_6448424330139796371[202] = 0;
   out_6448424330139796371[203] = 0;
   out_6448424330139796371[204] = 0;
   out_6448424330139796371[205] = 0;
   out_6448424330139796371[206] = 0;
   out_6448424330139796371[207] = 0;
   out_6448424330139796371[208] = 0;
   out_6448424330139796371[209] = 1;
   out_6448424330139796371[210] = 0;
   out_6448424330139796371[211] = 0;
   out_6448424330139796371[212] = 0;
   out_6448424330139796371[213] = 0;
   out_6448424330139796371[214] = 0;
   out_6448424330139796371[215] = 0;
   out_6448424330139796371[216] = 0;
   out_6448424330139796371[217] = 0;
   out_6448424330139796371[218] = 0;
   out_6448424330139796371[219] = 0;
   out_6448424330139796371[220] = 0;
   out_6448424330139796371[221] = 0;
   out_6448424330139796371[222] = 0;
   out_6448424330139796371[223] = 0;
   out_6448424330139796371[224] = 0;
   out_6448424330139796371[225] = 0;
   out_6448424330139796371[226] = 0;
   out_6448424330139796371[227] = 0;
   out_6448424330139796371[228] = 1;
   out_6448424330139796371[229] = 0;
   out_6448424330139796371[230] = 0;
   out_6448424330139796371[231] = 0;
   out_6448424330139796371[232] = 0;
   out_6448424330139796371[233] = 0;
   out_6448424330139796371[234] = 0;
   out_6448424330139796371[235] = 0;
   out_6448424330139796371[236] = 0;
   out_6448424330139796371[237] = 0;
   out_6448424330139796371[238] = 0;
   out_6448424330139796371[239] = 0;
   out_6448424330139796371[240] = 0;
   out_6448424330139796371[241] = 0;
   out_6448424330139796371[242] = 0;
   out_6448424330139796371[243] = 0;
   out_6448424330139796371[244] = 0;
   out_6448424330139796371[245] = 0;
   out_6448424330139796371[246] = 0;
   out_6448424330139796371[247] = 1;
   out_6448424330139796371[248] = 0;
   out_6448424330139796371[249] = 0;
   out_6448424330139796371[250] = 0;
   out_6448424330139796371[251] = 0;
   out_6448424330139796371[252] = 0;
   out_6448424330139796371[253] = 0;
   out_6448424330139796371[254] = 0;
   out_6448424330139796371[255] = 0;
   out_6448424330139796371[256] = 0;
   out_6448424330139796371[257] = 0;
   out_6448424330139796371[258] = 0;
   out_6448424330139796371[259] = 0;
   out_6448424330139796371[260] = 0;
   out_6448424330139796371[261] = 0;
   out_6448424330139796371[262] = 0;
   out_6448424330139796371[263] = 0;
   out_6448424330139796371[264] = 0;
   out_6448424330139796371[265] = 0;
   out_6448424330139796371[266] = 1;
   out_6448424330139796371[267] = 0;
   out_6448424330139796371[268] = 0;
   out_6448424330139796371[269] = 0;
   out_6448424330139796371[270] = 0;
   out_6448424330139796371[271] = 0;
   out_6448424330139796371[272] = 0;
   out_6448424330139796371[273] = 0;
   out_6448424330139796371[274] = 0;
   out_6448424330139796371[275] = 0;
   out_6448424330139796371[276] = 0;
   out_6448424330139796371[277] = 0;
   out_6448424330139796371[278] = 0;
   out_6448424330139796371[279] = 0;
   out_6448424330139796371[280] = 0;
   out_6448424330139796371[281] = 0;
   out_6448424330139796371[282] = 0;
   out_6448424330139796371[283] = 0;
   out_6448424330139796371[284] = 0;
   out_6448424330139796371[285] = 1;
   out_6448424330139796371[286] = 0;
   out_6448424330139796371[287] = 0;
   out_6448424330139796371[288] = 0;
   out_6448424330139796371[289] = 0;
   out_6448424330139796371[290] = 0;
   out_6448424330139796371[291] = 0;
   out_6448424330139796371[292] = 0;
   out_6448424330139796371[293] = 0;
   out_6448424330139796371[294] = 0;
   out_6448424330139796371[295] = 0;
   out_6448424330139796371[296] = 0;
   out_6448424330139796371[297] = 0;
   out_6448424330139796371[298] = 0;
   out_6448424330139796371[299] = 0;
   out_6448424330139796371[300] = 0;
   out_6448424330139796371[301] = 0;
   out_6448424330139796371[302] = 0;
   out_6448424330139796371[303] = 0;
   out_6448424330139796371[304] = 1;
   out_6448424330139796371[305] = 0;
   out_6448424330139796371[306] = 0;
   out_6448424330139796371[307] = 0;
   out_6448424330139796371[308] = 0;
   out_6448424330139796371[309] = 0;
   out_6448424330139796371[310] = 0;
   out_6448424330139796371[311] = 0;
   out_6448424330139796371[312] = 0;
   out_6448424330139796371[313] = 0;
   out_6448424330139796371[314] = 0;
   out_6448424330139796371[315] = 0;
   out_6448424330139796371[316] = 0;
   out_6448424330139796371[317] = 0;
   out_6448424330139796371[318] = 0;
   out_6448424330139796371[319] = 0;
   out_6448424330139796371[320] = 0;
   out_6448424330139796371[321] = 0;
   out_6448424330139796371[322] = 0;
   out_6448424330139796371[323] = 1;
}
void h_4(double *state, double *unused, double *out_4289702124009644444) {
   out_4289702124009644444[0] = state[6] + state[9];
   out_4289702124009644444[1] = state[7] + state[10];
   out_4289702124009644444[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_6782071020311383479) {
   out_6782071020311383479[0] = 0;
   out_6782071020311383479[1] = 0;
   out_6782071020311383479[2] = 0;
   out_6782071020311383479[3] = 0;
   out_6782071020311383479[4] = 0;
   out_6782071020311383479[5] = 0;
   out_6782071020311383479[6] = 1;
   out_6782071020311383479[7] = 0;
   out_6782071020311383479[8] = 0;
   out_6782071020311383479[9] = 1;
   out_6782071020311383479[10] = 0;
   out_6782071020311383479[11] = 0;
   out_6782071020311383479[12] = 0;
   out_6782071020311383479[13] = 0;
   out_6782071020311383479[14] = 0;
   out_6782071020311383479[15] = 0;
   out_6782071020311383479[16] = 0;
   out_6782071020311383479[17] = 0;
   out_6782071020311383479[18] = 0;
   out_6782071020311383479[19] = 0;
   out_6782071020311383479[20] = 0;
   out_6782071020311383479[21] = 0;
   out_6782071020311383479[22] = 0;
   out_6782071020311383479[23] = 0;
   out_6782071020311383479[24] = 0;
   out_6782071020311383479[25] = 1;
   out_6782071020311383479[26] = 0;
   out_6782071020311383479[27] = 0;
   out_6782071020311383479[28] = 1;
   out_6782071020311383479[29] = 0;
   out_6782071020311383479[30] = 0;
   out_6782071020311383479[31] = 0;
   out_6782071020311383479[32] = 0;
   out_6782071020311383479[33] = 0;
   out_6782071020311383479[34] = 0;
   out_6782071020311383479[35] = 0;
   out_6782071020311383479[36] = 0;
   out_6782071020311383479[37] = 0;
   out_6782071020311383479[38] = 0;
   out_6782071020311383479[39] = 0;
   out_6782071020311383479[40] = 0;
   out_6782071020311383479[41] = 0;
   out_6782071020311383479[42] = 0;
   out_6782071020311383479[43] = 0;
   out_6782071020311383479[44] = 1;
   out_6782071020311383479[45] = 0;
   out_6782071020311383479[46] = 0;
   out_6782071020311383479[47] = 1;
   out_6782071020311383479[48] = 0;
   out_6782071020311383479[49] = 0;
   out_6782071020311383479[50] = 0;
   out_6782071020311383479[51] = 0;
   out_6782071020311383479[52] = 0;
   out_6782071020311383479[53] = 0;
}
void h_10(double *state, double *unused, double *out_7934488606380957591) {
   out_7934488606380957591[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7934488606380957591[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7934488606380957591[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4068427810281274883) {
   out_4068427810281274883[0] = 0;
   out_4068427810281274883[1] = 9.8100000000000005*cos(state[1]);
   out_4068427810281274883[2] = 0;
   out_4068427810281274883[3] = 0;
   out_4068427810281274883[4] = -state[8];
   out_4068427810281274883[5] = state[7];
   out_4068427810281274883[6] = 0;
   out_4068427810281274883[7] = state[5];
   out_4068427810281274883[8] = -state[4];
   out_4068427810281274883[9] = 0;
   out_4068427810281274883[10] = 0;
   out_4068427810281274883[11] = 0;
   out_4068427810281274883[12] = 1;
   out_4068427810281274883[13] = 0;
   out_4068427810281274883[14] = 0;
   out_4068427810281274883[15] = 1;
   out_4068427810281274883[16] = 0;
   out_4068427810281274883[17] = 0;
   out_4068427810281274883[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4068427810281274883[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4068427810281274883[20] = 0;
   out_4068427810281274883[21] = state[8];
   out_4068427810281274883[22] = 0;
   out_4068427810281274883[23] = -state[6];
   out_4068427810281274883[24] = -state[5];
   out_4068427810281274883[25] = 0;
   out_4068427810281274883[26] = state[3];
   out_4068427810281274883[27] = 0;
   out_4068427810281274883[28] = 0;
   out_4068427810281274883[29] = 0;
   out_4068427810281274883[30] = 0;
   out_4068427810281274883[31] = 1;
   out_4068427810281274883[32] = 0;
   out_4068427810281274883[33] = 0;
   out_4068427810281274883[34] = 1;
   out_4068427810281274883[35] = 0;
   out_4068427810281274883[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4068427810281274883[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4068427810281274883[38] = 0;
   out_4068427810281274883[39] = -state[7];
   out_4068427810281274883[40] = state[6];
   out_4068427810281274883[41] = 0;
   out_4068427810281274883[42] = state[4];
   out_4068427810281274883[43] = -state[3];
   out_4068427810281274883[44] = 0;
   out_4068427810281274883[45] = 0;
   out_4068427810281274883[46] = 0;
   out_4068427810281274883[47] = 0;
   out_4068427810281274883[48] = 0;
   out_4068427810281274883[49] = 0;
   out_4068427810281274883[50] = 1;
   out_4068427810281274883[51] = 0;
   out_4068427810281274883[52] = 0;
   out_4068427810281274883[53] = 1;
}
void h_13(double *state, double *unused, double *out_8978738644302890974) {
   out_8978738644302890974[0] = state[3];
   out_8978738644302890974[1] = state[4];
   out_8978738644302890974[2] = state[5];
}
void H_13(double *state, double *unused, double *out_8452399228065835336) {
   out_8452399228065835336[0] = 0;
   out_8452399228065835336[1] = 0;
   out_8452399228065835336[2] = 0;
   out_8452399228065835336[3] = 1;
   out_8452399228065835336[4] = 0;
   out_8452399228065835336[5] = 0;
   out_8452399228065835336[6] = 0;
   out_8452399228065835336[7] = 0;
   out_8452399228065835336[8] = 0;
   out_8452399228065835336[9] = 0;
   out_8452399228065835336[10] = 0;
   out_8452399228065835336[11] = 0;
   out_8452399228065835336[12] = 0;
   out_8452399228065835336[13] = 0;
   out_8452399228065835336[14] = 0;
   out_8452399228065835336[15] = 0;
   out_8452399228065835336[16] = 0;
   out_8452399228065835336[17] = 0;
   out_8452399228065835336[18] = 0;
   out_8452399228065835336[19] = 0;
   out_8452399228065835336[20] = 0;
   out_8452399228065835336[21] = 0;
   out_8452399228065835336[22] = 1;
   out_8452399228065835336[23] = 0;
   out_8452399228065835336[24] = 0;
   out_8452399228065835336[25] = 0;
   out_8452399228065835336[26] = 0;
   out_8452399228065835336[27] = 0;
   out_8452399228065835336[28] = 0;
   out_8452399228065835336[29] = 0;
   out_8452399228065835336[30] = 0;
   out_8452399228065835336[31] = 0;
   out_8452399228065835336[32] = 0;
   out_8452399228065835336[33] = 0;
   out_8452399228065835336[34] = 0;
   out_8452399228065835336[35] = 0;
   out_8452399228065835336[36] = 0;
   out_8452399228065835336[37] = 0;
   out_8452399228065835336[38] = 0;
   out_8452399228065835336[39] = 0;
   out_8452399228065835336[40] = 0;
   out_8452399228065835336[41] = 1;
   out_8452399228065835336[42] = 0;
   out_8452399228065835336[43] = 0;
   out_8452399228065835336[44] = 0;
   out_8452399228065835336[45] = 0;
   out_8452399228065835336[46] = 0;
   out_8452399228065835336[47] = 0;
   out_8452399228065835336[48] = 0;
   out_8452399228065835336[49] = 0;
   out_8452399228065835336[50] = 0;
   out_8452399228065835336[51] = 0;
   out_8452399228065835336[52] = 0;
   out_8452399228065835336[53] = 0;
}
void h_14(double *state, double *unused, double *out_7145417579323282935) {
   out_7145417579323282935[0] = state[6];
   out_7145417579323282935[1] = state[7];
   out_7145417579323282935[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7701432197058683608) {
   out_7701432197058683608[0] = 0;
   out_7701432197058683608[1] = 0;
   out_7701432197058683608[2] = 0;
   out_7701432197058683608[3] = 0;
   out_7701432197058683608[4] = 0;
   out_7701432197058683608[5] = 0;
   out_7701432197058683608[6] = 1;
   out_7701432197058683608[7] = 0;
   out_7701432197058683608[8] = 0;
   out_7701432197058683608[9] = 0;
   out_7701432197058683608[10] = 0;
   out_7701432197058683608[11] = 0;
   out_7701432197058683608[12] = 0;
   out_7701432197058683608[13] = 0;
   out_7701432197058683608[14] = 0;
   out_7701432197058683608[15] = 0;
   out_7701432197058683608[16] = 0;
   out_7701432197058683608[17] = 0;
   out_7701432197058683608[18] = 0;
   out_7701432197058683608[19] = 0;
   out_7701432197058683608[20] = 0;
   out_7701432197058683608[21] = 0;
   out_7701432197058683608[22] = 0;
   out_7701432197058683608[23] = 0;
   out_7701432197058683608[24] = 0;
   out_7701432197058683608[25] = 1;
   out_7701432197058683608[26] = 0;
   out_7701432197058683608[27] = 0;
   out_7701432197058683608[28] = 0;
   out_7701432197058683608[29] = 0;
   out_7701432197058683608[30] = 0;
   out_7701432197058683608[31] = 0;
   out_7701432197058683608[32] = 0;
   out_7701432197058683608[33] = 0;
   out_7701432197058683608[34] = 0;
   out_7701432197058683608[35] = 0;
   out_7701432197058683608[36] = 0;
   out_7701432197058683608[37] = 0;
   out_7701432197058683608[38] = 0;
   out_7701432197058683608[39] = 0;
   out_7701432197058683608[40] = 0;
   out_7701432197058683608[41] = 0;
   out_7701432197058683608[42] = 0;
   out_7701432197058683608[43] = 0;
   out_7701432197058683608[44] = 1;
   out_7701432197058683608[45] = 0;
   out_7701432197058683608[46] = 0;
   out_7701432197058683608[47] = 0;
   out_7701432197058683608[48] = 0;
   out_7701432197058683608[49] = 0;
   out_7701432197058683608[50] = 0;
   out_7701432197058683608[51] = 0;
   out_7701432197058683608[52] = 0;
   out_7701432197058683608[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_849063694558529375) {
  err_fun(nom_x, delta_x, out_849063694558529375);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5536998468017687086) {
  inv_err_fun(nom_x, true_x, out_5536998468017687086);
}
void pose_H_mod_fun(double *state, double *out_8675581923907159569) {
  H_mod_fun(state, out_8675581923907159569);
}
void pose_f_fun(double *state, double dt, double *out_5828399727577413921) {
  f_fun(state,  dt, out_5828399727577413921);
}
void pose_F_fun(double *state, double dt, double *out_6448424330139796371) {
  F_fun(state,  dt, out_6448424330139796371);
}
void pose_h_4(double *state, double *unused, double *out_4289702124009644444) {
  h_4(state, unused, out_4289702124009644444);
}
void pose_H_4(double *state, double *unused, double *out_6782071020311383479) {
  H_4(state, unused, out_6782071020311383479);
}
void pose_h_10(double *state, double *unused, double *out_7934488606380957591) {
  h_10(state, unused, out_7934488606380957591);
}
void pose_H_10(double *state, double *unused, double *out_4068427810281274883) {
  H_10(state, unused, out_4068427810281274883);
}
void pose_h_13(double *state, double *unused, double *out_8978738644302890974) {
  h_13(state, unused, out_8978738644302890974);
}
void pose_H_13(double *state, double *unused, double *out_8452399228065835336) {
  H_13(state, unused, out_8452399228065835336);
}
void pose_h_14(double *state, double *unused, double *out_7145417579323282935) {
  h_14(state, unused, out_7145417579323282935);
}
void pose_H_14(double *state, double *unused, double *out_7701432197058683608) {
  H_14(state, unused, out_7701432197058683608);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
