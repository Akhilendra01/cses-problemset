#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
/*code*/

    int n; cin>>n;
    int arr[n-1];
    for (int i = 0; i < n-1; i++)
    {   
        cin>>arr[i];
    }

    sort(arr, arr+n-1);
    bool printed=false;
    for (int i = 0 ; i < n-1; i++)
    {
        /* code */
        if(arr[i]!=i+1){
            cout<<i+1;
            printed=true;
            break;
        }
    }
    if(!printed)cout<<n;
    
    return 0;
}