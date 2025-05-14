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


int power(int a, int b){
  int r=1;
  while(b){
    if(b&1)r=(r*a)%mod; a=(a*a)%mod; b/=2;
  }
  return r;
}
int inv(int x){return power(x, mod-2);}
class Z {
public:
  int n, M;
  Z() : n(0), M(mod){}    Z(int n) : n(n), M(mod){}
  friend std::ostream& operator<<(std::ostream& os, const Z& z) {os << z.n; return os;}
  friend std::istream& operator>>(std::istream& is, Z& z) {is >> z.n; return is;}
  Z operator+(const Z& b) const { return Z((n + b.n)%M); }
  Z operator-(const Z& b) const { return Z((n - b.n + M)%M); }
  Z operator*(const Z& b) const { return Z((n*b.n)%M); }
  Z operator/(const Z& b) const { return Z((n*inv(b.n))%M); }
  Z operator%(const Z& b) const { return Z(n%(b.n)); }
  Z operator++(int32_t) {Z temp(*this); ++(*this); return temp; }
  Z operator--(int32_t) {Z temp(*this); --(*this); return temp; }
  Z& operator=(int n) { this->n = n; return *this;}
  Z& operator+=(const Z& b) {n = (n + b.n) % M; return *this; }
  Z& operator-=(const Z& b) {n = (n - b.n + M) % M; return *this; }
  Z& operator*=(const Z& b) {n = (n * b.n)% M; return *this; }
  Z& operator/=(const Z& b) {n = (n * inv(b.n))% M; return *this; }
  Z& operator%=(const Z& b) {n = (n % b.n); return *this; }
  Z& operator++(){n=(n+1)%M; return *this;} 
  Z& operator--(){n=(n-1+M)%M; return *this;} 
  bool operator==(const Z&b){return n==b.n;}
  bool operator!=(const Z&b){return n!=b.n;}
};

void solve(){
  int n;
  cin>>n;

  vi a(n);
  cin>>a;

  map<int, Z> mp;

  Z prod{1}, ans{};

  for(int i{n-1};i>=0;i--){
  	prod=prod/(mp[a[i]]+1);
  	ans+=prod;
  	mp[a[i]]++;
  	prod=prod*(mp[a[i]]+1);
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

class Line{
public:
  double x, y;
  int m, c;
  Line(double x, int m, int c): x(x), m(m), c(c){
    this->y=m*x+c;
  }
  double calculate(int x_pt){
    return m*x_pt+c;
  }
};

class ConvexHull{
private:
  vector<Line*> hull;
public:
  void insert(int m, int c){
    while(!hull.empty()){
      Line *l{hull.back()};
      if(l->y > m*l->x+c){
        if(m-l->m)hull.push_back(new Line( -(l->c-c)*1.0/(l->m-m)  ,m, c));
        return;
      }
      delete l;
      hull.pop_back();
    }
    hull.push_back(new Line(-inf, m, c));
  }

  int query(int x){
    Line *l {*--upper_bound(entire(hull), x, 
      [](int a, Line *l)->bool{
        return a<l->x;
      }
    )};
    return l->calculate(x);
  }

  ~ConvexHull(){
    for(Line *l: hull)delete l;
  }
};