//
// Created by omkarkh1 on 29/10/20.
//

#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    list<pair<int,int> > l;
    Graph(int V){
        this->V = V;
    }
    void addEdge(int u,int v){
        l.push_back({u,v});
        //l.push_back({v,u});
    }

    int findSet(int i,int *parent){
        if(parent[i] == -1){
            return i;
        }
        return parent[i] = findSet(parent[i],parent);
    }

    void unionOfSets(int x,int y,int *parent,int *rank){
        int xs = findSet(x,parent);
        int ys = findSet(y,parent);
        if(xs != ys)
            if(rank[xs] < rank[ys]){
                parent[xs] = ys;
                rank[ys] += rank[xs];
            }else{
                parent[ys] = xs;
                rank[xs] += rank[ys];
            }
    }
    bool contains_cycle(){
        int *parent = new int[V];
        int *rank = new int[V];
        for(int i = 0;i<V;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
        for(auto edge : l){
            int x = edge.first;
            int y = edge.second;

            int xs = findSet(x,parent);
            int ys = findSet(y,parent);

            if(xs != ys){
                unionOfSets(xs,ys,parent,rank);
            }else{
                return true;
            }
        }

        delete [] parent;
        return false;
    }

};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
   // g.addEdge(1,2);
    //g.addEdge(1,3);
    cout<<g.contains_cycle()<<endl;
    return 0;
}