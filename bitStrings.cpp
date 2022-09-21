#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define mod 1000000007

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	int ans=1, a=2;
	while(n){
		if(n&1)ans=(ans*a)%mod;
		n/=2; a=(a*a)%mod;
	}
	cout<<ans<<endl;
	return 0;
}