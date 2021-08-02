
#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;
typedef long long lint;
lint Fac[5001]={}, Rev[5001]={};

lint Pow(lint N, int X){
    if(X==0) return 1;
    if(X==1) return N;
    lint A = Pow(N,X/2);
    lint B = (A*A)%MOD;
    if(X&1) return (B*N)%MOD;
    return B;
}

void init(int L){
    Fac[0]=1; Rev[0]=1;
    for(int i=1; i<=L; i++){
        Fac[i]=(Fac[i-1]*i)%MOD;
        Rev[i]=Pow(Fac[i],MOD-2);
    }
}

lint ncm(int N, int M){
    if(N<M) return 0;
    lint Ans = (Fac[N]*Rev[N-M])%MOD;
    Ans = (Ans*Rev[M])%MOD; 
    return Ans;
}

int main()
{
    int N, K; scanf("%d %d", &N, &K);
    int Line[5000]={}; init(5000);
    lint Ans=ncm(N,K);
    for(int i=0; i<K; i++){
        scanf("%d", &Line[i]);
        Ans = (Ans-ncm(N-Line[i],K-i)+MOD)%MOD;
    }printf("%lld\n", Ans);
    for(int i=K-1; i>=0; i--){
        if(Line[i]==i+N+1-K) continue;
        for(int j=0; j<i; j++) printf("%d ", Line[j]);
        Line[i]++; printf("%d ", Line[i]);
        for(int j=i+1; j<K; j++){ Line[j]=Line[j-1]+1; printf("%d ", Line[j]); }
        break;
    }
}
