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
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
	map<int, int> freq;

	int i=0, j=0;

	int cnt=0;
	while(i<n or j<n){
		while(j<n and (freq.size()<k or freq.count(a[j])>0)){
			freq[a[j]]++;
			j++;
		}

		cnt+=j-i;
		freq[a[i]]--;
		if(freq[a[i]]==0){
			freq.erase(a[i]);
		}
		i++;
	}

	cout<<cnt;
	
	return 0;
}