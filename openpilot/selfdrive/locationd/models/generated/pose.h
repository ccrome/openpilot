#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_849063694558529375);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5536998468017687086);
void pose_H_mod_fun(double *state, double *out_8675581923907159569);
void pose_f_fun(double *state, double dt, double *out_5828399727577413921);
void pose_F_fun(double *state, double dt, double *out_6448424330139796371);
void pose_h_4(double *state, double *unused, double *out_4289702124009644444);
void pose_H_4(double *state, double *unused, double *out_6782071020311383479);
void pose_h_10(double *state, double *unused, double *out_7934488606380957591);
void pose_H_10(double *state, double *unused, double *out_4068427810281274883);
void pose_h_13(double *state, double *unused, double *out_8978738644302890974);
void pose_H_13(double *state, double *unused, double *out_8452399228065835336);
void pose_h_14(double *state, double *unused, double *out_7145417579323282935);
void pose_H_14(double *state, double *unused, double *out_7701432197058683608);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}