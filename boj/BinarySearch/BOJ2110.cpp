//BOJ
//ID : 2110 / Binary Search
//2017/08/05

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000000000;
int hs[200001],n,c;
bool ck[200001];

bool check(int len) {

	int k = c,cur=0;

	for (int i = 1; i < n; i++) {
		if (hs[i] - hs[cur] >= len) {
			k--;
			cur = i;
		}
	}
	return k > 1 ? false : true;
}

int main() {

	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d", &hs[i]);

	sort(hs, hs + n);

	int lo = 0, hi = MAX + 1;
	
	while (lo + 1 < hi) {

		int mid = (lo + hi) / 2;

		if (check(mid)) lo = mid;
		else hi = mid;
	}
	printf("%d", lo);
}