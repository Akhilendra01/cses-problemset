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

	int n; 	cin>>n;
	vector<pair<int, int>> v(n);
	for(int i=0;i<n;i++)cin>>v[i].first, v[i].second=i;

	sort(v.begin(), v.end());
	
	int cnt=1;
	for(int i=1;i<n;i++){
		if(v[i].second<v[i-1].second)cnt++;
	}

	cout<<cnt;

	return 0;
}