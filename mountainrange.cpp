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

vector<int> NGR(vector<int>& a){
	int n=a.size();
	vector<int> ngr(n);
	stack<int> st;
	for(int i=n-1;i>=0;i--){
		if(st.empty()){
			ngr[i]=-1;
		}else{
			while(!st.empty() and a[st.top()]<=a[i])st.pop();
			ngr[i]=st.empty()?-1:st.top();
		}
		st.push(i);
	}
	return ngr;
}

vector<int> NGL(vector<int>& a){
	int n=a.size();
	vector<int> ngl(n);
	stack<int> st;
	for(int i=0;i<n;i++){
		if(st.empty()){
			ngl[i]=-1;
		}else{
			while(!st.empty() and a[st.top()]<=a[i])st.pop();
			ngl[i]=st.empty()?-1:st.top();
		}
		st.push(i);
	}
	return ngl;
}

void solve(){
	int n;
	cin>>n;

	vi h(n);
	cin>>h;

	vi ngr{NGR(h)}, ngl{NGL(h)};

	vector<vi> dag(n);
	vi vis(n), d(n, -1), din(n);

	for(int i{};i<n;i++){
		if(ngr[i]!=-1){
			dag[ngr[i]].pb(i);
			din[i]++;
		}
		if(ngl[i]!=-1){
			dag[ngl[i]].pb(i);
			din[i]++;
		}
	}

	vi srcs{};
	for(int i{};i<n;i++){
		if(din[i]==0)srcs.pb(i);
	}

	queue<int> q;
	for(int s: srcs){
		q.push(s);
		d[s]=1;
	}
	
	while(!q.empty()){
		int node{q.front()};
		q.pop();
		for(int child: dag[node]){
			din[child]--;
			d[child]=max(d[child], 1+d[node]);
			if(din[child]==0){
				q.push(child);
			}
		}
	}
	cout<<*max_element(entire(d));
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