/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


vector<int> adj[200005];
int dist[200005];
int depth[200005];

void evalDepth(int node, int par){
	for(int child: adj[node]){
		if(child!=par){
			evalDepth(child, node);
			depth[node]=max(depth[node], 1+depth[child]);
		}
	}
}


void solve(int node, int par, int parAns){
	vector<int> pre, suf;
	for(int child: adj[node]){
		if(child!=par){
			pre.push_back(depth[child]);
			suf.push_back(depth[child]);
		}
	}

	for(int i=1;i<pre.size();i++)pre[i]=max(pre[i], pre[i-1]);
	for(int i=(int)suf.size()-2;i>=0;i--)suf[i]=max(suf[i], suf[i+1]);

	dist[node]=1+max(parAns, suf.empty()?-1: suf[0]);

	int cno=0;
	for(int child: adj[node]){
		if(child!=par){
			int l=(cno==0?INT_MIN: pre[cno-1]);
			int r=(cno==suf.size()-1?INT_MIN: suf[cno+1]);

			solve(child, node, (int)1+(int)max({l, r, parAns}));
			cno++;
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
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	} 

	evalDepth(1, 0);
	solve(1, 0, -1);
	for(int i=1;i<=n;i++)cout<<dist[i]<<" "; cout<<"\n";
	
	return 0;
}