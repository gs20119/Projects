
#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;
typedef long long lint;
vector<lint> Line, Sum;

int Find(int X){
    int left=0, right=Line.size()-1, mid;
    while(left<right){
        mid = (left+right+1)/2;
        if((lint)X>Line[mid]) left=mid;
        else right=mid-1;
    }return left;
}

int main()
{
    int N, Q; scanf("%d %d", &N, &Q);
    Line.resize(N+2); Sum.resize(N+2);
    for(int i=1; i<=N; i++) scanf("%lld", &Line[i]);
    Line[N+1]=INF; sort(Line.begin(),Line.end()); 
    for(int i=1; i<=N+1; i++) Sum[i] = Sum[i-1]+Line[i];
    while(Q--){
        int L, R; scanf("%d %d", &L, &R);
        if(L>R){ printf("0 0\n"); continue; }
        L = Find(L); R = Find(R+1);
        printf("%d %lld\n", R-L, Sum[R]-Sum[L]);
    }
}
