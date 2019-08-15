#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

#include "Card.h"
#include "Hand.h"

using namespace std;

class GenericPlayer : public Hand
{
private:
    friend ostream& operator << (ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const string& name = "") : m_Name(name) {
    }

    virtual ~GenericPlayer() {
    }

    virtual bool IsHitting() const = 0; //Whether CPU keeps hitting

    bool IsBusted() const{ //CPU hand total greater than 21
    return (getTotal() > 21);
    }

    void Bust() const{ //CPU busts
    cout << m_Name << " busted.\n";
    }

protected:
    string m_Name;
};

CPU strategy
If ((dealer card 1 == 2 || dealer card 1 == 3)) && ((cpu handtotal >= 2 && cpu handottal <=12))
    CPU hits

If ((dealer card 1 == 2 || dealer card 1 == 3)) && ((cpu handtotal >=13 && cpu handtotal <= 20))
    CPU stands 

If ((dealer card 1 == 4 || dealer card 1 == 5 || dealer card 1 == 6)) && ((cpu handtotal >= 2 && cpu handtotal <= 11))
	CPU hits

If ((dealer card 1 == 4 || dealer card 1 == 5 || dealer card 1 == 6)) && ((cpu handtotal >= 12 && cpu handtotal <= 20))
	CPU stands

If ((dealer card 1 == 7 || dealer card 1 == 8 || dealer card 1 == 9) || dealer card 1 == 10 || dealer card 1 == A)) && ((cpu handtotal >= 2 && cpu handtotal <= 16))
	CPU hits

If ((dealer card 1 == 7 || dealer card 1 == 8 || dealer card 1 == 9) || dealer card 1 == 10 || dealer card 1 == A)) && ((cpu handtotal >= 17 && cpu handtotal <= 20))
	CPU stands
