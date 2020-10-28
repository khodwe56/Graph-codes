//
// Created by omkarkh1 on 28/10/20.
//
#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    list<int> *l;
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int a,int b){
        l[a].push_back(b);
        l[b].push_back(a);
    }

    void print(){
        for(int i = 0;i<V;i++){
            for(int nbr : l[i]){
                cout << i <<":"<<nbr<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(4);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.print();
    return 0;
}
