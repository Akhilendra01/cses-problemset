#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	

    int pof10[19]; pof10[0]=1;
    for(int i=1;i<19;i++)pof10[i]=pof10[i-1]*10;

	int q; cin>>q;
	while(q--){
		int k; cin>>k;
		int d=0;
		int sum=0;
		while(k>0){
			k-=(pof10[d]-pof10[d-1])*d;
			d++;
		}

		if(k!=0)d--;
		k+=(pof10[d]-pof10[d-1])*d;

		int s=pof10[d-1], e=pof10[d]-1;

		int start=s;
		int num=0, pos=0;
		while(s<=e){
			int mid=(s+e)/2;
			int digits=(mid-start)*d+1;
			if(digits<=k){
				num=mid;
				pos=digits;
				s=mid+1;
			}
			else{
				e=mid-1;
			}
		}
		int digIdx=k-pos;
		string N=to_string(num);
		cout<<N[digIdx]<<endl;
	}
	
	return 0;
}