#include<bits/stdc++.h>
using namespace std;
 
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
 
int ar[(int)1e7+1];
 
void solve(){
  int n, k, x, a, b, c;
  cin>>n>>k>>x>>a>>b>>c;
 
  ar[0]=x%c;
  for(int i{1};i<n;i++){
  	ar[i]=((a*1ll*ar[i-1])%c+1ll*b)%c;
  }
 
  multiset<int> st;
  for(int i{};i<k;i++){
		st.insert(ar[i]);  
  }
 
  int xor_sum{*st.begin()};
  for(int i{k};i<n;i++){
  	st.extract(ar[i-k]);
  	st.insert(ar[i]);
  	xor_sum^=*st.begin();
  }
  cout<<xor_sum;
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
