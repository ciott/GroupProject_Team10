#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

#include "Hand.h"
#include "GenericPlayer.h"

using namespace std;

class Deck : public Hand
{
public:
    Deck();

    virtual ~Deck();

    void Populate();

    void Shuffle();

    void Deal(Hand& aHand);

    void AdditionalCards(GenericPlayer& aGenericPlayer);
};

Deck::Deck()
{
    m_Cards.reserve(52);
    Populate();
}

Deck::~Deck()
{}

void Deck::Populate()
{
    Clear();
    
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
        for (int r = Card::ACE; r <= Card::KING; ++r)
            Add(new Card(static_cast<Card::rank>(r),
                static_cast<Card::suit>(s)));
}

void Deck::Shuffle()
{
    random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand)
{
    if (!m_Cards.empty())
    {
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
    else
    {
        // "Out of cards. Unable to deal". Reshuffle
    }
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
    while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
    {
        Deal(aGenericPlayer);

        if (aGenericPlayer.IsBusted())
            aGenericPlayer.Bust();
    }
}



//Reference https://codereview.stackexchange.com/questions/78710/oop-blackjack-in-c
// Example below to initialize deck with 13 values of 4 suits
Loading card into deck
suit diamond = 0;
suit heart = 1;
suit club = 2;
suit spade = 3;

for (int value = 1; value < 13; value++) //Cycle through A->K
    for (int suit = 0; suit < 3; suit++) //Assign each value with 4 suits
        if (value == 11)
            push_back Jack
        stack<int>.push_back
