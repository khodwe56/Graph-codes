//
// Created by omkarkh1 on 30/10/20.
//
#include<bits/stdc++.h>

using namespace std;

template<typename T>

class Graph{
    unordered_map<T,list<pair<T,int> > > l;
public:
    void addEdge(T u,T v,int wt,bool bidir = true){
        l[u].push_back({v,wt});
        if(bidir){
            l[v].push_back({u,wt});
        }
    }

    void printAdj(){
        for(const auto& x : l){
            int node = x.first;
            cout<<node<<" :::>"<<endl;
            for(auto q : x.second){
                cout<<q.first<<" Wt: "<<q.second<<endl;
            }
            cout<<endl;
        }
    }


    void djikastra(T src){
        unordered_map<T,int> dist;
        for(auto j : l){
            dist[j.first] = INT_MAX;
        }
        set<pair<T,int>> s;
        dist[src] = 0;
        s.insert({0,src});

        while(s.empty() == false){
            auto p = *(s.begin());
            T node = p.second;
            int nd =  p.first;
            s.erase(s.begin());

            for(auto node_pair : l[node]){
                if(nd + node_pair.second < dist[node_pair.first]){
                    auto f = s.find({node_pair.second,node_pair.first});
                    if(f != s.end()){
                        s.erase(f);
                    }
                    dist[node_pair.first] = nd + node_pair.second;
                    s.insert({dist[node_pair.first],node_pair.first});
                }
            }
        }
        cout <<"From Source :"<<endl;
        for(auto d : dist){
            cout<<d.first << " -> " << d.second << endl;
        }
    }
};
int main(){

    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    //g.printAdj();
    g.djikastra(1);
    return 0;
}
