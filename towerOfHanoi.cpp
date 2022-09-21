#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


vector<pair<int, int>> moves;
int cnt=0;

void towerOfHanoi(int n, int from, int helper, int to){
	if(n==0)return;
	towerOfHanoi(n-1, from, to, helper);
	moves.push_back({from, to});
	cnt++;
	towerOfHanoi(n-1, helper, from, to);
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	towerOfHanoi(n, 1, 2, 3);
	cout<<cnt<<endl;

	for(auto i: moves){
		cout<<i.first<<" "<<i.second<<endl;
	} 
	return 0;
}