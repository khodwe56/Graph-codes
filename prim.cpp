//
// Created by omkarkh1 on 29/10/20.
//
#include<bits/stdc++.h>

using namespace std;

class Graph{
    vector<pair<int,int> > *l;
    int V;
public:
    Graph(int V){
        this->V = V;
        l = new vector<pair<int,int>>[V];
    }

    void addEdge(int u,int v,int w){
        l[u].push_back({v,w});
        l[v].push_back({u,w});
    }

    int prim_mst(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > pq;
        bool *visited = new bool[V];
        for(int i = 0;i<V;i++){
            visited[i] = false;
        }
        pq.push({0,0});
        int ans = 0;
        while(!pq.empty()){
            auto best = pq.top();
            pq.pop();
            int tp = best.first;
            int wt = best.second;

            if(visited[tp]){
                continue;
            }

            ans += wt;
            visited[tp] = true;

            for(auto x: l[tp]){
                if(visited[x.first] == false){
                    pq.push({x.first,x.second});
                }
            }
        }
        return ans;
    }

};

int main(){
    Graph g(4);

    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);

    cout<<g.prim_mst()<<endl;
    return 0;
}