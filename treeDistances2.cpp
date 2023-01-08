/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


int n;
vector<int> tree[(int)2e5+1];
int subTreeSize[(int)2e5+1];
int subTreeAns[(int)2e5+1];
int ans[(int)2e5+1];


void preprocess(int node, int par){
	subTreeSize[node]=1;
	for(int child: tree[node]){
		if(child!=par){
			preprocess(child, node);
			subTreeSize[node]+=subTreeSize[child];
			subTreeAns[node]+=subTreeSize[child]+subTreeAns[child];
		}	
	}
}


void solve(int node, int par, int par_ans){
	ans[node]=subTreeAns[node]+par_ans+n-subTreeSize[node];

	for(int child: tree[node]){
		if(child!=par)
		solve(child, node, ans[node]-(subTreeAns[child]+subTreeSize[child]));
	}

}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


	cin>>n;

	for(int i=0;i<n-1;i++){
		int x, y;
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	preprocess(1, 0);

	solve(1, 0, 0);

	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	
	return 0;
}