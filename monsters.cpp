/*
	author: akhilendra11
*/
 
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long int
#define endl "\n"
 
struct Node{
	int x, y;
};
 
int n, m;
char mat[1001][1001];
 
int vis1[1001][1001];
int vis2[1001][1001];
 
int dist1[1001][1001];
int dist2[1001][1001];
 
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
 
int idx[1001][1001];
 
int mv[]={'D', 'R', 'U', 'L'};
 
 
void bfs1(Node s){
	queue<Node> q;
	q.push(s);
	vis1[s.x][s.y]=1;
	dist1[s.x][s.y]=0;
 
	while(!q.empty()){
		Node node=q.front();
		q.pop();
 
		for(int k=0;k<4;k++){
 
			int x=node.x+dx[k];
			int y=node.y+dy[k];
 
 
			if(x>=0 and y>=0 and x<n and y<m and vis1[x][y]==0){
				dist1[x][y]=1+dist1[node.x][node.y];
				vis1[x][y]=1;
				idx[x][y]=k;
				q.push({x, y});
			}
		}
	}
 
}
 
void bfs2(){
	queue<Node> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j]=='M'){
				q.push({i, j});
				vis2[i][j]=1;
				dist2[i][j]=0;
			}
		}
	}
 
	while(!q.empty()){
		Node node=q.front();
		q.pop();
 
		for(int k=0;k<4;k++){
 
			int x=node.x+dx[k];
			int y=node.y+dy[k];
 
 
			if(x>=0 and y>=0 and x<n and y<m and vis2[x][y]==0){
				dist2[x][y]=1+dist2[node.x][node.y];
				vis2[x][y]=1;
				q.push({x, y});
			}
		}
	}
}
 
 
Node check(){
	for(int i=0;i<n;i++){
		if(mat[i][0]=='.' and vis1[i][0]==1){
			if(dist1[i][0]<dist2[i][0])return {i, 0};
		}
		if(mat[i][m-1]=='.' and vis1[i][m-1]==1){
			if(dist1[i][m-1]<dist2[i][m-1])return {i, m-1};
		}
	}
 
	for(int j=0;j<m;j++){
		if(mat[0][j]=='.' and vis1[0][j]==1){
			if(dist1[0][j]<dist2[0][j])return {0, j};
		}
		if(mat[n-1][j]=='.' and vis1[n-1][j]==1){
			if(dist1[n-1][j]<dist2[n-1][j])return {n-1, j};
		}
	}
 
	return {-1, -1};
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
    	for(int j=0;j<m;j++)dist2[i][j]=INT_MAX;
    }
 
    Node s;
 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
			if(mat[i][j]=='#'){
				vis1[i][j]=1;
				vis2[i][j]=1;
			}
			else if(mat[i][j]=='A'){
				s={i, j};
			}
		}
	}
 	
 	if(s.x==0 or s.x==n-1 or s.y==0 or s.y==m-1){
 		cout<<"YES";
 		return 0;
 	}

	bfs2();
 
	bfs1(s);

	Node r= check();
 
	if(r.x==-1 and r.y==-1){
		cout<<"NO";
	}else{
 
		string ans="";
		while(r.x!=s.x or r.y!=s.y){
			ans+=mv[idx[r.x][r.y]];
 
			r={
				r.x-dx[idx[r.x][r.y]],
				r.y-dy[idx[r.x][r.y]]
			};
		}
		reverse(ans.begin(), ans.end());
		cout<<"YES\n"<<ans.size()<<"\n"<<ans;
	}
	
	return 0;
}