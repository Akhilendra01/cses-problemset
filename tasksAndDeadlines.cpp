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
	int d[n], f[n];
	int sum=0;
	for(int i=0;i<n;i++)cin>>d[i]>>f[i], sum+=f[i];

	sort(d, d+n, greater<int>());
	
	for(int i=0;i<n;i++){
		sum-=d[i]*(i+1);
	}
	cout<<sum;
	return 0;
}