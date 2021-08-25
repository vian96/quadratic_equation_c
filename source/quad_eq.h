/** @file */ 
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

#ifndef __cplusplus
typedef enum NumberOfRoots NumberOfRoots;
#endif

/// Enumeration of numbers of roots to be returned from function
enum NumberOfRoots {
    NO_ROOTS = 0, ONE_ROOT = 1,
    TWO_ROOTS = 2, INF_ROOTS = 3,
};

/// Maximum difference between numbers to be equal
/** @see is_equal_double */
const double DOUBLE_EPSILON = 1e-5;

/// User interface for solving quadratic equations
void quadratic_solver ();

/// Solves quadratic equations over real numbers
/** 
 * Roots are placed to x1 and x2 (see table)
 * a, b, c are coefficients in this equation: a*x^2 + b*x + c = 0
 * 
 * | Returned value | Number of roots | x1 | x2 |
 * | --- | --- | --- | --- |
 * | INF_ROOTS | Infinite | NaN | NaN |
 * | TWO_ROOTS | 2 | Smaller root | Bigger root |
 * | ONE_ROOT | 1 | Root | NaN |
 * | NO_ROOTS | 0 | NaN | NaN |
 * 
 * @param[in] a The first coefficient
 * @param[in] b The second coefficient
 * @param[in] c The third coefficient
 * @param[out] x1 Pointer to the first root
 * @param[out] x2 Pointer to the second root
 * @return number of roots by enum NumberOfRoots 
*/
NumberOfRoots solve_quad_eq (const double a, const double b, const double c, double *x1, double *x2);

/// Solves linear equations
/** 
 * Root is placed to x 
 * a, b are coefficients in this equation: a*x + b = 0
 * If there is not one root then x is NaN
 * 
 * @param[in] a The first coefficient
 * @param[in] b The second coefficient
 * @param[out] x Pointer to root
 * @return number of roots by enum NumberOfRoots 
*/
NumberOfRoots solve_linear_eq (const double a, const double b, double *x);

/// Calculates discriminant
double calc_discriminant (const double a, const double b, const double c);

/// Reads double variable
/** 
 * User interface for reading double variable
 * @param message name of variable
*/
double read_double_coef (const char *message);

/// Prints roots of equation
void print_roots (NumberOfRoots num, const double x1, const double x2);

/// Compares two double variables
/** 
 * @return true if difference between numbers is less than DOUBLE_EPSILON
*/
bool is_equal_double (const double a, const double b);

/// Clears input buffer until the end of line
void clear_input_buffer ();
