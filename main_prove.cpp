	
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main(int argc, char** argv)
{
	int L = 32;
	vector<int> cg_size {4,4,2};
	int linear_index = atoi( *(argv+1) );	
	vector<int> pos;
	int offset = 1;
	int dividi;
	int divisione_intera;

	for (vector<int>::reverse_iterator it = cg_size.rbegin(); it != cg_size.rend(); it++)
	{
		offset *= *it;
		dividi = (L / offset);
		cout << "Dividi per: " << dividi << endl;
		divisione_intera = (linear_index-1) / dividi;
		cout << "Divisione intera: " << divisione_intera << endl;	
		pos.push_back( divisione_intera );
		linear_index -= divisione_intera*dividi;
		cout << "Linear index: " << linear_index << endl;
	}

	reverse(pos.begin(), pos.end());	

	for (vector<int>::iterator it = pos.begin(); it != pos.end(); ++it)
	{
		cout << *it;
	}
	cout << endl;

}
