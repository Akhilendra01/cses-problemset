/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

string a, b;
int n, m;

int dp[5001][5001];

int solve(int i, int j){
	if(i<0){
		return j+1;
	}
	if(j<0){
		return i+1;
	}

	if(dp[i][j]!=-1)return dp[i][j];

	if(a[i]==b[j]){
		return dp[i][j]=solve(i-1, j-1);
	}
	else{
		return dp[i][j]=min({
			1+solve(i-1, j-1),
			1+solve(i-1, j),
			1+solve(i, j-1)
		});
	}

}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>a>>b;

    memset(dp, -1, sizeof(dp));

    n=a.length();
    m=b.length();

	int l=solve(n-1, m-1);

	cout<<l;
	
	return 0;
}