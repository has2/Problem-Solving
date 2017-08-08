//BOJ
//ID : 11585 / KMP
//2017/07/25
//문제의 출력 조건 제대로 확인
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

string H,N;
int Hlen,Nlen;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}


int main() {
	
	scanf("%d", &Hlen);
	char c;
	for (int i = 0; i < Hlen; i++) {
		scanf(" %c", &c);
		H.push_back(c);
	}
	for (int i = 0; i < Hlen; i++) {
		scanf(" %c", &c);
		N.push_back(c);
	}
	H += H;
	Nlen = Hlen;
	Hlen = H.size();
	vector<int> pi(Hlen);

	int b = 1, m = 0;
	while (b + m < Nlen) {
		if (N[b + m] == N[m]) {
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

	int cnt = 0;
	b = 0, m = 0;

	while (b < Hlen - Nlen) {
		if (m < Nlen && N[m] == H[b + m]) {
			++m;
			if (m == Nlen) cnt++;
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

	if (Nlen == cnt) {
		printf("1/1");
		return 0;
	}

	int g = gcd(Nlen, cnt);
	if (g != 0) {
		cnt /= g;
		Nlen /= g;
	}

	printf("%d/%d", cnt, Nlen);
}