//BOJ
//ID : 1786 / KMP
//2017/07/23
//begin,matched 헷갈리지 않기
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int MAX = 1000000;

vector<int> getPi(const string& p) {

	int m = p.size();
	vector<int> pi(m,0);

	int begin = 1, matched = 0;
	while (begin + matched < m) {
		
		if (p[matched] == p[begin + matched]) {
			
			matched++;
			pi[begin+matched-1] = matched;
		}
		else {
			if (matched == 0)
				begin++;

			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

int main() {
	string T, P;

	getline(cin,T);
	getline(cin, P);

	vector<int> pi = getPi(P);
	vector<int> ret;

	int cnt = 0;
	int n = T.size(), m = P.size();

	int begin = 0, matched = 0;
	while (begin <= n-m) {

		if (matched < m && T[begin + matched] == P[matched]) {
			++matched;
			if (matched == m) {
				cnt++;
				ret.push_back(begin);
			}
		}
		else {
			if (matched == 0)
			++begin;
			else {
				begin += (matched - pi[matched - 1]);
				matched = pi[matched - 1];
			}
		}
	}
	printf("%d\n", cnt);
	for (auto pos : ret)
		printf("%d ", pos + 1);
}