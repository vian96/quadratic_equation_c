# Quadratic equation solver

This code allows you to to solve quadratic and linear equations. 

To use user interface include `"quad_eq.h"` and call `quadratic_solver`. If you want to solve equation by yourself call function `solve_quad_eq`. To execute unit tests inclue `"unit_tests.h"` and call `unit_tests`. 

For more detailed information see documentation in folder docs.
    
| Returned value | Number of roots | x1 | x2 |
| --- | --- | --- | --- |
| 3 | Infinite | NaN | NaN |
| 2 | 2 | Smaller root | Bigger root |
| 1 | 1 | Root | NaN |
| 0 | 0 | NaN | NaN |

