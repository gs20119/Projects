
#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    vector<int> Line(N);
    for(int i=0; i<N; i++) scanf("%d", &Line[i]);
    int left=0, right=1000000000, mid;
    while(left<right){
        mid = (left+right+1)/2;
        lint Score=0;
        for(int i=0; i<N; i++) Score += max(0,Line[i]-mid);
        if(Score<M) right=mid-1;
        else left=mid;
    }printf("%d\n", left);
}
