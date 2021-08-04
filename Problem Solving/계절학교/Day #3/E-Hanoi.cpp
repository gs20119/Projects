
#include <bits/stdc++.h>
using namespace std;

void Print(int N, int From, int To, int Else){
    if(N==1){ printf("%d %d\n", From+1, To+1); return; }
    Print(N-1,From,Else,To);
    printf("%d %d\n", From+1, To+1); 
    Print(N-1,Else,To,From);
}

int main()
{
    int N; scanf("%d", &N);
    Print(N,0,2,1);
    return 0;
}

