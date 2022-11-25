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
		int n, k;
		cin>>n>>k;

		int a[n];
		bool ok=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int idx=-1;
		for(int i=0;i<n;i++){
			if(a[i]==k){
				idx=i;
				break;
			}
		}
		if(n==1 and a[0]==k){
			cout<<"YES\n";
		}
		else if(idx==-1 or idx==n-1){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}

	}
	
	return 0;
}