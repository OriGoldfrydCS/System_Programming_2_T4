// Email: origoldbsc@gmail.com

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <sstream>

/**
 * @class Complex
 * @brief Represents a complex number with real and imaginary parts.
 */
class Complex {

    private:

        double real;        // The real part of the complex number
        double imag;        // The imaginary part of the complex number

    public:

        /**
         * @brief Constructor for Complex class.
         * @param r Real part of the complex number (default is 0.0).
         * @param i Imaginary part of the complex number (default is 0.0).
         */
        Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}


        /**
         * @brief Overload the == operator for comparison.
         * @param other The other complex number to compare with.
         * @return True if the complex numbers are equal, false otherwise.
         */
        bool operator==(const Complex& other) const 
        {
            return real == other.real && imag == other.imag;
        }




        /**
         * @brief Overload the != operator for comparison.
         * @param other The other complex number to compare with.
         * @return True if the complex numbers are not equal, false otherwise.
         */
        bool operator!=(const Complex& other) const 
        {
            return !(*this == other);
        }


        /**
         * @brief Overload the > operator for comparison.
         * @param other The other complex number to compare with.
         * @return True if this complex number is greater than the other.
         */
        bool operator>(const Complex& other) const 
        {
            return (real * real + imag * imag) > (other.real * other.real + other.imag * other.imag);
        }

        // Overload the < operator for comparison
        bool operator<(const Complex& other) const 
        {
            return !(*this > other) && (*this != other);
        }


        /**
         * @brief Converts the complex number to a string representation.
         * @return A string in the form "real+imagi" or "real-imagi".
         */
        std::string toString() const 
        {
            std::ostringstream oss;
            oss << real << (imag >= 0 ? "+" : "") << imag << "i";
            return oss.str();
        }


        /**
         * @brief Overloads the << operator for outputting a complex number.
         * @param os The output stream.
         * @param c The complex number to output.
         * @return The output stream.
         */
        friend std::ostream& operator<<(std::ostream& os, const Complex& c) 
        {
            os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
            return os;
        }

};

#endif
