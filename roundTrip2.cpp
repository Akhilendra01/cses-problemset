/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int n, m;
vector<int> gr[(int)1e5+1];

stack<int> s;
int inst[(int)1e5+1];
int vis[(int)1e5+1];

bool dfs(int node){
	vis[node]=1;
	
	inst[node]=1;
	s.push(node);

	for(int child: gr[node]){
		if(!vis[child])
			if(dfs(child))return true;

		if(inst[child]){
			s.push(child);
			return true;
		}
	}

	s.pop();
	inst[node]=0;
	return false;
}

void solve(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u, v;
		cin>>u>>v;
		gr[u].push_back(v);
	}

	bool ok=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ok=dfs(i);
			if(ok)break;
		}
	}
	if(!ok){
		cout<<"IMPOSSIBLE";
		return;
	}

	vector<int> v;
	v.push_back(s.top()); s.pop();

	while(s.size()>0 and s.top()!=v[0]){
		v.push_back(s.top()); s.pop();
	}

	v.push_back(v[0]);
	reverse(v.begin(), v.end());
	cout<<v.size()<<"\n";
	for(int x: v)cout<<x<<" ";

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
