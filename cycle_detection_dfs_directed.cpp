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
       // l[b].push_back(a);
    }

    bool cycle_helper(int node,bool *visited,bool *stack){
        stack[node] = true;
        visited[node] = false;
        for(auto nbr : l[node]){
            if(stack[nbr] == true){
                return true;
            }
            else if(visited[nbr] == false){
                bool cm = cycle_helper(nbr,visited,stack);
                if(cm)
                    return true;
            }
        }

        stack[node] = false;
        return false;
    }

    bool containsCycle(){
        bool *visited = new bool[V];
        bool *stack = new bool[V];
        return cycle_helper(0,visited,stack);
    }
};

int main(){
    Graph g(5);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.addEdge(0,1);
    g.addEdge(3,4);
    //g.addEdge(4,0);
    cout << g.containsCycle()<<endl;
    return 0;
}
