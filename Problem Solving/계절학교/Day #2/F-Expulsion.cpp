
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef struct pint{ int a; int b; } pint;
db mid;

bool Comp(pint& a, pint& b){
    db x = (db)a.a-mid*a.b;
    db y = (db)b.a-mid*b.b;
    return x>y;
}


int main()
{
    int N, K; scanf("%d %d", &N, &K);
    vector<pint> Line(N);
    for(int i=0; i<N; i++) scanf("%d %d", &Line[i].a, &Line[i].b);
    db left=0.0, right=1.0;
    while(right-left>(db)0.00000001){
        mid = (right+left)/(db)2.0;
        sort(Line.begin(), Line.end(), Comp);
        db Check=0.0;
        for(int i=0; i<N-K; i++) Check += (db)Line[i].a-mid*Line[i].b;
        if(Check>=0.0) left=mid;
        else right=mid;
    }mid = (right+left)/(db)2.0;
    printf("%.9lf\n", mid);
}
