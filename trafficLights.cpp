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

	int n, x;
	cin>>n>>x;

	set<int> s;
	multiset<int> dist;
	s.insert(0);
	s.insert(n);
	dist.insert(n);

	while(x--){
		int y; cin>>y;
		auto l=s.upper_bound(y);
		auto r=l--;

		dist.erase(dist.find(*r-*l));
		s.insert(y);
		dist.insert(*r-y);
		dist.insert(y-*l);

		auto ans=dist.end();
		ans--;
		cout<<*ans<<" ";

	}
	
	return 0;
}