#include<bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &nums,int n){
    for(int i=0;i<n;i++){
        bool swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(nums[j] >= nums[j+1]){
                swap(nums[j], nums[j+1]);
                swapped = true;
            }
        }

        if(!swapped) break;
    }
}

int main(){

    vector<int> nums = {5,4,3,2,1};
    bubbleSort(nums,nums.size());
    for(auto num: nums){
        cout<<num<<" ";
    }
    return 0;

}