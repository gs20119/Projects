
#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;
typedef long long lint;

int main()
{
    int N, K; scanf("%d %d", &N, &K);
    int Alive[6000]={}, Line[6000]={};
    lint Penalty[6000]={}; Penalty[K-1]=1;
    lint Ans=1;
    for(int i=K-2; i>=0; i--) Penalty[i] = (Penalty[i+1]*(N-i-1))%MOD;
    for(int i=0; i<K; i++){
        scanf("%d", &Line[i]); Alive[Line[i]]=i+1;
        int PenCount=0;
        for(int j=1; j<Line[i]; j++) if(!Alive[j]) PenCount++;
        Ans = (Ans+PenCount*Penalty[i])%MOD;
    }printf("%lld\n", Ans);
    for(int i=K-1; i>=0; i--){
        int Pos=Line[i]+1;
        for(Pos; Pos<=N && Alive[Pos]<=i && Alive[Pos]; Pos++);
        if(Pos>N) continue;
        for(int j=0; j<i; j++) printf("%d ", Line[j]);
        printf("%d ", Pos); Alive[Line[i]]=0; Alive[Pos]=i+1;
        int Reset=1;
        for(int j=i+1; j<K; j++){
            while(Alive[Reset]<=i+1 && Alive[Reset]) Reset++;
            printf("%d ", Reset); Reset++;
        }break;
    }
}

