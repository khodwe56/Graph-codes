//
// Created by omkarkh1 on 07/11/20.
//

#include <bits/stdc++.h>
using namespace std;

struct sparse_table{
    vector<vector<int>> mat;
    vector<int> p2;
    int n,m;
    void init(int _n,int _m){
        n = _n;
        m = _m;
        p2.resize(n+1);
        mat.resize(n,vector<int>(m));
        for(int i = 1;i <= n;i++){
            p2[i] = p2[i/2] + 1;
        }
    }

    void build(int a[]){
        for(int i = 0;i<n;i++){
            mat[i][0] = a[i];
        }
        for(int j = 1; j < m;j++){
            for(int i = 0;i + (1 << j) - 1 < n;i++)
            mat[i][j] = min(mat[i][j-1],mat[i + (1 << (j-1))][j-1])
        }
    }

    int query(int l,int r){
        int pw = p2[r-l];
        return min(mat[l][pw],mat[r - (1 << pw) + 1][pw]);
    }
};
int main(){

    return 0;
}