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

float
FtoC(float fahrenheit)
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float
FtoK(float fahrenheit)
{
    return ((fahrenheit - 32.0) * 5.0 / 9.0) + 273.15;
}

float
CtoF(float celsius)
{
    return (celsius * 9.0 / 5.0) + 32;
}

float
CtoK(float celsius)
{
    return celsius - 273.15;
}

float
KtoF(float kelvin)
{

    return ((kelvin + 273.15) * 9.0 / 5.0) + 32;
}

float
KtoC(float kelvin)
{
    return kelvin + 273.15;
}

int
main(int argc, char *argv[])
{

    return 0;
}
