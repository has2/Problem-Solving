//BOJ
//ID : 1787 / KMP
//2017/07/25
//문자열의 길이가 100만이기 때문에 dp를 이용해야 한다.
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
string s;
int slen;
int cache[1000000];

int main() {

	memset(cache, -1, sizeof(cache));
	scanf("%d\n", &slen);
	cin >> s;
	vector<int> pi(slen);

	int b = 1, m = 0;
	while (b + m < slen) {
		if (s[b + m] == s[m]) {
			++m;
			pi[b + m - 1] = m;
		}
		else {
			if (m == 0)
				++b;
			else {
				b += m - pi[m - 1];
				m = pi[m - 1];
			}
		}
	}
	long long sum = 0;
	for (int l = 2; l <= slen; l++) {
		
			int k = l-1;
			int& ret = cache[l - 1];

			bool ok = false;
			while (k > 0 && pi[k] != 0) {
				k = pi[k] - 1;
				if (cache[k] != -1) {
					ret = cache[k];
					ok = true;
					break;
				}
			}
			if(!ok)
			ret = k+1;

			if (ret != 0 && l - ret >= l / 2)
				sum += l - ret;
	}
	printf("%lld", sum);
}
