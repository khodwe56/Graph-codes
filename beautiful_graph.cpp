//
// Created by omkarkh1 on 12/11/20.
//

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define int long long
vector<vector<int> > adj;
int n,m;
int cnt1 = 0;int cnt0 = 0;int can = 1;

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int power_mod(int a,int b){
    int res = 1;
    while(b > 0){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b >>= 1;
    }
    return res%mod;
}

void dfs(int i,vector<int>&vis,int parity = 0){
    if(vis[i]){
        if(1 + parity != vis[i]){
            can = 0;
        }
        return;
    }

    if(parity == 0){
        cnt0++;
        vis[i] = 1;
    }
    else{
        cnt1++;vis[i] = 2;
    }
    for(auto nbr : adj[i]){
        dfs(nbr,vis,1-parity);
    }
}
int get_ans(){
    int ans = 1;
    vector<int>vis(n+1,0);
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            cnt0 = 0;cnt1 = 0;can = 1;
            dfs(i,vis,0);
            if(!can){
                return 0;
            }
            ans = (ans * ((power_mod(2,cnt0)) + power_mod(2,cnt1))) % mod;
        }
    }

    return ans;
}

int32_t main(){
    int t;cin >> t;
    while (t--){
        adj.clear();
        cin >> n >> m;
        adj.resize(n+1);
        for(int i = 0;i < m;i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout<<get_ans()<<endl;
    }
    return 0;
}
