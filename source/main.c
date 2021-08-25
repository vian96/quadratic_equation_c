#define _DEBUG 

#ifdef _DEBUG
    #include "unit_tests.h"
#else
    #include "quad_eq.h"
#endif

/** 
 * @mainpage Quadratic equation solver
 * 
 * @section intro_sec Introduction
 * This code allows you to to solve quadratic and linear equations.
 * 
 * @section solving Solving equations 
 * To use user interface include "quad_eq.h" and call quadratic_solver. 
 * If you want to solve equations by yourself 
 * call function solve_quad_eq or solve_linear_eq.  
 * @see quadratic_solver
 * @see solve_linear_eq
 * @see solve_quad_eq
 * 
 * @section testing Unit tests
 * To execute unit tests include "unit_tests.h" and call unit_tests.
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
