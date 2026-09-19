#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_1930119882406415422);
void live_err_fun(double *nom_x, double *delta_x, double *out_3827008319707989394);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_4260650487744536334);
void live_H_mod_fun(double *state, double *out_3190959537550126582);
void live_f_fun(double *state, double dt, double *out_8154941172860301166);
void live_F_fun(double *state, double dt, double *out_5801573248129388914);
void live_h_4(double *state, double *unused, double *out_6193303223598320248);
void live_H_4(double *state, double *unused, double *out_2031484393258249901);
void live_h_9(double *state, double *unused, double *out_2178130778922553171);
void live_H_9(double *state, double *unused, double *out_5255734542006197569);
void live_h_10(double *state, double *unused, double *out_6774105664635166066);
void live_H_10(double *state, double *unused, double *out_8031619601784158855);
void live_h_12(double *state, double *unused, double *out_3655512714931246893);
void live_H_12(double *state, double *unused, double *out_2987972014773711894);
void live_h_35(double *state, double *unused, double *out_3069808773595975371);
void live_H_35(double *state, double *unused, double *out_1335177664114357475);
void live_h_32(double *state, double *unused, double *out_8923001604712024720);
void live_H_32(double *state, double *unused, double *out_1466342449055097944);
void live_h_13(double *state, double *unused, double *out_9111085500428235805);
void live_H_13(double *state, double *unused, double *out_8433480983190335709);
void live_h_14(double *state, double *unused, double *out_2178130778922553171);
void live_H_14(double *state, double *unused, double *out_5255734542006197569);
void live_h_33(double *state, double *unused, double *out_410130355886361364);
void live_H_33(double *state, double *unused, double *out_4485734668753215079);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}