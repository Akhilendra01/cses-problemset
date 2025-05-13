/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


const int INF=1e18;

struct Edge{
	int u, v, wt;
};


int n, m;
Edge e[5000];
vector<int> gr[2501];
vector<int> gr1[2501];
int vis[2501];
int vis1[2501];

void dfs(int node){
	vis[node]=1;
	for(int child: gr[node]){
		if(!vis[child])dfs(child);
	}
}
void dfs1(int node){
	vis1[node]=1;
	for(int child: gr1[node]){
		if(!vis1[child])dfs1(child);
	}
}

void solve(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>e[i].u>>e[i].v>>e[i].wt;
		e[i].wt*=-1;
		gr[e[i].u].push_back(e[i].v);
		gr1[e[i].v].push_back(e[i].u);
	}

	dfs(1);
	dfs1(n);

	vector<int> dist(n+1, INF);
	dist[1]=0;
	for(int j=1;j<n;j++){
		for(int i=0;i<m;i++){
			if(dist[e[i].u]<INF and vis[e[i].u] and vis1[e[i].v]){
				dist[e[i].v]=min(dist[e[i].v], dist[e[i].u]+e[i].wt);
			}
		}
	}

	for(int i=0;i<m;i++){
		if(vis[e[i].u] and vis1[e[i].v]and dist[e[i].v]>dist[e[i].u]+e[i].wt){
			cout<<"-1";
			return;
		}
	}
	cout<<-dist[n];
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
