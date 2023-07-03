#include <iostream>

class Fraction {
public:
    // Constructors
    Fraction() : num(0), den(1) {}
    Fraction(int n, int d) : num(n), den(d) {}

    // Getters and Setters
    int getNum() const 
    { 
        return num; 
    }
    void setNum(int n) 
    { 
        num = n; 
    }
    int getDen() const
    { 
        return den;
    }
    void setDen(int d)
    {
        if (d != 0)
            den = d;
    }

    // Unary operator overloading
    Fraction operator-() const 
    {
        return Fraction(-num, den);
    }

    // Binary operator overloading
    Fraction operator+(const Fraction& other) const 
    {
		if (den == other.den)
			return Fraction(num + other.num, den);
		else
			return Fraction(num * other.den + other.num * den, den * other.den);
    }
    Fraction operator-(const Fraction& other) const 
    { 
		if (den == other.den)
			return Fraction(num - other.num, den);
		else
			return Fraction(num * other.den - other.num * den, den * other.den);
    }
    Fraction operator*(const Fraction& other) const
    {
        return Fraction(num * other.num, den * other.den);
    }
    Fraction operator/(const Fraction& other) const
    { 
        return Fraction(num * other.den, den * other.num);
    }

    // Increment/decrement operator overloading
    Fraction operator+(int num) const
    { 
        return Fraction(this->num + num * this->den, this->den);
    }
    Fraction operator-(int num) const 
    { 
        return Fraction(this->num - num * this->den, this->den);
    }
    Fraction& operator++()
    {
        num += den;
        int gcd = getGCD(num, den);
        num /= gcd;
        den /= gcd;
        return *this;
    }

    Fraction& operator--()
    {
        num -= den;
        int gcd = getGCD(num, den);
        num /= gcd;
        den /= gcd;
        return *this;
    }

    // Postfix increment/decrement operator overloading
    Fraction operator++(int)
    {
        Fraction temp(*this);
        ++(*this);
        return temp;
    }
    Fraction operator--(int)
    {
        Fraction temp(*this);
        --(*this);
        return temp;
    }
    Fraction& operator+=(const Fraction& other) 
    { 
        num = num * other.den + other.num * den;
        den *= other.den;
        int gcd = getGCD(num, den);
        num /= gcd;
        den /= gcd;
        return *this; 
    }
    Fraction& operator+=(int num)
    { 
        this->num += num * this->den;
        return *this; 
    
    }
    Fraction& operator-=(const Fraction& other)
    { 
        num = num * other.den - other.num * den;
        den *= other.den;
        int gcd = getGCD(num, den);
        num /= gcd;
        den /= gcd;
        return *this;
    }
    Fraction& operator-=(int num) 
    {
        this->num -= num * this->den;
        return *this; 
    }

    // Assignment operator overloading
    Fraction& operator=(const Fraction& other)
    {
        num = other.num;
        den = other.den;
        return *this;
    }

    // Relational operator overloading
    bool operator<(const Fraction& other) const
    { 
        return num * other.den < other.num* den; 
    }
    bool operator>(const Fraction& other) const 
    { 
        return num * other.den > other.num * den; 
    }
    bool operator==(const Fraction& other) const 
    {
        return num * other.den == other.num * den;
    }
    bool operator<=(const Fraction& other) const 
    { 
        return num * other.den <= other.num * den; 
    }
    bool operator>=(const Fraction& other) const
    {
        return num * other.den >= other.num * den; 
    }
    bool operator!=(const Fraction& other) const 
    {
        return num * other.den != other.num * den; 
    }



    // Input/output operator overloading
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f)
    {
        os << f.num << '/' << f.den;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Fraction& f)
    {
        int n, d;
        is >> n >> d;
        f.setNum(n);
        f.setDen(d);
        return is;
    }

    // Data function to simplify fraction
    Fraction simplify() const
    {
        int gcd = getGCD(num, den);
        return Fraction(num / gcd, den / gcd);
    }
private:
    int num;
    int den;

    // Helper function to get greatest common divisor using Euclidean algorithm
    int getGCD(int a, int b) const
    {
        if (b == 0) return a;
        return getGCD(b, a % b);
    }
};