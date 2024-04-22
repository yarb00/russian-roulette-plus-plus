#include "RussianRoulettePlusPlus.h"
#include <iostream>
#include <time.h>

void RussianRoulettePlusPlus::start()
{
	this->main();
}

void RussianRoulettePlusPlus::printTitle()
{
	const std::string version{ "1.1.0" };

	std::cout << "\033[7m| RussianRoulette++ |\033[27m (\033[4m https://github.com/yarb00/russian-roulette-plus-plus \033[24m)" << std::endl << "�� yarb00 (\033[4m https://github.com/yarb00 \033[24m)" << std::endl << std::endl << "v" << version << std::endl << std::endl << "-----" << std::endl << std::endl;
}

void RussianRoulettePlusPlus::menu()
{
	system("cls");

	this->printTitle();
	std::cout << "����� ���������� � ������� �������!" << std::endl << std::endl << "----------" << std::endl << "������� ����� ������, ����� ������ ����..." << std::endl << "----------";

	system("pause > nul 2>&1");

	while (true)
	{
		int gameMode{ -1 };
		bool isExit{ false };

		system("color 9f");

		system("cls");

		this->printTitle();
		std::cout << "�������� ����� ���� � ������� ��� �����:" << std::endl << std::endl << "0. ����� �� ����" << std::endl << std::endl << "1. 6 ����� (����� 6 �������/���������) [������������]" << std::endl << "2. ����������� (������������, ���� ���-������ �� ���������)" << std::endl << "3. 12 ����� (����� 12 �������/���������) [�������������]" << std::endl << "4. 24 ���� (����� 24 �������/��������)" << std::endl << std::endl;
		std::cout << "������� ����� � ������� Enter |>>> ";
		std::cin >> gameMode;

		switch (gameMode)
		{
		case 0:
			isExit = true;

			break;
		case 1:
			this->game(GameModes::Attempts6);

			break;
		case 2:
			this->game(GameModes::Endless);

			break;
		case 3:
			this->game(GameModes::Attempts12);

			break;
		case 4:
			this->game(GameModes::Attempts24);

			break;
		default:
			std::cout << "������: ������ ������ �� ����������. ������� ����� ������, ����� ��������� �����.";
			system("pause > nul 2>&1");

			break;
		}

		if (isExit) break;
	}
}

void RussianRoulettePlusPlus::game(GameModes gameMode)
{
	system("color 1f");

	system("cls");

	const int numberTwo{ rand() % 6 + 1 };
	int attemptsLeft{ 0 };
	bool isPlayerMove{ false };
	GameResults gameResult{ GameResults::Draw };

	if (gameMode == GameModes::Endless)
	{
		for (attemptsLeft; true; attemptsLeft++)
		{
			int numberOne{ rand() % 6 + 1 };

			if (numberOne == numberTwo && isPlayerMove && attemptsLeft != 0)
			{
				gameResult = GameResults::OpponentWin;
				break;
			}
			else if (numberOne == numberTwo && !isPlayerMove && attemptsLeft != 0)
			{
				gameResult = GameResults::PlayerWin;
				break;
			}

			isPlayerMove = !isPlayerMove;

			system("cls");

			this->printTitle();
			if (attemptsLeft != 0) std::cout << "� ������� ���� �������� �� ���������." << std::endl << std::endl;

			if (isPlayerMove)
			{
				std::cout << "������ ��� ���." << std::endl << std::endl << "������� ����� ������, ����� ������� ���� �������...";
			}
			else
			{
				std::cout << "������ ��� ����������." << std::endl << std::endl << "������� ����� ������, ����� ������� � ���� �������...";
			}

			system("pause > nul 2>&1");
		}
	}
	else if (gameMode == GameModes::Attempts6)
	{
		attemptsLeft = 6;
	}
	else if (gameMode == GameModes::Attempts12)
	{
		attemptsLeft = 12;
	}
	else if (gameMode == GameModes::Attempts24)
	{
		attemptsLeft = 24;
	}
	
	if (gameMode != GameModes::Endless)
	{
		int realAttempts{ attemptsLeft };

		for (attemptsLeft; attemptsLeft > 0; attemptsLeft--)
		{
			int numberOne{ rand() % 6 + 1 };

			if (numberOne == numberTwo && isPlayerMove && attemptsLeft - realAttempts != 0)
			{
				gameResult = GameResults::OpponentWin;
				break;
			}
			else if (numberOne == numberTwo && !isPlayerMove && attemptsLeft - realAttempts != 0)
			{
				gameResult = GameResults::PlayerWin;
				break;
			}

			isPlayerMove = !isPlayerMove;

			system("cls");

			this->printTitle();
			if (attemptsLeft - realAttempts != 0) std::cout << "� ������� ���� �������� �� ���������." << std::endl << std::endl;
			std::cout << "�������� " << attemptsLeft << " �����." << std::endl << std::endl;

			if (isPlayerMove)
			{
				std::cout << "������ ��� ���." << std::endl << std::endl << "������� ����� ������, ����� ������� ���� �������...";
			}
			else
			{
				std::cout << "������ ��� ����������." << std::endl << std::endl << "������� ����� ������, ����� ������� � ���� �������...";
			}

			system("pause > nul 2>&1");
		}
	}

	system("cls");

	this->printTitle();

	if (gameResult == GameResults::Draw)
	{
		system("color 8f");

		std::cout << "\033[7m \\\\ ! ����� ! // \033[27m" << std::endl << std::endl;
		std::cout << "��� ���� ���������, � ���� ��� � �� �������� �� ������ �� ���. ����� �� �������." << std::endl << std::endl;
	}
	else if (gameResult == GameResults::PlayerWin)
	{
		system("color 2f");

		std::cout << "\033[7m \\\\ ! ������ ! // \033[27m" << std::endl << std::endl;
		std::cout << "��� �������� ����. �� ��������!" << std::endl << std::endl;
	}
	else if (gameResult == GameResults::OpponentWin)
	{
		system("color 4f");

		std::cout << "\033[7m \\\\ ! ��������� ! // \033[27m" << std::endl << std::endl;
		std::cout << "�� ������. ��� �������� �������!" << std::endl << std::endl;
	}

	std::cout << "������� �� ����." << std::endl << "����� ��������� � ������� ����, ������� ����� �������...";
	system("pause > nul 2>&1");
}

void RussianRoulettePlusPlus::main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "ru-RU");

	system("title RussianRoulette++");

	this->menu();
}