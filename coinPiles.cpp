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

	int t; cin>>t;
	while(t--){
		int a, b;	cin>>a>>b;

		int x=2*a-b;
		int y=2*b-a;

		if(x%3==0 and y%3==0 and x>=0 and y>=0){
			cout<<"YES\n";
		}
		else {
			cout<<"NO\n";
		}
	}
	
	return 0;
}