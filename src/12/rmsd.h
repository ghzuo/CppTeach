#ifndef RMSD_H
#define RMSD_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

typedef Matrix<double, 3, 1> Site;
typedef vector<Site> Mol;

bool readOnePdb(istream& is, Mol& mol);
double calcRMSD(const Mol& ref, const Mol& obj);

#endif
