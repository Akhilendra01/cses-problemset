#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
/*code*/

    int n;
    cin>>n;
    if(n==3||n==2){
        cout<<"NO SOLUTION";
        return 0;
    }
    else if(n==4){
        cout<<"2 4 1 3";
        return 0;
    }

    for (int i = 1; i <=n ; i++){
        if(i%2!=0)cout<<i<<" ";
    }
    for(int i=2;i<=n;i++){
        if(i%2==0)cout<<i<<" ";
    }
    

    return 0;
}