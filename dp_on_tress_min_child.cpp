//
// Created by omkarkh1 on 31/10/20.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<int>graph[N];
int dp[N];
void dfs(int curr,int parent){
    dp[curr] = curr;
    for(auto x : graph[curr]){
        if(x != parent){
            dfs(x,curr);
            dp[curr] = min(dp[x],dp[curr]);
        }
    }
}

int main(){
    int n;cin >> n;
    for(int i = 1;i <= n;i++){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1,0);

    for(int i = 0;i<n+1;i++){
        cout<<i<<" "<<dp[i]<<endl;
    }
    return 0;
}
