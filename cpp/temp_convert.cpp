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
// --help shows program usage
//
// Usage example:
//
//      temp_convert --FtoC 32
//
// Output: 
//  
//      32° fahrenheit is 0° celsius.
// 
// **********************************************************************


#include <iostream>
#include <string>       // std::string


// Print program usage if user invokes help, argc < 3, or
// argv is invalid
// Arguments taken: argv[0], the program name
// Returns: no return value. Prints program options and example usage as cerr
static void print_usage(std::string program_name) {
    std::cerr << "\nUsage: " << program_name << " <option> TEMP\n\n"
              << "Options:\n"
              << "\t--FtoC converts from fahrenheit to celsius\n"
              << "\t--FtoK converts from fahrenheit to kelvin\n"
              << "\t--CtoF converts from celsius to fahrenheit\n"
              << "\t--CtoK converts from celsius to kelvin\n"
              << "\t--KtoF converts from kelvin to fahrenheit\n"
              << "\t--KtoC converts from kelvin to celsius\n"
              << "\t--help shows program usage\n\n"
              << "Example:\n"
              << "\ttemp_convert --FtoC 32"
              << std::endl;
}


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


// MAIN
int main(int argc, char* argv[]) {

    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    } 

    std::string program_name = argv[0];
    std::string option = argv[1];
    double temp = atof(argv[2]);

    if (option == "--FtoC") {
        FtoC(temp);
    } else if (option== "--FtoK") {
        FtoK(temp);
    } else if (option == "--CtoF") {
        CtoF(temp);
    } else if (option == "--CtoK") {
        CtoK(temp);
    } else if (option== "--KtoF") {
        KtoF(temp);
    } else if (option == "--KtoC") {
        KtoC(temp);
    } else {
        print_usage(program_name);
    }

    return 0;
}
