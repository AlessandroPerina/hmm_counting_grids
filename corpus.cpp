#include "corpus.h"
#include "general_header.h"

corpus::corpus(string filename)
{
	// Creo un fstream
	std::ifstream in_file(filename);

	smatch result;
	regex pattern_title("\"([^\"]*)\"", regex::icase);
	regex pattern("([0-9]+:[0-9]+)", regex::extended);
	string line;

	int d = 0;
	while (std::getline(in_file, line))
	{
		regex_search(line, result, pattern_title);
		document_names[d] = result.str().substr(1, result.length() - 2);
		cout << "Document name: " << document_names[d];
	}

};