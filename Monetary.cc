//Monetary.cc
#include "Monetary.h"
#include <string>
#include <iostream>
using namespace std;

namespace monetary
{

    Money::Money (string a, int b, int c)
    {
        if(a.size() != 3 && a.size() != 0)
        {
            cerr << "Fel längd på valutabeteckning!" << endl;
            return;
        }
        
        if(b < 0)
        {
            cerr << "Antal enheter kan inte vara negativt!" << endl;
            return;
        }

        if(c < 0 || c > 99)
        {
            cerr << "Antal hundradelar har fått ett ogiltigt värde!" << endl;
            return;
        }
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

    void Money::print(ostream& o_stream)
    {
        if(this->cur() != "")
        {
            o_stream << this->cur() << " ";
        }
       
        o_stream << this->uni() << ".";

        if(this->hun() < 10)
        {
            o_stream << 0;
        }

        o_stream << this->hun();

        return;
    } 

    ostream& operator<< (ostream& o, Money& m)
    {
        if(m.cur() != "")
        {
            o << m.cur() << " ";
        }

        o << m.uni() << ".";

        if(m.hun() < 10)
        {
            o << 0;
        }
        
        return o << m.hun();
    }

}
