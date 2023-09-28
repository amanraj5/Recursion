#include <bits/stdc++.h>
using namespace std;
void print(int indx,vector<int> &arr,vector<int> v,int n){
    if(indx==n){
        for(auto it: arr){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    // Picking this element for the subsequence
    arr.push_back(v[indx]);
    print(indx+1,arr,v,n);
    // Not picking this element for the subsequence
    arr.pop_back();
    print(indx+1,arr,v,n);
}

int main()
{
    vector<int> arr;
    vector<int> v={3,1,2};
    print(0,arr,v,3);
    return 0;
}