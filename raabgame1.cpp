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
const bool testcases{true};

void solve(){
  int n, a, b;
  cin>>n>>a>>b;

  int d{n-a-b};

  if(d<0){
    cout<<"NO\n";
    return;
  }

  vi pa(n), pb(n);

  iota(entire(pa), 1ll);
  iota(entire(pb), 1ll);


  bool flip{false};

  if(a<b){
    swap(a, b);
    flip=true;
  }

  int del{n-a-d};

  for(int i{};i<a;i++){
    if(i+del<n){
      pa[i]=pa[i+del];
    }else{
      cout<<"NO\n";
      return;
    }
  }

  for(int j{a}, k{1};j<n and k<=del;j++, k++){
    pa[j]=k;
  } 

  if(flip){
    swap(a, b);
    swap(pa, pb);
  }

  int ca{}, cb{};
  for(int i{};i<n;i++){
    if(pa[i]>pb[i])ca++;
    if(pa[i]<pb[i])cb++;
  }

  if(ca!=a or cb!=b){
    cout<<"NO\n";
    return;
  }

  cout<<"YES\n";
  cout<<pa<<"\n"<<pb<<"\n";
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