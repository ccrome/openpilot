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
void live_H(double *in_vec, double *out_8228107202709385699);
void live_err_fun(double *nom_x, double *delta_x, double *out_7285546952580167690);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2105095879422131793);
void live_H_mod_fun(double *state, double *out_7346253528114610498);
void live_f_fun(double *state, double dt, double *out_1760032132989818675);
void live_F_fun(double *state, double dt, double *out_5894746300274630600);
void live_h_4(double *state, double *unused, double *out_148841726174455481);
void live_H_4(double *state, double *unused, double *out_2397348258356090954);
void live_h_9(double *state, double *unused, double *out_458857123944214916);
void live_H_9(double *state, double *unused, double *out_8762176880089013192);
void live_h_10(double *state, double *unused, double *out_2641320079454843661);
void live_H_10(double *state, double *unused, double *out_3072535957938307665);
void live_h_12(double *state, double *unused, double *out_5446535797743988996);
void live_H_12(double *state, double *unused, double *out_3983910118686642042);
void live_h_35(double *state, double *unused, double *out_8483420327882055329);
void live_H_35(double *state, double *unused, double *out_8284376374996485158);
void live_h_32(double *state, double *unused, double *out_6190061626212954131);
void live_H_32(double *state, double *unused, double *out_5579351862094735221);
void live_h_13(double *state, double *unused, double *out_8912196411825827307);
void live_H_13(double *state, double *unused, double *out_3144028181681836691);
void live_h_14(double *state, double *unused, double *out_458857123944214916);
void live_H_14(double *state, double *unused, double *out_8762176880089013192);
void live_h_33(double *state, double *unused, double *out_7294185637115451865);
void live_H_33(double *state, double *unused, double *out_8914567320367555934);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}