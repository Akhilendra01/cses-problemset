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

	sort(a, a+n);
	int cur=0;
	for(int i=0;i<n;i++){
		if(cur+1<a[i]){
			break;
		}
		else {
			cur+=a[i];
		}
	}

	cout<<cur+1;
	
	return 0;
}