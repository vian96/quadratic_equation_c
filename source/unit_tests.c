#include "unit_tests.h"

bool unit_tests () {
    TestData tests[] = {
        {1, 1, 1, 0, NAN, NAN},
        {0, 0, 0, 3, NAN, NAN},
        {0, 1, 1, 1, -1.0, NAN},
        {0, 0, 1, 0, NAN, NAN},
        {46, 32, 52, 0, NAN, NAN},
        {-63, 5, 99, 2, -1.214512, 1.293876},
        {-11, -73, 65, 2, -7.431504, 0.79514},
        {63, 15, 49, 0, NAN, NAN},
        {21, -33, 12, 2, 0.571428, 1.0},
        {-90, 63, -69, 0, NAN, NAN},
        {38, 41, -47, 2, -1.775546, 0.696598},
        {-95, 85, 39, 2, -0.334082, 1.228818},
        {93, 78, 70, 0, NAN, NAN},
        {5, -100, 68, 2, 0.70484, 19.29516},
        {939.248, 770.948, 659.721, 0, NAN, NAN},
        {-877.562, -692.729, 616.921, 2, -1.32139, 0.532012},
        {191.994, 668.262, -430.517, 2, -4.036198, 0.555558},
        {-716.991, -841.98, -280.357, 0, NAN, NAN},
        {969.562, -197.88, 867.318, 0, NAN, NAN},
        {-875.457, -803.269, 582.298, 2, -1.39451, 0.476968},
        {222.589, 66.762, -822.478, 2, -2.07806, 1.778126},
        {-543.961, 881.829, -898.304, 0, NAN, NAN},
        {-84.384, 480.633, -799.085, 0, NAN, NAN},
        {900.988, 543.191, 755.287, 0, NAN, NAN},
    };

    int counter = 0;
    double x1 = NAN, x2 = NAN;
    for (int i = 0; i < sizeof (tests) / sizeof (*tests); i++) {
        NumberOfRoots res = solve_quad_eq (tests[i].a, tests[i].b, tests[i].c, &x1, &x2);

        if (check_test (res, x1, x2, tests[i])) {
            printf ("Test %d OK\n", i);
            counter++;
        }
        else
            printf ("Test %d failed! Expected: %d %f %f. Returned: %d %f %f\n", 
                i, tests[i].num_of_roots, tests[i].x1, tests[i].x2, res, x1, x2);
    }

    printf ("\n%d of %d tests passed\n", 
        counter, sizeof (tests) / sizeof (*tests));
        
    return counter == sizeof (tests) / sizeof (*tests);
}


bool check_test (NumberOfRoots res, const double x1, const double x2, 
                    const TestData expected) {
                        
    return (res == expected.num_of_roots) && 
        (isnan (x1) && isnan (expected.x1) || is_equal_double (x1, expected.x1)) &&
        (isnan (x2) && isnan (expected.x2) || is_equal_double (x2, expected.x2));
}
