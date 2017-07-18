#include <cstdio>
#include <cstring>

bool self[10001];
int main() {

	for (int i = 1; i <= 10000; i++) {

		int k=i,snum = i;
		while (k != 0) {
			snum += k - (k / 10) * 10;
			k /= 10;
		}
		if (snum <= 10000)
			self[snum] = true;
	}

	for (int i = 1; i <= 10000; i++)
		if (!self[i])
			printf("%d\n", i);
}