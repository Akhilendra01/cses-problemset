/*
	author: akhilendra11
*/
 
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long int
#define endl "\n"
 
int n, m;
vector<pair<int, int>> gr[(int)1e5+1];
 
int vis[(int)1e5+1];
int dist[(int)1e5+1];
 
void dijsktra(int src){
	set<pair<int, int>> s;
	s.insert({0, src});
 
	for(int i=0;i<=n;i++)dist[i]=1e18;
	dist[src]=0;
	
	while(s.size()>0){
		pair<int, int> p=*s.begin();
		s.erase(s.begin());
 
		int v=p.second;
		int d=p.first;
 
		if(vis[v])continue;
 
		vis[v]=1;
 
		for(pair<int, int> c: gr[v]){
			int child_v=c.first;
			int wt=c.second;
 
			if(dist[child_v]>dist[v]+wt){
				dist[child_v]=dist[v]+wt;
				s.insert({dist[child_v], child_v});
			}
 
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
 
	cin>>n>>m;
 
	for(int i=0;i<m;i++){
		int x, y, z;
		cin>>x>>y>>z;
 
		gr[x].push_back({y, z});
	}
 
	dijsktra(1);
	for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
	
	return 0;
}