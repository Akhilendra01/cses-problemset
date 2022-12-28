/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

vector<int> tree[200005];
int dp[200005][2];

void dfs(int node, int par){
	dp[node][0]=0;
	dp[node][1]=0;

	bool leaf=1;

	for(int child: tree[node]){
		if(child!=par){
			leaf=0;
			dfs(child, node);
			dp[node][0]+=max(dp[child][0], dp[child][1]);
		}
	}
	if(leaf)return;

	for(int child: tree[node]){
		if(child!=par){
			dp[node][1]=max(
				dp[node][1],
				dp[node][0]-max(dp[child][0], dp[child][1])+dp[child][0]+1
			);
		}
	}
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	for(int i=1;i<n;i++){
		int x, y; cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	dfs(1, 0);

	cout<<max(dp[1][0], dp[1][1]);
	
	return 0;
}