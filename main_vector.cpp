#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	vector<int> cg_size(3);
	cg_size = {5,5,5};
	vector<int> pos(3);
	pos = {1,2,1};

	cout << "Pos: " << pos[1] << endl;

	int linear_index = pos[0];
	int offset = cg_size[0];

	for (int i = 1; i<pos.size(); i++)
	{
		linear_index += pos[i]*offset;
		offset *= cg_size[i];
	}

	cout << "linear index = " << linear_index << endl;

	return linear_index;
}