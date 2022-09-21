#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


int board[9][9];
int ways=0;

bool isValid(int I, int J){
	for(int i=1;i<=8;i++)if(board[i][J]==1)return false;
	for(int j=1;j<=8;j++)if(board[I][j]==1)return false;

	int i=I, j=J;
	while(i>0 and j>0){
		if(board[i][j]==1)return false;
		i--; j--;
	}
	i=I, j=J;
	while(i>0 and j<=8){
		if(board[i][j]==1)return false;
		i--; j++;
	}

	i=I, j=J;
	while(i<=8 and j>0){
		if(board[i][j]==1)return false;
		i++; j--;
	}
	i=I, j=J;
	while(i<=8 and j<=8){
		if(board[i][j]==1)return false;
		i++; j++;
	}
	return true;
}

bool solve(int row=1){
	if(row>8){
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				if(board[i][j]==1)cout<<"Q ";
				else cout<<"X ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}

	int i=row;
	for(int j=1;j<=8;j++){
		if(board[i][j]==-1)continue;
		if(isValid(i, j)){
			board[i][j]=1;
			bool res=solve(row+1);
			board[i][j]=0;
			if(res==true)ways++;
		}

	}
	return false;
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			char x; cin>>x;
			if(x=='*')board[i][j]=-1;
			else board[i][j]=0;
		}
	}
	solve();
	cout<<ways<<endl;
	return 0;
}