#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

#include "GenericPlayer.h"

using namespace std;

class Player : public GenericPlayer {
public:
    Player(const string& name = "");

    virtual ~Player();

    virtual bool IsHitting() const;

    void Win() const;

    void Lose() const;

    void Push() const;
};

Player::Player(const string& name) : GenericPlayer(name) {

}

Player::~Player() {

}

bool Player::IsHitting() const {
    //Ask player if want to hit
    //cin as char response
    return (response == 'y' || response == 'Y');
}

void Player::Win() const {
    //cout player_name wins
}

void Player::Lose() const {
    //cout player_name loses
}

void Player::Push() const {
    //cout player_name pushes
}