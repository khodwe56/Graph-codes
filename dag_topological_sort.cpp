//
// Created by omkarkh1 on 29/10/20.
//

#include<bits/stdc++.h>

using namespace std;
template<typename T>
class Graph{
    map<T,list<T> >l;
public:
    void addEdge(T x,T y,bool bidir = true){
        l[x].push_back(y);
//        if(bidir){
//            l[y].push_back(x);
//        }
    }

    void dfs_util(T node,map<T,int> &visited,list<T> &ordering){
        //cout<<node<<endl;
        visited[node] = 1;
        for(auto nbr : l[node]){
            if(visited[nbr] == 0){
                dfs_util(nbr,visited,ordering);
            }
        }
        ordering.push_front(node);
    }

    void dfs(){
        map<T,int> visited;
        list<T> ordering;
        for(auto p: l){
            T node = p.first;
            if(!visited[node])
                dfs_util(node,visited,ordering);
        }
        for(auto x : ordering){
            cout << x << endl;
        }
    }
};

int main(){
    Graph<string> g;
    g.addEdge("Python","DataProcessing");
    g.addEdge("Python","Pytorch");
    g.addEdge("Python","ML");
    g.addEdge("DataProcessing","ML");
    g.addEdge("ML","DL");
    g.addEdge("DL","FaceRecognition");
    g.addEdge("Dataset","FaceRecognition");
    g.dfs();
    return 0;
}