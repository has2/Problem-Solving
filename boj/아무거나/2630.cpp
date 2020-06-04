#include <cstdio>
using namespace std;

int N, a[129][129], ret[2];

bool check(int y, int x, int sz) {
	for (int i = y; i < y + sz; i++) {
		for (int j = x; j < x + sz; j++) {
			if (a[i][j] != a[y][x]) return false;
		}
	}
	return true;
}
void sol(int y, int x,int sz) {

	if (sz == 1 || check(y, x, sz)) {
		ret[a[y][x]]++;
		return;
	}
	int nsz = sz / 2;
	sol(y, x, nsz);
	sol(y+nsz, x, nsz);
	sol(y+nsz, x+nsz, nsz);
	sol(y, x+nsz, nsz);
}

int main() {

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	sol(1, 1, N);
	printf("%d\n%d",ret[0],ret[1]);
}