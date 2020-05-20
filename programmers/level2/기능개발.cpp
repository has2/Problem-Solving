#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;
	vector<int> day(speeds.size());
	for (int i = 0; i < speeds.size(); i++) {
		int remain = 100 - progresses[i];
		day[i] = remain / speeds[i];
		if (remain % speeds[i] > 0) day[i]++;
		q.push(i);
	}
	while (!q.empty()) {

		int first = q.front();
		int cnt = 0;
		while (!q.empty() && day[first] >= day[q.front()]) {
			q.pop();
			cnt++;
		}
		answer.push_back(cnt);
	}
	return answer;
}