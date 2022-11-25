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
	sort(a, a+n);
	int i=0, j=n-1, cnt=0;
	while(i<=j){
		if(a[i]+a[j]<=x)cnt++, i++, j--;
		else if(a[i]+a[j]>x)cnt++, j--;
	}
	cout<<cnt<<endl;
	return 0;
}