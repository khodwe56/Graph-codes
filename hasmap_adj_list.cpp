//
// Created by omkarkh1 on 28/10/20.
//

#include<bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<string,list<pair<string,int> >> l;
public:
    void addEdge(string x,string y,int w = 0,bool bidir = false){
        l[x].push_back({y,w});
        if(bidir){
            l[y].push_back({x,w});
        }
    }


};

int main(){
    return 0;
}

