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

int play(std::vector<std::vector<char>>& grid, std::vector<char>& master);
void rules();
void showgrid(std::vector<std::vector<char>>& grid);

int main()
{
	std::vector<std::vector<char>> grid = std::vector<std::vector<char>>();
	
	std::vector<char> colors = std::vector<char>({ 'a','b','c','d','e', 'f' });
	std::vector<char> master = std::vector<char>({ colors[choix(hasard)], colors[choix(hasard)], colors[choix(hasard)], colors[choix(hasard)] });
	//std::cout << master[0] << master[1] << master[2] << master[3] << std::endl;

	int gridWidth = 6;
	int gridHeight = 10;

	for (int i = 0; i < gridWidth; i++)
	{
		grid.push_back(std::vector<char>());

		for (int j = 0; j < gridHeight; j++)
		{
			grid[i].push_back(' ');
		}
	}
	play(grid, master);
}

int play(std::vector<std::vector<char>>& grid, std::vector<char>& master)
{
	int round;
	round = 0;
	rules();
	do
	{
		round += 1;
		std::cout << " " << std::endl;
		std::cout << "Entrez une séquence ";
		std::cin >> grid[round][0], grid[round][1], grid[round][2], grid[round][3];

		//verification()
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
	} while (round == 10 || grid[round][0] == master[0] && grid[round][1] == master[1] && grid[round][2] == master[2] && grid[round][3] == master[3]);

	return round;
}
	
void rules()
{
	std::string jouer;
	std::cout << "Bonsoir étranger," << std::endl;
	std::cout << "j'étais justement à la recherche d'un serrurier!" << std::endl;
	std::cout << "Un ancien voleur de banque fera très bien l'affaire!" << std::endl;

	do
	{
		std::cout << "Vous voulez bien m'aider à ouvrir mon coffre-fort? (oui / non): " << std::endl;
		std::cin >> jouer;
		if (jouer != "oui")
		{
			std::cout << "S'il vous plaît monsieur!" << std::endl;
		}
	} while (jouer == "oui");

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
	std::cout << "     " << "     " << "     " << "    " << "[ BP  MP ]" << std::endl;
	std::cout << "[" << grid[1][1] << "][" << grid[1][2] << "][" << grid[1][3] << "][" << grid[1][4] << "] - [" << grid[1][5] << "][" << grid[1][6] << "]" << std::endl;
	std::cout << "[" << grid[2][1] << "][" << grid[2][2] << "][" << grid[2][3] << "][" << grid[2][4] << "] - [" << grid[2][5] << "][" << grid[2][6] << "]" << std::endl;
	std::cout << "[" << grid[3][1] << "][" << grid[3][2] << "][" << grid[3][3] << "][" << grid[3][4] << "] - [" << grid[3][5] << "][" << grid[3][6] << "]" << std::endl;
	std::cout << "[" << grid[4][1] << "][" << grid[4][2] << "][" << grid[4][3] << "][" << grid[4][4] << "] - [" << grid[4][5] << "][" << grid[4][6] << "]" << std::endl;
	std::cout << "[" << grid[5][1] << "][" << grid[5][2] << "][" << grid[5][3] << "][" << grid[5][4] << "] - [" << grid[5][5] << "][" << grid[5][6] << "]" << std::endl;
	std::cout << "[" << grid[6][1] << "][" << grid[6][2] << "][" << grid[6][3] << "][" << grid[6][4] << "] - [" << grid[6][5] << "][" << grid[6][6] << "]" << std::endl;
	std::cout << "[" << grid[7][1] << "][" << grid[7][2] << "][" << grid[7][3] << "][" << grid[7][4] << "] - [" << grid[7][5] << "][" << grid[7][6] << "]" << std::endl;
	std::cout << "[" << grid[8][1] << "][" << grid[8][2] << "][" << grid[8][3] << "][" << grid[8][4] << "] - [" << grid[8][5] << "][" << grid[8][6] << "]" << std::endl;
	std::cout << "[" << grid[9][1] << "][" << grid[9][2] << "][" << grid[9][3] << "][" << grid[9][4] << "] - [" << grid[9][5] << "][" << grid[9][6] << "]" << std::endl;
	std::cout << "[" << grid[10][1] << "][" << grid[10][2] << "][" << grid[10][3] << "][" << grid[10][4] << "] - [" << grid[10][5] << "][" << grid[10][6] << "]" << std::endl;
}

