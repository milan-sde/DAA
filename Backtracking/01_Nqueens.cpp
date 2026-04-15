#include<bits/stdc++.h>

using namespace std;



bool isSafe(vector<int>&x, int k){
    for(int i=0;i<k;i++){
        if(x[i] == x[k] || abs(x[i] - x[k]) == abs(i-k)){
            return false;
        }
    }
    return true;
}

void printBoard(vector<int> &x,int n){
    cout<<"Solution:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(x[i] == j){
                cout << "1 ";
            }
            else{
                cout<< "0 ";
            }
        }
        cout<<endl;
    }

    cout<<endl;
}

void solve(int k,vector<int> &x,int n){
    if(k == n){
        for (int i=0;i<n;i++){
            cout<<x[i]<< " ";
        }
        cout<<endl;
        return;
        // printBoard(x,n);
        return;
    }

    //all columns:
    for(int c = 0;c<n;c++){
        x[k] = c;

        if(isSafe(x,k)){
            solve(k+1,x,n);
        }
    }
}

int main(){

    int n=4;
    vector<int> x(n);
    solve(0,x,n);
    return 0;
}