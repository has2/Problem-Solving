#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int> pq;
	for (int& t : scoville) pq.push(-t);
	
	while (!pq.empty()) {

		if (-pq.top() >= K) return answer;
		if (pq.size() <= 1) return -1;

		int a = -pq.top(); pq.pop();
		a += -2 * pq.top(); pq.pop();

		pq.push(-a);

		answer++;
	}
	return answer;
}