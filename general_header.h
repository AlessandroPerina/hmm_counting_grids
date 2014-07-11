#ifdef GENERAL_HEADER_H
#define GENERAL_HEADER_H
#endif

#include <iostream>
#include <map>
#include <Eigen/Dense>
#include <Eigen/SparseCore>

using namespace Eigen;
using namespace std;

class counting_grid;
class corpus;

#define CGr 32
#define CGw 32
#define Wr 5
#define Wr 6

typedef Matrix<double, Dynamic, Dynamic> matrixd; 
typedef SparseMatrix<double> matrixs;
typedef Array<double, Dyanmic, Dynamic> arrayd;

