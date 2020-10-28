//
// Created by omkarkh1 on 28/10/20.
//

#include<bits/stdc++.h>

//void dfs_helper(int i, int *pInt, int n);

using namespace std;

bool dfs_helper(vector<int> graph[],int node, int *visited, int color,int parent) {
    visited[node] = color;
    for(auto nbr : graph[node]){
        if(visited[nbr] == 0){
            bool sp = dfs_helper(graph,nbr,visited,3 - color,node);
            if(!sp){
                return false;
            }
        }
        else if(nbr != parent and visited[nbr] == color){
            return false;
        }
    }

    return true;
}


bool dfs(vector<int> graph[],int n){
    int *visited = new int[n]{0};
    int color = 1;
    cout << dfs_helper(graph,0,visited,color,-1) << endl;
}


int main(){
    int n,m;cin >> n >> m;
    vector<int> graph[n];
    while(m--){
        int x,y;cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(graph,n);
    return 0;
}