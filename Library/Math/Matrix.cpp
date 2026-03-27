#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix {
    int n;
    vector<vector<long long>> mat;

    Matrix(int size) {
        n = size;
        mat.assign(n, vector<long long>(n, 0));
    }

    void makeIdentity() {
        for (int i = 0; i < n; i++) {
            mat[i][i] = 1;
        }
    }

    Matrix operator*(const Matrix &other) const {
        Matrix res(n);
        
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (mat[i][k] == 0) continue; 
                
                for (int j = 0; j < n; j++) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};
