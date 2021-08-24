#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

#define DOUBLE_EPSILON 1e-5

#ifndef __cplusplus
typedef enum ReturnedValues ReturnedValues;
#endif

enum ReturnedValues {
    NO_ROOTS = 0, ONE_ROOT = 1,
    TWO_ROOTS = 2, INF_ROOTS = 3,
};

void quadratic_solver ();

ReturnedValues solve_quad_eq (double a, double b, double c, double *x1, double *x2);

ReturnedValues solve_linear_eq (double a, double b, double *x);

double read_double_coef (char *message);

bool is_equal_double (double a, double b);

void clear_input_buffer ();
