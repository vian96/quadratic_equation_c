# Quadratic equation solver

This code allows you to to solve quadratic equation. 

After including '"quad_eq.h"' all you need is to call the function 'quadratic_solver'. If you want to solve equation by yourself call function 'solve_quad_eq' (description below).

## solve_quad_eq
'int solve_quad_eq (double a, double b, double c, double *x1, double *x2);'
**Description**:
    This function solves quadratic equation in real numbers. It returns number of roots (3 means infinite roots), roots are placed to x1 and x2 (see table below). a, b, c are coefficients in this equation: 'a\*x^2 + b\*x + c'
**Arguments**:
    - 'double a' - coefficient of x^2
    - 'double b' - coefficient of x
    - 'double c' - constant coefficient
    - 'double *x1' - pointer to the first root
    - 'double *x2' - pointer to the second root
    
| Returned value | Number of roots | x1 | x2 |
| --- | --- | --- | --- |
| 3 | Infinite | NaN | NaN |
| 2 | 2 | Smaller root | Bigger root |
| 1 | 1 | Root | NaN |
| 0 | 0 | NaN | NaN |

