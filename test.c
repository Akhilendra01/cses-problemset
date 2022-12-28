#include <stdio.h>

#define N (200005*2)

typedef long long int ll;

int cnt[N];
int used[N];
int t; 

void solve(){
	int n; scanf("%d", &n);
	int x=0, y;
	ll ans=(ll)n*(n+1)/2;
	for(int i=0;i<n;i++){
		if(used[x]<t)cnt[x]=0;
		used[x]=t;
		cnt[x]++;

		scanf("%d", &y);
		x=(x^y);
		for(int j=0;j*j<2*n;j++){
			if(used[(j*j)^x]==t)ans-=cnt[(j*j)^x];
		}
	}
	printf("%lld\n", ans);
}

int main(){
	scanf("%d", &t);
	while(t--){
		solve();
	}
}