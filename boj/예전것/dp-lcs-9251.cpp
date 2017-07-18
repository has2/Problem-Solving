#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char A[1001], B[1001];
int AB[1001][1001];

int main(void) {

	int len;
	scanf("%s", A);
	scanf("%s", B);

	for (int i = 1; i <= strlen(A) ; i++) {
		for (int j = 1; j <= strlen(B); j++) {
			if (A[i - 1] == B[j - 1])
				AB[i][j] = AB[i - 1][j - 1] + 1;
			else
				AB[i][j] = max(AB[i - 1][j], AB[i][j - 1]);
		}
	}
	printf("%d", AB[strlen(A)][strlen(B)]);
}