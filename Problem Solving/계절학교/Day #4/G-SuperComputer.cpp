
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> pint;

bool Comp(pint& a, pint& b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

bool Comp2(pint& a, pint& b){
    if(a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}

int main()
{
    int N, M, K; 
    scanf("%d %d %d", &N, &M, &K);
    vector<pint> CPU(N), P(M);
    for(int i=0; i<N; i++) scanf("%d %d", &CPU[i].x, &CPU[i].y);
    sort(CPU.begin(),CPU.end(),Comp);
    for(int i=0; i<M; i++) scanf("%d %d", &P[i].x, &P[i].y);
    sort(P.begin(),P.end(),Comp2); int j=0;
    
    priority_queue<int> Heap, Total;
    for(int i=0; i<N; i++){
        while( j<M && CPU[i].y>=P[j].y ){ Heap.push(P[j].x); j++; }
        if(!Heap.empty()){ Total.push(Heap.top()-CPU[i].x); Heap.pop(); }
    }
    
    long long Ans=0;
    for(int i=0; i<K; i++){
        if(Total.empty() || Total.top()<=0) break;
        Ans += Total.top(); Total.pop();
    }printf("%lld\n", Ans);
    
}
