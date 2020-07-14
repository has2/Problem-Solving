#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int solution(string name) {
	int answer = 0;

	string curName(name.size(), 'A');
	int cur = 0;

	while (name != curName) {

		int near = -1;
		int minDiff = 30;
		for (int i = 0; i < name.size(); i++) {
			if (name[i] != curName[i]) {
				int diff = abs(cur - i);
				diff = min(diff, (int)name.size() - diff);
				if (minDiff > diff) {
					near = i;
					minDiff = diff;
				}
			}
		}
		cur = near;
		curName[cur] = name[cur];
		answer += minDiff;
		
		int k = name[cur] - 'A';
		answer += min(26 - k, k);

		//cout << "cur : " << cur << ", minDiff : " << minDiff << ", k : " << k << ", len -k : " << 26-k << endl;
	}

	return answer;
}