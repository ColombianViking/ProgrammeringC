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
    Money (std::string a, int b, int c) : currency{a}, units{b}, hundreds{c} {};
      /* Money (int);
    Money (int, int);
    Money (std::string);
    Money (std::string, int);
    Money (std::string, int, int);
    Money (Money&);*/
    std::string cur () {return currency;}
    int uni () {return units;}
    int hun () {return hundreds;}
};

//TJA
}
#endif
