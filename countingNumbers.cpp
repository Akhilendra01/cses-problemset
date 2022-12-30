/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int dp[20][2][2][10];
int n;

int f(string& R, int i, int tight, int leadingZ, int last){
	if(i==n){
		return 1;
	}

	if(dp[i][tight][leadingZ][last]!=-1)return dp[i][tight][leadingZ][last];
	int ans=0;

	int ub= tight? (R[i]- '0'): 9;

	for(int dig=0; dig<=ub;dig++){
		if(dig!=last or (leadingZ==1 and dig==0))
			ans+=f(R, i+1, (tight&(dig==ub)), (leadingZ&(dig==0)), dig);
	}
	return dp[i][tight][leadingZ][last]=ans;
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n1, n2;
    cin>>n1>>n2;	

    n1--;

	string a, b;
	
	a=to_string(n1);
	b=to_string(n2);

	memset(dp, -1, sizeof(dp));
	n=a.length();
	int x=f(a, 0, 1, 1, 0);

	memset(dp, -1, sizeof(dp));
	n=b.length();
	int y=f(b, 0, 1, 1, 0);
	
	cout<<y-x;
	
	return 0;
}