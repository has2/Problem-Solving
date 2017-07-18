#include <stdio.h>
using namespace std;

int Max(int a, int b) {
	if (a > b) {
		return a;
	}else {
		return b;
	}
}

int nValue[1001][1001],nMaxValue[1001][1001],nForward[1001], nBackward[1001];

int main() {

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) 
		for (int j = 1; j < M + 1; j++) 
			scanf("%d", &nValue[i][j]);

	nMaxValue[1][1] = nValue[1][1];
	for (int i = 2; i < M + 1; i++) {
		nMaxValue[1][i] = nMaxValue[1][i - 1] + nValue[1][i];
	}
	
	for (int i = 2; i < N + 1; i++) {
		nForward[1] = nMaxValue[i - 1][1] + nValue[i][1];
		for (int j = 2; j < M + 1; j++) 
			nForward[j] = Max(nForward[j - 1], nMaxValue[i-1][j])+nValue[i][j];
		
		nBackward[M - 1] = nMaxValue[i - 1][M] + nValue[i][M] + nValue[i][M - 1];
		for (int j = M - 2; j > 0; j--) 
			nBackward[j] = Max(nMaxValue[i - 1][j + 1] + nValue[i][j + 1], nBackward[j + 1]) + nValue[i][j];
		
		nBackward[M] = -999999999;
		for (int j = 1; j < M + 1; j++) 
			nMaxValue[i][j] = Max(nForward[j], nBackward[j]);
		
	}
	printf("%d", nMaxValue[N][M]);
}
