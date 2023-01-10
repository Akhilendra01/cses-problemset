/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

#define N (int)2e5+1

int a[N+1], cnt[N*10], distinct;

struct query{
	int l, r, ans, id, block;
}q[N];


void add(int val){
	cnt[val]++;
	if(cnt[val]==1)distinct++;
}

void remove(int val){
	cnt[val]--;
	if(cnt[val]==0)distinct--;
}

void solve(){
	int n, m;
	cin>>n;		m=sqrt(n)+1;

	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];


	int queries; cin>>queries;
	
	for(int i=0;i<queries;i++){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
		q[i].l--;	q[i].r--;

		q[i].block=q[i].l/m;
		
		q[i].ans=0;
	}

	sort(q, q+queries, [&](query q1, query q2){
		return make_pair(q1.block, q1.r) < make_pair(q2.block, q2.r);
	});

	int ans[queries];
	int x=0, y=0;

	for(int i=0;i<queries;i++){
		while(y<=q[i].r){
			add(a[y++]);
		}

		while(y>q[i].r+1){
			remove(a[y--]);
		}

		while(x>q[i].l){
			add(a[--x]);
		}

		while(x<q[i].l){
			remove(a[x++]);
		}

		ans[q[i].id]=distinct;
	}

	for(int i=0;i<queries;i++)cout<<ans[i]<<"\n";

}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
	
	return 0;
}