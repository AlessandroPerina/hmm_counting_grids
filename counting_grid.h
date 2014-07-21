#ifndef COUNTINGGRID_H
#define COUNTINGGRID_H

#include <iostream>
#include "general_header.h"

class counting_grid
{

public:
	map<int,vector<int>> position_lookup; // position --> indeces of window

	vector<int> cg_size;
	vector<int> wd_size;
	int Z;
	int L;
	int D;
	int LW;
	double eps;

	counting_grid(vector<int>, vector<int>, int);
	virtual ~counting_grid();

	int sum_in_windows();

	// Utility functions
	int ind2sub(vector<int>);
	vector<int> sub2ind(int);
	static int print(DMatrix, vector<int>, int);
	int set_pi(PWMatrix*);
	int get_pi(PWMatrix*);
	int get_h(PWMatrix*);

private:
	PWMatrix pi;
	PWMatrix h;
};

#endif