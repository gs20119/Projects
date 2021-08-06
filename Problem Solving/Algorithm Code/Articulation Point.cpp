
#include <bits/stdc++.h>
using namespace std;
int VisCount=1;
vector<int> Vis;
vector<int> IsCut;
vector<vector<int>> Graph;

int DFS(int X, int start){
    Vis[X] = VisCount++;
    int Reach = Vis[X], Branch = 0; // X는 어디까지 닿는가
    for(int Y : Graph[X]){
        if(!Vis[Y]){ Branch++;
            int yReach = DFS(Y,0); Reach = min(Reach, yReach); // Y는 어디까지 닿는가
            if(yReach>=Vis[X] && !start) IsCut[X] = 1;
        }else Reach = min(Reach, Vis[Y]);
    }if(start) IsCut[X] = (Branch>=2);
    return Reach;
}

int main(){
    int N, M; scanf("%d %d", &N, &M);
    Vis.resize(N+1); IsCut.resize(N+1); Graph.resize(N+1);
    for(int i=0; i<M; i++){
        int a, b; scanf("%d %d", &a, &b);
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    int Count=0;
    for(int i=1; i<=N; i++) if(!Vis[i]) DFS(i,1);
    for(int i=1; i<=N; i++) if(IsCut[i]) Count++;
    printf("%d\n", Count);
    for(int i=1; i<=N; i++) if(IsCut[i]) printf("%d ", i);
}