#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int N, a[11], start[56], pos[56], INF = 987654321;
string expr;
bool ok = false;
void sol(int cur) {
	if (ok) return;
	if (cur == 0) {

		for (int i = 1; i <= N; i++) {
			printf("%d ", a[i]);
		}
		ok = 1;
		return;
	}

	int s = start[cur], e = pos[cur];
	if (a[s] == INF) {
		int sum = 0;
		for (int i = s+1; i <= e; i++) sum += a[i];
		for (int i = -10; i <= 10; i++) {
			if (expr[cur] == '+') {
				if (sum + i > 0) {
					a[s] = i;
					sol(cur -1);
				}
			}
			else if (expr[cur] == '-') {
				if (sum + i < 0) {
					a[s] = i;
					sol(cur - 1);
				}
			}
			else {
				if (sum + i == 0) {
					a[s] = i;
					sol(cur - 1);
				}
			}
			a[s] = INF;
		}
	}
	else {
		int sum = 0;
		for (int i = s; i <= e; i++) sum += a[i];
		if (expr[cur] == '+') {
			if (sum> 0) sol(cur - 1);
		}
		else if (expr[cur] == '-') {
			if (sum< 0) sol(cur - 1);
		}
		else {
			if (sum == 0) sol(cur - 1);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) a[i] = INF;
	cin >> expr;

	int base = 0;
	int a = N, it = 0;;
	for (int i = 1; i <= (N*(N + 1)) / 2; i++) {
		pos[i] = N - a + 1;
		start[i] = it + 1;
		if (--a == 0) {
			it++;
			a = N - it;
		}
	}
	expr = " " + expr;
	sol(expr.size());
}