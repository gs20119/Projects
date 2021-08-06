
#include <bits/stdc++.h>
#define INF 10000000000000000
using namespace std;
typedef long long lint;
vector<lint> Sum;

lint minimize_difference(vector<int> P){
    int N = P.size();
    lint Ans=INF; int p=0, q=2;   
    Sum.resize(N); Sum[0]=P[0];
    for(int i=1; i<N; i++) Sum[i]=Sum[i-1]+P[i];
    for(int i=1; i<N-2; i++){
        for(; p+2<i && Sum[p+1]<Sum[i]/2; p++);  
        for(q=max(q,i+1); q+2<N-1 && Sum[q+1]-Sum[i]<(Sum[N-1]-Sum[i])/2; q++);
        lint A, B, C, D;
        if(p+1<i){ 
            A = Sum[p+1]; B = Sum[i]-Sum[p+1]; 
            if(abs(Sum[i]-2*Sum[p])<abs(Sum[i]-2*Sum[p+1])){ 
                A = Sum[p]; B = Sum[i]-Sum[p]; 
            }
        }else{ A = Sum[p]; B = Sum[i]-Sum[p]; }
        if(q+1<N-1){
            C = Sum[q+1]-Sum[i]; D = Sum[N-1]-Sum[q+1]; 
            if(abs(Sum[N-1]+Sum[i]-2*Sum[q])<abs(Sum[N-1]+Sum[i]-2*Sum[q+1])){ 
                C = Sum[q]-Sum[i]; D = Sum[N-1]-Sum[q]; 
            }
        }else{ C = Sum[q]-Sum[i]; D = Sum[N-1]-Sum[q]; }
        lint Min = min({A,B,C,D});
        lint Max = max({A,B,C,D});
        Ans = min(Max-Min,Ans);
    }return Ans;
}

/*
int main(){
    int N; scanf("%d", &N);
    vector<int> P(N); 
    for(int i=0; i<N; i++) scanf("%d", &P[i]);
    printf("%lld\n", minimize_difference(P));
}
*/