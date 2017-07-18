#include <cstdio>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	int N, start, endp;
	vector<tuple<int, int, int>> obstacle;
	vector<tuple<int, int, int>>::iterator itobs;
	vector<long long> result_y;
	map<long long, long long> Map;
	map<long long, long long>::iterator itMap;

	scanf("%d%d%d", &N, &start, &endp);
	for (int i = 0; i < N; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		obstacle.push_back(make_tuple(a, b, c));
	}

	sort(obstacle.begin(), obstacle.end());

	for (itobs = obstacle.begin(); itobs != obstacle.end(); itobs++) {
		if (get<1>(*itobs) < start && get<2>(*itobs) > start) {
			Map[get<1>(*itobs)] = abs(get<1>(*itobs) - start);
			Map[get<2>(*itobs)] = abs(get<2>(*itobs) - start);
			break;
		}
		if (itobs == obstacle.end() - 1) {
			printf("%d\n%d %d", endp, 1,start);
			return 0;
		}
	}

	vector<tuple<int, int, int>>::iterator itobs2;
	

	//for (int i = 1; i < N; i++) {
	for (itobs2 = itobs; itobs2 != obstacle.end(); itobs2++) {
		int low = get<1>(*itobs2);
		int high = get<2>(*itobs2);
		for (itMap = Map.lower_bound(low + 1); itMap != Map.upper_bound(high - 1); ) {
			int low_value = Map[low];
			int high_value = Map[high];

			if (low_value == NULL) {
				Map[low] = itMap->second + abs(low - itMap->first);
			}
			else {
				Map[low] = std::min(Map[low], itMap->second + abs(low - itMap->first));
			}

			if (high_value == NULL) {
				Map[high] = itMap->second + abs(high - itMap->first);
			}
			else {
				Map[high] = std::min(Map[high], itMap->second + abs(high - itMap->first));
			}
			Map.erase(itMap++);
		}
	}
	//}

	vector<pair<int, int>> result;
	vector<pair<int ,int>>::iterator itRes;

	for (itMap = Map.begin(); itMap != Map.end(); itMap++) {
		result.push_back(make_pair(itMap->second, itMap->first));
	}

	sort(result.begin(), result.end());

	int cnt = 0, min = result[0].first;
	for (itRes = result.begin(); itRes != result.end(); itRes++) {
		if (itRes->first == min)
			cnt++;
		else
			break;
	}

	printf("%d\n%d ", min + endp, cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d ", result[i].second);

}