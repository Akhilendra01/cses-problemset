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
	int a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
 
	int i=1, j=1;
	unordered_map<int, int> last;
	int mx=-1;
	
	while(i<=n and j<=n){
		while(j<=n){
			if(last[a[j]]){
				mx=max(mx, j-i);
				i=max(i, last[a[j]]+1);
				last[a[j]]=0;
			}
			else{
				last[a[j]]=j;
				j++;
			}
		}
		mx=max(j-i, mx);
	}
	cout<<mx;
	return 0;
}