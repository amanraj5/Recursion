#include <bits/stdc++.h>
using namespace std;
void subset(int ind,int sum,vector<int> arr,vector<int> &ans){
    if(ind==arr.size()){
        ans.push_back(sum);
        return;
    }
    // Pick that element
    subset(ind+1,sum+arr[ind],arr,ans);
    // Not pick that element
    subset(ind+1,sum,arr,ans);
}
int main()
{
    vector<int> v={3,1,2};
    vector<int> ans;
    subset(0,0,v,ans);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}