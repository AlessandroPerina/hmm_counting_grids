#include <iostream>
#include <vector>

using namespace std;

int main( int argc, char** argv)
{
	vector<int> pos {1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2};
	vector<int> cg_size {3,3,2};

	cout << "Ultimo " << *(cg_size.end()-1) << endl;
	cout << "Ultimo 2 " << cg_size.back() << endl;

	return 1;
}