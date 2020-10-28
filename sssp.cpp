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

    void bfs(T src){
        map<T,int> visited;
        queue<T> q;
        for(auto node_pair : l){
            visited[node_pair.first] = INT_MAX;
        }
        q.push(src);
        visited[src] = 0;

        while(q.empty() == false){
            T node = q.front();
            q.pop();
            for(auto nbr : l[node]){
                if(visited[nbr] == INT_MAX){
                    visited[nbr] =  visited[node] + 1;
                    q.push(nbr);
                }
            }
        }
        for(auto node_pair : visited){
            cout<<node_pair.first << " " << visited[node_pair.first] << endl;
        }
    }
};


int main(){
    Graph<int> g;
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.addEdge(5,6);
    g.addEdge(3,6);
    g.bfs(3);
    return 0;
}
