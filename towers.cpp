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
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	multiset<int>s;
	int cnt=0;
	for(int i=0;i<n;i++){
		auto x=s.upper_bound(a[i]);
		if(x!=s.end()){
			s.erase(x);
		}
		s.insert(a[i]);
	}
	cout<<s.size();
	return 0;
}