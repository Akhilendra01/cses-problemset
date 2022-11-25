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

	int n, k; cin>>n>>k;
	int a[n], mx=INT_MIN;

	for(int i=0;i<n;i++)cin>>a[i], mx=max(mx, a[i]);
	
	int cur=0;

	int s=mx, e=1e18;
	int ans=1;
	while(s<=e){
		int mid=(s+e)/2;
		int parts=1, cur=0;
		for(int i=0;i<n;i++){
			if(cur+a[i]<=mid){
				cur+=a[i];
			}
			else{
				cur=a[i];
				parts++;
			}
		}
		if(parts<=k){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	cout<<s;
	return 0;
}