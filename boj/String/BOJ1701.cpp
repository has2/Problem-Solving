//BOJ
//ID : 1701 / KMP
//2017/07/24
//부분 문자열을 찾을 때 pi 배열은 부분 문자열의 것이어야 한다.
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
int n;

// kmp + 이분탐색을 이용한 풀이
//vector<int> getpi(const string& s) {
//
//	int n = s.size();
//	vector<int> pi(n);
//
//	int b = 1, m = 0;
//
//	while (b + m < n) {
//
//		if (s[m] == s[b + m]) {
//			m++;
//			pi[m + b - 1] = m;
//		}
//		else {
//			if (m == 0)
//				b++;
//			else {
//				b += m - pi[m - 1];
//				m = pi[m - 1];
//			}
//		}
//	}
//	return pi;
//}
//
//bool check(int len) {
//
//	for (int i = 0; i < n - len + 1; i++) {
//
//		string ne = s.substr(i, len);
//		int l = ne.size();
//		vector<int> tpi = getpi(ne);
//
//		int b = i, m = 0,cnt=0;
//		while (b <= n - l) {
//			if (m < l && s[b + m] == ne[m]) {
//				m++;
//				if (m == l) {
//					cnt++;
//					if (cnt == 2) {
//						return true;
//					}
//				}
//			}
//			else {
//				if (m == 0)
//					b++;
//				else {
//					b += m - tpi[m - 1];
//					m = tpi[m - 1];
//				}
//			}
//		}
//	}
//	return false;
//}
//
//int main() {
//
//	cin >> s;
//	n = s.size();
//	
//	int lo = 0, hi = n;
//
//	while (lo + 1 < hi) {
//		int mid = (lo + hi) / 2;
//		if (check(mid)) lo = mid;
//		else hi = mid;
//	}
//	int ans = 0;
//	if (lo != 0) ans = lo;
//	printf("%d", lo);
//}

int main() {

	cin >> s;
	n = s.size();
	int ret = 0;
	for (int i = 0; i < n - 1; i++) {

		string ne = s.substr(i, n - i);
		int l = ne.size();
		vector<int> pi(l);
		int b = 1, m = 0;
		while (b + m < l) {
			if (ne[b + m] == ne[m]) {
				m++;
				ret = max(ret,pi[b + m - 1] = m);
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
	}
	printf("%d", ret);
}
