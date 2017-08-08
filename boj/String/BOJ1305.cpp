//BOJ
//2017/07/24
//ID : 1305 / KMP
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n;
	string s;
	scanf("%d", &n);
	cin >> s;

	vector<int> pi(n);

	int b = 1, m = 0;
	while (b + m < n) {
		if (s[m] == s[b + m]) {
			m++;
			pi[b + m - 1] = m;
		}
		else {
			if (!m)
				b++;
			else {
				b += m - pi[m - 1];
				m = pi[m - 1];
			}
		}
	}

	int ans;
	if (pi[n - 1] == 0)
		ans = n;
	else
		ans = n - pi[n - 1];
	printf("%d", ans);

}
