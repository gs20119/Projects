
#include <bits/stdc++.h>
#define MOD 1234567891
#define x first
#define y second
using namespace std;
typedef long long lint;
typedef pair<lint,lint> pint;

bool Comp(pint& a, pint& b){ return a.x*b.y+a.y < b.x*a.y+b.y; }

int main()
{
    int N; scanf("%d", &N);
    vector<pint> Line(N);
    for(int i=0; i<N; i++) scanf("%lld %lld", &Line[i].x, &Line[i].y);
    sort(Line.begin(), Line.end(), Comp);
    lint Ans=1;
    for(int i=0; i<N; i++) Ans = (Line[i].x*Ans+Line[i].y)%MOD;
    printf("%lld\n", Ans);
}
