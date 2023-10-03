#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;
void combination(int i,vector<int> &arr,vector<int> v,int target){
    if(i==v.size()){
        if(target==0){  
            // ans.push_back(arr);
            for(auto it:arr){
                cout<<it<<" ";
            }
            cout<<endl;
        }
         
        return;
    }
    
    if(v[i]<=target){
        arr.push_back(v[i]);
        combination(i,arr,v,target-v[i]);
        arr.pop_back();
    }
    
    combination(i+1,arr,v,target);
}
int main()
{
    vector<int> v={2,3,6,7};
    vector<int> temp;
    int target=7;
    combination(0,temp,v,target);
    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++)
    //     cout<<ans[i][j]<<" ";
    //     cout<<endl;
    // }
    return 0;
}