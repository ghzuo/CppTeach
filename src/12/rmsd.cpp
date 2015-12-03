#include "rmsd.h"

int main(){

    Mol ref;
    readOnePdb(cin, ref);
    int index(0);
    cout << index << "  " << 0.0 << endl;

    Mol obj;
    while(readOnePdb(cin, obj))
        cout << ++index << " " << calcRMSD(ref, obj) << endl;
}

bool readOnePdb(istream& is, Mol& mol){

    mol.clear();
    for(string line; getline(is, line); ){
        string prefix;
        istringstream stream(line);
        stream >> prefix;
        if(prefix == "ATOM"){
            string atomName, resName;
            int iatom, ires;
            double x,y,z;
            stream >> iatom >> atomName
                   >> resName >> ires
                   >> x >> y >> z;
            mol.emplace_back(x,y,z);
        } else if(prefix == "TER"){
            break;
        }
    }

    if(mol.empty())
        return false;
    else
        return true;
}

double calcRMSD(const Mol& ref, const Mol& obj){
    Matrix<double, 4, 4> mat;
    mat.setConstant(0.0);
    
    for(int i=0; i<ref.size(); ++i){
        double xm = obj[i].x() - ref[i].x();
        double xp = obj[i].x() + ref[i].x();
        double ym = obj[i].y() - ref[i].y();
        double yp = obj[i].y() + ref[i].y();
        double zm = obj[i].z() - ref[i].z();
        double zp = obj[i].z() + ref[i].z();

        mat(0,0) += (xm*xm + ym*ym + zm*zm);
        mat(1,1) += (xm*xm + yp*yp + zp*zp);
        mat(2,2) += (xp*xp + ym*ym + zp*zp);
        mat(3,3) += (xp*xp + yp*yp + zm*zm);

        mat(0,1) += (zm*yp - ym*zp);
        mat(0,2) += (xm*zp - zm*xp);
        mat(0,3) += (ym*xp - xm*yp);
        mat(1,2) += (xm*ym - xp*yp);
        mat(1,3) += (xm*zm - xp*zp);
        mat(2,3) += (ym*zm - yp*zp);
    }

    for(int i=0; i<4; ++i){
        for(int j=i+1; j<4; ++j){
            mat(j,i) = mat(i,j);
        }
    }

    SelfAdjointEigenSolver<Matrix<double,4,4>> eigensolver(mat);
    double rmsd(numeric_limits<double>::max());
    for(int i=0; i<4; ++i){
        if(abs(eigensolver.eigenvalues()[i]) < rmsd)
            rmsd = abs(eigensolver.eigenvalues()[i]);
    }
    return sqrt(rmsd/ref.size());
}
