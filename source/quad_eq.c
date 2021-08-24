#include "quad_eq.h"


void quadratic_solver () {
    printf ("This is solver of quadratic equations made by Vian\n"
        "Input real coefficients from this equation:\n"
        "a*x^2 + b*x + c = 0\n");

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    while (1) {
        printf ("a =");
        while (!scanf ("%lf", &a)) {
            printf ("There is an error in your input, try again:\n"
                "a =");
            clear_input_buffer ();
        }
        printf ("b =");
        while (!scanf ("%lf", &b)) {
            printf ("There is an error in your input, try again:\n"
                "b =");
            clear_input_buffer ();
        }
        printf ("c =");
        while (!scanf ("%lf", &c)) {
            printf ("There is an error in your input, try again:\n"
                "c =");
            clear_input_buffer ();
        }

        int res = solve_quad_eq (a, b, c, &x1, &x2);
        switch (res) {
        case 0:
            printf ("There is no real roots in this equation!\n");
            break;
        case 1:
            printf ("This equation has only one root: %f\n", x1);
            break;
        case 2:
            printf ("This equation has two roots: %f and %f\n", x1, x2);
            break; 
        case 3:
            printf ("Any real number is a root of this equation\n");
            break;
        default:
            printf ("There is some error in your input, try again\n");
        }

        printf ("Type q if you want to exit the program or anything else if you want to continue\n");
        clear_input_buffer ();
        char c = getchar (); 
        if (c == 'q') {
            printf ("Thanks for using my program! Bye!");
            return;
        }
        else if (c != '\n')
            clear_input_buffer ();
    } 
}

int solve_quad_eq (double a, double b, double c, double *x1, double *x2) {
    // function solves quadratic equation and
    // returns number of roots (3 means infinite, -1 means error)
    // roots are placed to x1 and x2
    // if they are not filled there will be NaN

    assert (x1);
    assert (x2);
    assert (!isnan (a + b + c));

    if (!is_equal_double (a, 0)) {
        //quadratic equation

        double discriminant = b * b - 4 * a * c;
        if (is_equal_double (discriminant, 0)) {
            *x1 = -b / 2 / a;
            *x2 = NAN;
            return 1;
        }
        else if (discriminant > 0) {
            discriminant = sqrt (discriminant);
            *x1 = (-b - discriminant) / 2 / a;
            *x2 = (-b + discriminant) / 2 / a;
            return 2;
        }
        else {
            *x1 = NAN;
            *x2 = NAN;
            return 0;
        }
    }
    else {
        // linear equation

        if (is_equal_double (b, 0)) {
            // c = 0

            if (is_equal_double (c, 0)) {
                *x1 = NAN;
                *x2 = NAN;
                return 3;
            }
            else {
                *x1 = NAN;
                *x2 = NAN;
                return 0;
            }
        }
        else {
            // b*x + c = 0
            *x1 = -c / b;
            return 1;
        }
    }
}

_Bool is_equal_double (double a, double b) {
    // returns true if difference 
    // between numbers is less the DOUBLE_EPSILON
    return fabs (a - b) <= DOUBLE_EPSILON;
}

void clear_input_buffer () {
    // clears input buffer until end of line
    while (getchar () != '\n');
}