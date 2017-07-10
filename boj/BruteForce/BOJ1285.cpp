#include <cstdio>
#include <algorithm>
using namespace std;

int cn[20][20], col[20], N;

int get() {
	
	int ret=0;
	for (int i = 0; i < N; ++i)
		ret += col[i] < N - col[i] ? col[i] : N - col[i];

	return ret;
}

int sol(int cur) {

	if (cur == N) return get();

	int ret = sol(cur+1);
	for (int i = 0; i < N; i++)
		col[i]+=cn[cur][i] *= -1;
	ret = min(ret, sol(cur + 1));
	for (int i = 0; i < N; i++)
		col[i]+=cn[cur][i] *= -1;

	return ret;
}

int main(void) {

	char in[21];
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", in);
		for (int j = 0; j < N; j++) {
			cn[i][j] = in[j] == 'H' ? -1 : 1;
			if (cn[i][j] == 1) col[j] += 1;
		}
	}

	printf("%d\n", sol(0));
}