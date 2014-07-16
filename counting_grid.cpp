#include "counting_grid.h"
#include "general_header.h"

counting_grid::counting_grid(vector<int> cgsize, vector<int> wdsize, int Z_init) : eps(0.0000001)
{
	cg_size = cgsize;
	wd_size = wdsize;
	Z = Z_init;
	D = cgsize.size();
	L = 1;
	LW = 1;
	for (size_t i = 0; i < cgsize.size(); i++)
		L *= cgsize.at(0);

	for (size_t i = 0; i < wdsize.size(); i++)
		LW *= wdsize.at(0);

	// Initialization of pi
	int randbase = 0;
	//pi = randbase + ((PWMatrix::Random(Z, L) + 1) / 2);
	pi = randbase + ((PWMatrix::Random(Z, L) + 1) / 2);
	print(pi, cg_size, 0);
	print(pi, cg_size, 1);

	PWMatrix tmp = ( eps + pi.colwise().sum());
	for (int i = 0; i < tmp.cols(); i++)
		cout << tmp(i) << " ";

	pi.rowwise() /= (eps + pi.colwise().sum());
	print(pi, cg_size, 0);
	print(pi, cg_size, 1);

	// Initialization of h
	h = PWMatrix::Zero(Z, L);
	this->sum_in_windows(); // Warning. The object is still under construction, so be sure that you have created everything...
	h.colwise() /= h.colwise().sum().transpose();
	
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
	
}

counting_grid::~counting_grid()
{
	pi.resize(0, 0);
	h.resize(0, 0);
	position_lookup.clear();
}

int counting_grid::ind2sub(vector<int> pos)
{
	int linear_index = pos[0];
	int offset = this->cg_size[0];

	for (size_t i = 1; i<pos.size(); i++)
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
			double accumulator = 0;
			tmp_pos = this->position_lookup[l];
			for (int i = 0; i < this->LW; i++)
			{
				accumulator += this->pi( z,tmp_pos[i] );
			}
			this->h(z,l) = accumulator;
		}
	}
	return 0;
}

int counting_grid::print(DMatrix Minput, vector<int> siz, int z)
{
	int Z = Minput.rows();
	int L = Minput.cols();

	assert(siz.size() == 2 || siz.size() == 3);
	Matrix<double, Dynamic, Dynamic> M(siz[0], siz[1]);
	int locations_per_slice;
	int slices;
	if (siz.size() == 3)
	{
		locations_per_slice = L / siz.back();
		slices = siz.back();
	}
	else
	{
		locations_per_slice = L;
		slices = 1;
	}

	for (int s = 0; s < slices; s++) // or *(cg_size.end()-1) 
	{
		M.fill(0);
		for (int l = 0; l < locations_per_slice; l++)
		{
			M(l) = (double)Minput(z, l + s*locations_per_slice );
		}
		
		for (int r = 0; r < siz[0]; r++)
		{
			for (int c = 0; c < siz[1]; c++)
			{
				cout << M(r,c) << " ";
			}
			cout << endl;
		}
		cout << endl;

	}

	M.resize(0, 0);
	return 1;
}