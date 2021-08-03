
#include <bits/stdc++.h>
using namespace std;

static int NN;
static int A[100050];
static int B[100050];
static int compare_call_count = 0;
int compare(int i, int j) {
	compare_call_count++;
	if (i < 0 || i >= NN || j < 0 || j >= NN) {
		printf("Wrong Answer\n");
		exit(0);
	}
	if (A[i] < B[j]) return 1;
	else return 0;
}

/*********  MY CODE  ************/

int search(int N, int K){
    int Aleft=max(0,K-N-1), Bleft=max(0,K-N-1);
    int Aright=min(K-1,N-1), Bright=min(K-1,N-1);
    while(Aleft<Aright){
        int mid = (Aleft+Aright)/2;
        if(compare(mid,K-mid-2)){ Aleft=mid+1; Bright=K-mid-2; }
        else{ Aright=mid; Bleft=K-mid-1; }
        printf("%d %d %d %d\n", Aleft, Aright, Bleft, Bright);
    }if(!compare(Aleft,K-Aleft-2))
    if(K-Aleft-1>=N || compare(Aleft,K-Aleft-1)) return Aleft;
    while(Bleft<Bright){
        int mid = (Bleft+Bright)/2;
        if(!compare(K-mid-2,mid)) Bleft=mid+1;
        else Bright=mid;
    }return Bleft+N;
}

/*********  MY CODE  ************/

int main() {
	int N, K, i;
	scanf("%d %d", &N, &K);
	NN = N;
	for (i = 0; i < N; i++) scanf("%d", &A[i]);
	for (i = 0; i < N; i++) scanf("%d", &B[i]);

	int cnt = 0;

	int p0 = 0, p1 = 0;
	int ans = 0;
	for (int i = 1; i <= K; i++) {
		if (p0 == N || (p1 != N && A[p0] > B[p1])) {
			ans = p1 + N;
			p1++;
		}
		else {
			ans = p0;
			p0++;
		}
	}

	if (search(N, K) != ans) printf("Wrong Answer: %d\n", search(N,K));
	else {
		printf("Correct!\n");
		printf("Your function calls: %d\n", compare_call_count);
	}
	return 0;
}
