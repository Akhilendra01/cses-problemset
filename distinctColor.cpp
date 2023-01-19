/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

#define N (int)2e5+1

int n;
int color[N];
int arr[N];


void update(int idx, int val, vector<int>& bit){
	for(idx++;idx<=n;idx+=(idx&-idx))bit[idx]+=val;
}

int query(int idx, vector<int>& bit){
	int ans=0;
	for(idx++;idx>0;idx-=(idx&-idx))ans+=bit[idx];
	return ans;
}

int lend[N], tour[N];

vector<int> tree[N];

int idx;
void dfs(int node, int par){
	lend[node]=idx;
	for(int child: tree[node]){
		if(child!=par){
			dfs(child, node);
		}
	}
	tour[idx]=node;	
	idx++;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>color[i];

	for(int i=1;i<n;i++){
		int u, v;
		cin>>u>>v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}


	dfs(1, 0);

	int ans[n+1];
	map<int, int> last;
	vector<int> bit(n+1);
	for(int i=0;i<n;i++){

		if(last.count(color[tour[i]])){
			update(last[color[tour[i]]], -1, bit);
		}

		last[color[tour[i]]]=i;
		update(i, 1, bit);

		ans[tour[i]]=query(i, bit)-query(lend[tour[i]]-1, bit);
	}

	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";

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