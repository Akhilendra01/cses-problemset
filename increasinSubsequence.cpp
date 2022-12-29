/*
	author: akhilendra11
*/


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

	vector<int> v;

	for(int i=0;i<n;i++){
		auto x=upper_bound(v.begin(), v.end(), a[i]);
		auto y=lower_bound(v.begin(), v.end(), a[i]);
		if(x==v.end() and y==v.end())v.push_back(a[i]);
		else if(*y!=a[i])*x=a[i];
	}
	
	cout<<v.size();
	return 0;
}