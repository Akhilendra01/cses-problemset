/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

const int inf=1e18;
const int mod=1e9+7;

typedef pair<int, int> pii;
#define f first
#define s second


int n, m;
vector<pii> gr[(int)1e5+1];

int route[(int)1e5+1];
int mx[(int)1e5+1];
int mn[(int)1e5+1];
int dis[(int)1e5+1];

void solve(){
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int u, v, w;
		cin>>u>>v>>w;
		gr[u].push_back({v, w});
	}

	for(int i=1;i<=n;i++){
		dis[i]=inf;
		mn[i]=inf;
	}

	dis[1]=0;
	route[1]=1;
	mn[1]=0;
	mx[1]=0;

	priority_queue<pii> pq;
	pq.push({0, 1});

	while(!pq.empty()){
		int node=pq.top().s;
		int d=-pq.top().f;
		pq.pop();

		if(d>dis[node])continue;

		for(pii child: gr[node]){
			int child_v=child.f;
			int wt=child.s;

			if(dis[child_v]==dis[node]+wt){
				mx[child_v]=max(mx[child_v], mx[node]+1);
				mn[child_v]=min(mn[child_v], mn[node]+1);
				route[child_v]+=route[node];
				route[child_v]%=mod;
			}	

			if(dis[child_v]>dis[node]+wt){
				mx[child_v]=mx[node]+1;
				mn[child_v]=mn[node]+1;
				route[child_v]=route[node];
				dis[child_v]=dis[node]+wt;

				pq.push({-dis[child_v], child_v});
			}
		}
	}

	cout<<dis[n]<<" "<<route[n]<<" "<<mn[n]<<" "<<mx[n];
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
