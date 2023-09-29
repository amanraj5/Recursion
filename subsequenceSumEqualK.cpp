#include <bits/stdc++.h>
using namespace std;
void subsequence(int i,vector<int>&arr,vector<int> nums,int sum,int k,int n){
    if(i==n){
        if(sum==k){
            for(auto it:arr){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    arr.push_back(nums[i]);
    sum+=nums[i];
    subsequence(i+1,arr,nums,sum,2,n);
    arr.pop_back();
    sum-=nums[i];
    subsequence(i+1,arr,nums,sum,2,n);
}
int main()
{
    vector<int> nums={1,2,1};
    vector<int> arr;
    subsequence(0,arr,nums,0,2,3); 
    return 0;
}