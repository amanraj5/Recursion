#include <bits/stdc++.h>
using namespace std;
const int N = 10e+5;
vector<int> g[N];
vector<int> vis(N, 0);

void bfs(int vertex)
{
    queue<int> q;
    q.push(vertex);
    vis[vertex] = 1;
    while (!q.empty())
    {
        int len = q.size();
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int child : g[cur])
        {
            if (vis[child])
                continue;
            q.push(child);
            vis[child] = 1;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    return 0;
}