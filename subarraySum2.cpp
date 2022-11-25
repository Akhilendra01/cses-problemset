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

	vector<int> pre(n+1);
	pre[0]=0;

	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i-1];

	unordered_map<int, int> freq;
	int cnt=0;
	for(int i=0;i<=n;i++){
		cnt+=freq[pre[i]-x];
		freq[pre[i]]++;
	}
	cout<<cnt;
	return 0;
}