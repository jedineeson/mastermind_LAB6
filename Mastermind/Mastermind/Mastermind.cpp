// Mastermind.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "mastermind.h"
#include <random>

std::random_device depart;
std::mt19937 hasard(depart());
std::uniform_int_distribution<> choix(0, 5);

void play(std::vector<std::vector<char>>& grid, std::vector<char>& master);


int main()
{
	std::vector<std::vector<char>> grid = std::vector<std::vector<char>>();
	
	std::vector<char> colors = std::vector<char>({ 'a','b','c','d','e', 'f' });
	std::vector<char> master = std::vector<char>({ colors[choix(hasard)], colors[choix(hasard)], colors[choix(hasard)], colors[choix(hasard)] });
	std::cout << master[0] << master[1] << master[2] << master[3] << std::endl;

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

}

void play(std::vector<std::vector<char>>& grid, std::vector<char>& master)
{
	int round;
	round = 0;

	do
	{
		round += 1;
		std::cout << " " << std::endl;
		std::cout << "Entrez une séquence ";
		std::cin >> grid[round][0], grid[round][1], grid[round][2], grid[round][3];
		
		//verification()
		//showgrid()

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

}