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

	int n, x; cin>>n>>x;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];

	int i=0, j=0;
	int cur=0, cnt=0;
	while(i<n or j<n){
		while(cur<x and j<n){
			cur+=a[j];
			j++;
		}
		if(cur==x){
			cnt++;
		}
		cur-=a[i];
		i++;
	}
	cout<<cnt;

	return 0;
}