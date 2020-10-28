//
// Created by omkarkh1 on 28/10/20.
//

/*
 Input:
 5 6
 1 2
 1 3
 2 4
 2 5
 4 5
 5 3
 */

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> graph[],int index,int n,int &ans){
    vector<int> dist(n+1,INT_MAX);
    queue<int> q;
    q.push(index);
    dist[index] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto nbr : graph[curr]){
            if(dist[nbr] == INT_MAX){
                dist[nbr] = dist[curr] + 1;
                q.push(nbr);
            }
            else if(dist[curr] <= dist[nbr]){
                ans = min(ans,dist[curr] + dist[nbr] + 1);
            }
        }
    }
    
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> graph[n+1];
    while(m--){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int ans = n+1;
    for(int i = 1;i <= n;i++){
        bfs(graph,i,n,ans);
    }

    if(ans == n+1){
        cout<<"No Cycle"<<endl;
    }
    else{
        cout<<"Shortet Cycle is of length : "<<ans<<endl;
    }
    return 0;
}
