
#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;

int main()
{
    int N; scanf("%d", &N);
    vector<int> Line(N);
    for(int i=0; i<N; i++) scanf("%d", &Line[i]);
    if(!prev_permutation(all(Line))) sort(all(Line),greater<int>());
    for(int i=0; i<N; i++) printf("%d ", Line[i]); printf("\n");
    if(!next_permutation(all(Line))) sort(all(Line));
    if(!next_permutation(all(Line))) sort(all(Line));
    for(int i=0; i<N; i++) printf("%d ", Line[i]); printf("\n");
}
