#include<bits/stdc++.h>
using namespace std;


void selectionSort(vector<int> &arr,int n){
    for(int i=0;i<n;i++){
        int minIdx = i;

        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i],arr[minIdx]);
    }
}

int main(){

    vector<int> arr = {5, 2, 8, 1, 3};
    int n = arr.size();

    selectionSort(arr,n);
        for(auto num: arr){
        cout<<num<<" ";
    }


    return 0;
}