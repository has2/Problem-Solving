#include <cstdio>
#include <list>

using namespace std;

int main() {
	int c;
	scanf("%d", &c);
	while (c--) {

		int n, k;
		scanf("%d%d", &n, &k);
		list<int> L;
		for (int i = 1; i <= n; i++)
			L.push_back(i);

		list<int>::iterator ptr = L.begin();
		while (n > 2) {

			ptr = L.erase(ptr);
			n--;

			if (ptr == L.end()) ptr = L.begin();

			for (int i = 0; i < k-1; i++) {
				ptr++;
				if (ptr == L.end()) ptr = L.begin();
			}
		}
		for (auto p : L)
			printf("%d ", p);
		printf("\n");
	}

}