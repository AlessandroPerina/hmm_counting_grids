#ifndef CORPUS_H
#define CORPUS_H

#include "general_header.h"

class corpus
{
public:
	string corpus_name;
	map<int,string> document_names;
	SMatrix counts; // Sparse Matrix
	vector< map<int,int> > vector_counts;

	int T;
	int Z;
	corpus(string);
}; 
#endif