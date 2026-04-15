#include<bits/stdc++.h>

using namespace std;


void maxHeap(vector<int> &nums,int n){
    //1 priority queue:
    priority_queue<int> pq;

    for(int i=0;i<n;i++){
        pq.push(nums[i]);
    }

    //step 2: extract elements:
    for(int i=n-1;i>=0;i--){
        nums[i] = pq.top();
        pq.pop();
    }

}

int main(){

    vector<int> nums = {6,5,4,3,2,1};

    maxHeap(nums,nums.size());

    for(auto num : nums){
        cout<<num<< " ";
    }

    cout<<endl;
    return 0;
}