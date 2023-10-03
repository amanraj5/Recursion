#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }
        while(arr[j]>pivot && j>low){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(vector<int> &arr,int low,int high){
    if(low<high){
        int pivot=partition(arr,low,high);
        qs(arr,low,pivot-1);
        qs(arr,pivot+1,high);
    }
}

int main()
{
    vector<int> v={2,1,5,3,6,4};
    qs(v,0,v.size()-1);
    for(auto it:v){
        cout<<it<<" ";
    }
    return 0;
}