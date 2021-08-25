#include "unit_tests.h"

void unit_tests () {
    
    double input[][3] = {
        {1, 1, 1},
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 1},
        {46, 32, 52},
        {-63, 5, 99},
        {-11, -73, 65},
        {63, 15, 49},
        {21, -33, 12},
        {-90, 63, -69},
        {38, 41, -47},
        {-95, 85, 39},
        {93, 78, 70},
        {5, -100, 68},
        {939.248, 770.948, 659.721},
        {-877.562, -692.729, 616.921},
        {191.994, 668.262, -430.517},
        {-716.991, -841.98, -280.357},
        {969.562, -197.88, 867.318},
        {-875.457, -803.269, 582.298},
        {222.589, 66.762, -822.478},
        {-543.961, 881.829, -898.304},
        {-84.384, 480.633, -799.085},
        {900.988, 543.191, 755.287}
    };
    
    DataOut expected[] = {
        {0, NAN, NAN},
        {3, NAN, NAN},
        {1, -1.0, NAN},
        {0, NAN, NAN},
        {0, NAN, NAN},
        {2, -1.214512, 1.293876},
        {2, -7.431504, 0.79514},
        {0, NAN, NAN},
        {2, 0.571428, 1.0},
        {0, NAN, NAN},
        {2, -1.775546, 0.696598},
        {2, -0.334082, 1.228818},
        {0, NAN, NAN},
        {2, 0.70484, 19.29516},
        {0, NAN, NAN},
        {2, -1.32139, 0.532012},
        {2, -4.036198, 0.555558},
        {0, NAN, NAN},
        {0, NAN, NAN},
        {2, -1.39451, 0.476968},
        {2, -2.07806, 1.778126},
        {0, NAN, NAN},
        {0, NAN, NAN},
        {0, NAN, NAN},
    };

    int counter = 0;
    double x1 = NAN, x2 = NAN;
    for (int i = 0; i < sizeof (input) / sizeof (*input); i++) {
        int res = solve_quad_eq (input[i][0], input[i][1], input[i][2], &x1, &x2);

        if (check_test (res, x1, x2, expected[i])) {
            printf ("Test %d OK\n", i);
            counter++;
        }
        else
            printf ("Test %d failed! Expected: %d %f %f. Returned: %d %f %f\n", 
                i, expected[i].num, expected[i].x1, expected[i].x2, res, x1, x2);
    }

    printf ("\n%d of %d tests passed\n", 
        counter, sizeof (input) / sizeof (*input));
}


bool check_test (int res, double x1, double x2, DataOut expected) {
    return (res == expected.num) && 
        (isnan (x1) && isnan (expected.x1) || is_equal_double (x1, expected.x1)) &&
        (isnan (x2) && isnan (expected.x1) || is_equal_double (x2, expected.x2));
}
