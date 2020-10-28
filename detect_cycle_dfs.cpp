//
// Created by omkarkh1 on 28/10/20.
//

#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{

public:
    int V;
    list<int> *l;
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(T x,T y,bool bidir = true){
        l[x].push_back(y);
        if(bidir){
            l[y].push_back(x);
        }
    }

    bool contains_cycle(T node,bool* visited,T parent){
        visited[node] = true;
        for(auto nbr : l[node]){
            if(!visited[nbr]){
                bool get_cyc = contains_cycle(nbr,visited,node);
                if(get_cyc){
                    return true;
                }
            }
            else if(nbr != parent){
                return true;
            }
        }

        return false;
    }

    bool detect_cycle(T src){
        bool *visited = new bool[V]{false};
        return contains_cycle(src,visited,-1);
    }
};


int main(){
    Graph<int> g(7);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    g.addEdge(4,2);
    g.addEdge(5,6);
    g.addEdge(3,6);
    cout << g.detect_cycle(2) << endl;
    return 0;
}