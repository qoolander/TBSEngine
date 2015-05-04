#pragma once
#include "stdafx.h"
#include "TileType.h"

class Grid
{
public:
	Grid(std::map<int, TileType> *tileTypes, int xSize, int ySize);
	Grid(std::map<int, TileType> *tileTypes, std::vector<std::vector<char>> *tileData);
	~Grid();

	void Render(SDL_Renderer *renderer);

	std::vector<std::vector<char>> TileData;

	std::map<int, TileType> TileTypes;

	int xSize;
	int ySize;

	int tileSize; //In pixels
};

