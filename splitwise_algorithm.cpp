//
// Created by omkarkh1 on 30/10/20.
//

#include<bits/stdc++.h>
using namespace std;

int main(){
    int no_of_transactions;cin >> no_of_transactions;
    int no_of_friends;cin >> no_of_friends;
    int net_amount[100000] = {0};
    while(no_of_transactions--){
        int x,y,amount;cin >> x >> y >> amount;
        net_amount[x] -= amount;
        net_amount[y] += amount;
    }
    multiset<int> m;
    for(int i = 0;i<no_of_friends;i++){
        if(net_amount[i] != 0){
            m.insert(net_amount[i]);
        }
    }
    int cnt = 0;
    while(!m.empty()){
        auto low = m.begin();
        auto high = prev(m.end());
        int debit = *low;
        int credit = *high;
        m.erase(low);
        m.erase(high);

        int settlement_amount = min(-debit,credit);
        debit += settlement_amount;
        credit -= settlement_amount;
        cnt++;

        if(debit != 0){
            m.insert(debit);
        }
        if(credit != 0){
            m.insert(credit);
        }

    }
    cout<<cnt<<endl;
    return 0;
}

/*
 Input
 3 3
 0 1 100
 1 2 50
 2 1 50
 */