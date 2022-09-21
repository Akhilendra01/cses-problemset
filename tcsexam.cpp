#include<bits/stdc++.h>
using namespace std;
#define endl "\n";

string solve(int d1, int t1, int m1, int d2, int t2, int m2){
    int s1=d1+t1+m1;
    int s2=d2+t2+m2;
    string d="DRAGON", s="SLOTH";
    if(s1>s2)return d;
    else if(s1<s2)return s;
    else if(s1==s2){
        if(d1>d2)return d;
        else if(d1<d2)return s;
        else if(d1==d2){
            if(t1>t2)return d;
            else if(t1<t2)return s;
            else if(t1==t2)return "TIE";
        }
    }
}

int main(int argc, char const *argv[]){
/*code*/

    int T;
    cin>>T;
    int d1[T], t1[T], m1[T];
    int d2[T], t2[T], m2[T];

    for(int i=0;i<T;i++){
        cin>>d1[i]>>t1[i]>>m1[i];
        cin>>d2[i]>>t2[i]>>m2[i];
    }    

    for(int i=0;i<T;i++){
        cout<<solve(d1[i],t1[i],m1[i], d2[i],t2[i],m2[i])<<"\n";
    }
    return 0;
}