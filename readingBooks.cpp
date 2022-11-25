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
	int a[n], sum=0;
	for(int i=0;i<n;i++)cin>>a[i], sum+=a[i];

	sort(a, a+n);
	cout<<max(sum, a[n-1]*2);
	
	return 0;
}