//BOJ
//ID : 3933 // dp
//2017/10/04

#include <cstdio>
int mv = (1 << 16) - 1;
int cache[5][1<<16],a[1<<16];

int main() {

	for (int i = 1; i <= 256; i++) {
		if (i*i > mv) break;
		if (i*i <= mv) cache[1][i*i]++;
	}

	for (int i = 1; i <= 256; i++) {
		if (i*i >= mv) break;
		for (int j = i; j <= 256; j++) {
			if (j*j >= mv) break;
			if (i*i + j*j <= mv) cache[2][i*i + j*j]+=1;
		}
	}

	for (int i = 1; i <= 256; i++) {
		if (i*i >= mv) break;
		for (int j = i; j <= 256; j++) {
			if (j*j >= mv) break;
			for (int k = j; k <= 256; k++) {
				if (k*k >= mv) break;
				if (i*i + j*j +k*k<= mv) cache[3][i*i +j*j+k*k]++;
			}
		}
	}

	for (int i = 1; i <= 256; i++) {
		if (i*i >= mv) break;
		for (int j = i; j <= 256; j++) {
			if (j*j >= mv) break;
			for (int k = j; k <= 256; k++) {
				if (k*k >= mv) break;
				for (int m = k; m <= 256; m++) {
					if (m*m >= mv) break;
					if (i*i + j*j + k*k + m*m <= mv) {
						cache[4][i*i + j*j + k*k + m*m]++;
					}
				}
			}
		}
	}
	
	int k;
	while (scanf("%d", &k)) {
		if (k == 0) break;
		printf("%d\n", cache[1][k]+cache[2][k]+cache[3][k]+cache[4][k]);
	}
}