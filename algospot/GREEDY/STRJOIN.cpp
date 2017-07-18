#include <cstdio>
#include <queue>
using namespace std;

int main() {

	int c;
	scanf("%d", &c);
	while (c--) {
		int n;
		scanf("%d", &n);
		priority_queue<int> q;
		for (int i = 0; i < n; i++) {
			int len;
			scanf("%d", &len);
			q.push(-len);
		}
		
		int it = 0;
		while (!q.empty()) {
			int a = q.top(); q.pop();
			if (q.empty()) break;

			int b = q.top(); q.pop();
			it -= (a+b);
			printf("it : %d\n", it);
			q.push(a+b);
		}
		printf("%d\n", it);
	}

}