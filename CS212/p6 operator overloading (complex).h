/*
Author: Gary Tou
Course: CS212
Date: 5/16/2021
Purpose: C++ Program 6: operator overloading
*/
#include <string>
#include <cmath>
#include <iostream>

class Complex
{
public:
    //Constructors
    Complex() {
        real = 0;
        imaginary = 0;
    }

    Complex(double a) {
        real = a;
        imaginary = 0;
    }

    Complex(double a, double b) {
        std::cout << "DEBUG: " << a << " : " << b << std::endl;
        real = a;
        imaginary = b;
    }

    // Member Functions
    Complex& add(Complex other) const;
    Complex& subtract(Complex other) const;
    Complex& multiply(Complex other) const;
    Complex& divide(Complex other) const;

    double abs();

    double getRealPart() const;
    double getImaginaryPart() const;

    std::string to_string() const;

    void update(Complex number);

    // operators
    Complex& operator+=(Complex const& other);
    Complex& operator-=(Complex const& other);
    Complex& operator*=(Complex const& other);
    Complex& operator/=(Complex const& other);

    Complex& operator+();
    Complex& operator-();


    Complex& operator++(); // prefix ++
    Complex& operator--(); // prefix --
    Complex& operator++(int); // postfix ++
    Complex& operator--(int); // postfix --

    double& operator[](int const& index);
    

    // extraction and insertion
    friend std::istream& operator>>(std::istream& in, Complex& c);
    friend std::ostream& operator<<(std::ostream& out, Complex& c);

private:
    double real;
    double imaginary;
    
};



// Implementations

// non-members
Complex& operator+(Complex left, Complex right)
{
    return left.add(right);
}

Complex& operator-(Complex left, Complex right)
{
    return left.subtract(right);
}

Complex& operator*(Complex left, Complex right)
{
    return left.multiply(right);
}

Complex& operator/(Complex left, Complex right)
{
    return left.divide(right);
}

// members of Complex
double Complex::getRealPart() const {
    return real;
}

double Complex::getImaginaryPart() const {
    return imaginary;
}

std::string Complex::to_string() const {
    std::string s_real = std::to_string(real);
    std::string s_imaginary = std::to_string(imaginary);
    if (imaginary == 0) {
        return s_real;
    }
    else {
        return s_real + " + " + s_imaginary + "i";
    }
}

Complex& Complex::add(const Complex other) const {
    Complex solution = Complex(this->real + other.real, this->imaginary + other.imaginary);
    std::cout << "DEBUG: " << solution << std::endl;
    return solution;
}

Complex& Complex::subtract(const Complex other) const {
    Complex solution = Complex(this->real - other.real, this->imaginary - other.imaginary);
    return solution;
}

Complex& Complex::multiply(const Complex other) const {
    Complex solution = Complex(this->real * other.real, this->imaginary * other.imaginary);
    return solution;
}

Complex& Complex::divide(const Complex other) const {
    Complex solution = Complex(this->real / other.real, this->imaginary / other.imaginary);
    return solution;
}

double Complex::abs() {
    return sqrt(pow(this->real, 2) + pow(this->imaginary, 2));
}

Complex& Complex::operator+=(Complex const& other) {
    Complex solution = this->add(other);
    this->update(solution);
    return *this;
}

Complex& Complex::operator-=(Complex const& other) {
    Complex solution = this->subtract(other);
    this->update(solution);
    return *this;
}

Complex& Complex::operator*=(Complex const& other) {
    Complex solution = this->multiply(other);
    this->update(solution);
    return *this;
}

Complex& Complex::operator/=(Complex const& other) {
    Complex solution = this->divide(other);
    this->update(solution);
    return *this;
}

Complex& Complex::operator+() {
    return *this; // just return as is
}

Complex& Complex::operator-() {
    Complex solution = Complex(-this->real, -this->imaginary); // negate the value
    return *this;
}

double& Complex::operator[](int const& index) {
    if (index == 0) {
        return this->real;
    }
    else if (index == 1) {
        return this->imaginary;
    }
    else {
        std::cout << "Error: " << index << " is an unknown index for Complex [] operator.";
    }
}

Complex& Complex::operator++() { // prefix ++
    this->add(Complex(1));
    return *this;
}
Complex& Complex::operator--() { // prefix --
    this->add(Complex(-1));
    return *this;
}
Complex& Complex::operator++(int) { // postfix ++
    Complex original = *this;
    ++*this;
    return original;
}
Complex& Complex::operator--(int) { // postfix --
    Complex original = *this;
    --*this;
    return original;
}

void Complex::update(Complex number) {
    this->real = number.real;
    this->imaginary = number.imaginary;
}

// Operators (for cin/cout)
std::istream& operator>>(std::istream& in, Complex& c) {
    in >> c.real;
    in >> c.imaginary;
    return in;
}

std::ostream& operator<<(std::ostream& out, Complex& c) {
    out << c.to_string();
    return out;
}