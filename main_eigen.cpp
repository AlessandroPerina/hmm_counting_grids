#include <Eigen/Dense>
#include <iostream>

using namespace std;
using Eigen::MatrixXd;

int main( int argc, char** argv)
{

	cout << "Prova della libreria eigen" << endl;
	Eigen::Matrix<int, 2, 2> m;
	m(0,0) = 3;
	m(1,0) = 2;
	m(0,1) = -1;
	m(1,1) = m(1,0) + m(0,1);
	cout << "Er matricione: " << endl << m  << endl;
	return 1;
}