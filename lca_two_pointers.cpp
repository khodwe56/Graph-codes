//
// Created by omkarkh1 on 09/11/20.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
vector<int> graph[N];
int par[N];
int dep[N];
void dfs(int curr,int parent){
    par[curr] = parent;
//    if(curr != parent){
//
//    }
    for(auto node : graph[curr]){
        if(node != parent){
            dep[node] = dep[curr] + 1;
            dfs(node,curr);
        }

    }
}

int lca_brute(int x,int y){
    if(x == y)
        return x;
    if(dep[x] < dep[y]){
        swap(x,y);
    }
    while(dep[x] > dep[y]){
        x = par[x];
    }
    while(x != y){
        x = par[x];y = par[y];
    }
    return x;
}

int main(){

    int n;cin >> n;
    for(int i = 1;i<n;i++){
        int x,y;cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1,0);
    cout<<lca_brute(18,16)<<endl;
    return 0;
}

/*
 Input
 19
 1 2
 2 4
 2 5
 5 6
 6 7
 6 8
 6 9
 1 3
 3 10
 3 11
 10 17
 11 12
 17 18
 17 19
 12 13
 12 14
 12 15
 15 16
 */