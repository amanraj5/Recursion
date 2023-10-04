#include <bits/stdc++.h>
using namespace std;

// Brute Force 
// Time Complexity is (2^n*k*log(k))
// void combi(int i,vector<int> &arr,vector<int> main,int target,set<vector<int>> &s){
//         if(i==main.size()){
//             if(target==0)
//             s.insert(arr);
//             return;
//         }
//         if(main[i]<=target){
//             arr.push_back(main[i]);
//             combi(i+1,arr,main,target-main[i],s);
//             arr.pop_back();
//         }
        
//         combi(i+1,arr,main,target,s);
// }
void combi(int ind,vector<int> &arr,vector<int> main,int target,vector<vector<int> > &ans){
        // Base case : Check if the target become 0 then simply push that vector in answer
        if(target==0){
            ans.push_back(arr);
            return;
        }
        for(int i=ind;i<main.size();i++){
            // If the alternate number are equal then skip those number so that the answer should contain only unique values
            if(i>ind && main[i]==main[i-1]) continue;
            if(main[i]>target) break; // If element is greater than target then no need to consider that element and the elements next to this
            arr.push_back(main[i]); // Push that element into the data structure
            combi(i+1,arr,main,target-main[i],ans);
            arr.pop_back();
        }
}
int main()
{
    vector<int> v={10,1,2,7,6,1,5};
    sort(v.begin(),v.end());
    vector<int> temp;
    vector<vector<int> > ans;
    combi(0,temp,v,8,ans);
    
    // for(auto it:set){
    //     ans.push_back(it);
    // }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}