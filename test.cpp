/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

#define mod ((int)1e9+7)

int n, m;
vector<int> a;

int dp[(int)1e5+1][101];

int f(int idx, int last){
	if(idx<0)return 1;
	
	if(a[idx]!=0 and abs(a[idx]-last)>1)return 0;


	if(dp[idx][last]!=-1)return dp[idx][last];

	if(a[idx]!=0)
		return dp[idx][last]=f(idx-1, a[idx]);
	
	int ans=0;
	for(int x=0;x<=m;x++){
		ans=(ans+f(idx-1, x))%mod;
	}
	return dp[idx][last]=ans;
	
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    a.resize(n);

    for(int i=0;i<n;i++)cin>>a[i];

    memset(dp, -1, sizeof(dp));
	
	int lst=a[n-1];
	if(a[n-1]==0)lst=m;
	cout<<f(n-1, lst);

	return 0;
}