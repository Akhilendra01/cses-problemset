\#include<bits/stdc++.h>
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

	string s; cin>>s;
	int n=s.length();
	
	unordered_map<char, int> f;
	for(int i=0;i<n;i++)f[s[i]]++;

	int cnt=0;
	char ch='\0';
	for(auto i: f){
		if(i.second%2)cnt++, ch=i.first;
		if(cnt==2)break;
	}

	if(cnt==2){
		cout<<"NO SOLUTION\n";
		return 0;
	}
	string ans="";
	for(auto j: f){
		if(j.second%2)continue;
		for(int i=0;i<(j.second)/2;i++)ans+=j.first;
	}
	
	string s1=ans;
	reverse(s1.begin(), s1.end());
	if(ch!='\0'){
		for(int i=0;i<f[ch];i++)ans+=ch;
	}
	ans+=s1;

	cout<<ans<<endl;
	



	return 0;
}