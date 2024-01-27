#pragma once

class Russian_roulette_plus_plus
{
public:
	void start();
private:
	enum class gamemodes
	{
		ATTEMPTS_6 = 0,
		ENDLESS,
		ATTEMPTS_12,
		ATTEMPTS_24
	};

	enum class game_results
	{
		PLAYER_WIN = 0,
		OPPONENT_LOST = 0,

		PLAYER_LOST = 1,
		OPPONENT_WIN = 1,

		DRAW = 2
	};

	void print_title();
	void menu();
	void game(gamemodes _gamemode = gamemodes::ATTEMPTS_6);
	void main();
};