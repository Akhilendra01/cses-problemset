#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
/*code*/

    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    long long moves=0;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            moves+=(long long)a[i-1]-a[i];
            a[i]=a[i-1];
        }
    }
    cout<<moves;

    return 0;
}