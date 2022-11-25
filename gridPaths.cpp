#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"



int vis[8][8];

int solve(char* s, int idx, int i, int j){
	if(i<1 or i>7 or j<1 or j>7)return 0;
	if(vis[i][j]==1)return 0;
	if(i==7 and j==1){
		if(idx==48)return 1;
		return 0;
	}
	
	vis[i][j]=1;
	int cnt=0;

	if(s[idx]=='?'){
		cnt+=solve(s, idx+1, i, j+1);
		cnt+=solve(s, idx+1, i, j-1);
		cnt+=solve(s, idx+1, i+1, j);
		cnt+=solve(s, idx+1, i-1, j);
	}
	else{
		if(s[idx]=='R')cnt+=solve(s, idx+1, i, j+1);
		if(s[idx]=='L')cnt+=solve(s, idx+1, i, j-1);
		if(s[idx]=='D')cnt+=solve(s, idx+1, i+1, j);
		if(s[idx]=='U')cnt+=solve(s, idx+1, i-1, j);

	}
	vis[i][j]=0;
	return cnt;
}









int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i=0;i<=7;i++)for(int j=0;j<=7;j++)vis[i][j]=0;
  
	char s[48];
	cin>>s;
	solve(s, 0, 1, 1);
	
	return 0;
}