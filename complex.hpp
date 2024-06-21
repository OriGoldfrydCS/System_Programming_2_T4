#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>

using std::string;
using std::ostream;

namespace ori {

/**
 * @class Complex
 * @brief Represents a complex number with real and imaginary parts.
 */
class Complex {

    private:

        double real;        // The real part of the complex number
        double image;       // The imaginary part of the complex number

    public:

        // Constructors
        Complex(double r, double i);

        // Destructor
        ~Complex();

        // Operator Overloads
        bool operator==(const Complex& other) const;
        bool operator!=(const Complex& other) const;
        bool operator>(const Complex& other) const;
        bool operator<(const Complex& other) const;

        // toString function
        string toString() const;

        // Friend Function
        friend ostream& operator<<(ostream& os, const Complex& c);
    };
} 

#endif 
