#include "general_header.h"
#include "counting_grid.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	if (argc % 2 != 0 || argc < 4)
	{
		cout << "Usage: learn_counting_grid data_file.txt cg_size_1 cg_size_2 ... cg_size_D wd_size_1 wd_size_2 ... wd_size_D " << endl;
		cout << "Window and Grid MUST have the same number of dimensions" << endl;
		return 1;
	}
	char* filename = *(argv + 1);
	int dimensions = ( argc - 2 ) / 2;
	cout << "You are learning a " << dimensions << "-dimensional Counting Grid " << endl;
	vector<int> cgsize(dimensions);
	vector<int> wdsize(dimensions);
	for (int d = 0; d < dimensions; d++)
	{
		cgsize[d] = atoi(*(argv + 2 + d  ));
		wdsize[d] = atoi(*(argv + dimensions + 2 + d));
	}

	/*
	// Creo una matrice 4x4x2
	DMatrix Minput = DMatrix::Random(5, 32);
	cout << "(0,1): " << Minput(0, 1) << endl;
	cout << "(0,2): " << Minput(0, 2) << endl;
	cout << "(0,17): " << Minput(0, 17) << endl;
	vector<int> coord{ 4, 4, 2 };
	counting_grid::print(Minput, coord, 0);
	*/

	counting_grid CG(cgsize, wdsize, 2);



	cout << "Success!" << endl;
	return 0;
}

