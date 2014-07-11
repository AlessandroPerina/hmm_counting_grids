#include <iostream>

class counting_grid
{

public:
	matrixd pi;
	matrixd h;
	matrixd accumulator;
	map<int*,int*> lookup; // position --> indeces of window

	int* cg_size;
	int* wd_size;
	int Z;
	int T;

	counting_grid(int,int,int);
	counting_grid();
	virtual ~counting_grid();

	int* get_index_window(int*);
	int sum_in_windows();
}