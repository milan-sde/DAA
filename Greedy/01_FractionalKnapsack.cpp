#include<bits/stdc++.h>

using namespace std;

//this struct is for each items having value & weight
struct Item{
    int value,weight;
};

// helper to sort in descending:
// bool cmp(Item a, Item b) {
//     double r1 = (double)a.value / a.weight;
//     double r2 = (double)b.value / b.weight;
//     return r1 > r2;
// }

// helper to sort in descending: (shorter)
bool cmp(Item a, Item b){
    return double(a.value/a.weight) > double(b.value/b.weight);
}

double frationalKnapsack(vector<Item> &items,int n,int W){
    //sort the array as per the ratio in descending order:
    sort(items.begin(),items.end(),cmp);

    double totalValue = 0.0; // actual profit value

    for(int i=0 ;i < n;i++){
        // weight smaller than maximum capacity
        if(items[i].weight <= W){ 
            totalValue += items[i].value;
            W -= items[i].weight;
        }
        else{
            // weight larfger than maximum capacity
            double fraction = (double)W / items[i].weight; // taking the fractional part
            totalValue += items[i].value * fraction;
            break;
        }
    }

    return totalValue;
}


int main(){

    // int n;
    // cout<<"Enter the size of the weights and values : ";
    // cin>>n;

    // int W;
    // cout<<"Enter the maximum capacity : ";
    // cin>>W;

    // vector<Item> items(n);
    // for(int i=0;i<n;i++){
    //     cin>>items[i].value;
    //     cin>>items[i].weight;
    // }

    vector<Item> items = {
       {10,2},{5,3},{15,5},{7,7},{6,1},{18,4},{3,1}
    };

    // int profit = frationalKnapsack(items,n,W);
    double profit = frationalKnapsack(items,7,15);
    cout<<"Profit : "<<profit<<endl;

    return 0;
}