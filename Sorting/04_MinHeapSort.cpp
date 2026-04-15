#include<bits/stdc++.h>

using namespace std;


void minHeapSort(vector<int> &arr,int n){
    //creating the min priority queue and filling it:
    priority_queue<int , vector<int> , greater<int>> pq;

    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }

    //operation
    for(int i=0;i<n;i++){
        arr[i] = pq.top();
        pq.pop();
    }
}

int main(){

    vector<int> arr = {-1,3,30,0,2};
    minHeapSort(arr,arr.size());

    for(auto val : arr){
        cout<<val<< " ";
    }

    cout<<endl;
    return 0;
}