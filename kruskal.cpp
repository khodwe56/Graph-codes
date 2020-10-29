//
// Created by omkarkh1 on 29/10/20.
//

#include<bits/stdc++.h>

using namespace std;

class DSU{
    int *parent;
    int *rank;
public:
    DSU(int n){
        parent = new int[n];
        rank = new int[n];
        for(int i = 0;i<n;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int x){
        if(parent[x] == -1)
            return x;
        else{
            return parent[x] = find(parent[x]);
        }
    }

    void unite(int x,int y){
        int sx = find(x);
        int sy = find(y);

        if(sx != sy){
            if(rank[sx] < rank[sy]){
                parent[sx] = sy;
                rank[sy] += rank[sx];
            }
            else{
                parent[sy] = sx;
                rank[sx] += rank[sy];
            }
        }
    }
};

class Graph{
    vector<vector<int> >edgeList;
    int V;
public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int u,int v,int w){
        edgeList.push_back({w,u,v});
    }

    int kruskal(){
        sort(edgeList.begin(),edgeList.end());
        int ans = 0;
        DSU s(V);
        for(auto edge : edgeList){
            int w = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(s.find(u) != s.find(v)){
                s.unite(u,v);
                cout<<u<<"->"<<v<<endl;
                ans += w;
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

    cout<<g.kruskal()<<endl;

    return 0;
}