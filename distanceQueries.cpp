/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

vector<int> tree[(int)2e5+1];
int up[(int)2e5+1][21];
int lvl[(int)2e5+1];


void calcLvls(int node, int par){
	lvl[node]=lvl[par]+1;

	for(int child: tree[node]){
		if(child!=par){
			calcLvls(child, node);
		}
	}
}

void binaryLifting(int node, int par){
	up[node][0]=par;
	for(int i=1;i<=20;i++){
		if(up[node][i-1]!=-1){
			up[node][i]=up[up[node][i-1]][i-1];
		}else{
			up[node][i]=-1;
		}
	}

	for(int child: tree[node]){
		if(child!=par){
			binaryLifting(child, node);
		}
	}
}

int liftNode(int node, int jump){
	if(jump==0)return node;

	for(int j=20;j>=0;j--){
		if((jump>>j)&1){
			node=up[node][j];
			if(node==-1){
				return -1;
			}
		}
	}
	return node;
}

int lca(int u, int v){
	if(lvl[u]<lvl[v])swap(u, v);

	u=liftNode(u, lvl[u]-lvl[v]);
	if(u==v)return u;

	for(int j=20;j>=0;j--){
		if(up[u][j]!=up[v][j]){
			u=up[u][j];
			v=up[v][j];
		}
	}

	return liftNode(u, 1);
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, q;
	cin>>n>>q;

	for(int i=1;i<n;i++){
		int u, v;
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}					

	binaryLifting(1, -1);
	lvl[0]=-1; calcLvls(1, 0);

	while(q--){
		int u, v;
		cin>>u>>v;
		int LCA=lca(u, v);
		int dist=lvl[u]-lvl[LCA]+lvl[v]-lvl[LCA];
		cout<<dist<<"\n";
	}
		
	return 0;
}