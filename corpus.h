#include "general_header.h"

class corpus
{
public:
	string corpus_name;
	vector<string> document_names;
	SMatrix counts; // Sparse Matrix
	vector< map<int, vector<int> > > vector_counts;

	int T;
	int Z;
	corpus(string );
	~corpus();
};