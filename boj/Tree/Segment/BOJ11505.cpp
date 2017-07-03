#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
const long long mod = 1000000007;

vector<long long> segtree;
vector<long long> d;

long long treeinit(int L, int R,int cur) {

	if (L == R)
		return segtree[cur] = d[L];
	int mid = (L + R) / 2;
	return segtree[cur] = (treeinit(L, mid, 2 * cur) * treeinit(mid + 1, R, 2 * cur + 1))%mod;
}

long long query(int L, int R, int cur_node, int cur_L, int cur_R) {
	if (L <= cur_L && cur_R <= R) return segtree[cur_node];
	if (R < cur_L || L > cur_R) return 1;
	int mid = (cur_L + cur_R) / 2;
	return (query(L, R, 2 * cur_node, cur_L, mid)*query(L, R, 2 * cur_node + 1, mid + 1, cur_R))%mod;
}

void update(int i, long long v,int size) {
	int idx = size + i;
	segtree[idx] = v;
	idx /= 2;
	while (idx > 0) {
		segtree[idx] = (segtree[idx * 2] * segtree[idx * 2 + 1])%mod;
		idx /= 2;
	}
}

int main(int argc, char** argv)
{
	int N, M, K,size,mk,q,a,b;
	cin >> N >> M >> K;

	for(size = 1; size < N; size*=2){}

	segtree.resize(2*size);
	d.resize(size);
	

	for (int i=0; i<N;i++)
		cin >> d[i];
	for (int i = N; i < size; i++)
		d[i] = 1;
	treeinit(0, size-1, 1);
	mk = M + K;

	while (mk--) {
		cin >> q >> a >> b;
		if (q == 1)
			update(a-1, b, size);
		else
			cout << query(a-1, b-1, 1, 0, size-1) << endl;;
	}

	return 0;
}