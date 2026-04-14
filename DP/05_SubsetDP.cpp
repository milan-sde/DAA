#include<bits/stdc++.h>
using namespace std;


bool isSubset(vector<int> &nums, int target,vector<vector<int>> &dp,int n){
    
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }

    for(int j=1;j<=target;j++){
        dp[0][j] = false;
    }

    for(int i = 1 ; i <= n ;i++){
        for(int j=1;j <= target ;j++){
            if(nums[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            }
        }
    }

    return dp[n][target];
}

void printSubset(vector<int> &nums, int target,vector<vector<int>> &dp,int n){
    int i=n;
    int j=target;
    cout<<"Subsets are : ";

    while (i>0 && j>0){
        if(dp[i-1][j] == dp[i][j]){
            i--;
        }
        else{
            cout<<nums[i-1]<< " ";
            j = j - nums[i-1];
            i--;
        }
    }

}

int main(){

    vector<int> nums = {2,3,8,1};
    int n = nums.size();
    int target = 6;
    vector<vector<int>> dp(n+1,vector<int>(target+1));
    

    bool result = isSubset(nums,target,dp,n);

    result == true ? cout<<"Subset can be formed \n" :  cout<<"Subset cannot be formed \n";

    printSubset(nums,target,dp,n);

}