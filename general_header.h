#ifdef GENERAL_HEADER_H
#define GENERAL_HEADER_H
#endif

#include <iostream>
#include <map>
#include <Eigen/Dense>
#include <Eigen/SparseCore>
#include <vector>

using namespace Eigen;
using namespace std;

class counting_grid;
class corpus;

#define CGr 32
#define CGw 32
#define Wr 5
#define Wr 5

typedef Matrix<double, Dynamic, Dynamic> DMatrix;
typedef SparseMatrix<double> SMatrix;
typedef Array<double, Dynamic, Dynamic> PWMatrix;


