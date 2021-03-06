//
// Created by omkarkh1 on 28/10/20.
//

#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T> >l;
public:
    void addEdge(T x,T y,bool bidir = true){
        l[x].push_back(y);
        if(bidir){
            l[y].push_back(x);
        }
    }

    void dfs_util(T node,map<T,int> &visited){
        cout<<node<<endl;
        visited[node] = 1;
        for(auto nbr : l[node]){
            if(visited[nbr] == 0){
                dfs_util(nbr,visited);
            }
        }
    }


    void dfs_connected(){
        int cnt = 0;
        map<T,int> visited;
        for(auto node_pair : l){
            if(visited[node_pair.first] == 0) {
                dfs_util(node_pair.first, visited);
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
};


int main(){
    Graph<int> g;
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.addEdge(5,6);
    g.addEdge(3,6);
    g.addEdge(10,11);
    g.dfs_connected();
    return 0;
}
