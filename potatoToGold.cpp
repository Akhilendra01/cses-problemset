#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define mod ((int)1e9 + 7)


int power(int a, int b){
	int r=1;
	while(b){
		if(b&1)r=(r*a)%mod;
		a=(a*a)%mod; b/=2;
	}
	return r;
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int t; cin>>t;
	while(t--){
		int n, k; cin>>n>>k;
		int a[n];

		vector<int> v(k+1, 1);

		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i]%=k;
			v[a[i]]++;
		}

		int f=(power(2, n-v[0]))*v[0];

		for(int i=1;i<k;i++){
			f=(f-(v[i]-1)*(v[k-i]-1)+mod)%mod;
		}	
		cout<<f<<"\n";

	}
	
	return 0;
}