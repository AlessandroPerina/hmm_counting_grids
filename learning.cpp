#include "learning.h"
#include "counting_grid.h"
#include "corpus.h"
#include "general_header.h"

learning::learning(counting_grid* cg, int m_iter = 1, int no_p = 5, float thr = 0.00001 )
{
	m_step_iterations = m_iter;
	Z = cg->Z;
	no_peaks = no_p;
	eps = thr;
};

int learning::EStep(counting_grid* cg, corpus* c)
{
	//this->Posterior = ( *(cg->get_pi()->matrix())*c->counts).array();
	return 0;
};



int learning::lognormalizeRows(PWMatrix &MatArr )
{	
	// ATTENTION: This function lognormalize the ROWS of a eigen array
	MatArr.colwise() -= MatArr.rowwise().maxCoeff();
	MatArr.colwise() -= ((MatArr.exp()).rowwise().sum()).log();
	return 0;
}

int learning::lognormalizeCols(PWMatrix &MatArr)
{
	// ATTENTION: This function lognormalize the ROWS of a eigen array
	MatArr.rowwise() -= MatArr.colwise().maxCoeff();
	MatArr.rowwise() -= ((MatArr.exp()).colwise().sum()).log();
	return 0;
}