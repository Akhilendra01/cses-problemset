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
    int sum=(n+1)*n/2;
    if(sum%2){
        cout<<"NO\n";
        return 0;
    }

    int target=sum/2;
    bool s[n+1]={0};

    int N=n;
    while(target>0 and n>0){
        if(target>=n){
            target-=n;
            s[n]=1;
            n=min(n-1, target);
        }
        else{
            n--;
        }
    }

    // for(int i=1;i<=N;i++)cout<<s[i]<<" ";
    // cout<<endl;
    cout<<"YES\n";

    int cnt=0;
    for(int i=1;i<=N;i++)if(s[i]==1)cnt++;

    cout<<cnt<<endl;
    for(int i=1;i<=N;i++)if(s[i]==1)cout<<i<<" ";
    cout<<endl;
    
    cout<<N-cnt<<endl;
    for(int i=1;i<=N;i++)if(s[i]==0)cout<<i<<" ";
    cout<<endl;

    
    return 0;
}