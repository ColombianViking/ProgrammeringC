//Monetary.h
#include <string>

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
};

}
#endif
