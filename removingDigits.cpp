#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int mxDig(int n){
	int mx=0;
	while(n){
		mx=max(n%10, mx);
		n/=10;
	}
	return mx;
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	int cnt=0;
	while(n){
		n-=mxDig(n);
		cnt++;
	}
	cout<<cnt;
	
	return 0;
}