#include<bits/stdc++.h>
using namespace std;

long long  solve(long long r, long long c){
    long long n;
    if(r==c)return r*r-r+1;
    else if(r>c)n=r*r-r+1;
    else n=c*c-c+1;

    if(r>c){
        if(r%2!=0)
            return n-r+c;
        
        else
            return n+r-c;
        
    }
    else if(r<c){
        if(c%2!=0)
            return n+c-r;
        
        else 
            return n-c+r;
    }
}

int main(int argc, char const *argv[]){
/*code*/

    int T; cin>>T;
    long long y,x;
    while(T--){
        cin>>y>>x;
        cout<<solve(y,x)<<endl;
    }

    return 0;
}