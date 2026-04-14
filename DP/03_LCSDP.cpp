#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int LCS(string &X,string &Y,int m,int n){
    dp.assign(m+1,vector<int>(n+1));

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }

            else if(X[i-1] == Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    // to see the table:
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j]<< " ";
    //     }
    //     cout<<endl;
    // }

    return dp[m][n];
}

// set<string> getAllLCS(string &X, string &Y, int i,int j){
//     if ( i== 0 || j ==0){
//         return {""};
//     }

//     // if matched:

//     if(X[i-1] == Y[j-1]){
//         set<string> temp = getAllLCS(X,Y,i-1,j-1);
//         set<string> result;

//         for(auto s : temp){
//             result.insert(s + X[i-1]);
//         }

//         return result;
//     }

//     set<string> result;

//     //move up:
//     if(dp[i-1][j] >= dp[i][j-1]){
//         set<string> top = getAllLCS(X,Y,i-1,j);
//         result.insert(top.begin(),top.end());
//     }

//     if(dp[i][j-1] >= dp[i-1][j]){
//         set<string> left = getAllLCS(X,Y,i,j-1);
//         result.insert(left.begin(),left.end());
//     }

//     return result;
// }


set<string> getAllLCS(string &X, string &Y, int i, int j){
    if(i ==0 || j ==0){
        return {""};
    }

    if(X[i-1] == Y[j-1]){
        set<string> temp = getAllLCS(X,Y,i-1,j-1);
        set<string> result;

        for(auto s: temp){
            result.insert(s+X[i-1]);
        }

        return result;
    }

    set<string> result;

    //move up:
    if(dp[i-1][j] >= dp[i][j-1]){
        set<string> top = getAllLCS(X,Y,i-1,j);
        result.insert(top.begin(),top.end());
    }

    //move left:
    if(dp[i][j-1] >= dp[i-1][j]){
        set<string> left = getAllLCS(X,Y,i,j-1);
        result.insert(left.begin(),left.end());
    }

    return result;

}

int main(){

    string X = "BACDB";
    string Y = "BDCB";

    int m = X.size();
    int n = Y.size();

    

    int result = LCS(X,Y,m,n);

    cout<<"LCS : "<<result<<endl;

    // all lcs:
    cout<<"all LCS : "<<endl;
    set<string> lcs = getAllLCS(X,Y,m,n);

    for(auto s: lcs){
        cout<<s<<endl;
    }
    return 0;
}