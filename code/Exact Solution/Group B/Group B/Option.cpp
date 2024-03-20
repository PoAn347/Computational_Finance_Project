#include "Option.hpp"

// Constructors
Option::Option() : T(0), K(0), sig(0), r(0), S(0), b(0) {}

Option::Option(double T, double K, double sig, double r, double S, double b)
    : T(T), K(K), sig(sig), r(r), S(S), b(b) {}

// Copy constructor
Option::Option(const Option& other)
    : T(other.T), K(other.K), sig(other.sig), r(other.r), S(other.S), b(other.b) {}

// Destructor
Option::~Option() {}

// Assignment operator
Option& Option::operator=(const Option& other) 
{
    if (this != &other) 
    {
        T = other.T;
        K = other.K;
        sig = other.sig;
        r = other.r;
        S = other.S;
        b = other.b;
    }
    return *this;
}

// Getter and setter functions
double Option::getT() const { return T; }
void Option::setT(double T) { this->T = T; }
double Option::getK() const { return K; }
void Option::setK(double K) { this->K = K; }
double Option::getSig() const { return sig; }
void Option::setSig(double sig) { this->sig = sig; }
double Option::getR() const { return r; }
void Option::setR(double r) { this->r = r; }
double Option::getS() const { return S; }
void Option::setS(double S) { this->S = S; }
double Option::getB() const { return b; }
void Option::setB(double b) { this->b = b; }
