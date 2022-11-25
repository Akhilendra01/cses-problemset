#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define f first
#define s second

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, x; cin>>n>>x;
	int a[n];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	map<int, pair<int, int>> mp;

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int target=x-a[i]-a[j];
			if(mp.count(target)){
				cout<<i+1<<" "<<j+1<<" "<<mp[target].f+1<<" "<<mp[target].s+1;
				return 0;
			}
		}
		for(int j=0;j<i;j++){
			mp[a[i]+a[j]]={i, j};
		}
	}

	cout<<"IMPOSSIBLE";

	return 0;
}