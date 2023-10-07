#include <bits/stdc++.h>
using namespace std;
void generate(int open,int close,vector<string> &ans,string &s){
    if(open==0 && close==0){
        ans.push_back(s);
        return;
    }
    if(open>0){
        s.push_back('(');
        generate(open-1,close,ans,s);
        s.pop_back();
    }
    if(close>0){
        if(open<close){
            s.push_back(')');
            generate(open,close-1,ans,s);
            s.pop_back();
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<string> ans;
    string temp;
    generate(n,n,ans,temp);
    for(auto it:ans){
        cout<<it<<"-------";
    }
    return 0;
}