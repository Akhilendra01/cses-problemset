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
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin>>n;
	for(int i=0;i<pow(2, n);i++){
		string ans="";
		int d=0;
		while(d<n){
			int x=(i>>d)&1;
			int y=(i>>(d+1))&1;
			ans=to_string(x^y)+ans;
			d++;
		}
		cout<<ans<<endl;
	}
	return 0;
}