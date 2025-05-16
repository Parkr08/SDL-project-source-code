#pragma once
#include "Main.h"

class Tile
{
public:
	//tile types
	enum tile_type
	{
		Grass,
		Path
	};

	//constructor
	Tile(int x, int y, int size, tile_type type);

	//render method
	void render(SDL_Renderer* renderer);

private:
	int x, y, size;
	tile_type type;

	//method to get each tile
	SDL_FRect getrect();
};
