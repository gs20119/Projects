
#include <bits/stdc++.h>
using namespace std;
int VisCount=1;
vector<int> Vis, IsCut;
vector<vector<int>> Graph;
map<pair<int,int>,int> Edge;
 
int DFS(int X, int From){
    Vis[X] = VisCount++;
    int Reach = Vis[X]; // X는 어디까지 닿는가
    for(int Y : Graph[X]) if(Y!=From){
        if(!Vis[Y]){ 
            int yReach = DFS(Y,X); Reach = min(Reach, yReach);
            if(yReach>Vis[X]) IsCut[Edge[{min(X,Y),max(X,Y)}]]=1; 
        }else Reach = min(Reach, Vis[Y]);
    }return Reach;
}
 
int main(){
    int N, M; scanf("%d %d", &N, &M);
    Vis.resize(N+1); Graph.resize(N+1); IsCut.resize(N+1);
    for(int i=1; i<=M; i++){
        int a, b; scanf("%d %d", &a, &b);
        if(a>b) swap(a,b);
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        Edge[{a,b}]=i;
    }
    int Count=0;
    for(int i=1; i<=N; i++) if(!Vis[i]) DFS(i,0); 
    for(int i=1; i<=M; i++) if(IsCut[i]) Count++;
    printf("%d\n", Count);
    for(auto it=Edge.begin(); it!=Edge.end(); it++) 
    if(IsCut[it->second]) printf("%d %d\n", (it->first).first, (it->first).second);
}