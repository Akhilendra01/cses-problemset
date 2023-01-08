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
			if(node==-1)return -1;
		}
	}

	return node;
}

int lca(int a, int b){
	if(lvl[a]<lvl[b])swap(a, b);

	a=liftNode(a, lvl[a]-lvl[b]);

	if(a==b)return a;


	for(int i=20;i>=0;i--){
		if(up[a][i]!=up[b][i]){
			a=up[a][i];
			b=up[b][i];
		}
	}


	return liftNode(a, 1);
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

	for(int i=2;i<=n;i++){
		int x;	cin>>x;
		tree[x].push_back(i);
		tree[i].push_back(x);
	}
	lvl[0]=-1;
	calcLvls(1, 0);
	binaryLifting(1, -1);

	while(q--){
		int a, b;
		cin>>a>>b;

		cout<<lca(a, b)<<"\n";
	}
	return 0;
}