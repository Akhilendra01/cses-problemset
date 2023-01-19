/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

// #define int long long int
#define endl "\n"

#define N (int)2e5+1

#define DEAD INT_MIN

int n, q;

vector<int> tree[N];

int val[N], sz[N], lvl[N];

int up[N][21];

int chain[N], chainHead[N], position[N], arr[N];


int st[1<<21];

// int merge(int a, int b){
// 	return max(a, b);
// }

void build(int x, int lx , int rx){
	if(rx-lx==0){
		st[x]=arr[lx];
		return;
	}

	int mid=(lx+rx)/2;

	build(2*x+1, lx, mid);
	build(2*x+2, mid+1, rx);

	st[x]=max(st[2*x+1], st[2*x+2]);
}
void build(){
	build(0, 0, n-1);
}


void setVal(int val, int idx, int x, int lx, int rx){
	if(rx-lx==0){
		st[x]=val;
		return;
	}

	int mid=(lx+rx)/2;
	if(idx<=mid){
		setVal(val, idx, 2*x+1, lx, mid);
	}else{
		setVal(val, idx, 2*x+2, mid+1, rx);
	}
	st[x]=max(st[2*x+1], st[2*x+2]);
}

void setVal(int val, int idx){
	setVal(val, idx, 0, 0, n-1);
}

int query(int l, int r, int x, int lx, int rx){
	if(lx>r or l>rx){
		return DEAD;
	}

	if(l<=lx and rx<=r){
		return st[x];
	}

	int mid=(lx+rx)/2;

	int q1=query(l, r, 2*x+1, lx, mid);
	int q2=query(l, r, 2*x+2, mid+1, rx);

	return max(q1, q2);
}

int query(int l, int r){
	return query(l, r, 0, 0, n-1);
}


void dfs(int node, int par){
	up[node][0]=par;

	for(int i=1;i<=20;i++){
		if(up[node][i-1]!=-1){
			up[node][i]=up[up[node][i-1]][i-1];
		}else{
			up[node][i]=-1;
		}
	}


	if(par!=-1)lvl[node]=lvl[par]+1;

	sz[node]=1;

	for(int child: tree[node]){
		if(child!=par){
			dfs(child, node);
			sz[node]+=sz[child];
		}
	}
}

int lca(int u, int v){
	if(lvl[u]<lvl[v])swap(u, v);
	int jump=lvl[u]-lvl[v];

	for(int j=20;j>=0;j--){
		if((jump>>j)&1){
			u=up[u][j];
			if(u==-1)break;
		}
	}

	if(u==v)return u;

	for(int j=20;j>=0;j--){
		if(up[u][j]!=up[v][j]){
			u=up[u][j];
			v=up[v][j];
		}
	}

	return up[u][0];
}

int chainID, pos;
void HLD(int node, int par){
	position[node]=pos++;
	arr[position[node]]=val[node];
	chain[node]=chainID;

	int heavyChild=-1, heavySize=0;

	for(int child: tree[node]){
		if(child!=par){
			if(sz[child]>heavySize){
				heavySize=sz[child];
				heavyChild=child;
			}
		}
	}

	if(heavyChild!=-1){
		HLD(heavyChild, node);
	}

	for(int child: tree[node]){
		if(child==par or child==heavyChild)continue;

		chain[child]=++chainID;
		chainHead[chainID]=child;
		HLD(child, node);

	}
}

int HLDquery(int u, int v){
	int cur=u;
	int ans=0;
	while(chain[cur]!=chain[v]){
		ans=max(ans, query(position[chainHead[chain[cur]]], position[cur]) );
		cur=up[chainHead[chain[cur]]][0];
	}

	return ans=max(ans, query(position[v], position[cur]));
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin>>n>>q;

	for(int i=1;i<=n;i++)cin>>val[i];

	for(int i=1;i<n;i++){
		int u, v;
		cin>>u>>v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	
	dfs(1, -1);
	HLD(1, -1);

	build();

	while(q--){
		int t; cin>>t;
		if(t==1){
			int s, x;
			cin>>s>>x;
			setVal(x, position[s]);
		}

		if(t==2){
			int u, v;
			cin>>u>>v;
			int l=lca(u, v);
			cout<<max(HLDquery(u, l), HLDquery(v, l))<<" ";
		}
	}
	return 0;
}