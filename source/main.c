#include "unit_tests.h"

/// define _DEBUG to pass unit tests, delete if you need user interface
#define _DEBUG

/** 
 * @mainpage Quadratic equation solver
 * 
 * @section intro_sec Introduction
 * This code allows you to solve quadratic and linear equations.
 * 
 * @section solving Solving equations 
 * If you want to use prepared user interface you have to call `quadratic_solver`. 
 * If you don't need it, you can use functions `solve_quad_eq` and `solve_linear_eq`.
 * @see quadratic_solver
 * @see solve_linear_eq
 * @see solve_quad_eq
 * 
 * @section testing Unit tests
 * To execute unit tests include `"unit_tests.h"` and call unit_tests.
 * @see unit_tests
 */

int main (void) {
#ifdef _DEBUG
    unit_tests ();
#else
    quadratic_solver ();
#endif

    return 0;
}
