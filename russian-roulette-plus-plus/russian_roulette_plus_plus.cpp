#include "russian_roulette_plus_plus.h"
#include <iostream>
#include <time.h>

void Russian_roulette_plus_plus::start()
{
	this->main();
}

void Russian_roulette_plus_plus::print_title()
{
	const std::string version{ "1.0.0" };

	std::cout << "\033[7mRussianRoulette++\033[27m (\033[4mhttps://github.com/yarb00/russian-roulette-plus-plus\033[24m)" << std::endl << "�� yarb00 (\033[4mhttps://github.com/yarb00\033[24m)" << std::endl << std::endl << "v" << version << std::endl << std::endl << "-----" << std::endl << std::endl;
}

void Russian_roulette_plus_plus::menu()
{
	system("cls");

	this->print_title();
	std::cout << "����� ����������!" << std::endl << std::endl << "������� ����� ������, ����� ������ ����...";

	system("pause > nul 2>&1");

	while (true)
	{
		int gamemode{ -1 };
		bool is_exit{ false };

		system("color 9f");

		system("cls");

		this->print_title();
		std::cout << "�������� ����� ���� � ������� ��� �����:" << std::endl << std::endl << "0. ����� �� ����" << std::endl << std::endl << "1. 6 ����� (����� 6 �������/���������) [\033[7m������������\033[27m]" << std::endl << "2. ����������� (������������, ���� ���-������ �� ���������)" << std::endl << "3. 12 ����� (����� 12 �������/���������) [\033[7m�������������\033[27m]" << std::endl << "4. 24 ���� (����� 24 �������/��������)" << std::endl << std::endl;
		std::cout << "������� ����� � ������� Enter |>>> ";
		std::cin >> gamemode;

		switch (gamemode)
		{
		case 0:
			is_exit = true;

			break;
		case 1:
			this->game(gamemodes::ATTEMPTS_6);

			break;
		case 2:
			this->game(gamemodes::ENDLESS);

			break;
		case 3:
			this->game(gamemodes::ATTEMPTS_12);

			break;
		case 4:
			this->game(gamemodes::ATTEMPTS_24);

			break;
		default:
			std::cout << "������: ������ ������ �� ����������. ������� ����� ������, ����� ��������� �����.";
			system("pause > nul 2>&1");

			break;
		}

		if (is_exit) break;
	}
}

void Russian_roulette_plus_plus::game(gamemodes _gamemode)
{
	system("color 1f");

	system("cls");

	const int number_two{ rand() % 6 + 1 };
	int attempts_left{};
	bool is_player_move{ false };
	game_results game_result{ game_results::DRAW };

	if (_gamemode == gamemodes::ENDLESS)
	{
		for (attempts_left; true; attempts_left)
		{
			int number_one{ rand() % 6 + 1 };

			if (number_one == number_two && is_player_move)
			{
				game_result = game_results::OPPONENT_WIN;
				break;
			}
			else if (number_one == number_two && !is_player_move)
			{
				game_result = game_results::PLAYER_WIN;
				break;
			}

			is_player_move = !is_player_move;

			system("cls");

			this->print_title();
			std::cout << "� ������� ���� �������� �� ���������." << std::endl << std::endl;

			if (is_player_move)
			{
				std::cout << "������ \033[7m���\033[27m ���." << std::endl << std::endl << "������� ����� ������, ����� ������� ���� �������...";
			}
			else
			{
				std::cout << "������ ��� \033[7m����������\033[27m." << std::endl << std::endl << "������� ����� ������, ����� ������� � ���� �������...";
			}

			system("pause > nul 2>&1");
		}
	}
	else if (_gamemode == gamemodes::ATTEMPTS_6)
	{
		attempts_left = 6;
	}
	else if (_gamemode == gamemodes::ATTEMPTS_12)
	{
		attempts_left = 12;
	}
	else if (_gamemode == gamemodes::ATTEMPTS_24)
	{
		attempts_left = 24;
	}
	
	if (_gamemode != gamemodes::ENDLESS)
	{
		for (attempts_left; attempts_left > 0; attempts_left--)
		{
			int number_one{ rand() % 6 + 1 };

			if (number_one == number_two && is_player_move)
			{
				game_result = game_results::OPPONENT_WIN;
				break;
			}
			else if (number_one == number_two && !is_player_move)
			{
				game_result = game_results::PLAYER_WIN;
				break;
			}

			is_player_move = !is_player_move;

			system("cls");

			this->print_title();
			std::cout << "� ������� ���� �������� �� ���������." << std::endl << std::endl;
			std::cout << "�������� \033[7m" << attempts_left << "\033[27m �����." << std::endl << std::endl;

			if (is_player_move)
			{
				std::cout << "������ \033[7m���\033[27m ���." << std::endl << std::endl << "������� ����� ������, ����� ������� ���� �������...";
			}
			else
			{
				std::cout << "������ ��� \033[7m����������\033[27m." << std::endl << std::endl << "������� ����� ������, ����� ������� � ���� �������...";
			}

			system("pause > nul 2>&1");
		}
	}

	system("cls");

	this->print_title();

	if (game_result == game_results::DRAW)
	{
		system("color 8f");

		std::cout << "\033[7m�����\033[27m" << std::endl << std::endl;
		std::cout << "��� ���� ���������, � ���� ��� � �� �������� �� ������ �� ���. ����� �� �������." << std::endl << std::endl;
	}
	else if (game_result == game_results::PLAYER_WIN)
	{
		system("color 2f");

		std::cout << "\033[7m������\033[27m" << std::endl << std::endl;
		std::cout << "��� �������� ����. �� ��������!" << std::endl << std::endl;
	}
	else if (game_result == game_results::OPPONENT_WIN)
	{
		system("color 4f");

		std::cout << "\033[7m���������\033[27m" << std::endl << std::endl;
		std::cout << "�� ������. ��� �������� �������!" << std::endl << std::endl;
	}

	std::cout << "������� �� ����." << std::endl << "����� ��������� � ������� ����, ������� ����� �������...";
	system("pause > nul 2>&1");
}

void Russian_roulette_plus_plus::main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "ru-RU");

	system("title RussianRoulette++");

	this->menu();
}