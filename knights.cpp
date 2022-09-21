#include<bits/stdc++.h>
using namespace std;
#define endl "\n";


long solve(int n){
    if(n==1)return 0;
    long x=n*n;
    long allWays= x*(x-1)/2;
    long attackWays = (n-1)*(n-2)*2*2;
    return allWays-attackWays;
    
}

int main(int argc, char const *argv[]){
/*code*/

    int n;
    cin>>n;    
    for (int i = 1; i <=n; i++)
    {
        cout<<solve(i)<<"\n";
    }
    
    return 0;
}