
#include <bits/stdc++.h>
#define INF 1000000007
#define x first
#define y second
#define all(v) v.begin(),v.end()
using namespace std;
typedef pair<int,pair<int,int>> piint;
typedef pair<int,int> pint;
typedef long long lint;

bool Comp(piint& a, piint& b){ return a.x > b.x; }

int main()
{
    int N; scanf("%d", &N);
    vector<piint> Line(N);
    map<int,int> Map; Map[0]=INF;
    for(int i=0; i<N; i++) scanf("%d %d %d", &Line[i].x, &Line[i].y.x, &Line[i].y.y);
    sort(all(Line),Comp); lint Ans=0, Sum=0;
    for(int i=0; i<N; i++){
        lint Gap = (i==N-1)?Line[i].x:Line[i].x-Line[i+1].x;
        pint A = Line[i].y; 
        auto it = Map.lower_bound(A.x); 
        it = Map.upper_bound(A.x); 
        auto itt = it; itt--; 
        if(itt->first < A.x) if(A.y > it->second)
        { Sum += (lint)(A.x-(itt->first))*(A.y-(it->second)); } it--; 
        if(A.y <= (Map.lower_bound(A.x))->second){ Ans += Gap*Sum; continue; }
        while(it!=Map.begin() && it->second < A.y){
            itt = it; itt--;
            lint W = (lint)(it->first)-(itt->first);
            lint H = (lint)A.y-(it->second);
            Sum += W*H; 
            auto pit = it; pit--;
            Map.erase(it); it = pit;
        }Map[A.x]=A.y; Ans += Gap*Sum;
    }printf("%lld\n", Ans);
}
