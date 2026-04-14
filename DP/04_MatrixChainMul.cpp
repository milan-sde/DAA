#include<bits/stdc++.h>
using namespace std;

int matrixChainMul(vector<int> &p,int n){
    vector<vector<int>> m(n+1,vector<int>(n+1));
    vector<vector<int>> s(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        m[i][i] = 0;
    }

    for(int L=2;L<=n;L++){
        for(int i=1;i<=(n-L+1);i++){
            int j = i+L-1;
            m[i][j] = INT_MAX;

            for(int k=i;k<=j-1;k++){
                int q = m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j]);

                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }


        }
    }

    return m[1][n];
}

int main(){
    
    vector<int> A = {5,4,6,2,1};

    int result = matrixChainMul(A,A.size()-1);

    cout<<result<<endl;
}