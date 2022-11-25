#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


struct range{
	int l, r, i;
};

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	vector<range> v(n);

	for(int i=0;i<n;i++){
		cin>>v[i].l>>v[i].r;
		v[i].i=i;
	}

	sort(v.begin(), v.end(), [&](range r1, range r2){
		if(r1.l<r2.l)return 1;
		else if(r1.l==r2.l){
			if(r1.r>r2.r)return 1;
		}
		return 0;
	});

	vector<pair<int, int>> ans;
	int minRB=INT_MAX;

	for(int i=n-1;i>=0;i--){
		if(v[i].r<minRB){
			minRB=v[i].r;
			ans.push_back({v[i].i, 0});
		}
		else{
			ans.push_back({v[i].i, 1});
		}
	}

	sort(ans.begin(), ans.end());
	for(pair<int, int> p: ans) cout<<p.second<<" "; cout<<"\n";

	ans.clear();
	int maxRB=INT_MIN;
	for(int i=0;i<n;i++){
		if(maxRB<v[i].r){
			maxRB=v[i].r;
			ans.push_back({v[i].i, 0});
		}
		else{
			ans.push_back({v[i].i, 1});
		}
	}
	sort(ans.begin(), ans.end());
	for(pair<int, int> p: ans)cout<<p.second<<" "; cout<<"\n";
	
	return 0;
}