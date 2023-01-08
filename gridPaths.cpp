/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

string s;
const int n=48;

int vis[8][8];

int f(int i, int j, int idx){
	if(vis[i][j]){	
		return 0;
	}
	if(i==7 and j==1 and idx==48){
		return 1;
	}
	if(i==0 or j==0 or i==8 or j==8 or idx==48)return 0;


	vis[i][j]=1;

	int ans=0;

	if(s[idx]=='L')ans=f(i, j-1, idx+1);
	if(s[idx]=='U')ans=f(i-1, j, idx+1);
	if(s[idx]=='R')ans=f(i, j+1, idx+1);
	if(s[idx]=='D')ans=f(i+1, j, idx+1);

	if(s[idx]=='?')ans=f(i, j-1, idx+1)+f(i-1, j, idx+1)+f(i, j+1, idx+1)+f(i+1, j, idx+1);

	vis[i][j]=0;
	return ans;

}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


	cin>>s;


	cout<<f(1, 1, 0);
	
	return 0;
}