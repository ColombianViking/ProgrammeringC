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
    int units;
    int hundreds; 

public:
    Money () : Money("", 0, 0) {}
    Money (int b) : Money("", b, 0) {}
    Money (int b, int c) : Money("", b, c) {}
    Money (const std::string& a) : Money(a, 0, 0) {}
    Money (const std::string& a, int b) : Money(a, b, 0) {}
    Money (const Money&);
    Money (const std::string&, int, int);
    Money(Money&& m) noexcept = default;
    ~Money() = default;
    std::string cur () const {return currency;}
    int uni () const {return units;}
    int hun () const {return hundreds;}
    std::ostream& print(std::ostream&) const;
    Money& operator= (const Money&);
    Money operator+ (const Money&);
    bool operator== (const Money&);
    bool operator< (const Money&);
    bool operator<= (const Money&);
    bool operator> (const Money&);
    bool operator>= (const Money&);
    bool operator!= (const Money&);
    Money& operator++ ();
    Money operator++ (int);
    Money& operator-- ();
    Money operator-- (int);
    Money& operator+= (const Money&);
    Money operator- (const Money&);
    Money& operator-= (const Money&);
    
};

std::ostream& operator<<(std::ostream&, const Money&);
std::istream& operator>>(std::istream&, Money&);


class monetary_error : public std::logic_error
{
public:
explicit monetary_error (const std::string& message) noexcept
    : std::logic_error{message} {}
    
explicit monetary_error (const char* message) noexcept
    : std::logic_error{message} {}
};
}

#endif
