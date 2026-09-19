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
void err_fun(double *nom_x, double *delta_x, double *out_6048224022663336905) {
   out_6048224022663336905[0] = delta_x[0] + nom_x[0];
   out_6048224022663336905[1] = delta_x[1] + nom_x[1];
   out_6048224022663336905[2] = delta_x[2] + nom_x[2];
   out_6048224022663336905[3] = delta_x[3] + nom_x[3];
   out_6048224022663336905[4] = delta_x[4] + nom_x[4];
   out_6048224022663336905[5] = delta_x[5] + nom_x[5];
   out_6048224022663336905[6] = delta_x[6] + nom_x[6];
   out_6048224022663336905[7] = delta_x[7] + nom_x[7];
   out_6048224022663336905[8] = delta_x[8] + nom_x[8];
   out_6048224022663336905[9] = delta_x[9] + nom_x[9];
   out_6048224022663336905[10] = delta_x[10] + nom_x[10];
   out_6048224022663336905[11] = delta_x[11] + nom_x[11];
   out_6048224022663336905[12] = delta_x[12] + nom_x[12];
   out_6048224022663336905[13] = delta_x[13] + nom_x[13];
   out_6048224022663336905[14] = delta_x[14] + nom_x[14];
   out_6048224022663336905[15] = delta_x[15] + nom_x[15];
   out_6048224022663336905[16] = delta_x[16] + nom_x[16];
   out_6048224022663336905[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2486701244109526387) {
   out_2486701244109526387[0] = -nom_x[0] + true_x[0];
   out_2486701244109526387[1] = -nom_x[1] + true_x[1];
   out_2486701244109526387[2] = -nom_x[2] + true_x[2];
   out_2486701244109526387[3] = -nom_x[3] + true_x[3];
   out_2486701244109526387[4] = -nom_x[4] + true_x[4];
   out_2486701244109526387[5] = -nom_x[5] + true_x[5];
   out_2486701244109526387[6] = -nom_x[6] + true_x[6];
   out_2486701244109526387[7] = -nom_x[7] + true_x[7];
   out_2486701244109526387[8] = -nom_x[8] + true_x[8];
   out_2486701244109526387[9] = -nom_x[9] + true_x[9];
   out_2486701244109526387[10] = -nom_x[10] + true_x[10];
   out_2486701244109526387[11] = -nom_x[11] + true_x[11];
   out_2486701244109526387[12] = -nom_x[12] + true_x[12];
   out_2486701244109526387[13] = -nom_x[13] + true_x[13];
   out_2486701244109526387[14] = -nom_x[14] + true_x[14];
   out_2486701244109526387[15] = -nom_x[15] + true_x[15];
   out_2486701244109526387[16] = -nom_x[16] + true_x[16];
   out_2486701244109526387[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7677467036644633761) {
   out_7677467036644633761[0] = 1.0;
   out_7677467036644633761[1] = 0.0;
   out_7677467036644633761[2] = 0.0;
   out_7677467036644633761[3] = 0.0;
   out_7677467036644633761[4] = 0.0;
   out_7677467036644633761[5] = 0.0;
   out_7677467036644633761[6] = 0.0;
   out_7677467036644633761[7] = 0.0;
   out_7677467036644633761[8] = 0.0;
   out_7677467036644633761[9] = 0.0;
   out_7677467036644633761[10] = 0.0;
   out_7677467036644633761[11] = 0.0;
   out_7677467036644633761[12] = 0.0;
   out_7677467036644633761[13] = 0.0;
   out_7677467036644633761[14] = 0.0;
   out_7677467036644633761[15] = 0.0;
   out_7677467036644633761[16] = 0.0;
   out_7677467036644633761[17] = 0.0;
   out_7677467036644633761[18] = 0.0;
   out_7677467036644633761[19] = 1.0;
   out_7677467036644633761[20] = 0.0;
   out_7677467036644633761[21] = 0.0;
   out_7677467036644633761[22] = 0.0;
   out_7677467036644633761[23] = 0.0;
   out_7677467036644633761[24] = 0.0;
   out_7677467036644633761[25] = 0.0;
   out_7677467036644633761[26] = 0.0;
   out_7677467036644633761[27] = 0.0;
   out_7677467036644633761[28] = 0.0;
   out_7677467036644633761[29] = 0.0;
   out_7677467036644633761[30] = 0.0;
   out_7677467036644633761[31] = 0.0;
   out_7677467036644633761[32] = 0.0;
   out_7677467036644633761[33] = 0.0;
   out_7677467036644633761[34] = 0.0;
   out_7677467036644633761[35] = 0.0;
   out_7677467036644633761[36] = 0.0;
   out_7677467036644633761[37] = 0.0;
   out_7677467036644633761[38] = 1.0;
   out_7677467036644633761[39] = 0.0;
   out_7677467036644633761[40] = 0.0;
   out_7677467036644633761[41] = 0.0;
   out_7677467036644633761[42] = 0.0;
   out_7677467036644633761[43] = 0.0;
   out_7677467036644633761[44] = 0.0;
   out_7677467036644633761[45] = 0.0;
   out_7677467036644633761[46] = 0.0;
   out_7677467036644633761[47] = 0.0;
   out_7677467036644633761[48] = 0.0;
   out_7677467036644633761[49] = 0.0;
   out_7677467036644633761[50] = 0.0;
   out_7677467036644633761[51] = 0.0;
   out_7677467036644633761[52] = 0.0;
   out_7677467036644633761[53] = 0.0;
   out_7677467036644633761[54] = 0.0;
   out_7677467036644633761[55] = 0.0;
   out_7677467036644633761[56] = 0.0;
   out_7677467036644633761[57] = 1.0;
   out_7677467036644633761[58] = 0.0;
   out_7677467036644633761[59] = 0.0;
   out_7677467036644633761[60] = 0.0;
   out_7677467036644633761[61] = 0.0;
   out_7677467036644633761[62] = 0.0;
   out_7677467036644633761[63] = 0.0;
   out_7677467036644633761[64] = 0.0;
   out_7677467036644633761[65] = 0.0;
   out_7677467036644633761[66] = 0.0;
   out_7677467036644633761[67] = 0.0;
   out_7677467036644633761[68] = 0.0;
   out_7677467036644633761[69] = 0.0;
   out_7677467036644633761[70] = 0.0;
   out_7677467036644633761[71] = 0.0;
   out_7677467036644633761[72] = 0.0;
   out_7677467036644633761[73] = 0.0;
   out_7677467036644633761[74] = 0.0;
   out_7677467036644633761[75] = 0.0;
   out_7677467036644633761[76] = 1.0;
   out_7677467036644633761[77] = 0.0;
   out_7677467036644633761[78] = 0.0;
   out_7677467036644633761[79] = 0.0;
   out_7677467036644633761[80] = 0.0;
   out_7677467036644633761[81] = 0.0;
   out_7677467036644633761[82] = 0.0;
   out_7677467036644633761[83] = 0.0;
   out_7677467036644633761[84] = 0.0;
   out_7677467036644633761[85] = 0.0;
   out_7677467036644633761[86] = 0.0;
   out_7677467036644633761[87] = 0.0;
   out_7677467036644633761[88] = 0.0;
   out_7677467036644633761[89] = 0.0;
   out_7677467036644633761[90] = 0.0;
   out_7677467036644633761[91] = 0.0;
   out_7677467036644633761[92] = 0.0;
   out_7677467036644633761[93] = 0.0;
   out_7677467036644633761[94] = 0.0;
   out_7677467036644633761[95] = 1.0;
   out_7677467036644633761[96] = 0.0;
   out_7677467036644633761[97] = 0.0;
   out_7677467036644633761[98] = 0.0;
   out_7677467036644633761[99] = 0.0;
   out_7677467036644633761[100] = 0.0;
   out_7677467036644633761[101] = 0.0;
   out_7677467036644633761[102] = 0.0;
   out_7677467036644633761[103] = 0.0;
   out_7677467036644633761[104] = 0.0;
   out_7677467036644633761[105] = 0.0;
   out_7677467036644633761[106] = 0.0;
   out_7677467036644633761[107] = 0.0;
   out_7677467036644633761[108] = 0.0;
   out_7677467036644633761[109] = 0.0;
   out_7677467036644633761[110] = 0.0;
   out_7677467036644633761[111] = 0.0;
   out_7677467036644633761[112] = 0.0;
   out_7677467036644633761[113] = 0.0;
   out_7677467036644633761[114] = 1.0;
   out_7677467036644633761[115] = 0.0;
   out_7677467036644633761[116] = 0.0;
   out_7677467036644633761[117] = 0.0;
   out_7677467036644633761[118] = 0.0;
   out_7677467036644633761[119] = 0.0;
   out_7677467036644633761[120] = 0.0;
   out_7677467036644633761[121] = 0.0;
   out_7677467036644633761[122] = 0.0;
   out_7677467036644633761[123] = 0.0;
   out_7677467036644633761[124] = 0.0;
   out_7677467036644633761[125] = 0.0;
   out_7677467036644633761[126] = 0.0;
   out_7677467036644633761[127] = 0.0;
   out_7677467036644633761[128] = 0.0;
   out_7677467036644633761[129] = 0.0;
   out_7677467036644633761[130] = 0.0;
   out_7677467036644633761[131] = 0.0;
   out_7677467036644633761[132] = 0.0;
   out_7677467036644633761[133] = 1.0;
   out_7677467036644633761[134] = 0.0;
   out_7677467036644633761[135] = 0.0;
   out_7677467036644633761[136] = 0.0;
   out_7677467036644633761[137] = 0.0;
   out_7677467036644633761[138] = 0.0;
   out_7677467036644633761[139] = 0.0;
   out_7677467036644633761[140] = 0.0;
   out_7677467036644633761[141] = 0.0;
   out_7677467036644633761[142] = 0.0;
   out_7677467036644633761[143] = 0.0;
   out_7677467036644633761[144] = 0.0;
   out_7677467036644633761[145] = 0.0;
   out_7677467036644633761[146] = 0.0;
   out_7677467036644633761[147] = 0.0;
   out_7677467036644633761[148] = 0.0;
   out_7677467036644633761[149] = 0.0;
   out_7677467036644633761[150] = 0.0;
   out_7677467036644633761[151] = 0.0;
   out_7677467036644633761[152] = 1.0;
   out_7677467036644633761[153] = 0.0;
   out_7677467036644633761[154] = 0.0;
   out_7677467036644633761[155] = 0.0;
   out_7677467036644633761[156] = 0.0;
   out_7677467036644633761[157] = 0.0;
   out_7677467036644633761[158] = 0.0;
   out_7677467036644633761[159] = 0.0;
   out_7677467036644633761[160] = 0.0;
   out_7677467036644633761[161] = 0.0;
   out_7677467036644633761[162] = 0.0;
   out_7677467036644633761[163] = 0.0;
   out_7677467036644633761[164] = 0.0;
   out_7677467036644633761[165] = 0.0;
   out_7677467036644633761[166] = 0.0;
   out_7677467036644633761[167] = 0.0;
   out_7677467036644633761[168] = 0.0;
   out_7677467036644633761[169] = 0.0;
   out_7677467036644633761[170] = 0.0;
   out_7677467036644633761[171] = 1.0;
   out_7677467036644633761[172] = 0.0;
   out_7677467036644633761[173] = 0.0;
   out_7677467036644633761[174] = 0.0;
   out_7677467036644633761[175] = 0.0;
   out_7677467036644633761[176] = 0.0;
   out_7677467036644633761[177] = 0.0;
   out_7677467036644633761[178] = 0.0;
   out_7677467036644633761[179] = 0.0;
   out_7677467036644633761[180] = 0.0;
   out_7677467036644633761[181] = 0.0;
   out_7677467036644633761[182] = 0.0;
   out_7677467036644633761[183] = 0.0;
   out_7677467036644633761[184] = 0.0;
   out_7677467036644633761[185] = 0.0;
   out_7677467036644633761[186] = 0.0;
   out_7677467036644633761[187] = 0.0;
   out_7677467036644633761[188] = 0.0;
   out_7677467036644633761[189] = 0.0;
   out_7677467036644633761[190] = 1.0;
   out_7677467036644633761[191] = 0.0;
   out_7677467036644633761[192] = 0.0;
   out_7677467036644633761[193] = 0.0;
   out_7677467036644633761[194] = 0.0;
   out_7677467036644633761[195] = 0.0;
   out_7677467036644633761[196] = 0.0;
   out_7677467036644633761[197] = 0.0;
   out_7677467036644633761[198] = 0.0;
   out_7677467036644633761[199] = 0.0;
   out_7677467036644633761[200] = 0.0;
   out_7677467036644633761[201] = 0.0;
   out_7677467036644633761[202] = 0.0;
   out_7677467036644633761[203] = 0.0;
   out_7677467036644633761[204] = 0.0;
   out_7677467036644633761[205] = 0.0;
   out_7677467036644633761[206] = 0.0;
   out_7677467036644633761[207] = 0.0;
   out_7677467036644633761[208] = 0.0;
   out_7677467036644633761[209] = 1.0;
   out_7677467036644633761[210] = 0.0;
   out_7677467036644633761[211] = 0.0;
   out_7677467036644633761[212] = 0.0;
   out_7677467036644633761[213] = 0.0;
   out_7677467036644633761[214] = 0.0;
   out_7677467036644633761[215] = 0.0;
   out_7677467036644633761[216] = 0.0;
   out_7677467036644633761[217] = 0.0;
   out_7677467036644633761[218] = 0.0;
   out_7677467036644633761[219] = 0.0;
   out_7677467036644633761[220] = 0.0;
   out_7677467036644633761[221] = 0.0;
   out_7677467036644633761[222] = 0.0;
   out_7677467036644633761[223] = 0.0;
   out_7677467036644633761[224] = 0.0;
   out_7677467036644633761[225] = 0.0;
   out_7677467036644633761[226] = 0.0;
   out_7677467036644633761[227] = 0.0;
   out_7677467036644633761[228] = 1.0;
   out_7677467036644633761[229] = 0.0;
   out_7677467036644633761[230] = 0.0;
   out_7677467036644633761[231] = 0.0;
   out_7677467036644633761[232] = 0.0;
   out_7677467036644633761[233] = 0.0;
   out_7677467036644633761[234] = 0.0;
   out_7677467036644633761[235] = 0.0;
   out_7677467036644633761[236] = 0.0;
   out_7677467036644633761[237] = 0.0;
   out_7677467036644633761[238] = 0.0;
   out_7677467036644633761[239] = 0.0;
   out_7677467036644633761[240] = 0.0;
   out_7677467036644633761[241] = 0.0;
   out_7677467036644633761[242] = 0.0;
   out_7677467036644633761[243] = 0.0;
   out_7677467036644633761[244] = 0.0;
   out_7677467036644633761[245] = 0.0;
   out_7677467036644633761[246] = 0.0;
   out_7677467036644633761[247] = 1.0;
   out_7677467036644633761[248] = 0.0;
   out_7677467036644633761[249] = 0.0;
   out_7677467036644633761[250] = 0.0;
   out_7677467036644633761[251] = 0.0;
   out_7677467036644633761[252] = 0.0;
   out_7677467036644633761[253] = 0.0;
   out_7677467036644633761[254] = 0.0;
   out_7677467036644633761[255] = 0.0;
   out_7677467036644633761[256] = 0.0;
   out_7677467036644633761[257] = 0.0;
   out_7677467036644633761[258] = 0.0;
   out_7677467036644633761[259] = 0.0;
   out_7677467036644633761[260] = 0.0;
   out_7677467036644633761[261] = 0.0;
   out_7677467036644633761[262] = 0.0;
   out_7677467036644633761[263] = 0.0;
   out_7677467036644633761[264] = 0.0;
   out_7677467036644633761[265] = 0.0;
   out_7677467036644633761[266] = 1.0;
   out_7677467036644633761[267] = 0.0;
   out_7677467036644633761[268] = 0.0;
   out_7677467036644633761[269] = 0.0;
   out_7677467036644633761[270] = 0.0;
   out_7677467036644633761[271] = 0.0;
   out_7677467036644633761[272] = 0.0;
   out_7677467036644633761[273] = 0.0;
   out_7677467036644633761[274] = 0.0;
   out_7677467036644633761[275] = 0.0;
   out_7677467036644633761[276] = 0.0;
   out_7677467036644633761[277] = 0.0;
   out_7677467036644633761[278] = 0.0;
   out_7677467036644633761[279] = 0.0;
   out_7677467036644633761[280] = 0.0;
   out_7677467036644633761[281] = 0.0;
   out_7677467036644633761[282] = 0.0;
   out_7677467036644633761[283] = 0.0;
   out_7677467036644633761[284] = 0.0;
   out_7677467036644633761[285] = 1.0;
   out_7677467036644633761[286] = 0.0;
   out_7677467036644633761[287] = 0.0;
   out_7677467036644633761[288] = 0.0;
   out_7677467036644633761[289] = 0.0;
   out_7677467036644633761[290] = 0.0;
   out_7677467036644633761[291] = 0.0;
   out_7677467036644633761[292] = 0.0;
   out_7677467036644633761[293] = 0.0;
   out_7677467036644633761[294] = 0.0;
   out_7677467036644633761[295] = 0.0;
   out_7677467036644633761[296] = 0.0;
   out_7677467036644633761[297] = 0.0;
   out_7677467036644633761[298] = 0.0;
   out_7677467036644633761[299] = 0.0;
   out_7677467036644633761[300] = 0.0;
   out_7677467036644633761[301] = 0.0;
   out_7677467036644633761[302] = 0.0;
   out_7677467036644633761[303] = 0.0;
   out_7677467036644633761[304] = 1.0;
   out_7677467036644633761[305] = 0.0;
   out_7677467036644633761[306] = 0.0;
   out_7677467036644633761[307] = 0.0;
   out_7677467036644633761[308] = 0.0;
   out_7677467036644633761[309] = 0.0;
   out_7677467036644633761[310] = 0.0;
   out_7677467036644633761[311] = 0.0;
   out_7677467036644633761[312] = 0.0;
   out_7677467036644633761[313] = 0.0;
   out_7677467036644633761[314] = 0.0;
   out_7677467036644633761[315] = 0.0;
   out_7677467036644633761[316] = 0.0;
   out_7677467036644633761[317] = 0.0;
   out_7677467036644633761[318] = 0.0;
   out_7677467036644633761[319] = 0.0;
   out_7677467036644633761[320] = 0.0;
   out_7677467036644633761[321] = 0.0;
   out_7677467036644633761[322] = 0.0;
   out_7677467036644633761[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_632218751387016029) {
   out_632218751387016029[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_632218751387016029[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_632218751387016029[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_632218751387016029[3] = dt*state[12] + state[3];
   out_632218751387016029[4] = dt*state[13] + state[4];
   out_632218751387016029[5] = dt*state[14] + state[5];
   out_632218751387016029[6] = state[6];
   out_632218751387016029[7] = state[7];
   out_632218751387016029[8] = state[8];
   out_632218751387016029[9] = state[9];
   out_632218751387016029[10] = state[10];
   out_632218751387016029[11] = state[11];
   out_632218751387016029[12] = state[12];
   out_632218751387016029[13] = state[13];
   out_632218751387016029[14] = state[14];
   out_632218751387016029[15] = state[15];
   out_632218751387016029[16] = state[16];
   out_632218751387016029[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6975990122146713878) {
   out_6975990122146713878[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6975990122146713878[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6975990122146713878[2] = 0;
   out_6975990122146713878[3] = 0;
   out_6975990122146713878[4] = 0;
   out_6975990122146713878[5] = 0;
   out_6975990122146713878[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6975990122146713878[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6975990122146713878[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6975990122146713878[9] = 0;
   out_6975990122146713878[10] = 0;
   out_6975990122146713878[11] = 0;
   out_6975990122146713878[12] = 0;
   out_6975990122146713878[13] = 0;
   out_6975990122146713878[14] = 0;
   out_6975990122146713878[15] = 0;
   out_6975990122146713878[16] = 0;
   out_6975990122146713878[17] = 0;
   out_6975990122146713878[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6975990122146713878[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6975990122146713878[20] = 0;
   out_6975990122146713878[21] = 0;
   out_6975990122146713878[22] = 0;
   out_6975990122146713878[23] = 0;
   out_6975990122146713878[24] = 0;
   out_6975990122146713878[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6975990122146713878[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6975990122146713878[27] = 0;
   out_6975990122146713878[28] = 0;
   out_6975990122146713878[29] = 0;
   out_6975990122146713878[30] = 0;
   out_6975990122146713878[31] = 0;
   out_6975990122146713878[32] = 0;
   out_6975990122146713878[33] = 0;
   out_6975990122146713878[34] = 0;
   out_6975990122146713878[35] = 0;
   out_6975990122146713878[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6975990122146713878[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6975990122146713878[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6975990122146713878[39] = 0;
   out_6975990122146713878[40] = 0;
   out_6975990122146713878[41] = 0;
   out_6975990122146713878[42] = 0;
   out_6975990122146713878[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6975990122146713878[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6975990122146713878[45] = 0;
   out_6975990122146713878[46] = 0;
   out_6975990122146713878[47] = 0;
   out_6975990122146713878[48] = 0;
   out_6975990122146713878[49] = 0;
   out_6975990122146713878[50] = 0;
   out_6975990122146713878[51] = 0;
   out_6975990122146713878[52] = 0;
   out_6975990122146713878[53] = 0;
   out_6975990122146713878[54] = 0;
   out_6975990122146713878[55] = 0;
   out_6975990122146713878[56] = 0;
   out_6975990122146713878[57] = 1;
   out_6975990122146713878[58] = 0;
   out_6975990122146713878[59] = 0;
   out_6975990122146713878[60] = 0;
   out_6975990122146713878[61] = 0;
   out_6975990122146713878[62] = 0;
   out_6975990122146713878[63] = 0;
   out_6975990122146713878[64] = 0;
   out_6975990122146713878[65] = 0;
   out_6975990122146713878[66] = dt;
   out_6975990122146713878[67] = 0;
   out_6975990122146713878[68] = 0;
   out_6975990122146713878[69] = 0;
   out_6975990122146713878[70] = 0;
   out_6975990122146713878[71] = 0;
   out_6975990122146713878[72] = 0;
   out_6975990122146713878[73] = 0;
   out_6975990122146713878[74] = 0;
   out_6975990122146713878[75] = 0;
   out_6975990122146713878[76] = 1;
   out_6975990122146713878[77] = 0;
   out_6975990122146713878[78] = 0;
   out_6975990122146713878[79] = 0;
   out_6975990122146713878[80] = 0;
   out_6975990122146713878[81] = 0;
   out_6975990122146713878[82] = 0;
   out_6975990122146713878[83] = 0;
   out_6975990122146713878[84] = 0;
   out_6975990122146713878[85] = dt;
   out_6975990122146713878[86] = 0;
   out_6975990122146713878[87] = 0;
   out_6975990122146713878[88] = 0;
   out_6975990122146713878[89] = 0;
   out_6975990122146713878[90] = 0;
   out_6975990122146713878[91] = 0;
   out_6975990122146713878[92] = 0;
   out_6975990122146713878[93] = 0;
   out_6975990122146713878[94] = 0;
   out_6975990122146713878[95] = 1;
   out_6975990122146713878[96] = 0;
   out_6975990122146713878[97] = 0;
   out_6975990122146713878[98] = 0;
   out_6975990122146713878[99] = 0;
   out_6975990122146713878[100] = 0;
   out_6975990122146713878[101] = 0;
   out_6975990122146713878[102] = 0;
   out_6975990122146713878[103] = 0;
   out_6975990122146713878[104] = dt;
   out_6975990122146713878[105] = 0;
   out_6975990122146713878[106] = 0;
   out_6975990122146713878[107] = 0;
   out_6975990122146713878[108] = 0;
   out_6975990122146713878[109] = 0;
   out_6975990122146713878[110] = 0;
   out_6975990122146713878[111] = 0;
   out_6975990122146713878[112] = 0;
   out_6975990122146713878[113] = 0;
   out_6975990122146713878[114] = 1;
   out_6975990122146713878[115] = 0;
   out_6975990122146713878[116] = 0;
   out_6975990122146713878[117] = 0;
   out_6975990122146713878[118] = 0;
   out_6975990122146713878[119] = 0;
   out_6975990122146713878[120] = 0;
   out_6975990122146713878[121] = 0;
   out_6975990122146713878[122] = 0;
   out_6975990122146713878[123] = 0;
   out_6975990122146713878[124] = 0;
   out_6975990122146713878[125] = 0;
   out_6975990122146713878[126] = 0;
   out_6975990122146713878[127] = 0;
   out_6975990122146713878[128] = 0;
   out_6975990122146713878[129] = 0;
   out_6975990122146713878[130] = 0;
   out_6975990122146713878[131] = 0;
   out_6975990122146713878[132] = 0;
   out_6975990122146713878[133] = 1;
   out_6975990122146713878[134] = 0;
   out_6975990122146713878[135] = 0;
   out_6975990122146713878[136] = 0;
   out_6975990122146713878[137] = 0;
   out_6975990122146713878[138] = 0;
   out_6975990122146713878[139] = 0;
   out_6975990122146713878[140] = 0;
   out_6975990122146713878[141] = 0;
   out_6975990122146713878[142] = 0;
   out_6975990122146713878[143] = 0;
   out_6975990122146713878[144] = 0;
   out_6975990122146713878[145] = 0;
   out_6975990122146713878[146] = 0;
   out_6975990122146713878[147] = 0;
   out_6975990122146713878[148] = 0;
   out_6975990122146713878[149] = 0;
   out_6975990122146713878[150] = 0;
   out_6975990122146713878[151] = 0;
   out_6975990122146713878[152] = 1;
   out_6975990122146713878[153] = 0;
   out_6975990122146713878[154] = 0;
   out_6975990122146713878[155] = 0;
   out_6975990122146713878[156] = 0;
   out_6975990122146713878[157] = 0;
   out_6975990122146713878[158] = 0;
   out_6975990122146713878[159] = 0;
   out_6975990122146713878[160] = 0;
   out_6975990122146713878[161] = 0;
   out_6975990122146713878[162] = 0;
   out_6975990122146713878[163] = 0;
   out_6975990122146713878[164] = 0;
   out_6975990122146713878[165] = 0;
   out_6975990122146713878[166] = 0;
   out_6975990122146713878[167] = 0;
   out_6975990122146713878[168] = 0;
   out_6975990122146713878[169] = 0;
   out_6975990122146713878[170] = 0;
   out_6975990122146713878[171] = 1;
   out_6975990122146713878[172] = 0;
   out_6975990122146713878[173] = 0;
   out_6975990122146713878[174] = 0;
   out_6975990122146713878[175] = 0;
   out_6975990122146713878[176] = 0;
   out_6975990122146713878[177] = 0;
   out_6975990122146713878[178] = 0;
   out_6975990122146713878[179] = 0;
   out_6975990122146713878[180] = 0;
   out_6975990122146713878[181] = 0;
   out_6975990122146713878[182] = 0;
   out_6975990122146713878[183] = 0;
   out_6975990122146713878[184] = 0;
   out_6975990122146713878[185] = 0;
   out_6975990122146713878[186] = 0;
   out_6975990122146713878[187] = 0;
   out_6975990122146713878[188] = 0;
   out_6975990122146713878[189] = 0;
   out_6975990122146713878[190] = 1;
   out_6975990122146713878[191] = 0;
   out_6975990122146713878[192] = 0;
   out_6975990122146713878[193] = 0;
   out_6975990122146713878[194] = 0;
   out_6975990122146713878[195] = 0;
   out_6975990122146713878[196] = 0;
   out_6975990122146713878[197] = 0;
   out_6975990122146713878[198] = 0;
   out_6975990122146713878[199] = 0;
   out_6975990122146713878[200] = 0;
   out_6975990122146713878[201] = 0;
   out_6975990122146713878[202] = 0;
   out_6975990122146713878[203] = 0;
   out_6975990122146713878[204] = 0;
   out_6975990122146713878[205] = 0;
   out_6975990122146713878[206] = 0;
   out_6975990122146713878[207] = 0;
   out_6975990122146713878[208] = 0;
   out_6975990122146713878[209] = 1;
   out_6975990122146713878[210] = 0;
   out_6975990122146713878[211] = 0;
   out_6975990122146713878[212] = 0;
   out_6975990122146713878[213] = 0;
   out_6975990122146713878[214] = 0;
   out_6975990122146713878[215] = 0;
   out_6975990122146713878[216] = 0;
   out_6975990122146713878[217] = 0;
   out_6975990122146713878[218] = 0;
   out_6975990122146713878[219] = 0;
   out_6975990122146713878[220] = 0;
   out_6975990122146713878[221] = 0;
   out_6975990122146713878[222] = 0;
   out_6975990122146713878[223] = 0;
   out_6975990122146713878[224] = 0;
   out_6975990122146713878[225] = 0;
   out_6975990122146713878[226] = 0;
   out_6975990122146713878[227] = 0;
   out_6975990122146713878[228] = 1;
   out_6975990122146713878[229] = 0;
   out_6975990122146713878[230] = 0;
   out_6975990122146713878[231] = 0;
   out_6975990122146713878[232] = 0;
   out_6975990122146713878[233] = 0;
   out_6975990122146713878[234] = 0;
   out_6975990122146713878[235] = 0;
   out_6975990122146713878[236] = 0;
   out_6975990122146713878[237] = 0;
   out_6975990122146713878[238] = 0;
   out_6975990122146713878[239] = 0;
   out_6975990122146713878[240] = 0;
   out_6975990122146713878[241] = 0;
   out_6975990122146713878[242] = 0;
   out_6975990122146713878[243] = 0;
   out_6975990122146713878[244] = 0;
   out_6975990122146713878[245] = 0;
   out_6975990122146713878[246] = 0;
   out_6975990122146713878[247] = 1;
   out_6975990122146713878[248] = 0;
   out_6975990122146713878[249] = 0;
   out_6975990122146713878[250] = 0;
   out_6975990122146713878[251] = 0;
   out_6975990122146713878[252] = 0;
   out_6975990122146713878[253] = 0;
   out_6975990122146713878[254] = 0;
   out_6975990122146713878[255] = 0;
   out_6975990122146713878[256] = 0;
   out_6975990122146713878[257] = 0;
   out_6975990122146713878[258] = 0;
   out_6975990122146713878[259] = 0;
   out_6975990122146713878[260] = 0;
   out_6975990122146713878[261] = 0;
   out_6975990122146713878[262] = 0;
   out_6975990122146713878[263] = 0;
   out_6975990122146713878[264] = 0;
   out_6975990122146713878[265] = 0;
   out_6975990122146713878[266] = 1;
   out_6975990122146713878[267] = 0;
   out_6975990122146713878[268] = 0;
   out_6975990122146713878[269] = 0;
   out_6975990122146713878[270] = 0;
   out_6975990122146713878[271] = 0;
   out_6975990122146713878[272] = 0;
   out_6975990122146713878[273] = 0;
   out_6975990122146713878[274] = 0;
   out_6975990122146713878[275] = 0;
   out_6975990122146713878[276] = 0;
   out_6975990122146713878[277] = 0;
   out_6975990122146713878[278] = 0;
   out_6975990122146713878[279] = 0;
   out_6975990122146713878[280] = 0;
   out_6975990122146713878[281] = 0;
   out_6975990122146713878[282] = 0;
   out_6975990122146713878[283] = 0;
   out_6975990122146713878[284] = 0;
   out_6975990122146713878[285] = 1;
   out_6975990122146713878[286] = 0;
   out_6975990122146713878[287] = 0;
   out_6975990122146713878[288] = 0;
   out_6975990122146713878[289] = 0;
   out_6975990122146713878[290] = 0;
   out_6975990122146713878[291] = 0;
   out_6975990122146713878[292] = 0;
   out_6975990122146713878[293] = 0;
   out_6975990122146713878[294] = 0;
   out_6975990122146713878[295] = 0;
   out_6975990122146713878[296] = 0;
   out_6975990122146713878[297] = 0;
   out_6975990122146713878[298] = 0;
   out_6975990122146713878[299] = 0;
   out_6975990122146713878[300] = 0;
   out_6975990122146713878[301] = 0;
   out_6975990122146713878[302] = 0;
   out_6975990122146713878[303] = 0;
   out_6975990122146713878[304] = 1;
   out_6975990122146713878[305] = 0;
   out_6975990122146713878[306] = 0;
   out_6975990122146713878[307] = 0;
   out_6975990122146713878[308] = 0;
   out_6975990122146713878[309] = 0;
   out_6975990122146713878[310] = 0;
   out_6975990122146713878[311] = 0;
   out_6975990122146713878[312] = 0;
   out_6975990122146713878[313] = 0;
   out_6975990122146713878[314] = 0;
   out_6975990122146713878[315] = 0;
   out_6975990122146713878[316] = 0;
   out_6975990122146713878[317] = 0;
   out_6975990122146713878[318] = 0;
   out_6975990122146713878[319] = 0;
   out_6975990122146713878[320] = 0;
   out_6975990122146713878[321] = 0;
   out_6975990122146713878[322] = 0;
   out_6975990122146713878[323] = 1;
}
void h_4(double *state, double *unused, double *out_3113731581817245961) {
   out_3113731581817245961[0] = state[6] + state[9];
   out_3113731581817245961[1] = state[7] + state[10];
   out_3113731581817245961[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3905659826800726189) {
   out_3905659826800726189[0] = 0;
   out_3905659826800726189[1] = 0;
   out_3905659826800726189[2] = 0;
   out_3905659826800726189[3] = 0;
   out_3905659826800726189[4] = 0;
   out_3905659826800726189[5] = 0;
   out_3905659826800726189[6] = 1;
   out_3905659826800726189[7] = 0;
   out_3905659826800726189[8] = 0;
   out_3905659826800726189[9] = 1;
   out_3905659826800726189[10] = 0;
   out_3905659826800726189[11] = 0;
   out_3905659826800726189[12] = 0;
   out_3905659826800726189[13] = 0;
   out_3905659826800726189[14] = 0;
   out_3905659826800726189[15] = 0;
   out_3905659826800726189[16] = 0;
   out_3905659826800726189[17] = 0;
   out_3905659826800726189[18] = 0;
   out_3905659826800726189[19] = 0;
   out_3905659826800726189[20] = 0;
   out_3905659826800726189[21] = 0;
   out_3905659826800726189[22] = 0;
   out_3905659826800726189[23] = 0;
   out_3905659826800726189[24] = 0;
   out_3905659826800726189[25] = 1;
   out_3905659826800726189[26] = 0;
   out_3905659826800726189[27] = 0;
   out_3905659826800726189[28] = 1;
   out_3905659826800726189[29] = 0;
   out_3905659826800726189[30] = 0;
   out_3905659826800726189[31] = 0;
   out_3905659826800726189[32] = 0;
   out_3905659826800726189[33] = 0;
   out_3905659826800726189[34] = 0;
   out_3905659826800726189[35] = 0;
   out_3905659826800726189[36] = 0;
   out_3905659826800726189[37] = 0;
   out_3905659826800726189[38] = 0;
   out_3905659826800726189[39] = 0;
   out_3905659826800726189[40] = 0;
   out_3905659826800726189[41] = 0;
   out_3905659826800726189[42] = 0;
   out_3905659826800726189[43] = 0;
   out_3905659826800726189[44] = 1;
   out_3905659826800726189[45] = 0;
   out_3905659826800726189[46] = 0;
   out_3905659826800726189[47] = 1;
   out_3905659826800726189[48] = 0;
   out_3905659826800726189[49] = 0;
   out_3905659826800726189[50] = 0;
   out_3905659826800726189[51] = 0;
   out_3905659826800726189[52] = 0;
   out_3905659826800726189[53] = 0;
}
void h_10(double *state, double *unused, double *out_5622970145742276884) {
   out_5622970145742276884[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5622970145742276884[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5622970145742276884[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3601623212465959136) {
   out_3601623212465959136[0] = 0;
   out_3601623212465959136[1] = 9.8100000000000005*cos(state[1]);
   out_3601623212465959136[2] = 0;
   out_3601623212465959136[3] = 0;
   out_3601623212465959136[4] = -state[8];
   out_3601623212465959136[5] = state[7];
   out_3601623212465959136[6] = 0;
   out_3601623212465959136[7] = state[5];
   out_3601623212465959136[8] = -state[4];
   out_3601623212465959136[9] = 0;
   out_3601623212465959136[10] = 0;
   out_3601623212465959136[11] = 0;
   out_3601623212465959136[12] = 1;
   out_3601623212465959136[13] = 0;
   out_3601623212465959136[14] = 0;
   out_3601623212465959136[15] = 1;
   out_3601623212465959136[16] = 0;
   out_3601623212465959136[17] = 0;
   out_3601623212465959136[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3601623212465959136[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3601623212465959136[20] = 0;
   out_3601623212465959136[21] = state[8];
   out_3601623212465959136[22] = 0;
   out_3601623212465959136[23] = -state[6];
   out_3601623212465959136[24] = -state[5];
   out_3601623212465959136[25] = 0;
   out_3601623212465959136[26] = state[3];
   out_3601623212465959136[27] = 0;
   out_3601623212465959136[28] = 0;
   out_3601623212465959136[29] = 0;
   out_3601623212465959136[30] = 0;
   out_3601623212465959136[31] = 1;
   out_3601623212465959136[32] = 0;
   out_3601623212465959136[33] = 0;
   out_3601623212465959136[34] = 1;
   out_3601623212465959136[35] = 0;
   out_3601623212465959136[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3601623212465959136[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3601623212465959136[38] = 0;
   out_3601623212465959136[39] = -state[7];
   out_3601623212465959136[40] = state[6];
   out_3601623212465959136[41] = 0;
   out_3601623212465959136[42] = state[4];
   out_3601623212465959136[43] = -state[3];
   out_3601623212465959136[44] = 0;
   out_3601623212465959136[45] = 0;
   out_3601623212465959136[46] = 0;
   out_3601623212465959136[47] = 0;
   out_3601623212465959136[48] = 0;
   out_3601623212465959136[49] = 0;
   out_3601623212465959136[50] = 1;
   out_3601623212465959136[51] = 0;
   out_3601623212465959136[52] = 0;
   out_3601623212465959136[53] = 1;
}
void h_13(double *state, double *unused, double *out_4238190991132771673) {
   out_4238190991132771673[0] = state[3];
   out_4238190991132771673[1] = state[4];
   out_4238190991132771673[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3704971381515974740) {
   out_3704971381515974740[0] = 0;
   out_3704971381515974740[1] = 0;
   out_3704971381515974740[2] = 0;
   out_3704971381515974740[3] = 1;
   out_3704971381515974740[4] = 0;
   out_3704971381515974740[5] = 0;
   out_3704971381515974740[6] = 0;
   out_3704971381515974740[7] = 0;
   out_3704971381515974740[8] = 0;
   out_3704971381515974740[9] = 0;
   out_3704971381515974740[10] = 0;
   out_3704971381515974740[11] = 0;
   out_3704971381515974740[12] = 0;
   out_3704971381515974740[13] = 0;
   out_3704971381515974740[14] = 0;
   out_3704971381515974740[15] = 0;
   out_3704971381515974740[16] = 0;
   out_3704971381515974740[17] = 0;
   out_3704971381515974740[18] = 0;
   out_3704971381515974740[19] = 0;
   out_3704971381515974740[20] = 0;
   out_3704971381515974740[21] = 0;
   out_3704971381515974740[22] = 1;
   out_3704971381515974740[23] = 0;
   out_3704971381515974740[24] = 0;
   out_3704971381515974740[25] = 0;
   out_3704971381515974740[26] = 0;
   out_3704971381515974740[27] = 0;
   out_3704971381515974740[28] = 0;
   out_3704971381515974740[29] = 0;
   out_3704971381515974740[30] = 0;
   out_3704971381515974740[31] = 0;
   out_3704971381515974740[32] = 0;
   out_3704971381515974740[33] = 0;
   out_3704971381515974740[34] = 0;
   out_3704971381515974740[35] = 0;
   out_3704971381515974740[36] = 0;
   out_3704971381515974740[37] = 0;
   out_3704971381515974740[38] = 0;
   out_3704971381515974740[39] = 0;
   out_3704971381515974740[40] = 0;
   out_3704971381515974740[41] = 1;
   out_3704971381515974740[42] = 0;
   out_3704971381515974740[43] = 0;
   out_3704971381515974740[44] = 0;
   out_3704971381515974740[45] = 0;
   out_3704971381515974740[46] = 0;
   out_3704971381515974740[47] = 0;
   out_3704971381515974740[48] = 0;
   out_3704971381515974740[49] = 0;
   out_3704971381515974740[50] = 0;
   out_3704971381515974740[51] = 0;
   out_3704971381515974740[52] = 0;
   out_3704971381515974740[53] = 0;
}
void h_14(double *state, double *unused, double *out_3879113581675309191) {
   out_3879113581675309191[0] = state[6];
   out_3879113581675309191[1] = state[7];
   out_3879113581675309191[2] = state[8];
}
void H_14(double *state, double *unused, double *out_57581029538758340) {
   out_57581029538758340[0] = 0;
   out_57581029538758340[1] = 0;
   out_57581029538758340[2] = 0;
   out_57581029538758340[3] = 0;
   out_57581029538758340[4] = 0;
   out_57581029538758340[5] = 0;
   out_57581029538758340[6] = 1;
   out_57581029538758340[7] = 0;
   out_57581029538758340[8] = 0;
   out_57581029538758340[9] = 0;
   out_57581029538758340[10] = 0;
   out_57581029538758340[11] = 0;
   out_57581029538758340[12] = 0;
   out_57581029538758340[13] = 0;
   out_57581029538758340[14] = 0;
   out_57581029538758340[15] = 0;
   out_57581029538758340[16] = 0;
   out_57581029538758340[17] = 0;
   out_57581029538758340[18] = 0;
   out_57581029538758340[19] = 0;
   out_57581029538758340[20] = 0;
   out_57581029538758340[21] = 0;
   out_57581029538758340[22] = 0;
   out_57581029538758340[23] = 0;
   out_57581029538758340[24] = 0;
   out_57581029538758340[25] = 1;
   out_57581029538758340[26] = 0;
   out_57581029538758340[27] = 0;
   out_57581029538758340[28] = 0;
   out_57581029538758340[29] = 0;
   out_57581029538758340[30] = 0;
   out_57581029538758340[31] = 0;
   out_57581029538758340[32] = 0;
   out_57581029538758340[33] = 0;
   out_57581029538758340[34] = 0;
   out_57581029538758340[35] = 0;
   out_57581029538758340[36] = 0;
   out_57581029538758340[37] = 0;
   out_57581029538758340[38] = 0;
   out_57581029538758340[39] = 0;
   out_57581029538758340[40] = 0;
   out_57581029538758340[41] = 0;
   out_57581029538758340[42] = 0;
   out_57581029538758340[43] = 0;
   out_57581029538758340[44] = 1;
   out_57581029538758340[45] = 0;
   out_57581029538758340[46] = 0;
   out_57581029538758340[47] = 0;
   out_57581029538758340[48] = 0;
   out_57581029538758340[49] = 0;
   out_57581029538758340[50] = 0;
   out_57581029538758340[51] = 0;
   out_57581029538758340[52] = 0;
   out_57581029538758340[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_6048224022663336905) {
  err_fun(nom_x, delta_x, out_6048224022663336905);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2486701244109526387) {
  inv_err_fun(nom_x, true_x, out_2486701244109526387);
}
void pose_H_mod_fun(double *state, double *out_7677467036644633761) {
  H_mod_fun(state, out_7677467036644633761);
}
void pose_f_fun(double *state, double dt, double *out_632218751387016029) {
  f_fun(state,  dt, out_632218751387016029);
}
void pose_F_fun(double *state, double dt, double *out_6975990122146713878) {
  F_fun(state,  dt, out_6975990122146713878);
}
void pose_h_4(double *state, double *unused, double *out_3113731581817245961) {
  h_4(state, unused, out_3113731581817245961);
}
void pose_H_4(double *state, double *unused, double *out_3905659826800726189) {
  H_4(state, unused, out_3905659826800726189);
}
void pose_h_10(double *state, double *unused, double *out_5622970145742276884) {
  h_10(state, unused, out_5622970145742276884);
}
void pose_H_10(double *state, double *unused, double *out_3601623212465959136) {
  H_10(state, unused, out_3601623212465959136);
}
void pose_h_13(double *state, double *unused, double *out_4238190991132771673) {
  h_13(state, unused, out_4238190991132771673);
}
void pose_H_13(double *state, double *unused, double *out_3704971381515974740) {
  H_13(state, unused, out_3704971381515974740);
}
void pose_h_14(double *state, double *unused, double *out_3879113581675309191) {
  h_14(state, unused, out_3879113581675309191);
}
void pose_H_14(double *state, double *unused, double *out_57581029538758340) {
  H_14(state, unused, out_57581029538758340);
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
