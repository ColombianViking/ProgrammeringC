//Monetary.cc
#include "Monetary.h"
#include <string>
using namespace std;

namespace monetary
{

    Money::Money (string a, int b, int c)
    {
        currency = a;
        units = b;
        hundreds = c;
    }
    
    Money::Money (Money& m)
    {
        currency = m.cur();
        units = m.uni();
        hundreds = m.hun();
    }

}
