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

	int n, m, k; cin>>n>>m>>k;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int b[m];
	for(int i=0;i<m;i++)cin>>b[i];

	vector<pair<int, int>> v(n);
	for(int i=0;i<n;i++)v[i]={a[i]-k, a[i]+k};
	sort(v.begin(), v.end());
	sort(b, b+m);
	int i=0, j=0, cnt=0;
	while(i<n and j<m){
		if(b[j]>=v[i].first and b[j]<=v[i].second){cnt++; i++, j++;}
		else if(b[j]<v[i].first){j++;}
		else if(b[j]>v[i].second){i++;}
	}	
	cout<<cnt<<endl;
	return 0;
}