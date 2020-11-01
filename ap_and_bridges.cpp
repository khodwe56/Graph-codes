//
// Created by omkarkh1 on 01/11/20.
//
#include<bits/stdc++.h>

#define ll long long
#define f(i,start,end,inc) for(int i = start;i<end;i+=inc)
#define fl(i,start,end,inc) for(ll i = start;i<end;i+=inc)
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define umap unordered_map
#define uset unordered_set
#define vpii vector<pair<int,int> >
#define vpll vector<pair<ll,ll> >
#define vpis vector<pair<int,string> >
#define vpls vector<pair<ll,string> >
#define w(t) int t;cin >> t;while(t--)
#define mp make_pair
#define pb push_back
#define pf push_front
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pis pair<int,string>
#define pls pair<ll,string>
#define F first
#define S second
#define inp(c) int c;cin >> c
#define inpl(c) ll c;cin >> c
#define si stack<int>
#define ss stack<string>
#define qi queue<int>
#define qs queue<string>
#define sl stack<ll>
#define ql queue<ll>




using namespace std;

const int N = 10000;
std::vector<int> g[N];

int dis[N],low[N],timer;
// We can also use set to ensure that there are no repaeating vertices.That's preferred actually.
std::vector<int> articulation_points;
std::vector<pii> bridges;
int no_of_child;
void dfs(int curr,int parent){
    dis[curr] = low[curr] = timer++;
    for(auto child : g[curr]){
        if(dis[child] == 0){
            dfs(child,curr);
            no_of_child++;
            low[curr] = min(low[curr],low[child]);
            if(parent != 0 and low[child] >= dis[curr]){
                articulation_points.pb(curr);
            }
            if(low[child] > dis[curr]){
                bridges.pb(mp(curr,child));
            }
        }
        else if(child != parent){
            low[curr] = min(low[curr],dis[child]);
        }
    }

    if(parent == 0 and no_of_child >=2){
        articulation_points.push_back(curr);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//#endif

    int n,m;
    cin >> n >> m;
    f(i,0,m,1){
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    timer = 1;
    dfs(1,0);
    for(int i = 0;i<n;i++){
        cout<<"Discovery Time "<<dis[i]<<endl;
        cout<<"Lower Time "<<low[i]<<endl;
    }

    for(int i = 0;i<articulation_points.size();i++){
        cout<<"art pt "<<articulation_points[i]<<endl;
    }
    for(int i = 0;i<bridges.size();i++){
        cout<<"bridges "<<bridges[i].first<<" "<<bridges[i].second<<endl;
    }
    return 0;
}
