#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


string s;
int n;
vector<string> ans;
unordered_map<string, int> mp;
void generate(int idx){
	if(idx==n){
		// cout<<s<<endl;
		if(!mp[s]){
			ans.push_back(s);
			mp[s]=1;
		}
		return;
	}
	
	for(int i=idx;i<n;i++){
		swap(s[idx], s[i]);	
		generate(idx+1);
		swap(s[idx], s[i]);	

	}
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	
    cin>>s;
    n=s.length();

    generate(0);
    cout<<ans.size()<<endl;
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
	return 0;
}