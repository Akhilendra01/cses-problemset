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
	vector<pair<int, int>> a(n);
	for(int i=0;i<n;i++)cin>>a[i].first, a[i].second=i;

	sort(a.begin(), a.end());

	int i=0, j=n-1;
	vector<int> res;
	while(i<j){
		if(a[i].first+a[j].first==x){
			res={a[i].second+1, a[j].second+1};
			break;
		}
		if(a[i].first+a[j].first<x)i++;
		else j--;
	}
	if(res.size()==0){
		cout<<"IMPOSSIBLE";
		return 0;
	}

	sort(res.begin(), res.end());
	cout<<res[0]<<" "<<res[1];
	
	return 0;
}