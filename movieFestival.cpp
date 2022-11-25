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
	vector<pair<int, int>> v(n);

	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}

	sort(v.begin(), v.end(), [&](pair<int, int> p1, pair<int, int> p2){
		return p1.second<p2.second;
	});

	int cnt=1;
	int last=v[0].second;

	for(int i=1;i<n;i++){
		if(v[i].first>=last){
			cnt++;
			last=v[i].second;
		}
	}
	
	cout<<cnt;
	return 0;
}