#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr,int l,int m,int h){

    vector<int> temp;
    int left=l;
    int right=m+1;
    int k=0;
    while(left<=m && right<=h){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
    }
    while(left<=m){
        temp.push_back(arr[left++]);
    }

    while(right<=h){
        temp.push_back(arr[right++]);
    }
    for(int i=l;i<=h;i++){
        arr[i]=temp[i-l];
    }
}
void mergeSort(vector<int> &arr,int low,int high){
    if(low>=high) return ;
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main()
{
    vector<int> v={3,1,2,5,4,7,6};
    mergeSort(v,0,7);
    for(auto &it:v){
        cout<<it<<" ";
    }
    return 0;
}