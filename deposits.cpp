#include<bits/stdc++.h>
using namespace std;
#define endl "\n";

int solve(vector<int> &v, int coins){
    sort(v.begin(), v.end());
    int len=v.size();
    int count=0;
    for(int i=len-1;i>=0;i--){
        count++;
        if(coins>0)coins-=v[i];
        if(coins<=0)return count;
    }
    return -1;
}
int main(int argc, char const *argv[]){
/*code*/

    int T;
    cin>>T;

    int NX[T][2];
    vector<int> v[T];
    for (int i = 0; i < T; i++)
    {
        cin>>NX[i][0]>>NX[i][1];
        for(int j=0;j<NX[i][0];j++){
            int x; cin>>x;
            v[i].push_back(x);
        }
    }
    for (int i = 0; i < T; i++)
    {
        cout<<solve(v[i], NX[i][1])<<"\n";
    }
    

    return 0;
}