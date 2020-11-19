//
// Created by omkarkh1 on 19/11/20.
//

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100002;
vector<int> graph[N];
//vector<int> visited(N,0);

//int cnt = 0;
void dfs(int node,int &cnt,vector<int> &visited){
    //cout<<node<<endl;
    visited[node] = 1;
    for(auto x : graph[node]){
        if(visited[x] == 0){
            cnt++;
            dfs(x,cnt,visited);
        }

    }
    //return cnt;
}

pair<int,int> solve(int n){
    //int count = 0;
    vector<int> visited(N,0);
    vector<int>counter;
    for(int i = 0;i<n;i++){
        if(visited[i] == 0){
            int cnt = 1;
            dfs(i,cnt,visited);
            counter.push_back(cnt);
        }
    }
    int f = counter.size();
    int ans = 1;
    for(auto x : counter){
        ans = (ans*x)%(1000000007);
    }
    int s = ans;
    pair<int,int>res = make_pair(f,s);
    return res;
}

int32_t main(){
    int t;cin >> t;
    while(t--){
       // visited.clear();
        for(int i = 0;i<N;i++){
            graph[i].clear();
        }
        int n,m;cin >> n >> m;
        //cout<<n << m<<endl;
        for(int i = 0;i<m;i++){
            int x,y;
            cin >> x >> y;
            x--;y--;
            //cout<<x << " "<<y << endl;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        pair<int,int>result = solve(n);
        cout<<result.first<<" "<<result.second<<endl;
        //graph.clear();
    }
    return 0;
}
