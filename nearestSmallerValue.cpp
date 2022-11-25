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

	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];

	stack<int> s;
	vector<int> nsl(n);

	for(int i=0;i<n;i++){
		if(s.empty()){
			nsl[i]=-1;
		}
		else if(s.size()>0 and a[s.top()]>=a[i]){
			while(s.size()>0 and a[s.top()]>=a[i]){
				s.pop();
			}
			if(s.empty()){
				nsl[i]=-1; 
			}
			else{
				nsl[i]=s.top();
			}
		}
		else{
			nsl[i]=s.top();
		}
		s.push(i);
	}
	for(int i=0;i<n;i++)cout<<nsl[i]+1<<" ";

	return 0;
}