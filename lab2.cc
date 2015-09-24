//lab2.cc
#include "Monetary.h"
#include <iostream>
using namespace std;
using namespace monetary;

int main()
{
  cout << endl << "m1{\"SEK\",13,37}";
  Money m1{"SEK",13,37};
  cout << endl << "m2{m1}";
  Money m2{m1};
  cout << endl << "m3{\"USD\"}";
  Money m3{"USD"};
  cout << endl << "m4{15}" << endl;
  Money m4{15};

  cout << "m1.print skriver ut" << endl;
  m1.print(cout);
  cout << endl << "Utskrift av m1 med << operatorn ger" << endl;
  cout << m1 << endl;
  

    return 0;
}
