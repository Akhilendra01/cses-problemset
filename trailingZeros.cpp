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
	int p=5, cnt=0;
	while(n/p>0){
		cnt+=n/p;
		p*=5;
	}
	cout<<cnt<<endl;
	return 0;
}