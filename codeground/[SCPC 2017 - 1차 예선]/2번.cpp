#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;
int S[5], L[5], D[5];

bool isNatural(int k,int time) {

	int ret = (S[k] * time + D[k]) % L[k];

	return ret == 0 ? true : false;
}

int lcm(int a, int b) {
	int mod = a % b;
	int multi = a * b;

	while (mod != 0) {
		a = b;
		b = mod;
		mod = a % b;
	}

	return multi / b;
}


int main(void)
{
	int T, test_case;
	
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int N;
		vector<pair<int, int>> CD;
		set<int> ex;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d%d%d", &S[i], &L[i], &D[i]);

		for (int k = 0; k < N; k++) {
			int time = 2;
			while (true) {
				if (isNatural(k, time)) {
					CD.push_back(make_pair(0,time)); 
					break;
				}
				time++;
			}
		}

		for (int k = 0; k < N; k++) {
			int a = S[k], b = L[k];
			int l;
			if (a < b) l = lcm(b, a);
			else l = lcm(a, b);
			CD[k].first = l/a;
			if (CD[k].first == CD[k].second) CD[k].second = 0;
		}

		sort(CD.begin(), CD.end(), greater<pair<int,int>>());

		int cur_f, cur_cd;

		int num = CD[0].second > 0 ? CD[0].second : 0;
		while (true) {

			if (num%CD[1].first == CD[1].second) {
				cur_f = num;
				cur_cd = CD[0].first > CD[1].first ? lcm(CD[0].first, CD[1].first):lcm(CD[1].first, CD[0].first);
				break;
			}
			num += CD[0].first;
		}

		for (int k = 2; k < N; k++) {

			int num = cur_f;
			while (true) {
				if (num%CD[k].first == CD[k].second) {
					cur_f = num;
					cur_cd = cur_cd > CD[k].first ? lcm(cur_cd, CD[k].first) : lcm(CD[k].first, cur_cd);
					break;
				}
				num += cur_cd;
			}
		}
		if (cur_f == 0) cur_f = cur_cd;
		printf("Case #%d\n", test_case + 1);
		cout << cur_f << endl;
	}

	return 0;
}