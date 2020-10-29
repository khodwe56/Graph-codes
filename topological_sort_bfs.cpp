//
// Created by omkarkh1 on 30/10/20.
//

#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
    }

    void topological_sort(){
        int indegree[V];
        for(int i = 0;i<V;i++){
            indegree[i] = 0;
        }
        for(int i = 0;i<V;i++){
            for(auto x : l[i]){
                indegree[x]++;
            }
        }

        queue<int> q;
        for(int i = 0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ordering;
        while (!q.empty()){
            int node = q.front();
            ordering.push_back(node);
            q.pop();
            for(auto x : l[node]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }

        for(auto node : ordering){
            cout<<node<<endl;
        }
    }
};
int main(){
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(4,5);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(2,3);
    g.topological_sort();
    return 0;
}
