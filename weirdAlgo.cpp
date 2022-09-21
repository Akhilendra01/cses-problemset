#include<bits/stdc++.h>
using namespace std;

string solve(long long n, string ans=""){
    while(n!=1){
        ans=ans+to_string(n)+" ";
        if(n%2==0)n=n/2;
        else n=3*n+1;
    }
    ans=ans+"1";
    return ans;
}
int main(int argc, char const *argv[]){
/*code*/

    long long n;
    cin>>n;

    cout<<solve(n);

    return 0;
}