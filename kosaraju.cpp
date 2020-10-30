//
// Created by omkarkh1 on 30/10/20.
//

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[],int node,bool* visited,vector<int> &stack){
    visited[node] = true;

}

void solve(vector<int> graph[],vector<int>rgraph[],int n){
    bool* visited = new bool[n];
    vector<int> stack;
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            dfs(graph,i,visited,stack);
        }
    }
}
int main(){
    int n;cin >> n;
    vector<int> graph[n];
    vector<int> rgraph[n];
    int m;cin >> m;
    while(m--){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        rgraph[y].push_back(x);
    }

    return 0;
}
