/*
    author: akhilendra11
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

#define mod ((int)1e9 + 7)

int n, m;
vector<int> gr[(int)1e5 + 1];
int dp[(int)1e5 + 1];
int vis[(int)1e5 + 1];

int dfs(int node)
{
    vis[node] = 1;
    for (int child : gr[node])
    {
        if (!vis[child])
        {
            dp[node] += dfs(child);
            dp[node] %= mod;
        }
        else
        {
            dp[node] += dp[child];
            dp[node] %= mod;
        }
    }
    return dp[node];
}

void solve()
{
    cin >> n >> m;
    dp[n] = 1;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
    }

    cout << dfs(1);
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}