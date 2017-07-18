////½ÇÆÐ : Çà·ÄÀÇ °ÅµìÁ¦°ö
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 5;
double prob[5][50];
double Next[50][50];
int len[50];

int main() {
	int c;
	scanf("%d", &c);

	while (c--) {
		memset(prob, 0, sizeof(prob));
		memset(Next, 0, sizeof(Next));

		int n, k, m;
		scanf("%d%d%d", &n, &k, &m);

		for (int i = 0; i < n; i++)
			scanf("%d", &len[i]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%lf", &Next[i][j]);

		prob[0][0] = 1;
		for (int i = 1; i <= k; i++) {
			for (int j = 0; j < n; j++) {
				double& ret = prob[i%MOD][j];
				ret = 0;
				for (int l = 0; l < n; l++) {
					if(i-len[l] >= 0)
					ret += prob[(i - len[l]) % MOD][l] * Next[l][j];
				}
			}
		}

		while (m--) {
			int fav,l;
			double p = 0.0;
			scanf("%d", &fav);
			l = len[fav];

			for (int i = k - len[fav] + 1; i <= k; i++)
				p += prob[i%MOD][fav];

			printf("%f ", p);
		}
	}


}



