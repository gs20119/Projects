
#include <bits/stdc++.h>
using namespace std;
int St[300001]; 

int main()
{
    int N, I=-1; cin >> N;
    while(N--){
        string cmd; int X;
        cin >> cmd;
        if(cmd=="PUSH"){ cin >> X; St[++I]=X; }
        if(cmd=="TOP" || cmd=="POP"){
            if(I<0) printf("-1\n");
            else printf("%d\n", St[I]); 
        }if(cmd=="POP") I=max(I-1,-1);
    }printf("%d\n", I+1);
    for(int i=0; i<=I; i++) printf("%d ", St[i]);
}
