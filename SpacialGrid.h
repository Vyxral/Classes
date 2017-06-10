#pragma once

#include <vector>


class SpacialGrid
{

	private :
		unsigned int _width;
		unsigned int _height;
		std::vector<std::vector<std::vector<void*>>> grid_xy;

	public :
		SpacialGrid();
		SpacialGrid(unsigned int, unsigned int);

		unsigned int getWidth();
		unsigned int getHeight();
		std::vector<void*>* getGridXY(unsigned int, unsigned int);

		void addToGridXY(void*, unsigned int, unsigned int);
		void addToGridXY(void*, std::vector<void*>*);
		void removeFromGridXY(void*, unsigned int, unsigned int);
		void removeFromGridXY(void*, std::vector<void*>*);
};