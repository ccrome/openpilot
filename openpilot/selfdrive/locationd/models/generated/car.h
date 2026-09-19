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
void car_err_fun(double *nom_x, double *delta_x, double *out_1565628999694736811);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2092600406140220529);
void car_H_mod_fun(double *state, double *out_1817686528085378799);
void car_f_fun(double *state, double dt, double *out_1983356715662398263);
void car_F_fun(double *state, double dt, double *out_7930873036226248037);
void car_h_25(double *state, double *unused, double *out_9084158657378903885);
void car_H_25(double *state, double *unused, double *out_2584134290167586048);
void car_h_24(double *state, double *unused, double *out_2444310780920195379);
void car_H_24(double *state, double *unused, double *out_8785166970018747474);
void car_h_30(double *state, double *unused, double *out_5725135888076625381);
void car_H_30(double *state, double *unused, double *out_7111830620295194246);
void car_h_26(double *state, double *unused, double *out_7719934917972080590);
void car_H_26(double *state, double *unused, double *out_6325637609041642272);
void car_h_27(double *state, double *unused, double *out_102189485372063120);
void car_H_27(double *state, double *unused, double *out_4888236549111251029);
void car_h_29(double *state, double *unused, double *out_6668645740978287816);
void car_H_29(double *state, double *unused, double *out_6601599275980802062);
void car_h_28(double *state, double *unused, double *out_8898498949638060260);
void car_H_28(double *state, double *unused, double *out_6762745780659218980);
void car_h_31(double *state, double *unused, double *out_3448852389659899358);
void car_H_31(double *state, double *unused, double *out_2553488328290625620);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}