//
// Created by omkarkh1 on 29/10/20.
//

#include<bits/stdc++.h>
using namespace std;

struct dsu{
    vector<int> parent;
    void init(int n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
    }

    int get(int x){
        return (x == parent[x] ? x : parent[x] = get(parent[x]));
    }

    void unite(int x,int y){
        x = get(x);
        y = get(y);
        if(x != y){
            parent[x] = max(parent[x],parent[y]);
            parent[y] = max(parent[x],parent[y]);
        }
    }

};
int main(){
    int n,q;
    cin >> n >> q;
    int l[q],r[q],c[q];
    for(int i = 0;i<q;i++){
        cin >> l[i] >> r[i] >> c[i];
    }
    dsu G;
    G.init(n+2);
    int res[n+2];
    for(int i = q-1; i >= 0;i--){
        int index = G.get(l[i]);
        while(index <= r[i]){
            res[index] = c[i];
            G.unite(index,index + 1);
            index = G.get(index);
        }
    }

    for(int i = 1;i<=n;i++){
        cout<<res[i]<<endl;
    }
    return 0;
}