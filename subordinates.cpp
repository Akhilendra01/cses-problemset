/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

vector<int> adj[(int)2e5+1];

int subordinates[(int)2e5+1];


int dfs(int node){

	for(int child: adj[node]){
		subordinates[node]+=dfs(child);
	}

	return subordinates[node]+1;
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;

	for(int i=2;i<=n;i++){
		int x; cin>>x;
		adj[x].push_back(i);
	}

	dfs(1);

	for(int i=1;i<=n;i++)cout<<subordinates[i]<<" ";	
	return 0;
}