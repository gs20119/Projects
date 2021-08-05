
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; scanf("%d", &N);
    map<int,int> Map;
    while(N--){
        int Q, X; scanf("%d %d", &Q, &X);
        if(Q==1){
            if(Map.find(X)==Map.end()) Map[X]=1;
            else Map[X]++;
        }if(Q==2) if(Map.find(X)!=Map.end()) Map[X]=max(0,Map[X]-1);
        if(Q==3) printf("%d\n", (Map.find(X)!=Map.end())?Map[X]:0);
    }
}
