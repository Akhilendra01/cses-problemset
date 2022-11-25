#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

struct stay{
	int s, e, i;
};


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	vector<stay> v(n);

	for(int i=0;i<n;i++){
		cin>>v[i].s>>v[i].e;
		v[i].i=i;
	}

	sort(v.begin(), v.end(), [&](stay a, stay b){
		if(a.s<b.s)return true;
		if(a.s==b.s and a.e<b.e)return true;
		return false;
	});

	// for(stay s: v)cout<<s.s<<" "<<s.e<<" "<<s.i<<"\n"; 

	vector<int> ans(n, -1);
	int cnt=1, cur=1;
	ans[v[0].i]=1;

	multimap<int, int>mp;
	mp.insert({v[0].e, ans[v[0].i]});

	for(int i=1;i<n;i++){
		auto x=mp.lower_bound(v[i].s);
		if(x==mp.begin()){
			cur++; cnt++;
			ans[v[i].i]=cur;
		}else{
			x--;
			ans[v[i].i]=x->second;
			mp.erase(x);
		}
		mp.insert({v[i].e, ans[v[i].i]});
	}

	cout<<cnt<<"\n";
	for(int i: ans)cout<<i<<" ";

	return 0;
}