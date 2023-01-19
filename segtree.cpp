/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

#define N (int)2e5+5

#define DEAD INT_MIN

int st[2*N];

int n;
int a[N];

int merge(int q1, int q2){
	return max(q1, q2);
}
void build(int x, int lx, int rx){
	if(rx-lx==1){
		st[x]=a[lx];
		return;
	}

	int mid=(lx+rx)/2;
	build(2*x+1, lx, mid);
	build(2*x+2, mid, rx);

	st[x]=merge(st[2*x+1], st[2*x+2]);
}

void build(){
	build(0, 0, n);
}



void setVal(int val, int idx, int node, int l, int r){
	if(r-l==1){
		st[node]=val;
		return;
	}

	int mid=(l+r)/2;

	if(idx<mid){
		setVal(val, idx, 2*node+1, l, mid);
	}else{
		setVal(val, idx, 2*node+2, mid, r);
	}

	st[node]=max(st[2*node+1], st[2*node+2]);
}


int query(int l, int r, int x, int lx, int rx){
	if(lx>=r or l>=rx){
		return DEAD;
	}

	if(l<=lx and rx<=r){
		return st[x];
	}

	int mid=(lx+rx)/2;

	int q1=query(l, r, 2*x+1, lx, mid);
	int q2=query(l, r, 2*x+2, mid, rx);

	return merge(q1, q2);
}

int query(int l, int r){
	return query(l, r, 0, 0, n);
}



void setVal(int val, int idx){
	setVal(val, idx, 0, 0, n);
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

	// for(int i=0;i<n;i++){
	// 	setVal(a[i], i);
	// }

	build();
	for(int i=0;i<n;i++)cout<<st[i]<<" ";

	cout<<"\n";

	cout<<query(0, 9);
	
	return 0;
}
