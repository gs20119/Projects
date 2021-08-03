
#include <bits/stdc++.h>
#define INF 2147483648
using namespace std;
typedef long long lint;
typedef struct pint{ int a; lint b; int c; } pint;

int main()
{
    int N; scanf("%d", &N);
    vector<pint> Line(N);
    for(int i=0; i<N; i++) scanf("%d %lld %d", &Line[i].a, &Line[i].b, &Line[i].c);
    
    lint left=0, right=INF, mid;
    while(left<right){
        mid=(left+right)/2; lint Sum=0;
        for(int i=0; i<N; i++) if(mid>=Line[i].a){
            lint range = min(mid,Line[i].b)-Line[i].a;
            Sum += 1+range/Line[i].c;
        }if(!(Sum&1)) left=mid+1;
        else right=mid;
    }
    
    lint Count=0;
    for(int i=0; i<N; i++) 
    if(Line[i].a<=left && left<=Line[i].b && (left-Line[i].a)%Line[i].c==0) Count++;
    if(!(Count&1)) printf("NOTHING\n");
    else printf("%lld %lld\n", left, Count);
}
