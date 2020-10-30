//
// Created by omkarkh1 on 30/10/20.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;

vector<int>graph[N];
int tin[N],tout[N],timer;

void euler_tour_1(int curr,int parent){
    cout<<curr<<" ";
    for(auto x : graph[curr]){
        if(x != parent){
            euler_tour_1(x,curr);
            cout<<curr<<" ";
        }
    }
    return;
}

void euler_tour_2(int curr,int parent){
    cout<<curr<<" ";
    for(auto x : graph[curr]){
        if(x != parent){
            euler_tour_2(x,curr);
        }
    }
    cout<<curr<<" ";
}

void euler_tour_3(int curr,int parent){
    cout<<curr<<" ";
    tin[curr] = ++timer;
    for(auto x : graph[curr]){
        if(x != parent){
            euler_tour_3(x,curr);
        }
    }
    tout[curr] = timer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;cin >> n;
    for(int i = 0;i<n-1;i++){
        int x,y;cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    timer = 0;
    euler_tour_3(1,0);
    cout<<endl;
    for(int i = 1;i <= n;i++){
        cout<<i<<" "<<tin[i]<<" "<<tout[i]<<endl;
    }
    return 0;
}

// INPUT
/*
 9
 1 2
 2 4
 2 5
 2 6
 1 3
 3 7
 7 8
 7 9
 */