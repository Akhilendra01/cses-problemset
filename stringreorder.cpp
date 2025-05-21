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
  string s;
  cin>>s;

  int n{(int)s.size()};

  vi freq(26);
  for(int i{};i<n;i++)freq[s[i]-'A']++;

  int mx{*max_element(entire(freq))};
	if(mx>(n+1)/2){
		cout<<"-1\n";
		return;
	}

  string res{};
	char prev{'.'};
  for(int i{};i<n;i++){
  	for(int j{};j<26;j++){
  		if(freq[j]==0 or j==(prev-'A'))continue;
  		freq[j]--;
  		int mx{*max_element(entire(freq))};
  		if(mx<=(n-i)/2){
  			res+=(char)(j+'A');
  			prev=(char)(j+'A');
  			break;
  		}
  		freq[j]++;
  	}
  }
  cout<<res<<"\n";
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