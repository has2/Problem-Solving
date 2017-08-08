//Algospot
//ID : BRACKETS2 / stack
//string.find() 활용, 마지막에 {[(들이 남았는지 확인.
#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int c;
	scanf("%d", &c);
	while (c--) {

		const string op("({["), cl(")}]");
		string brackets;
		cin >> brackets;

		stack<char> S;
		bool ans = true;
		for (auto ch : brackets) {

			if (op.find(ch) != -1) 
				S.push(ch);
			else {
				if (!S.empty()) {
					char t = S.top();
					if (op.find(t) == cl.find(ch))
						S.pop();
					else {
						ans = false;
						break;
					}
				}
				else {
					ans = false;
					break;
				}
			}
		}
		if (ans  &&S.empty())
			printf("YES\n");
		else
			printf("NO\n");
	}
}