// Mastermind.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include <string>

std::random_device depart;
std::mt19937 hasard(depart());
std::uniform_int_distribution<> choix(0, 5);

int play(std::vector<std::vector<char>>& grid, std::vector<char>& master, int& round);
void rules();
void showgrid(std::vector<std::vector<char>>& grid);
void verification(std::vector<std::vector<char>>& grid, std::vector<char>& master, int& round);

int main()
{
	std::vector<std::vector<char>> grid = std::vector<std::vector<char>>();
	
	std::vector<char> colors = std::vector<char>({ 'a','b','c','d','e', 'f' });
	std::vector<char> master = std::vector<char>({ colors[choix(hasard)], colors[choix(hasard)], colors[choix(hasard)], colors[choix(hasard)] });
	//std::cout << master[0] << master[1] << master[2] << master[3] << std::endl;

	int gridWidth = 6;
	int gridHeight = 10;
	int round = 0;

	for (int i = 0; i < gridHeight; i++)
	{
		grid.push_back(std::vector<char>());

		for (int j = 0; j < gridWidth; j++)
		{
			grid[i].push_back(' ');
		}
	}

	play(grid, master, round);
}

int play(std::vector<std::vector<char>>& grid, std::vector<char>& master, int& round)
{
	rules();
	do
	{
		std::cout << " " << std::endl;
		std::cout << "Entrez une séquence ";
		std::cin >> grid[round][0] >> grid[round][1] >> grid[round][2] >> grid[round][3];

		verification(grid, master, round);
		showgrid(grid);

		if (grid[round][0] == master[0] && grid[round][1] == master[1] && grid[round][2] == master[2] && grid[round][3] == master[3])
		{
			std::cout << "-----------------------------------" << std::endl;
			std::cout << "Vous avez trouvé la combinaison!" << std::endl;
			std::cout << "Merci monsieur, grâce à vous nous sommes riche et mon patron l'est un peu moins." << std::endl;
			std::cout << "J'avoue que le coffre ne m'appartenait pas mais je partage les bénéfices avec vous en échange de votre mutisme." << std::endl;
			std::cout << "Ce qui viens de se passer devra rester entre nous!" << std::endl;
			std::cout << "Félicitation !" << std::endl;
		}
		round += 1;
	} while (round != 9 || (grid[round][0] == master[0] && grid[round][1] == master[1] && grid[round][2] == master[2] && grid[round][3] == master[3]));

	return round;
}
	
void rules()
{
	std::string jouer;
	std::cout << "Bonsoir étranger," << std::endl;
	std::cout << "j'étais justement à la recherche d'un serrurier!" << std::endl;
	std::cout << "Un ancien voleur de banque fera très bien l'affaire!" << std::endl;
	std::cout << "Vous voulez bien m'aider à ouvrir mon coffre-fort? (oui / non): " << std::endl;
	std::cin >> jouer;
	while(jouer != "oui")
	{
		std::cout << "S'il vous plaît monsieur!" << std::endl;
		std::cin >> jouer;
	}

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Merci monsieur!" << std::endl;
	std::cout << "Le code est composé de 4 charactères et peux contenir les lettres 'a', 'b', 'c', 'd', 'e' et 'f'." << std::endl;
	std::cout << "Attention, les lettres peuvent se répéter plus d'une fois." << std::endl;
	std::cout << "Nous n'avons que 10 tentatives avant que le coffre s'auto-détruise!" << std::endl;
	std::cout << "À chaque tentative le coffre affiche combien de lettres sont exactes et bien placées(BP) et combien de lettres sont exactes et mal placées." << std::endl;
	std::cout << "Bonne chance étranger!" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

void showgrid(std::vector<std::vector<char>>& grid)
{
	std::cout <<"               BP  MP" << std::endl;
	std::cout << "[" << grid[0][0] << "][" << grid[0][1] << "][" << grid[0][2] << "][" << grid[0][3] << "] - [" << grid[0][4] << "][" << grid[0][5] << "]" << std::endl;
	std::cout << "[" << grid[1][0] << "][" << grid[1][1] << "][" << grid[1][2] << "][" << grid[1][3] << "] - [" << grid[1][4] << "][" << grid[1][5] << "]" << std::endl;
	std::cout << "[" << grid[2][0] << "][" << grid[2][1] << "][" << grid[2][2] << "][" << grid[2][3] << "] - [" << grid[2][4] << "][" << grid[2][5] << "]" << std::endl;
	std::cout << "[" << grid[3][0] << "][" << grid[3][1] << "][" << grid[3][2] << "][" << grid[3][3] << "] - [" << grid[3][4] << "][" << grid[3][5] << "]" << std::endl;
	std::cout << "[" << grid[4][0] << "][" << grid[4][1] << "][" << grid[4][2] << "][" << grid[4][3] << "] - [" << grid[4][4] << "][" << grid[4][5] << "]" << std::endl;
	std::cout << "[" << grid[5][0] << "][" << grid[5][1] << "][" << grid[5][2] << "][" << grid[5][3] << "] - [" << grid[5][4] << "][" << grid[5][5] << "]" << std::endl;
	std::cout << "[" << grid[6][0] << "][" << grid[6][1] << "][" << grid[6][2] << "][" << grid[6][3] << "] - [" << grid[6][4] << "][" << grid[6][5] << "]" << std::endl;
	std::cout << "[" << grid[7][0] << "][" << grid[7][1] << "][" << grid[7][2] << "][" << grid[7][3] << "] - [" << grid[7][4] << "][" << grid[7][5] << "]" << std::endl;
	std::cout << "[" << grid[8][0] << "][" << grid[8][1] << "][" << grid[8][2] << "][" << grid[8][3] << "] - [" << grid[8][4] << "][" << grid[8][5] << "]" << std::endl;
	std::cout << "[" << grid[9][0] << "][" << grid[9][1] << "][" << grid[9][2] << "][" << grid[9][3] << "] - [" << grid[9][4] << "][" << grid[9][5] << "]" << std::endl;
}

void verification(std::vector<std::vector<char>>& grid, std::vector<char>& master, int& round)
{
	int bonnePlace = 0;
	int mauvaisePlace = 0;
	std::vector<char> gridCopy(4);
	std::vector<char> masterCopy(4);

	gridCopy[0] = grid[round][0];
	gridCopy[1] = grid[round][1];
	gridCopy[2] = grid[round][2];
	gridCopy[3] = grid[round][3];

	masterCopy[0] = master[0];
	masterCopy[1] = master[1];
	masterCopy[2] = master[2];
	masterCopy[3] = master[3];

	if (gridCopy[0] == masterCopy[0])
	{
		bonnePlace += 1;
		gridCopy[0] = ' ';
		masterCopy[0] = ' ';
	}
	else if (gridCopy[0] == masterCopy[1] && gridCopy[1] != masterCopy[1])
	{
		mauvaisePlace += 1;
		gridCopy[0] = ' ';
		masterCopy[1] = ' ';
	}
	else if (gridCopy[0] == masterCopy[2] && gridCopy[2] != masterCopy[2])
	{
		mauvaisePlace += 1;
		gridCopy[0] = ' ';
		masterCopy[2] = ' ';
	}
	else if (gridCopy[0] == masterCopy[3] && gridCopy[3] != masterCopy[3])
	{
		mauvaisePlace += 1;
		gridCopy[0] = ' ';
		masterCopy[3] = ' ';
	}

	if (gridCopy[1] == masterCopy[1])
	{
		bonnePlace += 1;
		gridCopy[1] = ' ';
		masterCopy[1] = ' ';
	}
	else if (gridCopy[1] == masterCopy[0] && gridCopy[0] != masterCopy[0])
	{
		mauvaisePlace += 1;
		gridCopy[1] = ' ';
		masterCopy[0] = ' ';
	}
	else if (gridCopy[1] == masterCopy[2] && gridCopy[2] != masterCopy[2])
	{
		mauvaisePlace += 1;
		gridCopy[1] = ' ';
		masterCopy[2] = ' ';
	}
	else if (gridCopy[1] == masterCopy[3] && gridCopy[3] != masterCopy[3])
	{
		mauvaisePlace += 1;
		gridCopy[1] = ' ';
		masterCopy[3] = ' ';
	}

	if (gridCopy[2] == masterCopy[2])
	{
		bonnePlace += 1;
		gridCopy[2] = ' ';
		masterCopy[2] = ' ';
	}
	else if (gridCopy[2] == masterCopy[0] && gridCopy[0] != masterCopy[0])
	{
		mauvaisePlace += 1;
		gridCopy[2] = ' ';
		masterCopy[0] = ' ';
	}
	else if (gridCopy[2] == masterCopy[1] && gridCopy[1] != masterCopy[1])
	{
		mauvaisePlace += 1;
		gridCopy[2] = ' ';
		masterCopy[1] = ' ';
	}
	else if (gridCopy[2] == masterCopy[3] && gridCopy[3] != masterCopy[3])
	{
		mauvaisePlace += 1;
		gridCopy[2] = ' ';
		masterCopy[3] = ' ';
	}


	if (gridCopy[3] == masterCopy[3])
	{
		bonnePlace += 1;
		gridCopy[2] = ' ';
		masterCopy[2] = ' ';
	}
	else if (gridCopy[3] && masterCopy[0] && gridCopy[0] != masterCopy[0])
	{
		mauvaisePlace += 1;
		gridCopy[3] = ' ';
		masterCopy[0] = ' ';
	}
	else if (gridCopy[3] == masterCopy[1] && gridCopy[1] != masterCopy[1])
	{
		mauvaisePlace += 1;
		gridCopy[3] = ' ';
		masterCopy[1] = ' ';
	}
	else if (gridCopy[3] == masterCopy[2] && gridCopy[2] != masterCopy[2])
	{
		mauvaisePlace += 1;
		gridCopy[3] = ' ';
		masterCopy[2] = ' ';
	}
	
	if (mauvaisePlace == 1)
	{
		grid[round][5] = '1';
	}
	else if (mauvaisePlace == 2)
	{
		grid[round][5] = '2';
	}
	else if (mauvaisePlace == 3)
	{
		grid[round][5] = '3';
	}
	else if (mauvaisePlace == 4)
	{
		grid[round][5] = '4';
	}
	else
	{
		grid[round][5] = '0';
	}

	if (bonnePlace == 1)
	{
		grid[round][4] = '1';
	}
	else if (bonnePlace == 2)
	{
		grid[round][4] = '2';
	}
	else if (bonnePlace == 3)
	{
		grid[round][4] = '3';
	}
	else if (bonnePlace == 4)
	{
		grid[round][4] = '4';
	}
	else
	{
		grid[round][4] = '0';
	}

}

