#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1565628999694736811) {
   out_1565628999694736811[0] = delta_x[0] + nom_x[0];
   out_1565628999694736811[1] = delta_x[1] + nom_x[1];
   out_1565628999694736811[2] = delta_x[2] + nom_x[2];
   out_1565628999694736811[3] = delta_x[3] + nom_x[3];
   out_1565628999694736811[4] = delta_x[4] + nom_x[4];
   out_1565628999694736811[5] = delta_x[5] + nom_x[5];
   out_1565628999694736811[6] = delta_x[6] + nom_x[6];
   out_1565628999694736811[7] = delta_x[7] + nom_x[7];
   out_1565628999694736811[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2092600406140220529) {
   out_2092600406140220529[0] = -nom_x[0] + true_x[0];
   out_2092600406140220529[1] = -nom_x[1] + true_x[1];
   out_2092600406140220529[2] = -nom_x[2] + true_x[2];
   out_2092600406140220529[3] = -nom_x[3] + true_x[3];
   out_2092600406140220529[4] = -nom_x[4] + true_x[4];
   out_2092600406140220529[5] = -nom_x[5] + true_x[5];
   out_2092600406140220529[6] = -nom_x[6] + true_x[6];
   out_2092600406140220529[7] = -nom_x[7] + true_x[7];
   out_2092600406140220529[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_1817686528085378799) {
   out_1817686528085378799[0] = 1.0;
   out_1817686528085378799[1] = 0.0;
   out_1817686528085378799[2] = 0.0;
   out_1817686528085378799[3] = 0.0;
   out_1817686528085378799[4] = 0.0;
   out_1817686528085378799[5] = 0.0;
   out_1817686528085378799[6] = 0.0;
   out_1817686528085378799[7] = 0.0;
   out_1817686528085378799[8] = 0.0;
   out_1817686528085378799[9] = 0.0;
   out_1817686528085378799[10] = 1.0;
   out_1817686528085378799[11] = 0.0;
   out_1817686528085378799[12] = 0.0;
   out_1817686528085378799[13] = 0.0;
   out_1817686528085378799[14] = 0.0;
   out_1817686528085378799[15] = 0.0;
   out_1817686528085378799[16] = 0.0;
   out_1817686528085378799[17] = 0.0;
   out_1817686528085378799[18] = 0.0;
   out_1817686528085378799[19] = 0.0;
   out_1817686528085378799[20] = 1.0;
   out_1817686528085378799[21] = 0.0;
   out_1817686528085378799[22] = 0.0;
   out_1817686528085378799[23] = 0.0;
   out_1817686528085378799[24] = 0.0;
   out_1817686528085378799[25] = 0.0;
   out_1817686528085378799[26] = 0.0;
   out_1817686528085378799[27] = 0.0;
   out_1817686528085378799[28] = 0.0;
   out_1817686528085378799[29] = 0.0;
   out_1817686528085378799[30] = 1.0;
   out_1817686528085378799[31] = 0.0;
   out_1817686528085378799[32] = 0.0;
   out_1817686528085378799[33] = 0.0;
   out_1817686528085378799[34] = 0.0;
   out_1817686528085378799[35] = 0.0;
   out_1817686528085378799[36] = 0.0;
   out_1817686528085378799[37] = 0.0;
   out_1817686528085378799[38] = 0.0;
   out_1817686528085378799[39] = 0.0;
   out_1817686528085378799[40] = 1.0;
   out_1817686528085378799[41] = 0.0;
   out_1817686528085378799[42] = 0.0;
   out_1817686528085378799[43] = 0.0;
   out_1817686528085378799[44] = 0.0;
   out_1817686528085378799[45] = 0.0;
   out_1817686528085378799[46] = 0.0;
   out_1817686528085378799[47] = 0.0;
   out_1817686528085378799[48] = 0.0;
   out_1817686528085378799[49] = 0.0;
   out_1817686528085378799[50] = 1.0;
   out_1817686528085378799[51] = 0.0;
   out_1817686528085378799[52] = 0.0;
   out_1817686528085378799[53] = 0.0;
   out_1817686528085378799[54] = 0.0;
   out_1817686528085378799[55] = 0.0;
   out_1817686528085378799[56] = 0.0;
   out_1817686528085378799[57] = 0.0;
   out_1817686528085378799[58] = 0.0;
   out_1817686528085378799[59] = 0.0;
   out_1817686528085378799[60] = 1.0;
   out_1817686528085378799[61] = 0.0;
   out_1817686528085378799[62] = 0.0;
   out_1817686528085378799[63] = 0.0;
   out_1817686528085378799[64] = 0.0;
   out_1817686528085378799[65] = 0.0;
   out_1817686528085378799[66] = 0.0;
   out_1817686528085378799[67] = 0.0;
   out_1817686528085378799[68] = 0.0;
   out_1817686528085378799[69] = 0.0;
   out_1817686528085378799[70] = 1.0;
   out_1817686528085378799[71] = 0.0;
   out_1817686528085378799[72] = 0.0;
   out_1817686528085378799[73] = 0.0;
   out_1817686528085378799[74] = 0.0;
   out_1817686528085378799[75] = 0.0;
   out_1817686528085378799[76] = 0.0;
   out_1817686528085378799[77] = 0.0;
   out_1817686528085378799[78] = 0.0;
   out_1817686528085378799[79] = 0.0;
   out_1817686528085378799[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1983356715662398263) {
   out_1983356715662398263[0] = state[0];
   out_1983356715662398263[1] = state[1];
   out_1983356715662398263[2] = state[2];
   out_1983356715662398263[3] = state[3];
   out_1983356715662398263[4] = state[4];
   out_1983356715662398263[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1983356715662398263[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1983356715662398263[7] = state[7];
   out_1983356715662398263[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7930873036226248037) {
   out_7930873036226248037[0] = 1;
   out_7930873036226248037[1] = 0;
   out_7930873036226248037[2] = 0;
   out_7930873036226248037[3] = 0;
   out_7930873036226248037[4] = 0;
   out_7930873036226248037[5] = 0;
   out_7930873036226248037[6] = 0;
   out_7930873036226248037[7] = 0;
   out_7930873036226248037[8] = 0;
   out_7930873036226248037[9] = 0;
   out_7930873036226248037[10] = 1;
   out_7930873036226248037[11] = 0;
   out_7930873036226248037[12] = 0;
   out_7930873036226248037[13] = 0;
   out_7930873036226248037[14] = 0;
   out_7930873036226248037[15] = 0;
   out_7930873036226248037[16] = 0;
   out_7930873036226248037[17] = 0;
   out_7930873036226248037[18] = 0;
   out_7930873036226248037[19] = 0;
   out_7930873036226248037[20] = 1;
   out_7930873036226248037[21] = 0;
   out_7930873036226248037[22] = 0;
   out_7930873036226248037[23] = 0;
   out_7930873036226248037[24] = 0;
   out_7930873036226248037[25] = 0;
   out_7930873036226248037[26] = 0;
   out_7930873036226248037[27] = 0;
   out_7930873036226248037[28] = 0;
   out_7930873036226248037[29] = 0;
   out_7930873036226248037[30] = 1;
   out_7930873036226248037[31] = 0;
   out_7930873036226248037[32] = 0;
   out_7930873036226248037[33] = 0;
   out_7930873036226248037[34] = 0;
   out_7930873036226248037[35] = 0;
   out_7930873036226248037[36] = 0;
   out_7930873036226248037[37] = 0;
   out_7930873036226248037[38] = 0;
   out_7930873036226248037[39] = 0;
   out_7930873036226248037[40] = 1;
   out_7930873036226248037[41] = 0;
   out_7930873036226248037[42] = 0;
   out_7930873036226248037[43] = 0;
   out_7930873036226248037[44] = 0;
   out_7930873036226248037[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7930873036226248037[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7930873036226248037[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7930873036226248037[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7930873036226248037[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7930873036226248037[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7930873036226248037[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7930873036226248037[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7930873036226248037[53] = -9.8100000000000005*dt;
   out_7930873036226248037[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7930873036226248037[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7930873036226248037[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7930873036226248037[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7930873036226248037[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7930873036226248037[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7930873036226248037[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7930873036226248037[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7930873036226248037[62] = 0;
   out_7930873036226248037[63] = 0;
   out_7930873036226248037[64] = 0;
   out_7930873036226248037[65] = 0;
   out_7930873036226248037[66] = 0;
   out_7930873036226248037[67] = 0;
   out_7930873036226248037[68] = 0;
   out_7930873036226248037[69] = 0;
   out_7930873036226248037[70] = 1;
   out_7930873036226248037[71] = 0;
   out_7930873036226248037[72] = 0;
   out_7930873036226248037[73] = 0;
   out_7930873036226248037[74] = 0;
   out_7930873036226248037[75] = 0;
   out_7930873036226248037[76] = 0;
   out_7930873036226248037[77] = 0;
   out_7930873036226248037[78] = 0;
   out_7930873036226248037[79] = 0;
   out_7930873036226248037[80] = 1;
}
void h_25(double *state, double *unused, double *out_9084158657378903885) {
   out_9084158657378903885[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2584134290167586048) {
   out_2584134290167586048[0] = 0;
   out_2584134290167586048[1] = 0;
   out_2584134290167586048[2] = 0;
   out_2584134290167586048[3] = 0;
   out_2584134290167586048[4] = 0;
   out_2584134290167586048[5] = 0;
   out_2584134290167586048[6] = 1;
   out_2584134290167586048[7] = 0;
   out_2584134290167586048[8] = 0;
}
void h_24(double *state, double *unused, double *out_2444310780920195379) {
   out_2444310780920195379[0] = state[4];
   out_2444310780920195379[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8785166970018747474) {
   out_8785166970018747474[0] = 0;
   out_8785166970018747474[1] = 0;
   out_8785166970018747474[2] = 0;
   out_8785166970018747474[3] = 0;
   out_8785166970018747474[4] = 1;
   out_8785166970018747474[5] = 0;
   out_8785166970018747474[6] = 0;
   out_8785166970018747474[7] = 0;
   out_8785166970018747474[8] = 0;
   out_8785166970018747474[9] = 0;
   out_8785166970018747474[10] = 0;
   out_8785166970018747474[11] = 0;
   out_8785166970018747474[12] = 0;
   out_8785166970018747474[13] = 0;
   out_8785166970018747474[14] = 1;
   out_8785166970018747474[15] = 0;
   out_8785166970018747474[16] = 0;
   out_8785166970018747474[17] = 0;
}
void h_30(double *state, double *unused, double *out_5725135888076625381) {
   out_5725135888076625381[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7111830620295194246) {
   out_7111830620295194246[0] = 0;
   out_7111830620295194246[1] = 0;
   out_7111830620295194246[2] = 0;
   out_7111830620295194246[3] = 0;
   out_7111830620295194246[4] = 1;
   out_7111830620295194246[5] = 0;
   out_7111830620295194246[6] = 0;
   out_7111830620295194246[7] = 0;
   out_7111830620295194246[8] = 0;
}
void h_26(double *state, double *unused, double *out_7719934917972080590) {
   out_7719934917972080590[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6325637609041642272) {
   out_6325637609041642272[0] = 0;
   out_6325637609041642272[1] = 0;
   out_6325637609041642272[2] = 0;
   out_6325637609041642272[3] = 0;
   out_6325637609041642272[4] = 0;
   out_6325637609041642272[5] = 0;
   out_6325637609041642272[6] = 0;
   out_6325637609041642272[7] = 1;
   out_6325637609041642272[8] = 0;
}
void h_27(double *state, double *unused, double *out_102189485372063120) {
   out_102189485372063120[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4888236549111251029) {
   out_4888236549111251029[0] = 0;
   out_4888236549111251029[1] = 0;
   out_4888236549111251029[2] = 0;
   out_4888236549111251029[3] = 1;
   out_4888236549111251029[4] = 0;
   out_4888236549111251029[5] = 0;
   out_4888236549111251029[6] = 0;
   out_4888236549111251029[7] = 0;
   out_4888236549111251029[8] = 0;
}
void h_29(double *state, double *unused, double *out_6668645740978287816) {
   out_6668645740978287816[0] = state[1];
}
void H_29(double *state, double *unused, double *out_6601599275980802062) {
   out_6601599275980802062[0] = 0;
   out_6601599275980802062[1] = 1;
   out_6601599275980802062[2] = 0;
   out_6601599275980802062[3] = 0;
   out_6601599275980802062[4] = 0;
   out_6601599275980802062[5] = 0;
   out_6601599275980802062[6] = 0;
   out_6601599275980802062[7] = 0;
   out_6601599275980802062[8] = 0;
}
void h_28(double *state, double *unused, double *out_8898498949638060260) {
   out_8898498949638060260[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6762745780659218980) {
   out_6762745780659218980[0] = 1;
   out_6762745780659218980[1] = 0;
   out_6762745780659218980[2] = 0;
   out_6762745780659218980[3] = 0;
   out_6762745780659218980[4] = 0;
   out_6762745780659218980[5] = 0;
   out_6762745780659218980[6] = 0;
   out_6762745780659218980[7] = 0;
   out_6762745780659218980[8] = 0;
}
void h_31(double *state, double *unused, double *out_3448852389659899358) {
   out_3448852389659899358[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2553488328290625620) {
   out_2553488328290625620[0] = 0;
   out_2553488328290625620[1] = 0;
   out_2553488328290625620[2] = 0;
   out_2553488328290625620[3] = 0;
   out_2553488328290625620[4] = 0;
   out_2553488328290625620[5] = 0;
   out_2553488328290625620[6] = 0;
   out_2553488328290625620[7] = 0;
   out_2553488328290625620[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_1565628999694736811) {
  err_fun(nom_x, delta_x, out_1565628999694736811);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2092600406140220529) {
  inv_err_fun(nom_x, true_x, out_2092600406140220529);
}
void car_H_mod_fun(double *state, double *out_1817686528085378799) {
  H_mod_fun(state, out_1817686528085378799);
}
void car_f_fun(double *state, double dt, double *out_1983356715662398263) {
  f_fun(state,  dt, out_1983356715662398263);
}
void car_F_fun(double *state, double dt, double *out_7930873036226248037) {
  F_fun(state,  dt, out_7930873036226248037);
}
void car_h_25(double *state, double *unused, double *out_9084158657378903885) {
  h_25(state, unused, out_9084158657378903885);
}
void car_H_25(double *state, double *unused, double *out_2584134290167586048) {
  H_25(state, unused, out_2584134290167586048);
}
void car_h_24(double *state, double *unused, double *out_2444310780920195379) {
  h_24(state, unused, out_2444310780920195379);
}
void car_H_24(double *state, double *unused, double *out_8785166970018747474) {
  H_24(state, unused, out_8785166970018747474);
}
void car_h_30(double *state, double *unused, double *out_5725135888076625381) {
  h_30(state, unused, out_5725135888076625381);
}
void car_H_30(double *state, double *unused, double *out_7111830620295194246) {
  H_30(state, unused, out_7111830620295194246);
}
void car_h_26(double *state, double *unused, double *out_7719934917972080590) {
  h_26(state, unused, out_7719934917972080590);
}
void car_H_26(double *state, double *unused, double *out_6325637609041642272) {
  H_26(state, unused, out_6325637609041642272);
}
void car_h_27(double *state, double *unused, double *out_102189485372063120) {
  h_27(state, unused, out_102189485372063120);
}
void car_H_27(double *state, double *unused, double *out_4888236549111251029) {
  H_27(state, unused, out_4888236549111251029);
}
void car_h_29(double *state, double *unused, double *out_6668645740978287816) {
  h_29(state, unused, out_6668645740978287816);
}
void car_H_29(double *state, double *unused, double *out_6601599275980802062) {
  H_29(state, unused, out_6601599275980802062);
}
void car_h_28(double *state, double *unused, double *out_8898498949638060260) {
  h_28(state, unused, out_8898498949638060260);
}
void car_H_28(double *state, double *unused, double *out_6762745780659218980) {
  H_28(state, unused, out_6762745780659218980);
}
void car_h_31(double *state, double *unused, double *out_3448852389659899358) {
  h_31(state, unused, out_3448852389659899358);
}
void car_H_31(double *state, double *unused, double *out_2553488328290625620) {
  H_31(state, unused, out_2553488328290625620);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
