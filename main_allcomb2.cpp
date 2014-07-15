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
	int LW = 27;

	for (int p = 0; p < D; p++)
	{
		for (int w = 0; w < wd_size[p]; w++)
		{
			cout << (pos[p] + w ) % cg_size[p] << endl;
			allcomb[p].push_back((pos[p] + w ) % cg_size[p]);
		}
	}

	vector<int> positions;
	for (int l=0; l<LW;l++)
	{
		int offset = 1;
		vector<int> tmppos(D);
		for (int p = 0; p < D; p++)
		{
			tmppos[p] = ( l / offset ) % wd_size[p];
			offset *= wd_size[p];
		}
		cout << tmppos[0] << " " << tmppos[1] << " " << tmppos[2] << endl;
	}


}