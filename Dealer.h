#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Dealer : public Player {
public:
    using Player::Player;

    void seeCard() {
        //Dealer's cards
        m_mano.displayAsDealer();
    }

    void game(Player) 
    {
        while (m_mano.getTotalVal() <= 21)
        {
            std::cout << "Cards: ";
            m_mano.display();
            std::cout << std::endl;
            if (m_mano.getTotalVal() > play.getScore() && m_mano.getTotalVal() <= 21)
            {
                std::cout << "The dealer won because his score was greater than yours and it didn't exceed 21 in any form." << std::endl;
                return;
            }

            if (m_mano.getTotalVal() == play.getScore())
            {
                std::cout << "A tie! " << std::endl;
                return;
            }
            anotherCard();
        }

        if (m_mano.getTotalVal() > 21)
        {
            std::cout << "El dealer se paso de 21, el perdio";
            return;
        }
    }
        

};