#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct P {
	int val, color, idx;
};
int N, ans[200000],sum[200000];
map<int, int> smap,samemap;
vector<P> a;

bool cmp(P& u, P& v) {
	return u.val < v.val;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int c, val;
		scanf("%d%d", &c, &val);
		a.push_back({ val,c,i });
	}

	sort(a.begin(), a.end(),cmp);

	sum[0]= a[0].val;
	smap[a[0].color] = a[0].val;
	samemap[a[0].color] += a[0].val;
	int sameidx = 0;
	for (int i = 1; i < a.size(); i++) {
		
		if (a[i - 1].val < a[i].val) {
			ans[a[i].idx] = sum[i - 1] - smap[a[i].color];
			samemap.clear();
			sameidx = i;
		}
		else {
			if (a[i - 1].color == a[i].color) ans[a[i].idx] = ans[a[i - 1].idx];
			else {
				if (sameidx > 0) {
					ans[a[i].idx] = sum[sameidx - 1] - smap[a[i].color] + samemap[a[i].color];
				}
			}
		}
		sum[i] = sum[i - 1] + a[i].val;
		smap[a[i].color] += a[i].val;
		samemap[a[i].color] += a[i].val;
	}
	for (int i = 0; i < N; i++) printf("%d\n", ans[i]);
}