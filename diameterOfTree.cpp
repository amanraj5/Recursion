#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];
void dfs(int vertex, int par = -1)
{
    for (int child : g[vertex])
    {
        // If parent and child is same then no need to go further as it will create inifnite iteration
        if (child == par)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // Run dfs to get the depth of each vertex by keeping 1 as root
    dfs(1);
    int mx_depth = -1;
    int mx_node;
    for (int i = 1; i <= n; i++)
    {
        // Doing this will store the vertex having max depth
        if (mx_depth < depth[i])
        {
            mx_depth = depth[i];
            mx_node = i;
        }

        // Reset that depth to 0 as we need to run dfs again in order to get the maximum diameter by
        // taking max_depth node as one of its diameter
        depth[i] = 0;
    }
    // Run dfs in that node in order to get the diameter of the tree as this node will give the max diameter
    dfs(mx_node);
    mx_depth=-1;
    for (int i = 1; i <= n; i++)
    {
        mx_depth = max(mx_depth, depth[i]);
    }
    cout << mx_depth;
    return 0;
}