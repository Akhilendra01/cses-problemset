/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


vector<int> gr[(int)1e5+1];
bool vis[(int)1e5+1];

vector<int> v;

int dfs(int node, int par){
	vis[node]=1;
	for(int child: gr[node]){
		if(!vis[child]){
			int res=dfs(child, node);
			if(res==node){
				v.push_back(node);
				return INT_MAX;
			}

			if(res==INT_MAX){
				return INT_MAX;
			}
			
			if(res!=0){
				v.push_back(node);
				return res;
			}
		}
		else if(child!=par){
			v.push_back(child);
			v.push_back(node);
			return child;
		}
		
	}
	return 0;
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
		if(!vis[i]){
			int res=dfs(i, 0);
			if(res){
				if(res==i){
					cout<<i<<" ";
				}
				break;
			}
		}
	}

	if(v.size()==0)cout<<"IMPOSSIBLE";
	else{
		cout<<v.size()<<"\n";
		for(int x: v)cout<<x<<" ";
	}

	return 0;
}