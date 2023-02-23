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
int cld[(int)1e5 + 1];
int vis[(int)1e5 + 1];

int dfs(int node)
{
    vis[node] = 1;
    for (int child : gr[node])
    {
        if (!vis[child])
        {
            int val = dfs(child);
            if (dp[node] < 1 + val and val > 0)
            {
                dp[node] = 1 + val;
                cld[node] = child;
            }
        }
        else
        {
            if (dp[node] < 1 + dp[child])
            {
                dp[node] = 1 + dp[child];
                cld[node] = child;
            }
        }
    }
    return dp[node];
}

void solve()
{
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    dp[n] = 1;
    cld[n] = -1;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
    }

    int i = 1;
    int val = dfs(1);
    if (vis[n] == 0)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << val << "\n";
    while (i != -1)
    {
        cout << i << " ";
        i = cld[i];
    }
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