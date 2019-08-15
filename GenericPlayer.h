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

    virtual bool IsHitting() const = 0; //Whether NPC keeps hitting

    bool IsBusted() const{ //NPC hand total greater than 21
    return (getTotal() > 21);
    }

    void Bust() const{ //NPC busts
    cout << m_Name << " busted.\n";
    }

protected:
    string m_Name;
};

NPC strategy
If ((dealer card 1 == 2 || dealer card 1 == 3)) && ((npc handtotal >= 2 && npc handottal <=12))
    NPC hits

If ((dealer card 1 == 2 || dealer card 1 == 3)) && ((npc handtotal >=13 && npc handtotal <= 20))
    NPC stands 

If ((dealer card 1 == 4 || dealer card 1 == 5 || dealer card 1 == 6)) && ((npc handtotal >= 2 && npc handtotal <= 11))
	NPC hits

If ((dealer card 1 == 4 || dealer card 1 == 5 || dealer card 1 == 6)) && ((npc handtotal >= 12 && npc handtotal <= 20))
	NPC stands

If ((dealer card 1 == 7 || dealer card 1 == 8 || dealer card 1 == 9) || dealer card 1 == 10 || dealer card 1 == A)) && ((npc handtotal >= 2 && npc handtotal <= 16))
	NPC hits

If ((dealer card 1 == 7 || dealer card 1 == 8 || dealer card 1 == 9) || dealer card 1 == 10 || dealer card 1 == A)) && ((npc handtotal >= 17 && npc handtotal <= 20))
	NPC stands
