#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	vector<int> a[10];
	for (int j = 0; j < number.size(); j++) {
		a[number[j] - '0'].push_back(j);
	}
	
	int cur = -1;
	for (int i = k; i < number.size(); i++) {
		for (int j = 9; j >= 0; j--) {
			if (a[j].empty()) continue;
			if (answer == "" && j == 0) continue;
			auto ub = upper_bound(a[j].begin(), a[j].end(), cur);
			if (ub == a[j].end()) continue;

			int m = ub - a[j].begin();
			if (a[j][m] <= i) {
				answer.push_back(j + '0');
				cur = a[j][m];
				break;
			}
		}
	}
	return answer;
}