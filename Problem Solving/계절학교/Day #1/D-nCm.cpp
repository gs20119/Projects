
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long lint;
lint Fac[10000001]={}, Rev[10000001]={};

lint Pow(lint N, int X){
    if(X==0) return 1;
    if(X==1) return N;
    lint A = Pow(N,X/2);
    lint B = (A*A)%MOD;
    if(X&1) return (B*N)%MOD;
    return B;
}

void init(int L){
    Fac[0]=1; 
    for(int i=1; i<=10000000; i++){ Fac[i]=(Fac[i-1]*i)%MOD; }
    Rev[10000000]=Pow(Fac[10000000],MOD-2);
    for(int i=9999999; i>=0; i--){ Rev[i]=(Rev[i+1]*(i+1))%MOD; }
}

int ncm(int N, int M){
    lint Ans = (Fac[N]*Rev[N-M])%MOD;
    Ans = (Ans*Rev[M])%MOD;
    return (lint)Ans;
}

