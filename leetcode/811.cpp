#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {

		vector<string> ans;
		map<string, int> m;

		for (string& s : cpdomains) {
			size_t pos = s.find(' ');
			int cnt = stoi(s.substr(0, pos + 1));

			do {
				s = s.substr(pos + 1);
				m[s] += cnt;
			} while ((pos = s.find('.')) != string::npos);
		}

		for (auto& a : m) {
			ans.push_back(to_string(a.second) + ' ' + a.first);
		}

		return ans;

	}
};