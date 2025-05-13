#include<bits/stdc++.h>
using namespace std;

#define int               long long int
#define double            long double
#define vi                vector<int>
#define pii               pair<int, int>
#define rep(i, s, n, m)   for(i=s;i<n;i+=m)
#define pb                push_back
#define ff                first
#define ss                second
#define entire(a)         begin(a), end(a)  

template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }

const int inf{(int)1e18};
const int mod{(int)1e9+7};
const double PI{(double)acos(-1)};
const bool testcases{false};

void solve(){
  int n;
  cin>>n;

  vector<vi> dp(n, vi(n, inf));
  dp[0][0]=0;

  queue<pii> q;
  q.push({0, 0});

  while(!q.empty()){
  	auto[i, j]{q.front()};
  	q.pop();

  	for(int di: {-2, -1, 1, 2})
  	for(int dj: {-2, -1, 1, 2}){
  		if(abs(di)==abs(dj))continue;

  		int ni{i+di}, nj{j+dj};
  		if(ni<0 or nj<0 or ni>=n or nj>=n)continue;

  		if(dp[ni][nj]>1+dp[i][j]){
  			dp[ni][nj]=1+dp[i][j];
  			q.push({ni, nj});
  		}
  	}
  }
  for(int i{};i<n;i++)cout<<dp[i]<<"\n";
}

int32_t main(){
#ifndef ONLINE_JUDGE
  freopen("f.in", "r", stdin);
  freopen("f.out", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t{1};
  if(testcases)cin>>t;
  while(t--){
    solve();
  }
  
  return 0;
}