#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

pair<string, int> pkm[100001];
string pkname[100001];

int main(void) {
	int N, M;
	char tmp[21];
	string tmpp;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%s", tmp);
		tmpp = tmp;
		pkm[i] = make_pair(tmpp, i);
		pkname[i] = tmpp;
	}
	
	sort(pkm + 1, pkm + N + 1);
	while (M--) {
		scanf("%s", tmp);
		tmpp = tmp;
		if (isdigit(tmpp.at(0))) printf("%s\n", pkname[stoi(tmpp)].c_str());
		else {

			int l = 1, r = N, m;
			while (true) {
				m = (l + r) / 2;
				if (tmpp.compare(pkm[m].first) < 0) r = m - 1;
				else if (tmpp.compare(pkm[m].first) > 0) l = m + 1;
				else break;
			}
			printf("%d\n", pkm[m].second);
		}
	}
}

//#include <cstdio>
//#include <string>
//#include <cctype>
//#include <map>
//using namespace std;
//
//map<string, int> pkm;
//string pkname[100001];
//
//int main(void) {
//	int N, M;
//	char tmp[21];
//	string tmpp;
//	scanf("%d%d", &N, &M);
//	for (int i = 1; i <= N; i++) {
//		scanf("%s", tmp);
//		tmpp = tmp;
//		pkm.insert(make_pair(tmpp, i));
//		pkname[i] = tmpp;
//	}
//	
//	while (M--) {
//		scanf("%s", tmp);
//		tmpp = tmp;
//		if (isdigit(tmpp.at(0))) printf("%s\n", pkname[stoi(tmpp)].c_str());
//		else printf("%d\n", pkm[tmpp]);
//	}
//}