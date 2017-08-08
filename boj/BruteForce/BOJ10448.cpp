//BOJ
//ID : 10448 / Brute force
//2017/07/26
#include <cstdio>
int tri[50];
bool check(int n, int k) {

	for (int i = 1; i < k; i++)
		for (int j = 1; j < k; j++)
			for (int m = 1; m < k; m++)
				if (n == tri[i] + tri[j] + tri[m])
					return true;

	return false;

}

int main() {

	for (int i = 1; i <= 50; i++)
		tri[i] = (i*(i + 1)) / 2;

	int t;
	scanf("%d", &t);
	while (t--) {
		int n,k,sum;
		scanf("%d", &n);
		for (k = 1; k <= 50 && n > tri[k]; k++) {}
		
		if (check(n, k)) printf("1\n");
		else printf("0\n");
	}
}

