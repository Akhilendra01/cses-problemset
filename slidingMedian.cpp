#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//find_by_order() order_of_key()

using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define endl "\n"

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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

    pbds s;
	
	for(int i=0;i<k;i++){
		s.insert({a[i], i});
	}
	cout<<(*s.find_by_order((k-1)/2)).first<<" ";

	int i=1;
	while(i<n-k+1){

		// for(auto p: s)cout<<p.first<<" "; cout<<"\n";

		s.erase({a[i-1], i-1});
		s.insert({a[i+k-1], i+k-1}); 
		cout<<(*s.find_by_order((k-1)/2)).first<<" ";
		i++;
	}

	
	return 0;
}