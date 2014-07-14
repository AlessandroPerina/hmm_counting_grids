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
	pi.colwise()  /= pi.colwise().sum();

	PWMatrix h;
}

counting_grid::~counting_grid()
{

}

int counting_grid::ind2sub(vector<int> pos)
{
	int linear_index = pos[0];
	int offset = this->cg_size[0];

	for (int i = 1; i<pos.size(); i++)
	{
		linear_index += pos[i]*offset;
		offset *= this->cg_size[i];
	}
	return linear_index;
}

vector<int> counting_grid::sub2ind(int)
{

}