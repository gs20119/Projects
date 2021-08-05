
#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> Set;
    int N, Q; scanf("%d %d", &N, &Q);
    for(int i=1; i<=N; i++) Set.insert(i);
    for(int i=0; i<Q; i++){
        int X; scanf("%d", &X);
        auto it = Set.upper_bound(X); 
        if(it==Set.begin()){ printf("%d\n", i); return 0; }
        it--; Set.erase(*it);
    }printf("%d\n", Q);
}
