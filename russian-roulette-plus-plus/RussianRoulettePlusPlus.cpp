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

	std::cout << "\033[7m| RussianRoulette++ |\033[27m (\033[4m https://github.com/yarb00/russian-roulette-plus-plus \033[24m)" << std::endl << "от yarb00 (\033[4m https://github.com/yarb00 \033[24m)" << std::endl << std::endl << "v" << version << std::endl << std::endl << "-----" << std::endl << std::endl;
}

void RussianRoulettePlusPlus::menu()
{
	system("cls");

	this->printTitle();
	std::cout << "Добро пожаловать в русскую рулетку!" << std::endl << std::endl << "----------" << std::endl << "Нажмите любую кнопку, чтобы начать игру..." << std::endl << "----------";

	system("pause > nul 2>&1");

	while (true)
	{
		int gameMode{ -1 };
		bool isExit{ false };

		system("color 9f");

		system("cls");

		this->printTitle();
		std::cout << "Выберите режим игры и введите его номер:" << std::endl << std::endl << "0. Выйти из игры" << std::endl << std::endl << "1. 6 ходов (всего 6 попыток/выстрелов) [КЛАССИЧЕСКИЙ]" << std::endl << "2. Бесконечный (продолжается, пока кто-нибудь не проиграет)" << std::endl << "3. 12 ходов (всего 12 попыток/выстрелов) [РЕКОМЕНДУЕТСЯ]" << std::endl << "4. 24 хода (всего 24 попытки/выстрела)" << std::endl << std::endl;
		std::cout << "Введите номер и нажмите Enter |>>> ";
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
			std::cout << "Ошибка: такого режима не существует. Нажмите любую кнопку, чтобы вернуться назад.";
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
			if (attemptsLeft != 0) std::cout << "В прошлом ходе выстрела не произошло." << std::endl << std::endl;

			if (isPlayerMove)
			{
				std::cout << "Сейчас ВАШ ход." << std::endl << std::endl << "Нажмите любую кнопку, чтобы сделать себе выстрел...";
			}
			else
			{
				std::cout << "Сейчас ход ПРОТИВНИКА." << std::endl << std::endl << "Нажмите любую кнопку, чтобы сделать в него выстрел...";
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
			if (attemptsLeft - realAttempts != 0) std::cout << "В прошлом ходе выстрела не произошло." << std::endl << std::endl;
			std::cout << "Осталось " << attemptsLeft << " ходов." << std::endl << std::endl;

			if (isPlayerMove)
			{
				std::cout << "Сейчас ВАШ ход." << std::endl << std::endl << "Нажмите любую кнопку, чтобы сделать себе выстрел...";
			}
			else
			{
				std::cout << "Сейчас ход ПРОТИВНИКА." << std::endl << std::endl << "Нажмите любую кнопку, чтобы сделать в него выстрел...";
			}

			system("pause > nul 2>&1");
		}
	}

	system("cls");

	this->printTitle();

	if (gameResult == GameResults::Draw)
	{
		system("color 8f");

		std::cout << "\033[7m \\\\ ! НИЧЬЯ ! // \033[27m" << std::endl << std::endl;
		std::cout << "Все ходы исчерпаны, и пуля так и не попалась ни одному из вас. Никто не выиграл." << std::endl << std::endl;
	}
	else if (gameResult == GameResults::PlayerWin)
	{
		system("color 2f");

		std::cout << "\033[7m \\\\ ! ПОБЕДА ! // \033[27m" << std::endl << std::endl;
		std::cout << "Ваш оппонент умер. Вы победили!" << std::endl << std::endl;
	}
	else if (gameResult == GameResults::OpponentWin)
	{
		system("color 4f");

		std::cout << "\033[7m \\\\ ! ПОРАЖЕНИЕ ! // \033[27m" << std::endl << std::endl;
		std::cout << "Вы умерли. Ваш оппонент победил!" << std::endl << std::endl;
	}

	std::cout << "Спасибо за игру." << std::endl << "Чтобы вернуться в главное меню, нажмите любую клавишу...";
	system("pause > nul 2>&1");
}

void RussianRoulettePlusPlus::main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "ru-RU");

	system("title RussianRoulette++");

	this->menu();
}