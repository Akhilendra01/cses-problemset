/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int n, m;

int a[1002][1002];
bool vis[1002][1002];

int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};

void dfs(int i, int j){
	if(i<0 or j<0 or i>=n or j>=m)return;
	vis[i][j]=1;
	for(int k=0;k<4;k++)
		if( (!vis[i+dx[k]][j+dy[k]]) and a[i+dx[k]][j+dy[k]]!=0)
			dfs(i+dx[k], j+dy[k]);
	
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;


	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char x; cin>>x;
			if(x=='.')a[i][j]=1;
		}
	}

	int cc=0;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]==1 and !vis[i][j]){
				cc++;
				dfs(i, j);
			}
		
	

	cout<<cc;

	return 0;
}