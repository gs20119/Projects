
#include <bits/stdc++.h>
using namespace std;
int Line[200001]={}, Ans[200001]={};

void Merge(int left, int right){
	int mid=(left+right)/2;
	int A=left, B=mid+1, X=left;
	
	while(A<=mid && B<=right){
		if(Line[A] > Line[B]) Ans[X++] = Line[B++]; 
		else Ans[X++] = Line[A++];
	}
	
	if(A>mid) while(B<=right) Ans[X++] = Line[B++];
	else while(A<=mid) Ans[X++] = Line[A++];
	for(int a=left; a<=right; a++) Line[a] = Ans[a];
}

void Div(int left, int right){
	if (left < right){
		int mid = (left+right) / 2;
		Div(left, mid); Div(mid+1, right);
		Merge(left, right);
	}
}

int main()
{
    int N; scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &Line[i]);
    Div(0,N-1);
    for(int i=0; i<N; i++) printf("%d ", Line[i]);
}
