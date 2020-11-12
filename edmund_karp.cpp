//
// Created by omkarkh1 on 12/11/20.
//

#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

bool bfs(int **residual_capacity,int src,int sink,int n,int *parent){
    int visited[n];
    queue<int>q;
    q.push(src);
    visited[src] = true;
    bool foundAugmentedPath = false;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0;v<n;v++){
            if(visited[v] == false and residual_capacity[u][v] > 0){
                parent[v] = u;
                visited[v] = true;
                q.push(v);
                if(v == sink){
                    foundAugmentedPath = true;
                    break;
                }
            }
        }
    }
    return foundAugmentedPath;
}

void printAugmentedPath(vector<vector<int> >augmentedPaths){
    for (int i = 0;i<augmentedPaths.size();i++){
        for(int j = 0;j<augmentedPaths[i].size();j++){
            cout<<augmentedPaths[i][j]<<",";
        }
        cout<<endl;
    }
}

int max_flow(int **capacity,int src,int sink,int n){
    int **residualCapacity = new int*[n];
    for(int i = 0;i<n;i++){
        residualCapacity[i] = new int[n];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j < n;j++){
            residualCapacity[i][j] = capacity[i][j];
        }
    }
    int *parent = new int[n];
    vector<vector<int> > augmentedPaths;
    int maxFlow = 0;
    while (bfs(residualCapacity,src,sink,n,parent)){
        vector<int> currAugPath;
        int flow = INT_MAX;
        //Check Variables.
        int v = sink;
        while (v != src){
            currAugPath.push_back(v);
            int u = parent[v];
            if(flow > residualCapacity[u][v]){
                flow = residualCapacity[u][v];
            }
            v = u;
        }
        currAugPath.push_back(src);
        reverse(currAugPath.begin(),currAugPath.end());
        augmentedPaths.push_back(currAugPath);

        v = sink;
        while (v != src){
            int u = parent[v];
            residualCapacity[u][v]-=flow;
            residualCapacity[v][u]+=flow;
            v = u;
        }
    }
    printAugmentedPath(augmentedPaths);
    return maxFlow;
}
int main(){
    int v,e;
    cin >> v >> e;
    int **capacity = new int *[v];
    for(int i = 0;i<v;i++){
        capacity[i] = new int[v];
    }
    for(int i = 0;i<e;i++){
        int u,y,w;
        cin >> u >> y >> w;
        capacity[u][y] = w;
    }
    cout<<max_flow(capacity,0,1,v)<<endl;
    return 0;
}

/*
 Input
 5 7
 0 2 100
 0 3 50
 2 3 50
 2 4 50
 3 4 100
 2 1 50
 4 1 75
 */