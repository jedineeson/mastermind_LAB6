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

int main()
{
	std::vector<std::vector<char>> grid = std::vector<std::vector<char>>();
	
	std::vector<char> colors = std::vector<char>({ 'a','b','c','d','e', 'f' });
	std::vector<char> Master = std::vector<char>({ colors[choix(hasard)], colors[choix(hasard)], colors[choix(hasard)], colors[choix(hasard)] });
	std::cout << Master[0] << Master[1] << Master[2] << Master[3] << std::endl;

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