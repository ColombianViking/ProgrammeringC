//lab2.cc
#include "Monetary.h"
#include <iostream>
using namespace std;

int main()
{
    monetary::Money m1{13,99};

    cout << endl << "m1 består av följande:" << endl
         << "Valuta: " << m1.cur() << endl 
         << "Enheter: " << m1.uni() << endl 
         << "Hundradelar: " << m1.hun() << endl<< endl;

    monetary::Money m2{m1};

    cout << "m2 blir en kopia av m1." << endl
         << endl << "m2 består nu av:" << endl
         << "Valuta: " << m2.cur() << endl 
         << "Enheter: " << m2.uni() << endl 
         << "Hundradelar: " << m2.hun() << endl<< endl;

    m2.print(cout);
    cout << endl;
    cout << m2 << endl;
    return 0;
}
