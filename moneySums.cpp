/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int n;
int a[101];

int f(int i, int sum){
	if(sum)
	if(i==n)return 0;
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];

	vector<int> prev(1e5+1);
	vector<int> cur(1e5+1);

	prev[0]=1;

	for(int i=1;i<=n;i++){
		for(int j=0;j<=1e5;j++){
			if(a[i-1]<=j){
				cur[j]=(prev[j]|prev[j-a[i-1]]);
			}else{
				cur[j]=prev[j];
			}
		}
		prev=cur;
	}

	int ans=0;
	for(int i=1;i<=1e5;i++){
		if(prev[i]!=0)ans++;
	}


	cout<<ans<<"\n";
	for(int i=1;i<=1e5;i++){
		if(prev[i]!=0)cout<<i<<" ";
	}
	return 0;
}