#include<bits/stdc++.h>

using namespace std;

struct Job{
    int id,deadline,profit;
};

bool cmp(Job a,Job b){
    return a.profit > b.profit;
}

pair<int,vector<int>> jobSequencing(vector<int> deadline,vector<int> profit,int n){
    //1. create jobs vector/array:
    vector<Job> jobs;
    for(int i=0;i<n;i++){
        jobs.push_back({i+1,deadline[i],profit[i]});
    }

    //2: sort by profit:
    sort(jobs.begin(),jobs.end(),cmp);

    //3. find the maxDeadline
    int maxDeadline = 0;
    for(int i=0;i<n;i++){
        maxDeadline = max(maxDeadline,jobs[i].deadline);
    }

    //4. making slots array of maxDealine size:
    vector<int> slots(maxDeadline + 1,-1);
    int totalProfit=0;


    //5: assign jobs:
    for(int i=0;i<n;i++){
        for(int j=jobs[i].deadline; j>0 ;j--){
            if(slots[j] == -1){
                slots[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return {totalProfit,slots};

}





int main(){

    vector<int> deadline = {2,1,3,2,1};
    vector<int> profit = {60,100,20,40,15};
    int n = 5;

    auto result = jobSequencing(deadline,profit,n);

    cout<<"Total Profit : "<<result.first<<endl;


    cout<<"Slots: \n";
    for(int i=1;i<result.second.size();i++){
        cout<<result.second[i]<< " ";
    }



    return 0;
}