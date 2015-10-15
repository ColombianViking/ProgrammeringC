/*
 * FILNAMN:       Monetary.cc
 * LABORATION:    2
 * PROGRAMMERARE: Jesper Karjalainen, 930311-4731, Y3c
 *                John Stynsberg, 941219-9359, Y3c
 * DATUM:         2015-10-02
 */

#include "Monetary.h"
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

namespace monetary
{

/*
 * FUNKTION Money::Money (const string& a, int b, int c)
 *
 * Skapar ett Money-objekt med valutan "a", "b" enheter och "c" hundradelar.
 */
    Money::Money (const string& a, int b, int c)
    {
        if(a.size() != 3 && a.size() != 0)
        {
            throw monetary_error{"Fel längd på valutabeteckning!"};
        }
        
        if(b < 0)
        {
            throw monetary_error{"Antal enheter kan inte vara negativt!"};
        }

        if(c < 0 || c > 99)
        {
            throw monetary_error{"Antal hundradelar "
                    "har fått ett ogiltigt värde!"};
        }
        currency = a;
        units = b;
        hundreds = c;
    }
  
/*
 * FUNKTION Money::Money (const Money& m)
 *
 * Skapar ett Money-objekt med samma värden som det existerande objektet "m".
 */
    Money::Money (const Money& m)
    {
        currency = m.currency;
        units = m.units;
        hundreds = m.hundreds;
    }

/*
 * FUNKTION void Money::print(ostream& o_stream)
 *
 * Skriver ut ett Money-objekts värden till utströmmen "o_stream".
 */
    ostream& Money::print(ostream& o_stream) const
    {
        if(currency != "")
        {
            o_stream << currency << " ";
        }
       
        o_stream << units << ".";

        if(hundreds < 10)
        {
            o_stream << 0;
        }

        o_stream << hundreds;

        return o_stream;
    } 

/*
 * FUNKTION Money::Money (string a, int b, int c)
 *
 * Skriver ut Money-objektet "m"'s värden till utströmmen "o_stream".
 */
    ostream& operator<< (ostream& o_stream, const Money& m)
    {
        return m.print(o_stream);
    }

/*
 * FUNKTION Money& Money::operator= (Money& rhs)
 *
 * Utför tilldelningen "m1 = m2". Resultatet är ett lvalue.
 */
    Money& Money::operator= (const Money& rhs)
    {
        if(currency == rhs.currency)
        {
            units = rhs.units;
            hundreds = rhs.hundreds;
            return *this;
        }

        if(rhs.currency == "")
        {
            units = rhs.units;
            hundreds = rhs.hundreds;
            return *this;
        }

        if(currency == "")
        {
            units = rhs.units;
            hundreds = rhs.hundreds;
            currency = rhs.currency;
            return *this;
        }
        throw monetary_error{"En specificerad valuta får ej ändras!"};
      
    }

/*
 * FUNKTION Money& Money::operator+ (Money& rhs)
 *
 * Utför additionen "m1 + m2". Resultatet är ett rvalue.
 */
    Money Money::operator+ (const Money& rhs)
    {
        Money m;
        if(! (currency == rhs.currency))
        {
            throw monetary_error{"Du kan inte summera två objekt "
                    "av olika valutor!"};
        }
        
        m.units = units + rhs.units + (hundreds + rhs.hundreds)/100;
        m.hundreds = (hundreds + rhs.hundreds) % 100;
     
        return m;
    }

/*
 * FUNKTION bool Money::operator== (const Money& rhs)
 *
 * Utför jämförelsen "m1 == m2".
 */
    bool Money::operator== (const Money& rhs)
    {
        if(currency == rhs.currency)
        {
            return((units == rhs.units) && (hundreds == rhs.hundreds));
        }

        if((currency == "") || (rhs.currency == ""))
        {
            return((units == rhs.units) && (hundreds == rhs.hundreds));
        }
        
        throw monetary_error{"Du kan inte jämföra två objekt "
                "av olika valutor!"};
    }
        
/*
 * FUNKTION bool Money::operator< (const Money& rhs)
 *
 * Utför jämförelsen "m1 < m2".
 */
    bool Money::operator< (const Money& rhs)
    {
        if(currency == rhs.currency)
        {
            return((units < rhs.units) || ((units == rhs.units) && (hundreds < rhs.hundreds)));
        }

        if((currency == "") || (rhs.currency == ""))
        {
            return((units < rhs.units) || ((units == rhs.units) && (hundreds < rhs.hundreds)));
        }

        throw monetary_error{"Du kan inte jämföra två objekt "
                "av olika valutor!"};   
    }

/*
 * FUNKTION bool Money::operator<= (const Money& rhs)
 *
 * Utför jämförelsen "m1 <= m2".
 */
    bool Money::operator<= (const Money& rhs)
    {
        return *this < rhs || *this == rhs;
    }

/*
 * FUNKTION bool Money::operator> (const Money& rhs)
 *
 * Utför jämförelsen "m1 > m2".
 */
    bool Money::operator> (const Money& rhs)
    {
        return (! (*this <= rhs));    
    }

/*
 * FUNKTION bool Money::operator >= (const Money& rhs)
 *
 * Utför jämförelsen "m1 >= m2".
 */
    bool Money::operator>= (const Money& rhs)
    {
        return *this > rhs || *this == rhs;
    }

/*
 * FUNKTION bool Money::operator!= (const Money& rhs)
 *
 * Utför jämförelsen "m1 != m2".
 */
    bool Money::operator!= (const Money& rhs)
    {
        return (! (*this == rhs));
    }

/*
 * FUNKTION Money& Money::operator++ ()
 *
 * Ökar ett Money-objekts hundradelar med 1. Resultatet är ett lvalue.
 * (Prefix ++).
 */
    Money& Money::operator++ ()
    {
        if(hundreds == 99)
        {
            units += 1;
            hundreds = 0;
        }
        else
        {
            hundreds += 1;
        }
        
        return *this;
    }

/*
 * FUNKTION Money& Money::operator++ (int)
 *
 * Ökar ett Money-objekts hundradelar med 1. Resultatet är ett rvalue av
 * objektets värde före stegningen. (Postfix ++).
 */
    Money Money::operator++ (int)
    {
        Money temp{*this};
        if(hundreds == 99)
        {
            ++units;
            hundreds = 0;
        }
        else
        {
            ++hundreds;
        }
        return temp;
    }
    
/*
 * FUNKTION Money& Money::operator-- ()
 *
 * Sänker ett Money-objekts hundradelar med 1. Resultatet är ett lvalue.
 * (Prefix --).
 */
    Money& Money::operator-- ()
    {
        if((hundreds == 0) && (units == 0))
        {
            throw monetary_error{"Nedstegning får ej ge ett negativt värde!"};
        }
        
        if(hundreds == 0)
        {
            units -= 1;
            hundreds = 99;
        }
        else
        {
            hundreds -= 1;
        }

        return *this;
    }

/*
 * FUNKTION Money& Money::operator-- (int)
 *
 * Sänker ett Money-objekts hundradelar med 1. Resultatet är ett rvalue av
 * objektets värde före stegningen. (Postfix --).
 */
    Money Money::operator-- (int)
    {
        Money temp{*this};
        if((hundreds == 0) && (units == 0))
        {
            throw monetary_error{"Nedstegning får ej ge ett negativt värde!"};
        }
        
        if(hundreds == 0)
        {
            --units;
            hundreds = 99;
        }
        else
        {
            --hundreds;
        }

        return temp;
    }

/*
 * FUNKTION Money& Money::operator+= (Money& rhs)
 *
 * Utför den sammansatta tilldelningen "m1 = m1 + m2".
 */
    Money& Money::operator+= (const Money& rhs)
    {
        return (*this = *this + rhs);
    }

/*
 * FUNKTION Money& Money::operator- (Money& rhs)
 *
 * Utför subtraktionen "m1 - m2". Resultatet är ett rvalue.
 */
    Money Money::operator- (const Money& rhs)
    {
        Money m;
        if(! (currency == rhs.currency))
        {
            throw monetary_error{"Du kan inte subtrahera två objekt "
                    "av olika valutor!"};
        }

        if(((units - rhs.units) < 0) ||
           (((units - rhs.units) == 0) && (hundreds - rhs.hundreds) < 0))
        {
            throw monetary_error{"Subtraktion får ej resultera "
                    "i ett negativt värde!"};
        }
        m.hundreds = hundreds - rhs.hundreds;
        if(m.hundreds < 0)
        {
            m.hundreds = m.hundreds + 100;
            m.units = units - rhs.units - 1;
        }
        else
        {
            m.units = units - rhs.units;
        }
        if(currency == "")
            m.currency = rhs.currency;
        else
            m.currency = currency;
        return m;
    }

/*
 * FUNKTION Money& Money::operator-= (Money& rhs)
 *
 * Utför den sammansatta tilldelningen "m1 = m1 - m2".
 */
    Money& Money::operator-= (const Money& rhs)
    {
        return  (*this = *this - rhs);
    }

/*
 * FUNKTION istream& operator>> (istream& i_stream, Money& m)
 *
 * Tillåter användaren att ändra på det existerande Money-objektet "m"
 * via inläsning från inströmmen "i_stream".
 */
    istream& operator>> (istream& i_stream, Money& m)
    {
        string curr{"XXX"};
        char control;
        int units{0};
        int hundreds{0};
	bool got_a_currency{false};

        i_stream >> ws;
        control = i_stream.peek();

	if((! isalpha(control)) && (! isdigit(control)))
        {
            i_stream.setstate(ios::failbit);
            return i_stream;
        }
        
        if(isalpha(control))
        {
	    for(int i{0}; i < 3; ++i)
            {
		i_stream.get(curr[i]);

		if(! isalpha(curr[i]))
		{
                    i_stream.setstate(ios::failbit);
                    return i_stream;
		}
            }

            control = i_stream.peek();

            if(! (control == ' '))
            {
                i_stream.setstate(ios::failbit);
                return i_stream;
            }

	    got_a_currency = true;
            i_stream >> ws;
            control = i_stream.peek();
        }

        if(isdigit(control))
        {
            i_stream.get(control);
            units = control - '0';
	    control = i_stream.peek();

            while(isdigit(control))
            {
                i_stream.get(control);
                units = units * 10;
                units = units + (control - '0');
                control = i_stream.peek();
            }
        }
	else
        {
            i_stream.setstate(ios::failbit);
            return i_stream;
        }
        
        if(control == '.')
        {
	    i_stream.get(control);
	    control = i_stream.peek();

	    if(isdigit(control))
            {
		i_stream.get(control);
		hundreds = control - '0';
		control = i_stream.peek();

		if(isdigit(control))
                {
		    i_stream.get(control);
		    hundreds = hundreds * 10;
		    hundreds = hundreds + (control - '0');
                }
                else
                {
                    hundreds = hundreds * 10;
                }
            }
	    else
            {
                i_stream.setstate(ios::failbit);
                return i_stream;
            }
        }
    
	if(got_a_currency)
        {
	    Money m_temp{curr,units,hundreds};
	    m = m_temp;
        }
	else
        {
	    Money m_temp{"",units,hundreds};
	    m = m_temp;
        }
 
        return i_stream;
    }
}

