#include "quad_eq.h"

void quadratic_solver () {
    // user interface for solving quadratic equations
    printf ("This is solver of quadratic equations made by Vian\n"
            "Input real coefficients of this equation:\n"
            "a*x^2 + b*x + c = 0\n");

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    while (1) {
        a = read_double_coef ("a");
        b = read_double_coef ("b");
        c = read_double_coef ("c");

        int res = solve_quad_eq (a, b, c, &x1, &x2);
        switch (res) {
        case NO_ROOTS:
            printf ("There is no real roots in this equation!\n");
            break;
        case ONE_ROOT:
            printf ("This equation has only one root: %f\n", x1);
            break;
        case TWO_ROOTS:
            printf ("This equation has two roots: %f and %f\n", x1, x2);
            break; 
        case INF_ROOTS:
            printf ("Any real number is a root of this equation\n");
            break;
        default:
            printf ("There is some error in your input, try again\n");
            break;
        }

        printf ("Type q if you want to exit the program " 
                "or anything else if you want to continue\n");

        clear_input_buffer ();
        char c = getchar (); 
        if (c == 'q') {
            printf ("Thanks for using my program! Bye!\n");
            return;
        }
        else if (c != '\n') {
            clear_input_buffer ();
        }
    } 
}

NumberOfRoots solve_quad_eq (double a, double b, double c, double *x1, double *x2) {
    // function solves quadratic equation and
    // returns number of roots by enum NumberOfRoots
    // roots are placed to x1 and x2 (see table in readme)

    assert (x1);
    assert (x2);
    assert (x1 != x2);
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    *x1 = NAN;
    *x2 = NAN;

    if (!is_equal_double (a, 0)) {
        //quadratic equation

        double discriminant = b * b - 4 * a * c;
        if (is_equal_double (discriminant, 0)) {
            *x1 = -b / 2 / a;
            return ONE_ROOT;
        }
        else if (discriminant > 0) {
            // for optimisation
            a *= 2;
            discriminant = sqrt (discriminant);

            // smaller root should be placed to x1
            if (a > 0) {
                *x1 = (-b - discriminant) / a;
                *x2 = (-b + discriminant) / a;
            }
            else {
                *x1 = (-b + discriminant) / a;
                *x2 = (-b - discriminant) / a;
            }
            return TWO_ROOTS;
        }
        else {
            return NO_ROOTS;
        }
    }
    else {
        // linear equation
        solve_linear_eq (b, c, x1);
    }
}

NumberOfRoots solve_linear_eq (double a, double b, double *x){
    assert (x);
    assert (isfinite(a));
    assert (isfinite(b));

    *x = NAN;

    if (is_equal_double (a, 0)) {
        // b = 0

        if (is_equal_double (b, 0))
            return INF_ROOTS;
        else 
            return NO_ROOTS;
    }
    else {
        // a*x + b = 0
        *x = -b / a;
        return ONE_ROOT;
    }
}

double read_double_coef (char *name) {
    assert (name);

    double x = NAN;
    printf ("%s =", name);
    while (!scanf ("%lf", &x)) {
        printf ("There is an error in your input, try again:\n"
                "%s =", name);
        clear_input_buffer ();
    }
    return x;
}

bool is_equal_double (double a, double b) {
    // returns true if difference 
    // between numbers is less than DOUBLE_EPSILON
    return fabs (a - b) <= DOUBLE_EPSILON;
}

void clear_input_buffer () {
    // clears input buffer until the end of line
    while (getchar () != '\n') { ; }
}