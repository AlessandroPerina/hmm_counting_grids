#include "general_header.h"
#include "counting_grid.h"

counting_grid::counting_grid(vector<int> cgsize, vector<int> wdsize, int Z_init)
{
	cg_size = cgsize;
	wd_size = wdsize;
	Z = Z_init;
	D = cgsize.size();
	L = 1;
	LW = 1;
	for (int i = 0; i < cgsize.size(); i++)
		L *= cgsize.at(0);

	for (int i = 0; i < wdsize.size(); i++)
		LW *= wdsize.at(0);

	// Initialization of pi
	int randbase = 3;
	PWMatrix pi = randbase + (PWMatrix::Random(Z, L) + 1) / 2;
	pi.colwise()  /= pi.colwise().sum();


	// Intailize the hashmap
	vector<int> pos;
	vector< vector<int> > allcomb; // Spazio tra i vettori!

	for (int l = 0; l < L; l++)
	{
		allcomb.clear();

		pos = this->sub2ind(l);
		for (int p = 0; p < D; p++)
		{
			for (int w = 0; w < wd_size[p]; w++)
			{
				allcomb[p].push_back((pos[p] + w) % cg_size[p]);
			}
		}


	}
	

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

vector<int> counting_grid::sub2ind(int linear_index)
{
	// Debugged -> see main_sub2ind; 
	vector<int> pos;
	int offset = 1;
	int dividi;
	int divisione_intera;

	for (vector<int>::reverse_iterator it = this->cg_size.rbegin(); it != this->cg_size.rend(); it++)
	{
		offset *= *it;
		dividi = (this->L / offset);
		divisione_intera = (linear_index - 1) / dividi;

		pos.push_back(divisione_intera);
		linear_index -= divisione_intera*dividi;
	}
	reverse(pos.begin(), pos.end());
	return pos;
}