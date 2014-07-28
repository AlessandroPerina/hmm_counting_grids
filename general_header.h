#ifndef GENERAL_HEADER_H
#define GENERAL_HEADER_H
#include <iostream>
#include <map>
#include <algorithm>
#include <Eigen/Dense>
#include <Eigen/SparseCore>
#include <vector>
#include <string>
#include <assert.h>
#include <fstream>
#include <regex>
#include <math.h>  
#endif

using namespace Eigen;
using namespace std;

class counting_grid;
class corpus;

typedef Matrix<double, Dynamic, Dynamic> DMatrix;
typedef SparseMatrix<double> SMatrix;
typedef Array<double, Dynamic, Dynamic> PWMatrix;