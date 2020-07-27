#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(const string& a, const string& b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> ns;
	for (int n : numbers) ns.push_back(to_string(n));
	sort(ns.begin(), ns.end(), cmp);
	for (auto s : ns) answer += s;
	if (answer[0] == '0') answer = "0";
	return answer;
}