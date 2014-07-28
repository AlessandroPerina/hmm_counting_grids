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

int learning::lognormalize(Array<float, Dynamic, Dynamic>* Mat, int side)
{
	Mat->array().colwise() -= Mat->array().rowwise().maxCoeff();
	int norm_factor = eigen::sum( Mat->array().colwise() -= Mat->array().rowwise().maxCoeff());


}
