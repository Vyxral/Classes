#include "SpacialGrid.h"

SpacialGrid::SpacialGrid()
{
	width = 1;
	height = 1;
	grid_xy = NULL;
}

SpacialGrid::SpacialGrid(unsigned int width, unsigned int height) : _width(width), _height(height)
{
	
	grid_xy.resize(width);
	for (int i{ 0 }; i < width; i++)
		grid_xy[i].resize(height);
}


unsigned int SpacialGrid::getWidth()
{
	return _width;
}

unsigned int SpacialGrid::getHeight()
{
	return _height;
}

std::vector<void*>* SpacialGrid::getGridXY(unsigned int x, unsigned int y)
{
	return &grid_xy[x][y];
}

void SpacialGrid::addToGridXY(void* obj, unsigned int x, unsigned int y)
{
	grid_xy[x][y].push_back(obj);
}

void SpacialGrid::addToGridXY(void* obj, std::vector<void*>* grid)
{
	grid->push_back(obj);
}

void SpacialGrid::removeFromGridXY(void* obj, unsigned int x, unsigned int y)
{
	grid_xy[x][y].erase(std::remove(grid_xy[x][y].begin(), grid_xy[x][y].end(), obj), grid_xy[x][y].end());
}

void SpacialGrid::removeFromGridXY(void* obj, std::vector<void*>* grid)
{
	grid.erase(std::remove(grid.begin(), grid.end(), obj), grid.end());
}
