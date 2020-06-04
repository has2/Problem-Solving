#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<pair<int,int>> q;

	int cnt = truck_weights.size();
	int cur_i = 0;
	int cur_w = 0;
	int time = 0;

	while (1) {

		if (cur_i < cnt && cur_w + truck_weights[cur_i] <= weight) {

			int qsize = q.size();
			while (qsize--) {

				auto truck = q.front();
				q.pop();
				if (truck.second != bridge_length) {
					q.push(make_pair(truck.first, truck.second + 1));
				}
				else {
					cur_w -= truck_weights[truck.first];
				}
			}
			
			cur_w += truck_weights[cur_i];
			q.push(make_pair(cur_i++, 1));
			time++;
		}
		else if (!q.empty()) {

			auto truck = q.front();
			q.pop();

			cur_w -= truck_weights[truck.first];

			int offset = bridge_length - truck.second+1;
			int qsize = q.size();
			while (qsize--) {
				truck = q.front();
				q.pop();
				q.push(make_pair(truck.first, truck.second + offset));
			}

			if (cur_i < cnt && cur_w + truck_weights[cur_i] <= weight) {
				cur_w += truck_weights[cur_i];
				q.push(make_pair(cur_i++, 1));
			}

			time += offset;
		}
		else {
			answer = time;
			break;
		}
		//printf("time : %d\n", time);
	}
	
	return answer;
}

int main() {

	int bridge = 2;
	int wi = 10;
	vector<int> a = { 7,4,5,6 };

	//int bridge = 100;
	//int wi = 100;
	//vector<int> a = { 10 };

	//int bridge = 1;
	//int wi = 6;
	//vector<int> a = { 6,6};

	printf("%d", solution(bridge, wi, a));

}