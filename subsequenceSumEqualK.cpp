#include <bits/stdc++.h>
using namespace std;
// Function to Print Subsequences
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

// If You want to print if subsequences is present or not
bool subsequence1(int i,vector<int>&arr,vector<int> nums,int sum,int k,int n){
    if(i==n){
        if(sum==k){
            return true;
        }
        return false;
    }
    arr.push_back(nums[i]);
    sum+=nums[i];
    if(subsequence1(i+1,arr,nums,sum,2,n)==true) return true;
    arr.pop_back();
    sum-=nums[i];
    if(subsequence1(i+1,arr,nums,sum,2,n)==true) return true;
    return false;
}

// If you want to count the subsequence then
int subsequence2(int i,vector<int> nums,int sum,int k,int n){
    if(i==n){
        if(sum==k){
            return 1;
        }
        return 0;
    }
    
    sum+=nums[i];
    int l=subsequence2(i+1,nums,sum,k,n);
    sum-=nums[i];
    int r=subsequence2(i+1,nums,sum,k,n);
    return l+r;
}
int main()
{
    vector<int> nums={1,2,1};
    vector<int> arr;
    subsequence(0,arr,nums,0,2,3); 
    cout<<subsequence1(0,arr,nums,0,2,3)<<endl; 
    int cnt=subsequence2(0,nums,0,2,3);
    cout<<cnt;
    return 0;
}