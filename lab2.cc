//lab2.cc
#include "Monetary.h"
#include <iostream>
using namespace std;

int main()
{
    monetary::Money m1{"SEK",13,37};

    cout << endl << "m1 består av följande:" << endl
         << "Valuta: " << m1.cur() << endl 
         << "Enheter: " << m1.uni() << endl 
         << "Hundradelar: " << m1.hun() << endl<< endl;

    monetary::Money m2{m1};

    cout << "m2 blir en kopia av m1 via \"m2{m1}\"." << endl
         << endl << "m2 består nu av:" << endl
         << "Valuta: " << m2.cur() << endl 
         << "Enheter: " << m2.uni() << endl 
         << "Hundradelar: " << m2.hun() << endl<< endl;

    cout << "m1 skrivs ut med print:" << endl;
    m1.print(cout);
    cout << endl;
    cout << "m2 skrivs ut genom \"cout << m2\":" << endl;
    cout << m2 << endl;
    monetary::Money m3{"SEK",20,80};
    cout << endl << "m3 består av följande:" << endl
         << "Valuta: " << m3.cur() << endl 
         << "Enheter: " << m3.uni() << endl 
         << "Hundradelar: " << m3.hun() << endl<< endl
         << "\"m1 = m3\", m1 skrivs ut med print:" << endl;
    m1 = m3;
    m1.print(cout);
    cout << endl;
    monetary::Money m_test;
    monetary::Money m4{"SEK",10,10};
    monetary::Money m5{"SEK",10,10};
    m_test = m4 + m5;
    //cout << m_test.cur() << endl;
    cout << m_test << endl;

    return 0;
}
