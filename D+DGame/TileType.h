#pragma once
#include "stdafx.h"

class TileType
{
public:
	TileType();
	~TileType();

	
	bool walkeable;
	int movmentCost;

	SDL_Surface GetSurface(){

	}

private:
	SDL_Surface surface;
};

