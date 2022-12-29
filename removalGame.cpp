/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int n;
int a[5001];

int dp[5001][5001][2];

int f(int i, int j, int first){
	if(i>j)return 0;
	if(dp[i][j][first]!=-1)return dp[i][j][first];
	if(first){
		return dp[i][j][first]=max(a[i]+f(i+1, j, 0), a[j]+f(i, j-1, 0));
	}else{
		return dp[i][j][first]=min(f(i+1, j, 1), f(i, j-1, 1));
	}
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];

	memset(dp, -1, sizeof(dp));
	cout<<f(0, n-1, 1);
	
	return 0;
}