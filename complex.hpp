#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
public:
    double real;
    double imag;

    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload the << operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return os;
    }

    // Overload the == operator for comparison
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    // Overload the != operator for comparison
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Overload the > operator for comparison
    bool operator>(const Complex& other) const {
        return (real * real + imag * imag) > (other.real * other.real + other.imag * other.imag);
    }

    // Overload the < operator for comparison
    bool operator<(const Complex& other) const {
        return (real * real + imag * imag) < (other.real * other.real + other.imag * other.imag);
    }
};

#endif // COMPLEX_HPP
