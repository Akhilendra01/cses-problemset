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

	int n; cin>>n;
	int a[n], b[n], c[n];

	map<int, int> compress;

	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
		b[i]++;
		compress[a[i]];
		compress[b[i]];
	}

	int x=0;

	for(auto &p: compress){
		p.second=(x++);
	}

	vector<pair<int, int>> projects[x];

	for(int i=0;i<n;i++){
		projects[compress[b[i]]].push_back({compress[a[i]], c[i]});
	}

	vector<int> dp(x);

	for(int i=0;i<x;i++){
		if(i>0)dp[i]=dp[i-1];

		for(pair<int, int>p: projects[i]){
			dp[i]=max(dp[i], dp[p.first]+p.second);
		}
	}

	cout<<dp[x-1];
	
	return 0;
}