/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int dist[505][505];

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	for(int i=0;i<=500;i++){
		for(int j=0;j<=500;j++)if(i!=j)dist[i][j]=1e15;
	}

	int n, m, q;
	cin>>n>>m>>q;

	for(int i=0;i<m;i++){
		int x, y, wt;
		cin>>x>>y>>wt;
		dist[x][y]=min(dist[x][y], wt);
		dist[y][x]=min(dist[y][x], wt);
	}

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][k]!=1e15 and dist[k][j]!=1e15)
					dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}		

	while(q--){
		int x, y;
		cin>>x>>y;

		int ans=dist[x][y];
		if(ans==1e15)cout<<"-1\n";
		else cout<<ans<<"\n";
	}
	
	return 0;
}