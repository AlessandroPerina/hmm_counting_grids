#ifndef LEARNING_H
#define LEARNING_H

#include "general_header.h"

class learning
{
public:
	int m_step_iterations;
	int no_peaks;
	int Z;
	float eps;

	learning(counting_grid*, int, int, float);
	~learning();
	int EStep(counting_grid*, corpus*);
	int MStep(counting_grid*);
	int compute_loglikelihood(counting_grid*,corpus*);
	int delete_posterior();
	static int lognormalizeRows(PWMatrix&);
	static int lognormalizeCols(PWMatrix&);

private:
	PWMatrix accumulator;
	vector< vector<int> > PosteriorPeaks;
	vector< PWMatrix > Posterior;
	vector< SMatrix > PosteriorSparse;
};

#endif