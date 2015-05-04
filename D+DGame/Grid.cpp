#include "stdafx.h"
#include "Grid.h"


Grid::Grid(std::map<int, TileType> *tileTypes, int xSize, int ySize)
{

}

Grid::Grid(std::map<int, TileType> *tileTypes, std::vector<std::vector<char>> *tileData){
	/*xSize = (*tileData)[0].size;
	ySize = (*tileData).size;

	TileData = *tileData;
	TileTypes = *tileTypes;*/
}

Grid::~Grid()
{
}

void Grid::Render(SDL_Renderer *renderer){
	SDL_Surface *MainSurface = SDL_CreateRGBSurface(0, xSize*tileSize, ySize*tileSize, 32, 0, 0, 0, 0);
	if (MainSurface == NULL) {
		fprintf(stderr, "CreateRGBSurface failed: %s\n", SDL_GetError());
		exit(1);
	}

	std::map<int, SDL_Surface*> TileSurfaces; //Needs to be freed

	for (std::map<int, TileType>::iterator it = TileTypes.begin(); it != TileTypes.end(); ++it)
	{
		TileSurfaces.insert(it->first, it->second.GetSurface());
	}

	SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer, MainSurface), NULL, NULL);
	SDL_FreeSurface(MainSurface);
	for (std::map<int, SDL_Surface*>::iterator it = TileSurfaces.begin(); it != TileSurfaces.end(); ++it)
	{
		SDL_FreeSurface(it->second);
	}
	
}