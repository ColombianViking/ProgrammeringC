//lab2.cc
#include "Monetary.h"
#include <iostream>
using namespace std;

int main()
{
    try
    {
        monetary::Money m1{"SEK",1,1};
    



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
        cout << endl << endl;

        monetary::Money m_test{"SEK",3,3};


        cout << "m_test består av:" << endl << m_test << endl;

        monetary::Money m4{"SEK",10,10};



        cout << "m4 består av:" << endl << m4 << endl;
  
        monetary::Money m5{"SEK",0,95};
 

        cout << "m5 består av:" << endl << m5 << endl;
        cout << "\"m_test = m4 + m5\", m_test skrivs ut:" << endl;
   
        m_test = m4 + m5;
  
     
        cout << m_test << endl << endl;
    

        monetary::Money m6{"SEK",4000};
  
        cout << "m6 består av:" << endl << m6 << endl;
        monetary::Money m7{"SEK",40,20};
  
   
        cout << "m7 består av:" << endl << m7 << endl;
        cout << endl << "m6 är följande, jämfört med m7:" << endl;
        if(m6 == m7)
        {
            cout << "LIKA MED" << endl;
        }
        else
        {
            cout << "INTE LIKA MED" << endl;
        }
        
        if(m6 < m7)
        {
            cout << "MINDRE" << endl;
        }
        else
        {
            cout << "INTE MINDRE" << endl;
        }

        if(m6 <= m7)
        {
            cout << "MINDRE ÄN ELLER LIKA MED" << endl;
        }
        else
        {
            cout << "INTE MINDRE ÄN ELLER LIKA MED" << endl;
        }

        if(m6 > m7)
        {
            cout << "STÖRRE" << endl;
        }
        else
        {
            cout << "INTE STÖRRE" << endl;
        }

        if(m6 >= m7)
        {
            cout << "STÖRRE ÄN ELLER LIKA MED" << endl;
        }
        else
        {
            cout << "INTE STÖRRE ÄN ELLER LIKA MED" << endl;
        }

        if(m6 != m7)
        {
            cout << "INTE LIKA MED" << endl;
        }
        else
        {
            cout << "LIKA MED" << endl;
        }
    
  
        monetary::Money m8{"SEK",10,99};
  
        ++m8;
        cout << m8 << endl;

   
        monetary::Money m9{"SEK",14,14};
 
        monetary::Money m10{"SEK",0,0};
 

        m10 = m9++;
        cout << m10 << endl;
        cout << m9 << endl;

        cout << endl;
        monetary::Money m11{"SEK",10,0};
        --m11;
        cout << m11 << endl;
    }
    catch (const monetary_error& message)
    {
        cout << message.what() << endl;
    }
    return 0;
}
