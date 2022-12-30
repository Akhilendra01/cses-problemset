/*
	author: akhilendra11
*/
 
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long int
#define endl "\n"
 
 
struct Node{
	int f, s;
};
 
int n, m;
bool vis[1000][1000];
int dist[1000][1000];
int movIdx[1000][1000];
 
	
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
 
char mov[]={'D', 'R', 'U', 'L'};
 
int si, sj, fi, fj;
 
void bfs(int x, int y){
	queue<Node> q;
	q.push({x, y});
 
	vis[x][y]=1;
	dist[x][y]=0;
 
	while(!q.empty()){
		Node node=q.front();
		q.pop();
 
		int I=node.f;
		int J=node.s;
 
		for(int i=0;i<4;i++){
			int X=I+dx[i];
			int Y=J+dy[i];
 
			if(X>=0 and Y>=0 and X<n and Y<m and !vis[X][Y]){
				movIdx[X][Y]=i;
				vis[X][Y]=1;
				dist[X][Y]=dist[I][J]+1;
				q.push({X, Y});
			}
		}

		if(vis[fi][fj])break;
	}
}
 
int32_t main(){
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
	cin>>n>>m;
	char x;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>x;
			if(x=='#')vis[i][j]=1;
			else if(x=='A')si=i, sj=j;
			else if(x=='B')fi=i, fj=j;
		}
	}
 
	bfs(si, sj);
 
	if(dist[fi][fj]==0){
		cout<<"NO";
	}else{
		cout<<"YES\n"<<dist[fi][fj]<<"\n";
 
		string ans="";
 
		while(fi!=si or fj!=sj){
			ans+=mov[movIdx[fi][fj]];
			int FI = fi-dx[movIdx[fi][fj]];
			int FJ = fj-dy[movIdx[fi][fj]];
			fi=FI; fj=FJ;
		}
 		reverse(ans.begin(), ans.end());
		cout<<ans;
	}
	
	return 0;
}