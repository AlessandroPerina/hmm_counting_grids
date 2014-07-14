#include "general_header.h"
#include "counting_grid.h"

counting_grid::counting_grid(vector<int> cgsize, vector<int> wdsize, int Z)
{
	int randbase = 3;

	L = 1;
	LW = 1;
	for (int i = 0; i < cgsize.size(); i++)
		L *= cgsize.at(0);

	for (int i = 0; i < wdsize.size(); i++)
		LW *= wdsize.at(0);

	PWMatrix pi = randbase + (PWMatrix::Random(Z, L) + 1) / 2;
	pi = pi.col

	PWMatrix h;
}

counting_grid::~counting_grid()
{

}

int counting_grid::ind2usb(Coordinate pos)
{
	int linear_index = (pos[1] - 1)*this->

}

Coordinate counting_grid(int)
{


}