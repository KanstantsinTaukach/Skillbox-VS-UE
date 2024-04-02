#pragma once

class Player
{
private:
	std::string Name;
	int Score;
public:
	Player();
	Player(std::string, int);
		
	void SetName();
	void SetScore();

	std::string GetName() const;
	int GetScore() const;
};

void SimpleSort(Player[], int);

void DisplayPlayers(Player[], int);
