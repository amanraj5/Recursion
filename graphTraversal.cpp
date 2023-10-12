#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
vector<vector<int>> gt;
vector<int> temp;
void dfs(int vertex)
{
    // Marked this as visited on entering
    vis[vertex] = true;
    temp.push_back(vertex);
    for (auto child : g[vertex])
    {
        // Check if that child is visited earlier or not if visited then continue
        if (vis[child])
            continue;
        dfs(child);
    }
    return;
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        temp.clear();
        dfs(i);
        gt.push_back(temp);
    }
    for(auto it:gt){
        for(auto c:it){
            cout<<c<<" ";
        }
    }
    return 0;
}