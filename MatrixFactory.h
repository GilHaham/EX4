//
// Created by meir on 09/01/19.
//

#ifndef EX4_MATRIXFACTORY_H
#define EX4_MATRIXFACTORY_H

#include <vector>

using namespace std;



class MatrixFactory {
public:
    int getSizeOfMAtrix() const;

    const vector<vector<int>> &getTheMatrix() const;

private:
    int sizeOfMAtrix;
    vector<vector<int>> theMatrix;

public:





};


#endif //EX4_MATRIXFACTORY_H
