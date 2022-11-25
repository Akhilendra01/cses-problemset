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
	vector<pair<int, int>> a(n);

	for(int i=0;i<n;i++){
		cin>>a[i].f;
		a[i].s=i+1;
	}
	
	sort(a.begin(), a.end());

	bool ok=0;

	for(int i=0;i<n-2;i++){
		int j=i+1, k=n-1;
		int target=x-a[i].f;
		if(target<0)break;
		while(j<k){
			if((a[j].f+a[k].f)>target){
				k--;
			}
			else if(a[j].f+a[k].f<target){
				j++;
			}
			else{
				ok=1;
				cout<<a[i].s<<" "<<a[j].s<<" "<<a[k].s;
				break;
			}
		}
		if(ok)break;
	}
	if(!ok)cout<<"IMPOSSIBLE";
	return 0;
}