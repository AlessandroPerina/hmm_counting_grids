#include "corpus.h"
#include "general_header.h"

corpus::corpus(string filename)
{
	// Creo un fstream
	corpus_name = filename;
	std::ifstream in_file(filename);
	if (!in_file.is_open())
	{
		throw exception("Failed to open the input file.");
	}

	smatch result;
	regex pattern_title("\"([^\"]*)\"", regex::icase);
	regex pattern_count("([0-9]+:[0-9]+)", regex::extended);
	string line;

	int d = 0;
	while ( getline(in_file, line))
	{
		regex_search(line, result, pattern_title);
		document_names.insert( pair<int,string>(d,result.str().substr(1, result.length() - 2)));
		d++;
	}
	T = d;

	// Leggi i counts
	// Sposto all'inizio del file
	Z = 0;
	in_file.clear();
	in_file.seekg(0, std::ios::beg);

	d = 0;
	int word_id;
	int count;
	vector< map<int, int> > vector_counts(T);

	while (getline(in_file, line))
	{
		regex_iterator<std::string::iterator> rit(line.begin(), line.end(), pattern_count);
		std::regex_iterator<std::string::iterator> rend; // Ilterator empty

		string tmp_match;
		while (rit != rend) {
			sscanf(rit->str().c_str(), "%10d:%10d", &word_id, &count);
			vector_counts[d].insert(pair<int, int>(word_id-1, count));
			if (word_id > Z)
				Z = word_id;
			++rit;
		}
		d++;
	}
	cout << "Documents: " << T << endl;
	cout << "Features: " << Z << endl;

	// Genero la counts matrix perchè ora so quante feature ho!
	SMatrix counts(T, Z);
	in_file.clear();
	in_file.seekg(0, std::ios::beg);

	d = 0;
	while (getline(in_file, line))
	{
		regex_iterator<std::string::iterator> rit(line.begin(), line.end(), pattern_count);
		std::regex_iterator<std::string::iterator> rend; // Ilterator empty

		string tmp_match;
		while (rit != rend) {
			sscanf(rit->str().c_str(), "%10d:%10d", &word_id, &count);
			counts.insert(d, word_id-1) = count;
			++rit;
		}
		d++;
	}
};