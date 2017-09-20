//BOJ
//ID : 1759 // backtracking
//2017/09/17

#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int L, C;
char arr[15];
bool isVowel[26];
string pass;

void sol(int cnt,int cur,int vw, int ja) {
	if (cnt == L) {
		if (vw >= 1 && ja >= 2) {
			cout << pass << endl;
		}
		return;
	}

	for (int i = cur + 1; i < C; i++) {

		char ch = arr[i];
		pass[cnt] = ch;
		sol(cnt + 1, i, vw + isVowel[ch-'a'], ja + !isVowel[ch-'a']);
	}
}


int main() {
	
	scanf("%d%d", &L, &C);
	for (int i = 0; i < C; i++)
		scanf(" %c", &arr[i]);
	std::sort(arr, arr + C);

	pass.resize(L);
	isVowel[0] = isVowel[4] = isVowel[8] = isVowel[14] = isVowel[20] = true;

	sol(0, -1, 0, 0);
}