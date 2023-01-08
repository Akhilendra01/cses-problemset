/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


vector<int> tree[(int)2e5+1];
int up[(int)2e5+1][21];

void binary_lifting(int node, int par){
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
			binary_lifting(child, node);
		}
	}
}


int query(int node, int jump){
	if(jump==0)return node;
	for(int j=20;j>=0;j--){
		if((jump>>j)&1){
			node=up[node][j];
			if(node<=0){
				return -1;
			}
		}
	}
	return node;
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
		int x; cin>>x;
		tree[x].push_back(i);
		tree[i].push_back(x);
	}

	binary_lifting(1, 0);

	while(q--){
		int x, k;
		cin>>x>>k;
		cout<<query(x, k)<<"\n";
	}

	return 0;
}