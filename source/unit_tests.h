/** @file */ 
#include "quad_eq.h"

#ifndef __cplusplus
typedef struct DataOut DataOut;
#endif

/// Strcture to store output data to compare
struct DataOut {
    int num;
    double x1,x2;
};

/// Function for unit tests
void unit_tests ();

/// Function checks if expected and received are the same
bool check_test (int res, double x1, double x2, DataOut expected);

