#include "general_header.h"
#include "counting_grid.h"
#include "corpus.h"
#include "learning.h"
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
	cout << "Input file: " << (string) filename << endl;
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


	corpus cp( (string) filename);
	counting_grid CG(cgsize, wdsize, cp.Z );

	cout << "Prova matrix multiplication" << endl;
	cout << "counts dimensions: " << cp.counts->rows() << " " << cp.counts->cols() << endl;
	cout << "h dimensions: " << CG.get_h()->rows() << " " << CG.get_h()->cols() << endl;
	PWMatrix posterior = ((*cp.counts)*(log(*(CG.get_h())).matrix()));
	counting_grid::print(posterior, cgsize, 0);


	posterior.colwise() -= posterior.rowwise().maxCoeff();
	counting_grid::print(posterior, cgsize, 0);
	
	posterior.colwise() -= ((posterior.exp()).rowwise().sum()).log();
	counting_grid::print(posterior, cgsize, 0);

	posterior = ((*cp.counts)*(log(*(CG.get_h())).matrix()));
	learning::lognormalizeRows( posterior );
	counting_grid::print(posterior, cgsize, 0);

	cout << posterior.exp().sum() << endl;

	cout << "Success!" << endl;
	system("PAUSE"); // NOT PORTABLE! Don't do it
	return 0;
}

