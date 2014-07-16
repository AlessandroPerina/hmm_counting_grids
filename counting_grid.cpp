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
	pi = randbase + (PWMatrix::Random(Z, L) + 1) / 2;
	pi.colwise()  /= pi.colwise().sum();
	
	// Initialization of h
	h = PWMatrix::Zero(Z, L);

	// Intailize the hashmap
	vector<int> pos;
	vector< vector<int> > allcomb; 
	for (int l = 0; l < L; l++) // For every position in the grid
	{
		allcomb.clear(); // D x No_Indeces_per_window_dimension
		pos = this->sub2ind(l);
		for (int d = 0; d < D; d++)
		{
			for (int w = 0; w < wd_size[d]; w++)
			{
				allcomb[d].push_back((pos[d] + w) % cg_size[d]);
			}
		}
		// l = (1,2,0), wd_size = (3,4,2)   => pos[0] = (1,2,3) - pos[1] = (2,3,4,5) - pos[2] = (0,1)
		// Generate all the possible combinations of allcomb picking a value in each dimension of pos
		vector<int> tmp_positions(LW);
		for (int lw = 0; lw<LW; lw++)
		{
			int offset = 1;
			vector<int> tmppos(D);
			for (int p = 0; p < D; p++)
			{
				tmppos[p] = allcomb[p][(lw / offset) % wd_size[p]];
				offset *= wd_size[p];
			}
			tmp_positions[lw] = ind2sub(tmppos); // linearize the index
		}
		// Add the linear positions of the indeces in the window at position l to the hashmap 
		position_lookup.insert(pair <int, vector<int>>(l, tmp_positions));
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

int counting_grid::sum_in_windows()
{
	vector<int> tmp_pos(this->LW);
	for (int l = 0; l < this->L; l++)
	{
		for (int z = 0; z < this->Z; z++)
		{
			int accumulator = 0;
			tmp_pos = this->position_lookup[l];
			for (int i = 0; i < this->LW; i++)
			{
				accumulator += this->pi( z,tmp_pos[i] );
			}
			this->h(z,l) = accumulator;
		}
	}
	return 1;
}