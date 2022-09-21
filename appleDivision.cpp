#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


int n, sum;
int dif=INT_MAX;
void func(int *a, int idx=0, int s1=0){
	if(idx==n){
		int s2=sum-s1;
		dif=min(dif, abs(s1-s2));
		return;
	}
	func(a, idx+1, s1);
	func(a, idx+1, s1+a[idx]);
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)sum+=a[i];
	
	func(a);
	cout<<dif<<endl;
	

	return 0;
}