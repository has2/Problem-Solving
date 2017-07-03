#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 1000000;
vector<int> seg;

void update(int taste, int cnt,int size) {
	taste = taste + size - 1;
	seg[taste] += cnt;
	
	for (taste /= 2; taste > 0; taste /= 2) 
		seg[taste] = seg[2 * taste] + seg[2 * taste + 1];
}

int query(int rank, int cur_node,int size) {

	if (cur_node >= size) {
		int candy = cur_node - size + 1;
		update(candy, -1, size);
		return candy;
	}
	return seg[2 * cur_node] >= rank ? query(rank, 2 * cur_node, size) : 
									   query(rank - seg[2 * cur_node], 2 *	cur_node + 1, size);
}

int main(void) {
	int N,size;
	scanf("%d", &N);
	
	for(size=1; size<MAX; size*=2){}
	seg.resize(2 * size);

	int a, b, c;
	while (N--) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d", &b);
			printf("%d\n", query(b, 1, size));
		}
		else {
			scanf("%d%d", &b, &c);
			update(b, c, size);
		}
	}
}