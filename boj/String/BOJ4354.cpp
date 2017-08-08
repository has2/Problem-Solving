//BOJ
//ID : 4354 / KMP
//2017/07/23
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {

	string s;

	while (1) {
		cin >> s;
		if (s == ".") break;

		int n = s.size();
		vector<int> pi(n, 0);

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
		
		for (int i = n; i > 0; i--) {
			if (pi[n - 1] == ((double)n / i)*(i - 1)) {
				printf("%d\n", i);
				break;
			}
		}
	}
}