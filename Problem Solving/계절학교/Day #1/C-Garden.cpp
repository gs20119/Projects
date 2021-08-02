
#include <bits/stdc++.h>
using namespace std;
int DP[3][1000010]={};

int main()
{
    int N, MOD; scanf("%d%d", &N, &MOD);
    DP[0][N]=DP[1][N]=DP[2][N]=1;
    DP[0][N-1]=DP[1][N-1]=DP[2][N-1]=2;
    for(int i=N-2; i>=0; i--){
        DP[0][i]=(2*DP[1][i+1])%MOD;
        DP[1][i]=(DP[1][i+1]+DP[2][i+2])%MOD;
        DP[2][i]=(2*DP[2][i+2])%MOD;
    }string S; cin >> S;
    int Ans=1, A=0, B=0;
    for(int i=0; i<N; i++){
        if(A==-1 && B==1){
            if(S[i]=='M') i++;
            else{ Ans = (Ans+DP[2][min(N,i+2)])%MOD; i++; }
        }else if(B==1){
            if(S[i]=='M'){ A=-1; i++; }
            else{ Ans = (Ans+DP[2][min(N,i+2)])%MOD; A=-1; B=0; } 
        }else if(A==-1){
            if(S[i]=='M'){ A=0; B=1; }
            else{ Ans = (Ans+DP[1][i+1])%MOD; A=-1; B=1; i++; }
        }else{
            if(S[i]=='M') B=1;
            else{ Ans = (Ans+DP[1][i+1])%MOD; A=-1; }
        } 
    }printf("%d\n", Ans);
}
