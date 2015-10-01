//Monetary.h
#include <string>
#include <iostream>
#include <stdexcept>
#ifndef MONEY_H
#define MONEY_H

namespace monetary
{

class Money
{
private:
    std::string currency;
    int units, hundreds; 

public:
    Money () : Money("", 0, 0) {}
    Money (int b) : Money("", b, 0) {}
    Money (int b, int c) : Money("", b, c) {}
    Money (std::string a) : Money(a, 0, 0) {}
    Money (std::string a, int b) : Money(a, b, 0) {}
    Money (Money&);
    Money (std::string, int, int);
    std::string cur () {return currency;}
    int uni () {return units;} 
    int hun () {return hundreds;}
    void print(std::ostream&);
    Money& operator= (Money&);
    Money& operator+ (Money&);
    bool operator== (const Money&);
    bool operator< (const Money&);
    bool operator<= (const Money&);
    bool operator> (const Money&);
    bool operator>= (const Money&);
    bool operator!= (const Money&);
    Money& operator++ ();
    Money& operator++ (int);
    Money& operator-- ();
    Money& operator-- (int);
    Money& operator+= (Money&);
    Money& operator- (Money&);
    Money& operator-= (Money&);
};

std::ostream& operator<<(std::ostream&, Money&);
std::istream& operator>>(std::istream&, Money&);

}

class monetary_error : public std::logic_error
{
public:
explicit monetary_error (const std::string& message) noexcept
    : std::logic_error{message} {}
    
explicit monetary_error (const char* message) noexcept
    : std::logic_error{message} {}
};

#endif
