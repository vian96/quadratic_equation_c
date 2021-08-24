#include <stdio.h>
#include <math.h>
#include <assert.h>

#define DOUBLE_EPSILON 1e-5


void quadratic_solver ();

int solve_quad_eq (double a, double b, double c, double *x1, double *x2);

_Bool is_equal_double (double a, double b);

void clear_input_buffer ();