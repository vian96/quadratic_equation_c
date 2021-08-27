/** @file */ 
#include "quad_eq.h"

// local functions' declaration

/// Reads double variable
/** 
 * User interface for reading double variable
 * @param message name of variable
 */
double read_double_coef (const char *message);

/// Prints roots of equation
void print_roots (NumberOfRoots num, const double x1, const double x2);

// functions' implementations

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

        NumberOfRoots res = solve_quad_eq (a, b, c, &x1, &x2);
        print_roots (res, x1, x2);

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

NumberOfRoots solve_quad_eq (const double a, const double b, const double c, 
                                double *x1, double *x2) {
    // function solves quadratic equation and
    // returns number of roots by enum NumberOfRoots
    // roots are placed to x1 and x2 (see table in readme)

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (x1);
    assert (x2);
    assert (x1 != x2);

    *x1 = NAN;
    *x2 = NAN;

    if (is_equal_double (a, 0))
        return solve_linear_eq (b, c, x1);

    if (is_equal_double (c, 0)) {
        solve_linear_eq (a, b, x1);

        if (is_equal_double (*x1, 0)) 
            return ONE_ROOT;

        *x2 = 0;
        swap_growth (x1, x2);

        return TWO_ROOTS;
    }

    double discriminant = calc_discriminant (a, b, c);
    if (is_equal_double (discriminant, 0)) {
        *x1 = -b / (2 * a);

        return ONE_ROOT;
    }
    else if (discriminant > 0) {
        // for optimisation
        const double _2a = 2 * a;
        discriminant = sqrt (discriminant);

        *x1 = (-b - discriminant) / _2a;
        *x2 = (-b + discriminant) / _2a;

        swap_growth (x1, x2);

        return TWO_ROOTS;
    }
    else {
        return NO_ROOTS;
    }
}

NumberOfRoots solve_linear_eq (const double a, const double b, double *x) {
    assert (isfinite (a));
    assert (isfinite (b));
    assert (x);

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

double calc_discriminant (const double a, const double b, const double c) {
    return b * b - 4 * a * c;
}

double read_double_coef (const char *name) {
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

void print_roots (NumberOfRoots num, const double x1, const double x2) {
    switch (num) {
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
            printf ("ERROR: expected 0-3 roots, received: %d\n", num);
            break;
    }
}

bool is_equal_double (const double a, const double b) {
    // returns true if difference 
    // between numbers is less than DOUBLE_EPSILON

    return fabs (a - b) <= DOUBLE_EPSILON;
}

void swap_growth (double *a, double *b) {
    assert (a);
    assert (b);

    if (*a > *b) {
        *a = *a+*b;
        *b = *a-*b;
        *a = *a-*b;
    }
}

void clear_input_buffer () {
    // clears input buffer until the end of line

    while (getchar () != '\n') { ; }
}
