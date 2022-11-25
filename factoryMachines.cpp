#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

bool good(int *a, int n, int time, int t){
	int items=0;
	for(int i=0;i<n;i++){
		items+=time/a[i];
	}
	return items>=t;
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, t; cin>>n>>t;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];

	sort(a, a+n);
	int s=0, e=a[0]*t;
	int ans=a[0]*t;

	while(s<=e){
		int m=(s+e)/2;
		if(good(a, n, m, t)){
			ans=m;
			e=m-1;
		}
		else{
			s=m+1;
		}
	}
	cout<<ans;
	return 0;
}