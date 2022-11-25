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

	vector<int> children;
	for(int i=0;i<n;i++)children.push_back(i+1);

	while(children.size()>1){
		vector<int> survivors;
		for(int i=0;i<children.size();i++){
			if(i%2==1){
				cout<<children[i]<<" ";
			}
			else{
				survivors.push_back(children[i]);
			}
		}
		if(children.size()%2){
			children.clear();
			children.push_back(survivors.back());
			survivors.pop_back();
			for(int c: survivors)children.push_back(c);
		}else{
			children=survivors;
		}

	}
	cout<<children[0];
	
	return 0;
}