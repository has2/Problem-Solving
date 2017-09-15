//BOJ
//ID : 2789 / string
//2017/09/07

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const string check = "CAMBRIDGE";
string ret;

int main() {
	
	cin >> ret;

	int cur = 0;
	for (int i = 0; i < ret.size(); i++) {

		int ch = ret[i];
		bool ok = false;
		for (char a : check) {
			if (ch == a) {
				ok = true;
				break;
			}
		}
		if(!ok)	ret[cur++] = ch;
	}
	for (int i = 0; i < cur; i++)
		printf("%c", ret[i]);
}



