#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
//find_by_order() order_of_key()

using namespace std;

#define int long long int
#define endl "\n"
#define ff first
#define ss second

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void update(int start, vector<int>&tree, int n, int val){
	for(;start<=n;start+=start&(-start))tree[start]+=val;
}

int query(int start, vector<int>&tree){
	int sum=0;
	for(;start>0;start-=start&(-start))sum+=tree[start];
	return sum;
}


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

	vector<pair<int, int>> opening(n);
	vector<pair<int, int>> closing(n);

	for(int i=0;i<n;i++){
		opening[i]={v[i].l, v[i].i};
		closing[i]={v[i].r, i};
	}

	sort(closing.begin(), closing.end(), [&](pair<int, int> p1, pair<int, int> p2){
		if(p1.ff<p2.ff)return true;
		if(p2.ff<p1.ff)return false;
		return p1.ss>p2.ss;
	});
	
	vector<int> BIT1 (n+1, 0);
	vector<int> BIT2 (n+1, 0);

	vector<int> ans1(n);
	vector<int> ans2(n);

	int i=0, j=0;
	while(i<n or j<n){
		if(i<n and opening[i].ff<closing[j].ff){
			update(i+1, BIT1, n, 1);
			i++;
		}else{
			update(closing[j].ss+1, BIT1, n, -1);
			int val=query(closing[j].ss+1, BIT1);
			int isorted=closing[j].ss;
			int iactual=opening[isorted].ss;
			ans1[iactual]=val;
			j++;
		}
	}

	i=0, j=0;
	while(i<n or j<n){
		if(i<n and opening[i].ff<closing[j].ff){
			i++;
		}else{
			int val=query(closing[j].ss+1, BIT2);
			int isorted=closing[j].ss;
			int iactual=opening[isorted].ss;
			ans2[iactual]=val;
			update(1, BIT2, n, 1);
			if(closing[j].ss+2<=n){
				update(closing[j].ss+2, BIT2, n, -1);
			}
			j++;
		}
	}

	for(int i: ans2)cout<<i<<" "; cout<<"\n";
	for(int i: ans1)cout<<i<<" ";

	return 0;
}