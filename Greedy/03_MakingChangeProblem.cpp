#include<bits/stdc++.h>

using namespace std;

void coinChange(vector<int> &coins, int amount){
    //sort in descending order:
    sort(coins.rbegin(),coins.rend());
    vector<int> used;

    // step 2: pick coins:
    for(int i=0;i<coins.size();i++){
        while(amount >= coins[i]){
            amount -= coins[i];
            used.push_back(coins[i]);
        }
    }

    //output:
    cout<<"Coins used : ";
    for(int c: coins){
        cout<< c << " ";
    }
    cout<<endl;
}

int main(){

    vector<int> coins = {25,10,5,1};
    int amount = 36;

    coinChange(coins,amount);

    return 0;
}