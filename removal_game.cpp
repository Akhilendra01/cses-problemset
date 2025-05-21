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

int dp[5000][5000];
 
void solve(){
  int n;
  cin>>n;
 
  vi a(n);
  cin>>a;
  memset(dp, -1, sizeof(dp));
 
  function<int(int, int)> f{
  	[&](int i, int j)->int{
  		if(i>j){
  			return 0;
  		}
  		if(dp[i][j]!=-1)return dp[i][j];
  		return dp[i][j]=max(a[i]-f(i+1, j), a[j]-f(i, j-1));
  	}
  };

  int tot{accumulate(entire(a), 0ll)};
 	
  cout<<(tot+f(0, n-1))/2<<"\n";
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