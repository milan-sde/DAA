#include<iostream>
#include<vector>

using namespace std;

int knapsack(vector<int> weights,vector<int>values,int W,int n){
    //1. Create dp (matrix) of [n+1][W+1]:
    vector<vector<int>> dp(n+1,vector<int>(W+1));

    //2: Filling the table : 
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            // 3. Base case when item is zero and the capacity/weight is also zero
            if (i==0 || j==0) 
            {
                dp[i][j] = 0;
            }
            else if(weights[i-1] <= j){
                //if weight of current item is less than or equal to the capacity of j
                dp[i][j] = max(values[i-1] + dp[i-1][j - weights[i-1]] , dp[i-1][j]); 
            }
            else{
                 //if weight of current item is greater than capacity of j
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main(){

    vector<int> weights = {1,5,4,3};
    vector<int> values = {15,10,9,5};

    int W = 8;
    int n = weights.size();
    int result = knapsack(weights,values,W,n);
    
    cout<<result<<endl;
    return 0;
}