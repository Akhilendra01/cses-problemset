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

	int n, m;
	cin>>n>>m;

	int a[n+1];
	vector<int> pos(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=i;
	}

	int cnt=1;
	for(int i=2;i<=n;i++){
		if(pos[i]<pos[i-1]){
			cnt++;
		}
	}

	while(m--){
		int x, y;
		cin>>x>>y;

		int n1=min(a[x], a[y]);
		int n2=max(a[x], a[y]);

		set<pair<int, int>> s;


		if(n1-1!=0)s.insert({n1-1, n1});
		if(n1+1!=n+1)s.insert({n1, n1+1});
		if(n2-1!=0)s.insert({n2-1, n2});
		if(n2+1!=n+1)s.insert({n2, n2+1});

		for(pair<int, int> p: s){
			if(pos[p.first]>pos[p.second])cnt--;
		}

		swap(pos[n1], pos[n2]);
		swap(a[x], a[y]);

		for(pair<int, int> p: s){
			if(pos[p.first]>pos[p.second])cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}