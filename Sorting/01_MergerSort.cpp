#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr,int l,int mid ,int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> a(n1);
    vector<int> b(n2);

    //copying element from l to mid in array 'a'
    for(int i=0;i<n1;i++){
        a[i] = arr[i+l];
    }

    //copying element from mid+1 to r in array 'b'
    for(int i=0;i<n2;i++){
        b[i] = arr[mid+1+i];
    }


    int i=0;//pointer on starting of a that is index 0
    int j=0; // pointer on starting of b that is index 0
    int k=l; // ponter on the original array

    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k++] = a[i];
            i++;
        }
        else{
            arr[k++] = b[j];
            j++;
        }
    }

    //if still elements are left in the array -> a 
    while(i < n1){
        arr[k++] = a[i];
        i++;
    }

    //if still elements are left in the array -> b
    while(j < n2){
        arr[k++] = b[j];
        j++;
    }
}

void mergeSort(vector<int> &arr, int l,int r){
    if(l < r){
        int mid = (l+r)/2;

        mergeSort(arr,l,mid); // left half
        mergeSort(arr,mid+1,r); // right half

        merge(arr,l,mid,r); // merging both half
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

    mergeSort(arr,0,arr.size()-1);

    for(int num : arr){
        cout<<num<<" ";
    }
    cout<<endl;

    
    return 0;
}