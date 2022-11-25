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

	int i=0, j=0;
	int mx=INT_MIN, cur=0;
	
	while(i<n and j<n){
		while(j<n){
			cur+=a[j];
			if(cur<=0){
				mx=max(mx, cur);
				cur=0;
				j++;
				break;
			}
			j++;
			mx=max(mx, cur);
		}
		i=j;
	}
	cout<<mx;
	
	return 0;
}