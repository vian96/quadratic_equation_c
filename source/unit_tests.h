/** @file */ 
#include "quad_eq.h"

#ifndef __cplusplus
typedef struct DataOut DataOut;
#endif

/// Structure to store output data to compare
struct TestData {
    double a; ///< The first coefficient of equation
    double b; ///< The second coefficient of equation
    double c; ///< The third coefficient of equation
    
    int num_of_roots; ///< Number of roots of equation
    
    double x1; ///< The first root
    double x2; ///< The second root
};

/// Function for unit tests
bool unit_tests ();

/// Function checks if expected and received are the same
bool check_test (const NumberOfRoots res, const double x1, const double x2, const TestData expected);

