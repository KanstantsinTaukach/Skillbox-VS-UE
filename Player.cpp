#include <string>
#include <iostream>
#include "Player.h"

Player::Player() : Name("Empty"), Score(0)
{

}

Player::Player(std::string name, int score) : Name(name), Score(score)
{

}

void Player::SetName()
{
	std::cout << "Enter player name: " << std::endl;
	std::cin >> Name;
}

void Player::SetScore()
{
	std::cout << "Enter player score: " << std::endl;
	std::cin >> Score;
}

std::string Player::GetName() const
{
	return Name;
}

int Player::GetScore() const
{
	return Score;
}


void SimpleSort(Player P[], int arrSize)
{
    for (int i = 0; i < arrSize - 1; ++i)
    {
        for (int j = i + 1; j < arrSize; ++j)
        {
            if (P[i].GetScore() < P[j].GetScore())
            {
                std::swap(P[i], P[j]);
            }
        }
    }
}

void DisplayPlayers(Player P[], int arrSize)
{
    for (int i = 0; i < arrSize; ++i)
    {
        std::cout << "Player " << i + 1 << ":" << std::endl;
        std::cout << "Name: " << P[i].GetName() << '\t';
        std::cout << "Score: " << P[i].GetScore() << '\t' << std::endl;
    }
}
