
#include <bits/stdc++.h>
using namespace std;
int Info[200000][5]={};

bool Comp(int x, int y){
    int Count=0;
    for(int i=0; i<5; i++) if(Info[x][i]<Info[y][i]) Count++;
    return (Count>=3);
}

int main()
{
    int N; scanf("%d", &N);
    for(int i=0; i<5; i++) for(int j=1; j<=N; j++){
        int X; scanf("%d", &X);
        Info[X][i]=j;
    }vector<int> Ans(N+1);
    for(int i=1; i<=N; i++) Ans[i]=i;
    sort(Ans.begin(), Ans.end(), Comp);
    for(int i=1; i<=N; i++) printf("%d ", Ans[i]);
}
