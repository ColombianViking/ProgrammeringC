//lab2.cc
#include "Monetary.h"
#include <iostream>
using namespace std;
using namespace monetary;

int main()
{
	cout << endl << "Konstruktorer:" << endl;
	cout << endl << "m1:" << endl;
	m1;
	cout << "m2{100}" << endl;
	Money m2{100};
	cout << "m3{10,50}" << endl;
	Money m3{10, 50);
	cout << "m4{\"SEK\"}" << endl;
	Money m4{"SEK"};
	cout << "m5{\"SEK\", 10}" << endl;
	Money m5{"SEK", 10};
	cout << "m6{\"FFR\", 100, 50}" << endl;
	Money m6{"FFR", 100, 50);
	cout << "m7{m6}" << endl;
	Money m7{m6);
	cout << "m8{m1}" << endl;
	Money m8{m1);
	//Felaktiga initieringar läggs till senare
	
	
	cout << "m1.print skriver ut" << endl;	//Lägg till en ev. try - catch när error har lagts till
	m1.print(cout);
	cout << endl << "Utskrift av m1 med << operatorn ger" << endl;
	cout << m1 << endl;
	cout << "Utskrift av \"ofullständiga\" m3 och m4." << endl;
	m3.print(cout);
	cout << endl << m3 << endl;
	m4.print(cout);
	cout << endl << m4 << endl;
   	return 0;
}
