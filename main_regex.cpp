#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	string str = "\"Merdaccia\" 1:3 3:1 12:2 13:1 6:5";
	cout << str << endl;
	string str2 = "Cicciopandoro";
	smatch result;
	regex pattern("([0-9]+:[0-9]+)", regex::extended);

	regex pattern_title("\"([^\"]*)\"", regex::icase);
	regex_search(str, result, pattern_title);
	cout << result[0] << endl;
	//regex pattern_counts("[0-9]+:[0-9]+");
	regex_iterator<std::string::iterator> rit(str.begin(), str.end(), pattern);
	std::regex_iterator<std::string::iterator> rend; // Ilterator empty

	int word_id;
	int count;
	string tmp_match;
	while (rit != rend) {
		std::cout << rit->str() << std::endl;
		sscanf(rit->str().c_str(), "%10d:%10d", &word_id, &count);
		cout << word_id << endl;
		++rit;
	}

	system("PAUSE");
	return 0;
}