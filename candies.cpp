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
		int n; cin>>n;
		int a[2*n];

		unordered_map<int, int> freq;

		for(int i=0;i<2*n;i++){
			cin>>a[i];
			freq[a[i]]++;
		}

		bool ok=1;
		for(pair<int, int> p: freq){
			if(p.second>2){
				ok=0;
				break;
			}
		}
		if(ok)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}