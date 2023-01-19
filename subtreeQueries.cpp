/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


#define N (int)2e5+1

int n, q;
vector<int> tree[N];

int val[N];
int s[N];
int e[N];
int timer;

void update(int i, int val, vector<int>& bit){
	for(;i<=n;i+=(i&-i))bit[i]+=val;
}

int query(int i, vector<int>& bit){
	int ans=0;
	for(;i>0;i-=(i&-i))ans+=bit[i];

	return ans;
}

void dfs(int node, int par){
	s[node]=++timer;
	for(int child: tree[node]){
		if(child!=par){
			dfs(child, node);
		}
	}
	e[node]=timer;
}

void solve(){
	cin>>n>>q;

	for(int i=1;i<=n;i++)cin>>val[i];
	for(int i=1;i<n;i++){
		int u, v;
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1, 0);

	vector<int> bit(n+1);
	for(int i=1;i<=n;i++){
		update(s[i], val[i], bit);
	}

	while(q--){
		int t;	cin>>t;

		if(t==1){
			int node, value;
			cin>>node>>value;

			update(s[node], value-val[node], bit);
			val[node]=value;

		}else{
			int node; cin>>node;
			cout<<query(e[node], bit)-query(s[node]-1, bit)<<"\n";
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

	solve();
	
	return 0;
}