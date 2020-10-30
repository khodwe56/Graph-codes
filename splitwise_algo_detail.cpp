//
// Created by omkarkh1 on 30/10/20.
//

#include<bits/stdc++.h>
using namespace std;

int main(){
    int no_of_transactions;cin >> no_of_transactions;
    int no_of_friends;cin >> no_of_friends;
    map<string,int> net_amount;
    while(no_of_transactions--) {
        string x, y;
        int amt;
        cin >> x >> y >> amt;
        if (net_amount.count(x) == 0) {
            net_amount[x] = 0;
        }
        if (net_amount.count(y) == 0) {
            net_amount[y] = 0;
        }
        net_amount[x] -= amt;
        net_amount[y] += amt;
    }
        multiset<pair<int,string> > s;
        for(const auto& p : net_amount){
            string person = p.first;
            int amount = p.second;
            if(amount != 0){
                s.insert({p.second,p.first});
            }

        }

        int cnt =  0;
        while(!s.empty()){
            auto low = s.begin();
            auto high = prev(s.end());
            int debit = low->first;
            string debit_person = low->second;
            int credit = high->first;
            string credit_person =  high->second;
            s.erase(low);
            s.erase(high);
            int settled_amount = min(-debit,credit);
            debit += settled_amount;
            credit -= settled_amount;
            cout<<debit_person<<" will pay "<<settled_amount<<" to the "<<credit_person<<endl;
            if(debit != 0)
                s.insert({debit,debit_person});
            if(credit != 0)
                s.insert({credit,credit_person});
            cnt++;
        }
        cout<<cnt<<endl;

    return 0;
}

/*
 Input
 3 3
 Rahul Ajay 100
 Ajay Neha 50
 Neha Rahul 40
 */