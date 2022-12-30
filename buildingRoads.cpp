/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

vector<int> gr[(int)1e5+1];
bool vis[(int)1e5+1];

void dfs(int node){
	vis[node]=1;

	for(int child: gr[node]){
		if(!vis[child]){
			dfs(child);
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

	int n, m;
	cin>>n>>m;

	for(int i=1;i<=m;i++){
		int x, y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	vector<int> v;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			v.push_back(i);
			dfs(i);
		}
	}

	cout<<v.size()-1<<"\n";

	for(int i=0;i<v.size()-1;i++){
		cout<<v[i]<<" "<<v[i+1]<<"\n";
	}
	
	return 0;
}