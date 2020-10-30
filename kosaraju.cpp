//
// Created by omkarkh1 on 30/10/20.
//

/*
 Input:
7 8
2 1
1 0
0 2
0 3
3 5
5 6
6 3
3 4
 */
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[],int node,bool* visited,vector<int> &stack){
    visited[node] = true;
    for(auto nbr : graph[node]){
        if(!visited[nbr]){
            dfs(graph,nbr,visited,stack);
        }
    }
    stack.push_back(node);
}

void dfs2(vector<int> graph[],int node,bool* visited,vector<int> &result){
    visited[node] = true;
    result.push_back(node);
    for(auto nbr : graph[node]){
        if(!visited[nbr]){
            dfs2(graph,nbr,visited,result);
        }
    }
}

void solve(vector<int> graph[],vector<int>rgraph[],int n){
    bool* visited = new bool[n];
    vector<int> stack;
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            dfs(graph,i,visited,stack);
        }
    }

    memset(visited,false,n);
    reverse(stack.begin(),stack.end());
    vector<int> result;
    for(auto node : stack){
        if(!visited[node]){
            result.clear();
            dfs2(rgraph,node,visited,result);
            //cout<<result.size()<<endl;
            for(auto x :  result){
                cout << x << " ";
            }
            cout<<endl;
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
    solve(graph,rgraph,n);
    return 0;
}
