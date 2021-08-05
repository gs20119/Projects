
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; scanf("%d", &N);
    vector<int> Line(N);
    for(int i=0; i<N; i++) scanf("%d", &Line[i]);
    sort(Line.begin(), Line.end()); printf("%d ", Line[0]);
    for(int i=1; i<N; i++) if(Line[i]!=Line[i-1]) printf("%d ", Line[i]);
}
