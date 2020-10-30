//
// Created by omkarkh1 on 30/10/20.
//

#include<bits/stdc++.h>
#define inf 9999
using namespace std;

vector<vector<int> > floyd_warshall(vector<vector<int> > graph){
    vector<vector<int> > dp(graph);
    int V = dp.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
            }
        }
    }
    return dp;
}

int main(){

    vector<vector<int> > graph = {
            {0,inf,-2,inf},
            {4,0,3,inf},
            {inf,inf,0,2},
            {inf,-1,inf,0}
    };

    auto result = floyd_warshall(graph);
    for(int i = 0;i<result.size();i++){
        for (int j = 0; j < result.size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}