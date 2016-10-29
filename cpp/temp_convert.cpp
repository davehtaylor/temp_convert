// This is a command line application to convert temperatures. When the
// application is called, it is given an argument to show what type of
// temperature unit is input, and what output is desired. The options are
// as follows:
//
// --FtoC converts from fahrenheit to celsius
// --FtoK converts from fahrenheit to kelvin
// --CtoF converts from celsius to fahrenheit
// --CtoK converts from celsius to kelvin
// --KtoF converts from kelvin to fahrenheit
// --KtoC converts from kelvin to celsius
//
// Usage example:
//
//      temp_convert --FtoC 32
//
// Output: 
//  
//      32° fahrenheit is 0° celsius.


#include <iostream>
#include <string>       // std::string


// Convert fahrenheit to celsius
void FtoC(double fahr) {
    double cel = (fahr - 32.0) * (5.0/9.0);
    std::cout << fahr << "° fahrenheit is " 
        << cel << "° celsius" << std::endl;
}


// Convert fahrenheit to kelvin
void FtoK(double fahr) {
    double kel = (fahr + 459.67) * (5.0/9.0);
    std::cout << fahr << "° fahrenheit is " 
        << kel << " kelvin" << std::endl;
}


// Convert celsius to fahrenheit
void CtoF(double cel) {
    double fahr = ((9.0/5.0) * cel) + 32.0;
    std::cout << cel << "° celsius is " 
        << fahr << "° fahrenheit" << std::endl;
}


// Convert celsius to kelvin
void CtoK(double cel) {
    double kel = cel + 273.15;
    std::cout << cel << "° celsius is " 
        << kel << " kelvin" << std::endl;
}


// Convert kelvin to fahrenheit
void KtoF(double kel) {
    double fahr = (kel * (9.0/5.0)) - 459.67;
    std::cout << kel << " kelvin is " 
        << fahr << "° fahrenheit" << std::endl;
}


// Convert kelvin to celsius
void KtoC(double kel) {
    double cel = kel - 273.15;
    std::cout << kel << " kelvin is " 
        << cel << "° celsius" << std::endl;
}


int main() {

    double user_temp;
    std::cout << "Please enter a temp to convert: ";
    std::cin >> user_temp;

    KtoC(user_temp);

    return 0;
}
