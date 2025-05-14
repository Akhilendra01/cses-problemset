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

        
template <typename T>
class SegmentTree{
private:
  T n, DEAD;
  vector<T> st;
  function<T(T, T)>comb;
public:
  SegmentTree(int n, function<T(T, T)>comb, int DEAD=0){
      this->n=n, this->comb=comb, this->DEAD=DEAD;
      st.resize(n<<2);
      for(int i=0;i<(n<<2);i++)this->st[i]=DEAD;  
  }
  void build(vector<int>& a, int lx, int rx, int x){
      if(lx==rx){st[x]=a[lx]; return;}
      int mid=(lx+rx)>>1;
      build(a, lx, mid, (x<<1)+1);
      build(a, mid+1, rx, (x<<1)+2);
      st[x]=this->comb(st[(x<<1)+1], st[(x<<1)+2]);
  }
  void build(vector<int>& a){build(a, 0, n-1, 0);}
  T query(int l, int r, int lx, int rx, int x){
      if(rx<l or r<lx)return DEAD;
      if(l<=lx and rx<=r)return st[x];
      int mid=(lx+rx)>>1;
      T q1=query(l, r, lx, mid, (x<<1)+1); 
      T q2=query(l, r, mid+1, rx, (x<<1)+2); 
      return this->comb(q1, q2);
  }
  T query(int l, int r){return query(l, r, 0, n-1, 0);}
  void update(int idx, T val, int lx, int rx, int x){
      if(lx==rx){st[x]=val;   return;}
      int mid=(lx+rx)/2;
      if(idx<=mid)update(idx, val, lx, mid, (x<<1)+1);
      else update(idx, val, mid+1, rx, (x<<1)+2);
      st[x]=this->comb(st[(x<<1)+1], st[(x<<1)+2]);
  }
  void update(int idx, T val){update(idx, val, 0, n-1, 0);}
};


void solve(){
  int n, a, b;
  cin>>n>>a>>b;

  vi ar(n);
  cin>>ar;

  vi pr(n+1);
  for(int i{};i<n;i++)pr[i+1]=pr[i]+ar[i];

  SegmentTree<int> tree(n, [](int x, int y)->int{
  	return min(x, y);
  }, inf);

	tree.build(pr);

	int ans{-inf};

	for(int i{a};i<=n;i++){
		int lb{max(0ll, i-b)};
		int ub{max(0ll, i-a)};
		ans=max(ans, pr[i]-tree.query(lb, ub));
	}
	cout<<ans<<"\n";
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