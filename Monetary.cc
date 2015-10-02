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
 * FUNKTION Money::Money (string a, int b, int c)
 *
 * Skapar ett Money-objekt med valutan "a", "b" enheter och "c" hundradelar.
 */
    Money::Money (string a, int b, int c)
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
 * FUNKTION Money::Money (Money& m)
 *
 * Skapar ett Money-objekt med samma värden som det existerande objektet "m".
 */
    Money::Money (Money& m)
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

/*
 * FUNKTION Money::Money (string a, int b, int c)
 *
 * Skriver ut Money-objektet "m"'s värden till utströmmen "o_stream".
 */
    ostream& operator<< (ostream& o_stream, Money& m)
    {
        m.print(o_stream);
        return o_stream;
    }

/*
 * FUNKTION Money& Money::operator= (Money& rhs)
 *
 * Utför tilldelningen "m1 = m2". Resultatet är ett lvalue.
 */
    Money& Money::operator= (Money& rhs)
    {
        if(this->currency == rhs.currency)
        {
            this->units = rhs.units;
            this->hundreds = rhs.hundreds;
            return *this;
        }

        if(rhs.currency == "")
        {
            this->units = rhs.units;
            this->hundreds = rhs.hundreds;
            return *this;
        }

        if(this->currency == "")
        {
            this->units = rhs.units;
            this->hundreds = rhs.hundreds;
            this->currency = rhs.cur();
            return *this;
        }
        throw monetary_error{"En specificerad valuta får ej ändras!"};
      
    }

/*
 * FUNKTION Money& Money::operator+ (Money& rhs)
 *
 * Utför additionen "m1 + m2". Resultatet är ett rvalue.
 */
    Money& Money::operator+ (Money& rhs)
    {
        Money m;
        int increase_units{0};
        int hundreds_to_add{this->hundreds + rhs.hundreds};
       
        if(hundreds_to_add > 99)
        {
            increase_units = 1;
            hundreds_to_add = hundreds_to_add - 100;
        }

        if(this->currency == rhs.currency)
        {
            m.currency = this->currency;
            m.units = this->units + rhs.units + increase_units;
            m.hundreds = hundreds_to_add;
            return m;
        }

        if(this->currency == "")
        {
            m.currency = rhs.currency;
            m.units = this->units + rhs.units + increase_units;
            m.hundreds = hundreds_to_add;
            return m;
        }
        
        if(rhs.currency == "")
        {
            m.currency = this->currency;
            m.units = this->units + rhs.units + increase_units;
            m.hundreds = hundreds_to_add;
            return m;
        }

        throw monetary_error{"Du kan inte summera två objekt "
                "av olika valutor!"};
    }

/*
 * FUNKTION bool Money::operator== (const Money& rhs)
 *
 * Utför jämförelsen "m1 == m2".
 */
    bool Money::operator== (const Money& rhs)
    {
        bool is_equal{false};
        
        if(this->currency == rhs.currency)
        {
            if((this->units == rhs.units) && (this->hundreds == rhs.hundreds))
            {
                is_equal = true;
                return is_equal;
            }

            return is_equal;
        }

        if((this->currency == "") || (rhs.currency == ""))
        {
            if((this->units == rhs.units) && (this->hundreds == rhs.hundreds))
            {
                is_equal = true;
                return is_equal;
            }

            return is_equal;
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
        bool is_less{false};
        
        if(this->currency == rhs.currency)
        {
            if(this->units < rhs.units)
            {
                is_less = true;
                return is_less;
            }
            
            if((this->units == rhs.units) && (this->hundreds < rhs.hundreds))
            {
                is_less = true;
                return is_less;
            }

            return is_less;
        }

        if((this->currency == "") || (rhs.currency == ""))
        {
            if(this->units < rhs.units)
            {
                is_less = true;
                return is_less;
            }
            
            if((this->units == rhs.units) && (this->hundreds < rhs.hundreds))
            {
                is_less = true;
                return is_less;
            }

            return is_less;
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
        bool is_less_or_equal{false};
        if((*this < rhs) || (*this == rhs))
        {
            is_less_or_equal = true;
            return is_less_or_equal;
        }
        
        return is_less_or_equal;
    }

/*
 * FUNKTION bool Money::operator> (const Money& rhs)
 *
 * Utför jämförelsen "m1 > m2".
 */
    bool Money::operator> (const Money& rhs)
    {
        bool is_greater{true};

        if(*this <= rhs)
        {
            is_greater = false;
            return is_greater;
        }

        return is_greater;
    }

/*
 * FUNKTION bool Money::operator >= (const Money& rhs)
 *
 * Utför jämförelsen "m1 >= m2".
 */
    bool Money::operator>= (const Money& rhs)
    {
        bool is_greater_or_equal{false};

        if((*this > rhs) || (*this == rhs))
        {
            is_greater_or_equal = true;
            return is_greater_or_equal;
        }
        
        return is_greater_or_equal;
    }

/*
 * FUNKTION bool Money::operator!= (const Money& rhs)
 *
 * Utför jämförelsen "m1 != m2".
 */
    bool Money::operator!= (const Money& rhs)
    {
        bool not_equal{true};
        
        if(*this == rhs)
        {
            not_equal = false;
            return not_equal;
        }
        
        return not_equal;
    }

/*
 * FUNKTION Money& Money::operator++ ()
 *
 * Ökar ett Money-objekts hundradelar med 1. Resultatet är ett lvalue.
 * (Prefix ++).
 */
    Money& Money::operator++ ()
    {
        if(this->hundreds == 99)
        {
            this->units = this->units + 1;
            this->hundreds = 0;
        }
        else
        {
            this->hundreds = this->hundreds + 1;
        }
        
        return *this;
    }

/*
 * FUNKTION Money& Money::operator++ (int)
 *
 * Ökar ett Money-objekts hundradelar med 1. Resultatet är ett rvalue av
 * objektets värde före stegningen. (Postfix ++).
 */
    Money& Money::operator++ (int)
    {
        Money m{*this};
        if(this->hundreds == 99)
        {
            this->units = this->units + 1;
            this->hundreds = 0;
        }
        else
        {
            this->hundreds = this->hundreds + 1;
        }
        return m;
    }
    
/*
 * FUNKTION Money& Money::operator-- ()
 *
 * Sänker ett Money-objekts hundradelar med 1. Resultatet är ett lvalue.
 * (Prefix --).
 */
    Money& Money::operator-- ()
    {
        if((this->hundreds == 0) && (this->units == 0))
        {
            throw monetary_error{"Nedstegning får ej ge ett negativt värde!"};
        }
        
        if(this->hundreds == 0)
        {
            this->units = this->units - 1;
            this->hundreds = 99;
        }
        else
        {
            this->hundreds = this->hundreds - 1;
        }

        return *this;
    }

/*
 * FUNKTION Money& Money::operator-- (int)
 *
 * Sänker ett Money-objekts hundradelar med 1. Resultatet är ett rvalue av
 * objektets värde före stegningen. (Postfix --).
 */
    Money& Money::operator-- (int)
    {
        Money m{*this};
        if((this->hundreds == 0) && (this->units == 0))
        {
            throw monetary_error{"Nedstegning får ej ge ett negativt värde!"};
        }
        
        if(this->hundreds == 0)
        {
            this->units = this->units - 1;
            this->hundreds = 99;
        }
        else
        {
            this->hundreds = this->hundreds - 1;
        }

        return m;
    }

/*
 * FUNKTION Money& Money::operator+= (Money& rhs)
 *
 * Utför den sammansatta tilldelningen "m1 = m1 + m2".
 */
    Money& Money::operator+= (Money& rhs)
    {
        *this = *this + rhs;
        return *this;
    }

/*
 * FUNKTION Money& Money::operator- (Money& rhs)
 *
 * Utför subtraktionen "m1 - m2". Resultatet är ett rvalue.
 */
    Money& Money::operator- (Money& rhs)
    {
        Money m;
        int decrease_units{0};
        int hundreds_to_add{this->hundreds - rhs.hundreds};

        if((this->units - rhs.units) < 0)
        {
            throw monetary_error{"Subtraktion får ej resultera "
                    "i ett negativt värde!"};
        }
        
        if(((this->units - rhs.units) == 0) && hundreds_to_add < 0)
        {
            throw monetary_error{"Subtraktion får ej resultera "
                    "i ett negativt värde!"};
        }
       
        if(hundreds_to_add < 0)
        {
            decrease_units = 1;
            hundreds_to_add = hundreds_to_add + 100;
        }

        if(this->currency == rhs.currency)
        {
            m.currency = this->currency;
            m.units = this->units - rhs.units - decrease_units;
            m.hundreds = hundreds_to_add;
            return m;
        }

        if(this->currency == "")
        {
            m.currency = rhs.currency;
            m.units = this->units - rhs.units - decrease_units;
            m.hundreds = hundreds_to_add;
            return m;
        }
        
        if(rhs.currency == "")
        {
            m.currency = this->currency;
            m.units = this->units - rhs.units - decrease_units;
            m.hundreds = hundreds_to_add;
            return m;
        }

        throw monetary_error{"Du kan inte subtrahera två objekt "
                "av olika valutor!"};
    }

/*
 * FUNKTION Money& Money::operator-= (Money& rhs)
 *
 * Utför den sammansatta tilldelningen "m1 = m1 - m2".
 */
    Money& Money::operator-= (Money& rhs)
    {
        *this = *this - rhs;
        return *this;
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
	    throw monetary_error{"Första funna tecknet vid inläsning "
                    "är felaktigt!"};
        }
        
        if(isalpha(control))
        {
	    for(int i{0}; i < 3; ++i)
            {
		i_stream.get(curr[i]);

		if(! isalpha(curr[i]))
		{
                    throw monetary_error{"Valutan måste bestå av tre bokstäver "
                            "och efterföljas av minst ett mellanslag!"};
		}
            }

            control = i_stream.peek();

            if(! (control == ' '))
            {
                throw monetary_error{"Valutan måste bestå av tre bokstäver "
                        "och efterföljas av minst ett mellanslag!"};
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
	    throw monetary_error{"Antal enheter har inte fått ett värde "
                    "vid inläsning!"};
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
		throw monetary_error{"Felaktigt värde på antal hundradelar "
                        "vid inläsning!"};
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

