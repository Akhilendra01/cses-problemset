/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

#define mod ((int)1e9+7)

int dp[1001][(1<<11)];


void generateNextMasks(int cur, int i, int next, int n, vector<int>&v){
	if(i==n){
		v.push_back(next);
		return;
	}
	if((cur&(1<<i))!=0)
		generateNextMasks(cur, i+1, next, n, v);

	if(i!=n-1)
	if((cur&(1<<i))==0 and  (cur&(1<<(i+1)))==0 )
		generateNextMasks(cur, i+2, next, n, v);
	
	if((cur&(1<<i))==0)
		generateNextMasks(cur, i+1, next+(1<<i), n, v);
}


int f(int col, int mask, int n, int m){
	if(col==m){
		if(mask == 0)return 1;
		return 0; 
	}

	if(dp[col][mask]!=-1)return dp[col][mask];

	int ans=0;
	vector<int> nextMasks;

	generateNextMasks(mask, 0, 0, n, nextMasks);

	for(int nextMask: nextMasks){
		ans=(ans+f(col+1, nextMask, n, m))%mod;
	}

	return dp[col][mask]=ans;
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
	memset(dp, -1, sizeof(dp));
	cout<<f(0, 0, n, m);
	
	return 0;
}