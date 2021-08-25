# Quadratic equation solver

This code allows you to to solve quadratic and linear equations. 

## Solving equations

To use user interface include `"quad_eq.h"` and call `quadratic_solver`. If you want to solve equation by yourself call function `solve_quad_eq`. 

## Unit tests

To execute unit tests inclue `"unit_tests.h"` and call `unit_tests`. 

## Documentation

For more detailed information see documentation in folder docs.
    
| Returned value | Number of roots | x1 | x2 |
| --- | --- | --- | --- |
| INF_ROOTS | Infinite | NaN | NaN |
| TWO_ROOTS | 2 | Smaller root | Bigger root |
| ONE_ROOT | 1 | Root | NaN |
| NO_ROOTS | 0 | NaN | NaN |

