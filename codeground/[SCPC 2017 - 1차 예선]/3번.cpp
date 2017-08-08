#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int seq[100001];
int cnt;

void check(int div, int l, int r) {

		bool ok = false;
		for (int j = l; j <= r; j++) {
			if (seq[j] % div == 0)
				ok = true;
		}
		if (ok == false) {
			cnt++;
		}
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, M;
		cnt = 0;
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++)
			scanf("%d", &seq[i]);

		while (M--) {
			int b, l, r;
			scanf("%d%d%d", &b, &l, &r);
			int sqr = int(sqrt(b));
			for (int i = 1; i <= sqr; i++) {
				if (b%i == 0) {
					check(i, l, r);
					int k = b / i;
					
					if (k != i) {
						check(k, l, r);
					}
				}
			}
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << cnt << endl;
	}

	return 0;
}