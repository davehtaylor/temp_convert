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
FtoC(double fahrenheit)
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double
FtoK(double fahrenheit)
{
    return (FtoC(fahrenheit) + 273.15);
}

double
CtoF(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32;
}

double
CtoK(double celsius)
{
    return celsius + 273.15;
}

double
KtoC(double kelvin)
{
    return kelvin - 273.15;
}

double
KtoF(double kelvin)
{

    return (KtoC(kelvin) * 9.0 / 5.0) + 32;
}

int
main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: temp_convert CONVERSION_SPECIFIER TEMPERATURE\n"
               "Example: temp_convert --FtoC 32\n");

        return 1;
    }

    double input_temp = atof(argv[2]);

    if (strcmp(argv[1], "--FtoC") == 0)
    {
        printf("%6.3f %sF = %6.3f %sC\n", input_temp, DEG, FtoC(input_temp), DEG);
    } 
    else if (strcmp(argv[1],"--FtoK") == 0)
    {
        printf("%6.3f %sF = %6.3f K\n", input_temp, DEG, FtoK(input_temp));
    } 
    else if (strcmp(argv[1], "--CtoF") == 0)
    {
        printf("%6.3f %sC = %6.3f %sF\n", input_temp, DEG, CtoF(input_temp), DEG);
    }
    else if (strcmp(argv[1], "--CtoK") == 0)
    {
        printf("%6.3f %sC = %6.3f K\n", input_temp, DEG, CtoK(input_temp));
    } 
    else if (strcmp(argv[1], "--KtoF") == 0)
    {
        printf("%6.3f K = %6.3f %sF\n", input_temp, KtoF(input_temp), DEG);
    }
    else if (strcmp(argv[1], "--KtoC") == 0)
    {
        printf("%6.3f K = %6.3f %sC\n", input_temp, KtoC(input_temp), DEG);
    }
    else
    {
        printf("Sorry, something went wrong.\n");
    }

    return 0;
}
