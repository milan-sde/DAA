#include<bits/stdc++.h>

using namespace std;


int minCoinChange(vector<int> coins,int target,vector<vector<int>> &dp,int n){
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }

    for(int j = 1;j<=target;j++){
        dp[0][j] = INT_MAX;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(coins[i-1] > j){ // exclude coin
                dp[i][j] = dp[i-1][j]; 
            }
            else{
                int exclude = dp[i-1][j];
                int include = 1 + dp[i][j-coins[i-1]];
                dp[i][j] = min(exclude,include);
            }
        }
    }

    if(dp[n][target] >= INT_MAX) return -1;
    return dp[n][target];
}


void printCoins(vector<int> coins,vector<vector<int>> &dp,int n,int target){
    int i = n;
    int j = target;

    cout<<"Coin Used are : ";

    while (i > 0 && j > 0){
        if(dp[i][j] == dp[i-1][j]) i--;
        else{
            cout<<coins[i-1]<< " ";
            j = j - coins[i-1];
        }
    }
    cout<<endl;
}

void printSubset(vector<int> coins,vector<vector>)

int main(){

    int n; // no of coins
    cin >> n;

    int target; // target
    cin >> target;

    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    vector<vector<int>> dp(n+1,vector<int>(target+1));

    int result = minCoinChange(coins,target,dp,n);
    cout<< "Minimum coins used : "<<result<<endl;

    printCoins(coins,dp,n,target);



    return 0;
}