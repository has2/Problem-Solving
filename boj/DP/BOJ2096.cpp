#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 987654321;
int N,c[2][2][3],s[3];

int main(void) {

	scanf("%d", &N);
	for (int i = 1; i <= N+1; i++) {

		if (i <= N)
			scanf("%d%d%d", &s[0], &s[1], &s[2]);
		else
			s[0] = s[1] = s[2] = 0;

		for (int k = 0; k < 2; k++) {
			for (int l = 0; l < 3; l++) {
				c[k][i%2][l] = k== 0 ? INF : -INF;
				for (int j = 0; j < 3; j++)
					if (i==N+1 || abs(j - l) < 2) 
						c[k][i%2][l] = k == 0 ? min(c[k][i%2][l], c[k][(i - 1) % 2][j] + s[l])
												  : max(c[k][i%2][l], c[k][(i - 1) % 2][j] + s[l]);
				}
			}
		}

	printf("%d %d\n", c[1][(N + 1) % 2][0], c[0][(N + 1) % 2][0]);
}
	
