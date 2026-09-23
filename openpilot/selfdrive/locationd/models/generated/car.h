#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_2238750889440829741);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3913702949277586696);
void car_H_mod_fun(double *state, double *out_3892854578449048920);
void car_f_fun(double *state, double dt, double *out_5246332095756241795);
void car_F_fun(double *state, double dt, double *out_8822821766495926600);
void car_h_25(double *state, double *unused, double *out_889642710733482015);
void car_H_25(double *state, double *unused, double *out_6632551462286642891);
void car_h_24(double *state, double *unused, double *out_1963768568526007856);
void car_H_24(double *state, double *unused, double *out_3074625863484319755);
void car_h_30(double *state, double *unused, double *out_8770915361487531200);
void car_H_30(double *state, double *unused, double *out_7286496281295300527);
void car_h_26(double *state, double *unused, double *out_4713448714540727184);
void car_H_26(double *state, double *unused, double *out_8072689292548852501);
void car_h_27(double *state, double *unused, double *out_6805273464467344351);
void car_H_27(double *state, double *unused, double *out_8936653721230307872);
void car_h_29(double *state, double *unused, double *out_8693744618886722304);
void car_H_29(double *state, double *unused, double *out_7796727625609692711);
void car_h_28(double *state, double *unused, double *out_6639797341581361620);
void car_H_28(double *state, double *unused, double *out_2714328608540162137);
void car_h_31(double *state, double *unused, double *out_2340274103362365182);
void car_H_31(double *state, double *unused, double *out_7446481190315501025);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}