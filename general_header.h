#ifdef GENERAL_HEADER_H
#define GENERAL_HEADER_H
#endif

#include <iostream>
#include <map>
#include <algorithm>
#include <Eigen/Dense>
#include <Eigen/SparseCore>
#include <vector>

using namespace Eigen;
using namespace std;

class counting_grid;
class corpus;

typedef Matrix<double, Dynamic, Dynamic> DMatrix;
typedef SparseMatrix<double> SMatrix;
typedef Array<double, Dynamic, Dynamic> PWMatrix;


