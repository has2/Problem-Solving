//Algospot
//ID : NERDS2 / map,tree
//2017/07/26

#include <cstdio>
#include <map>
using namespace std;
map<int, int> pa;
int n;

bool isDominated(int x, int y) {

	map<int, int>::iterator it = pa.lower_bound(x);
	if (it == pa.end()) return false;

	return it->second > y;
}

void remove(int x, int y) {

	map<int, int>::iterator it = pa.lower_bound(x);

	if (it == pa.begin()) return;
	--it;

	while (1) {

		if (it->second > y) {
			break;
		}

		if (it == pa.begin()){
			pa.erase(it);
			break;
		}
		else {
			map<int,int>::iterator jt = it;
			--jt;
			pa.erase(it);
			it = jt;
		}
	}
}

int main() {
	int c;
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		pa.clear();
		int total=0;
	

		for (int i = 0; i < n; i++) {

			int x, y;
			scanf("%d%d", &x, &y);
			if (isDominated(x, y)) {
				total += pa.size();
				continue;
			}

			remove(x, y);
			pa[x] = y;
			total += pa.size();
		}
		printf("%d\n", total);
	}
}