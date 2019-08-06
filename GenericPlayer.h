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
    friend ostream& operator << (ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const string& name = "");

    virtual ~GenericPlayer();

    virtual bool IsHitting() const = 0;

    bool IsBusted() const;

    void Bust() const;

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
