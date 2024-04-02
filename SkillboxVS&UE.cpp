#include <iostream>
#include "Player.h"

int main()
{
    int size;
    
    do 
    {
        std::cout << "Enter the number of players" << std::endl;
        std::cin >> size;
    } while (size < 2);
    
    Player* PlayersArray = new Player[size];

    for (int i = 0; i < size; ++i)
    {
        (PlayersArray + i)->SetName();
        (PlayersArray + i)->SetScore();
    };

    std::cout << std::endl << "Players before swap: " << std::endl;
    DisplayPlayers(PlayersArray, size);

    SimpleSort(PlayersArray, size);

    std::cout << std::endl << "Players after swap: " << std::endl;
    DisplayPlayers(PlayersArray, size);

    delete[] PlayersArray;
    PlayersArray = nullptr;

    return 0;
}
