#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main(int argc, char** argv)
{

	int D = 3;
	vector<int> pos {0,1,8};
	vector<int> wd_size {3,3,3};
	vector<int> cg_size {10,10,10};		
	vector< vector<int> > allcomb(D);
	allcomb.clear();

	for (int p = 0; p < D; p++)
	{
		for (int w = 0; w < wd_size[p]; w++)
		{
			cout << (pos[p] + w ) % cg_size[p] << endl;
			allcomb[p].push_back((pos[p] + w ) % cg_size[p]);
		}
	}

	for (int p = 0; p < D; p++)
	{
		for (int w = 0; w < wd_size[p]; w++)
		{
			cout << allcomb[p][w] << " ";
		}
		cout << endl;
	}


}