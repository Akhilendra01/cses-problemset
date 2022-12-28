/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


vector<int> tree [200005];
int dis[200005];

void dfs(int node, int par){
	dis[node]=dis[par]+1;
	for(int child: tree[node]){
		if(child!=par){
			dfs(child, node);
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
	dis[0]=-1;
	dfs(1, 0);

	int src=1;
	for(int i=1;i<=n;i++){
		if(dis[src]<dis[i])src=i;
	}

	memset(dis, 0, sizeof(dis));
	dis[0]=-1;

	dfs(src, 0);

	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans, dis[i]);

	cout<<ans;
	
	return 0;
}