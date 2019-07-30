#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Card
{
public:
    enum rank {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };

    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    friend ostream& operator << (ostream& os, const Card& aCard);

    Card(rank r = ACE, suit s = SPADES, bool ifUp = true);

    int GetValue() const;

    void Flip();

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

Card::Card(rank r, suit s, bool ifUp) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifUp)
{}

int Card::GetValue() const
{
    int value = 0;
    if (m_IsFaceUp)
    {
        value = m_Rank;

        if (value > 10)
            value = 10;
    }
    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}