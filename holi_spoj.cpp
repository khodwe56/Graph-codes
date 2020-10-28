//
// Created by omkarkh1 on 28/10/20.
//
//Check commits
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    int V;
    list<pair<T,T> > *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<pair<T,T> >[V];
    }
    void addEdge(T x,T y,int w,bool bidir = true){
        l[x].push_back({y,w});
        if(bidir){
            l[y].push_back({x,w});
        }
    }

    int dfs_util(T node,int* visited,int *count,int &ans){
        visited[node] = 1;
        count[node] = 1;
        for(auto nbr_pair : l[node]){
            T nbr = nbr_pair.first;
            if(visited[nbr] == 0){
                count[node] += dfs_util(nbr,visited,count,ans);
                ans += 2 * min(count[nbr],V - count[nbr]) * nbr_pair.second;
            }
        }

        return count[node];
    }

    int dfs(T src){
        int *visited =  new int[V]{0};
        int *count = new int[V]{0};
        int ans = 0;
        dfs_util(src,visited,count,ans);
        return ans;
    }
};


int main(){
    Graph<int> g(4);
    g.addEdge(0,1,3);
    g.addEdge(1,2,2);
    g.addEdge(3,2,2);
   // g.addEdge(3,6);
    cout<< g.dfs(0)<<endl;
    return 0;
}