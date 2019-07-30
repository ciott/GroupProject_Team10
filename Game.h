#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

#include "Deck.h"
#include "House.h"
#include "Player.h"
#include "Card.h"

using namespace std;

class Game
{
public:
    Game(const vector<string>& names);

    ~Game();

    void Play();

private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
};

Game::Game(const vector<string>& names)
{
    vector<string> :: const_iterator pName;

    for (pName = names.begin(); pName != names.end(); ++pName)
        m_Players.push_back(Player(*pName));

    srand(time(0));
    m_Deck.Populate();
    m_Deck.Shuffle();
}

Game::~Game()
{}

void Game::Play()
{
    vector<Player> :: iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
            ++pPlayer)
            m_Deck.Deal(*pPlayer);
        m_Deck.Deal(m_House);
    }

    m_House.FlipFirstCard();

    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        // Display players hand
        // Display house hand
    
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        m_Deck.AdditionalCards(*pPlayer);

    m_House.FlipFirstCard();
        // Display house first card

    m_Deck.AdditionalCards(m_House);

    if (m_House.IsBusted())
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
            ++pPlayer)
            if (!(pPlayer−>IsBusted()))
                pPlayer−>Win();
    }

    else
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
            ++pPlayer)
            if (!(pPlayer−>IsBusted()))
            {
                if (pPlayer−>GetTotal() > m_House.GetTotal())
                    pPlayer−>Win();
                else if (pPlayer−>GetTotal() < m_House.GetTotal())
                    pPlayer−>Lose();
                else
                    pPlayer−>Push();
            }
    }

    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        pPlayer−>Clear();
        m_House.Clear();
}