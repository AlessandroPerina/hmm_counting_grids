#include <Eigen/Dense>
#include <complex>
#include <iostream>

using namespace std;
using namespace Eigen;
typedef Eigen::Array<int, Dynamic, Dynamic> PWMatrix;

int main( int argc, char** argv)
{
	if (argc != 6)
	{
		cout << "Usage: learn_counting_grid datafile.txt CG_ROWS CG_COLS WD_ROWS WD_COLS" << endl;
		return 1; 
	}

	char* filename = *(argv+1);
	const int cg_rows = atoi(*(argv+2));
	const int cg_cols = atoi(*(argv+3));	
	const int wd_rows = atoi(*(argv+4));
	const int wd_cols = atoi(*(argv+5));

	PWMatrix m = ( PWMatrix::Random(wd_rows,wd_cols) +1 ) / 2;
	

	cout << "Prova della libreria eigen " << wd_rows << endl;
	
	m(0,0) = 3;
	m(1,0) = 2;
	m(0,1) = -1;
	m(1,1) = m(1,0) + m(0,1);

	cout << "Er matricione: " << endl << m  << endl;
	cout << "Er matricione: " << endl << m .block(1,1,2,2) << endl;

	int a[]={0,1,2};
	cout << "Er matricione: " << endl << m(0) << endl;
	cout << "Er matricione: " << endl << m(1) << endl;
	
	return 0; // Il return standard e' 0! 
}