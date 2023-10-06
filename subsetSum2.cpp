#include <bits/stdc++.h>
using namespace std;
void subset(int ind, vector<int> v, vector<int> &temp, vector<vector<int>> &ans)
{
   
    ans.push_back(temp);

    for (int i = ind; i < v.size(); i++)
    {
        if (i != ind && v[i] == v[i - 1])
            continue;
        temp.push_back(v[i]);
        subset(i + 1, v, temp, ans);
        temp.pop_back();
    }
}
int main()
{
    vector<int> v = {1, 2, 2, 3};
    vector<vector<int>> ans;
    vector<int> temp;
    subset(0, v, temp, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}