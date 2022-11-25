#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int pre[100005][60];

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int t; cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;

		int a[n+1];
		for(int i=1;i<=n;i++)cin>>a[i];

		for(int i=1;i<=n;i++){
			for(int k=0;k<60;k++){
				pre[i][k]=pre[i-1][k]+((a[i]>>k)&1);
			}
		}

		while(q--){
			int k; cin>>k;
			int l1, r1, l2, r2;
			cin>>l1>>r1>>l2>>r2;

			int n1=r1-l1+1;
			int n2=r2-l2+1;

			int set1=pre[r1][k]-pre[l1-1][k];
			int set2=pre[r2][k]-pre[l2-1][k];
			
			int ans=set1*(n2-set2)+set2*(n1-set1);

			cout<<ans<<"\n";

		}
	}
	
	return 0;
}