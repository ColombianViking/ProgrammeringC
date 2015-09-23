//lab2.cc
#include "Monetary.h"
#include <iostream>
using namespace std;

int main()
{

    monetary::Money m1;
    monetary::Money m1("nisse", 100,1);

    cout << "Valuta: " << m1.cur() << endl 
         << "Enheter: " << m1.uni() << endl 
         << "Hundradelar: " << m1.hun() << endl;

return 0;
}
