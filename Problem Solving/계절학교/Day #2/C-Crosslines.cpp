
#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
lint Tree[2000000]={};

lint FixTree(int X, int xl, int xr, int Y, lint Q){
    int xm = (xl+xr)/2;
    if(xl==xr) return Tree[X] = Q;
    if(Y<=xm) FixTree(2*X, xl, xm, Y, Q);
    else FixTree(2*X+1, xm+1, xr, Y, Q);
    return Tree[X] = Tree[2*X]+Tree[2*X+1];
}

lint Sum(int X, int xl, int xr, int L, int R){
    int xm = (xl+xr)/2;
    if(xl==L && xr==R) return Tree[X];
    if(R<=xm) return Sum(2*X, xl, xm, L, R);
    else if(L>xm) return Sum(2*X+1, xm+1, xr, L, R);
    return Sum(2*X, xl, xm, L, xm)+Sum(2*X+1, xm+1, xr, xm+1, R);
}

int main()
{
    int N; scanf("%d", &N);
    long long Ans=0;
    for(int i=1; i<=N; i++) FixTree(1,1,N,i,1);
    for(int i=1; i<=N; i++){
        int X; scanf("%d", &X); FixTree(1,1,N,X,0);
        if(X>1) Ans += Sum(1,1,N,1,X-1);
    }printf("%lld\n", Ans);
}
