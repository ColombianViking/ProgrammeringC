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

        monetary::Money m_add1{"SEK",3,3};


        cout << "m_add1 består av:" << endl << m_add1 << endl;

        monetary::Money m4{"SEK",10,10};



        cout << "m4 består av:" << endl << m4 << endl;
  
        monetary::Money m5{"SEK",0,95};
 

        cout << "m5 består av:" << endl << m5 << endl;
        cout << "\"m_add1 = m4 + m5\", m_add1 skrivs ut:" << endl;
   
        m_add1 = m4 + m5;
  
     
        cout << m_add1 << endl << endl;
    

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
        cout << endl;
  
        monetary::Money m8{"SEK",10,99};
        cout << "m8 består av:" << endl << m8 << endl;
        ++m8;
        cout << "++m8, m8 skrivs ut:" << endl;
        cout << m8 << endl << endl;

        monetary::Money m9{"SEK",14,14};
        cout << "m9 består av:" << endl << m9 << endl;
        monetary::Money m10{"SEK",0,0};
        cout << "m10 består av:" << endl << m10 << endl;
        m10 = m9++;
        cout << "m10 = m9++, m10 skrivs ut:" << endl;
        cout << m10 << endl;
        cout << "m9 skrivs ut:" << endl;
        cout << m9 << endl;
        cout << endl;

        monetary::Money m11{"SEK",10,0};
        cout << "m11 består av:" << endl << m11 << endl;
        --m11;
        cout << "--m11, m11 skrivs ut:" << endl;
        cout << m11 << endl << endl;

        monetary::Money m12{"SEK",0,0};
        cout << "m12 består av:" << endl << m12 << endl;
        monetary::Money m13{"SEK",4};
        cout << "m13 består av:" << endl << m13 << endl;
        m12 = m13--;
        cout << "m12 = m13--, m12 skrivs ut:" << endl;
        cout << m12 << endl;
        cout << "m13 skrivs ut:" << endl;
        cout << m13 << endl << endl;

        cout << "m12 += m13, m12 skrivs ut:" << endl;
        m12 += m13;
        cout << m12 << endl << endl;

        monetary::Money m_sub1{"SEK",0,0};
        cout << "m_sub1 består av:" << endl << m_sub1 << endl;
        monetary::Money m14{"SEK",10,20};
        cout << "m14 består av:" << endl << m14 << endl;
        monetary::Money m15{"SEK",5,30};
        cout << "m15 består av:" << endl << m15 << endl;
        m_sub1 = m14 - m15;
        cout << "\"m_sub1 = m14 - m15\", m_sub1 skrivs ut:" << endl;
        cout << m_sub1 << endl << endl;
        
        cout << "m14 -= m15, m14 skrivs ut:" << endl;
        m14 -= m15;
        cout << m14 << endl << endl;

	monetary::Money m16{"SEK",12,34};
	cin >> m16;
	cout << m16 << endl;
    }
    catch (const monetary_error& message)
    {
        cout << message.what() << endl;
    }
    return 0;
}
