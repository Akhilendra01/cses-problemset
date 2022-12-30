/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

vector<int> gr[(int)1e5+1];
bool vis[(int)1e5+1];
int team[(int)1e5+1];

bool impossible;

void dfs(int node, int t){
	vis[node]=1;
	team[node]=t;
	for(int child: gr[node]){
		if(!vis[child]){
			dfs(child, t^1);
		}else{
			if(team[child]==t){
				impossible=1;
				return;
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

	int n, m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int x, y;
		cin>>x>>y;

		gr[x].push_back(y);
		gr[y].push_back(x);
	}	

	for(int i=1;i<=n;i++){
		if(!vis[i] and !impossible){
			dfs(i, 0);
			if(impossible)break;
		}
	}

	if(!impossible)for(int i=1;i<=n;i++)cout<<team[i]+1<<" ";
	else cout<<"IMPOSSIBLE";
	
	return 0;
}