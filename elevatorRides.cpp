/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, x; cin>>n>>x;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];

	int lim=(1<<n);
	vector<pair<int, int>> dp(lim);
	dp[0]={1, 0};


	for(int mask=1; mask<lim ;mask++){
		pair<int, int> best={INT_MAX, INT_MAX};
		for(int i=0;i<n;i++){
			if( (mask&(1<<i)) == 0 )continue;

			pair<int, int> res=dp[mask^(1<<i)];

			if(res.second+a[i]<=x){
				res.second+=a[i];
			}else{
				res.second=a[i];
				res.first+=1;
			}

			best=min(best, res);
		}

		dp[mask]=best;
	}

	cout<<dp[lim-1].first;
	
	return 0;
}