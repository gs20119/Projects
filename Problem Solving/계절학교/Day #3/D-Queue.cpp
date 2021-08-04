
#include <bits/stdc++.h>
using namespace std;
int Q[300001]; 

int main()
{
    int N, Ft=0, Bk=-1; cin >> N;
    while(N--){
        string cmd; int X;
        cin >> cmd;
        if(cmd=="PUSH"){ cin >> X; Q[++Bk]=X; }
        if(cmd!="PUSH"){
            if(Ft>Bk) printf("-1\n");
            else printf("%d\n", (cmd=="BACK")?Q[Bk]:Q[Ft]); 
        }if(cmd=="POP") Ft=min(Ft+1,Bk+1);
    }printf("%d\n", Bk-Ft+1);
    for(int i=Ft; i<=Bk; i++) printf("%d ", Q[i]);
}
