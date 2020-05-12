#include <string>
#include <vector>
using namespace std;
char pre[26];
int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (int i = 1; i < skill.size(); i++) {
		pre[skill[i] - 'A'] = skill[i - 1];
	}

	for (int i = 0; i < skill_trees.size(); i++) {
		string cur = skill_trees[i];
		char cur_skill = 0;
		bool ok = 1;
		for (int j = 0; j < cur.size(); j++) {
			if (skill.find(cur[j]) != string::npos) {
				if (pre[cur[j] - 'A'] != cur_skill) {
					ok = 0;
					break;
				}
				cur_skill = cur[j];
			}			
		}
		if (ok) answer++;
	}
	return answer;
}