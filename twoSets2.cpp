/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

#define mod ((int)1e9+7)

int power(int a, int b){
	int r=1;
	while(b){
		if(b&1)r=(r*a)%mod;
		a=(a*a)%mod; b/=2;
	}
	return r;
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n;
	cin>>n;
	int sum=n*(n+1)/2;
	if(sum%2){
		cout<<"0";
		return 0;
	} 

	vector<int> prev(sum/2+1);
	vector<int> cur(sum/2+1);

	prev[0]=1;

	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum/2;j++){
			if(j>=i){
				cur[j]=(prev[j]+prev[j-i])%mod;
			}else{
				cur[j]=prev[j];
			}
		}
		prev=cur;
	}

	cout<<(prev[sum/2]*power(2, mod-2))%mod;
	
	return 0;
}