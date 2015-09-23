//Monetary.cc
#include "Monetary.h"
#include <string>
using namespace std;

namespace monetary
{

    /*Money::Money (string a, int b, int c)
    {
        currency = a;
        units = b;
        hundreds = c;
        }*/
    
    Money::Money ()
    {
        Money("", 0, 0)
    }
    /*  Money::Money (int a)
    {
        currency{""};
        units{a};
        hundreds{0};
    }

    Money:: Money (int a, int b)
    {
        currency{""};
        units{a};
        hundreds{b};
    }
    
    Money::Money (string cur)
    {
        currency{cur};
        units{0};
        hundreds{0};
    }

    Money::Money (string cur, int a)
    {
        currency{cur};
        units{a};
        hundreds{0};
    }

    Money::Money (string cur, int a, int b)
    {
        currency{cur};
        units{a};
        hundreds{b};
    }

    Money::Money (Money m)
    {
        currency{m.cur()};
        units{m.uni()};
        hundreds{m.hun()}; 
        }*/

}
