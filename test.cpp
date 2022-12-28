/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


#define N ((1<<18)+5)

int n;
int freq[N];

void solve(){
	cin>>n;
	memset(freq, 0, sizeof(freq));

	int x=0, y;
	freq[0]=1;
	int ans=n*(n+1)/2;
	for(int i=0;i<n;i++){
		cin>>y;
		x^=y;

		for(int j=0;j<(1<<9);j++){
			ans-=freq[(j*j)^x];
		}	

		freq[x]++;
	}

	cout<<ans<<"\n";

}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}