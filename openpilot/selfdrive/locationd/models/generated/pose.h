#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6048224022663336905);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2486701244109526387);
void pose_H_mod_fun(double *state, double *out_7677467036644633761);
void pose_f_fun(double *state, double dt, double *out_632218751387016029);
void pose_F_fun(double *state, double dt, double *out_6975990122146713878);
void pose_h_4(double *state, double *unused, double *out_3113731581817245961);
void pose_H_4(double *state, double *unused, double *out_3905659826800726189);
void pose_h_10(double *state, double *unused, double *out_5622970145742276884);
void pose_H_10(double *state, double *unused, double *out_3601623212465959136);
void pose_h_13(double *state, double *unused, double *out_4238190991132771673);
void pose_H_13(double *state, double *unused, double *out_3704971381515974740);
void pose_h_14(double *state, double *unused, double *out_3879113581675309191);
void pose_H_14(double *state, double *unused, double *out_57581029538758340);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}