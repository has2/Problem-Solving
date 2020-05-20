#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	queue<int> q;
	priority_queue<int> pq;

	for (int i = 0; i < priorities.size(); i++) {
		q.push(i);
		pq.push(priorities[i]);
	}

	while (!q.empty()) {
		int i = q.front();
		q.pop();
		if (priorities[i] == pq.top()) {
			answer++;
			if (i == location) break;
			pq.pop();
		}
		else {
			q.push(i);
		}
	}
	return answer;
}