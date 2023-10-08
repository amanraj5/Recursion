#include <bits/stdc++.h>
using namespace std;
void permute(int ind, vector<int> &arr, vector<vector<int>> &ans)
{
    if (ind == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        swap(arr[ind], arr[i]);
        permute(ind + 1, arr, ans);
        swap(arr[ind], arr[i]);
    }
}
int main()
{
    vector<int> v = {1, 2, 3};
    vector<vector<int>> ans;
    permute(0, v, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}