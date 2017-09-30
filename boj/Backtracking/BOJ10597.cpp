//BOJ
//ID : 10597 // backtracking
//2017/09/20

#include <cstdio>

int n, seq[100],nc,ret[100],k;
bool check[70],end;

void sol(int cur) {

	if (end) return;

	if (cur >= n) {
		for (int i = 0; i < k; i++)
			printf("%d ", ret[i]);
		end = true;
		return;
	}

	if (seq[cur] == 0) return;

	if (!check[seq[cur]]) {
		check[seq[cur]] = 1;
		ret[k++] = seq[cur];
		sol(cur + 1);
		check[seq[cur]] = 0;
		k--;
	}
		
	if (cur < n-1) {
		int tn = 10 * seq[cur] + seq[cur + 1];
		if (tn <= nc && !check[tn]) {
			ret[k++] = tn;
			check[tn] = 1;
			sol(cur + 2);
			check[tn] = 0;
			k--;
		}
	}
}

int main() {

	while (1) {
		int ch = getchar();
		if (ch == '\n') break;
		seq[n++] = ch - '0';
	}

	nc = n < 10 ?  n : 9 + (n - 9) / 2;
	sol(0);
}


