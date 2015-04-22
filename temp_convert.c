/* This is a command line application to convert temperatures. When the
 * application is called, it is given an argument to show what type of
 * temperature unit is input, and what output is desired. The options are
 * as follows:
 *
 * --FtoC converts from fahrenheit to celsius
 * --FtoK converts from fahrenheit to kelvin
 * --CtoF converts from celsius to fahrenheit
 * --CtoK converts from celsius to kelvin
 * --KtoF converts from kelvin to fahrenheit
 * --KtoC converts from kelvin to celsius
 *
 * An example usage would be:
 *
 *     temp_convert --FtoC 32
 *
 * The result would answer that 32 degrees fahrenheit is 0 degreess celsius.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEG "°"

double
f_to_c(double fahrenheit)
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double
f_to_k(double fahrenheit)
{
    return (f_to_c(fahrenheit) + 273.15);
}

double
c_to_f(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32;
}

double
c_to_k(double celsius)
{
    return celsius + 273.15;
}

double
k_to_c(double kelvin)
{
    return kelvin - 273.15;
}

double
k_to_f(double kelvin)
{
    return (k_to_c(kelvin) * 9.0 / 5.0) + 32;
}

int
main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: temp_convert CONVERSION_SPECIFIER TEMPERATURE\n"
               "Example: temp_convert --FtoC 32\n\n"
               "Possilbe options:\n" 
               "--FtoC\n"
               "--FtoK\n"
               "--CtoF\n"
               "--CtoK\n"
               "--KtoF\n" 
               "--Ktoc\n\n");

        return 1;
    }

    double input_temp = atof(argv[2]);

    if (strcmp(argv[1], "--FtoC") == 0)
    {
        printf("%6.3f %sF = %6.3f %sC\n", 
                input_temp, DEG, f_to_c(input_temp), DEG);
    } 
    else if (strcmp(argv[1],"--FtoK") == 0)
    {
        printf("%6.3f %sF = %6.3f K\n", 
                input_temp, DEG, f_to_k(input_temp));
    } 
    else if (strcmp(argv[1], "--CtoF") == 0)
    {
        printf("%6.3f %sC = %6.3f %sF\n", 
                input_temp, DEG, c_to_f(input_temp), DEG);
    }
    else if (strcmp(argv[1], "--CtoK") == 0)
    {
        printf("%6.3f %sC = %6.3f K\n", 
                input_temp, DEG, c_to_k(input_temp));
    } 
    else if (strcmp(argv[1], "--KtoF") == 0)
    {
        printf("%6.3f K = %6.3f %sF\n", 
                input_temp, k_to_f(input_temp), DEG);
    }
    else if (strcmp(argv[1], "--KtoC") == 0)
    {
        printf("%6.3f K = %6.3f %sC\n", 
                input_temp, k_to_c(input_temp), DEG);
    }
    else
    {
        printf("Sorry, something went wrong.\n");
    }

    return 0;
}
