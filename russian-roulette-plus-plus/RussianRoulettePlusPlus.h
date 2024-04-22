#pragma once

enum class GameModes
{
	Attempts6 = 0,
	Endless,
	Attempts12,
	Attempts24
};

enum class GameResults
{
	PlayerWin = 0,
	OpponentLost = 0,

	PlayerLost = 1,
	OpponentWin = 1,

	Draw = 2
};

class RussianRoulettePlusPlus
{
public:
	void start();
private:
	void printTitle();
	void menu();
	void game(GameModes gameMode = GameModes::Attempts6);
	void main();
};