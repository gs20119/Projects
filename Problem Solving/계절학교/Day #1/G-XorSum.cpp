
#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
int Bit[200010][20]={};

int main()
{
    int N; scanf("%d", &N);
    vector<int> Line(N+1);
    for(int i=1; i<=N; i++){
        scanf("%d", &Line[i]); 
        for(int j=0; j<20; j++){
            if(i!=0) Bit[i][j]=Bit[i-1][j];
            if(Line[i]&(1<<j)) Bit[i][j]++; 
        }
    }lint Ans=0; 
    for(int i=1; i<=N; i++){
        int left=i, right=N, mid, Check; 
        while(left<right){
            mid = (left+right+1)/2; Check = 1;
            for(int k=0; k<20; k++){
                if(Bit[mid][k]-Bit[i-1][k]>1){ Check=0; break; }
            }if(Check) left=mid;
            else right=mid-1;
        }Ans += left-i+1; 
    }printf("%lld\n", Ans);
}
