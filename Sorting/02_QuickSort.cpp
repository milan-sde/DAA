#include<bits/stdc++.h>

using namespace std;


//step 2 : write the parition logic (here i am using last element as the pivot)
int partition(vector<int> &arr,int st, int end){
    int i = st-1;
    int pivot = arr[end];

    for(int j=st;j<end;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }

    i++;
    swap(arr[i],arr[end]); // placing the pivot at its correct place 

    return i;
}


// step 1: 
void quickSort(vector<int> &arr,int st,int end){
    if(st < end){
        int pivotIdx = partition(arr,st,end);

        quickSort(arr,st,pivotIdx-1);
        quickSort(arr,pivotIdx+1,end);
    }
}

int main(){
     int n;
    cout<<"Enter the array size : ";
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>> arr[i];
    }

    quickSort(arr,0,arr.size()-1);

    for(int num : arr){
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}