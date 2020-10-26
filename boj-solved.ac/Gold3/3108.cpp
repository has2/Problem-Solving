#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct P {
	int x,y;
};
struct Rec {
	P l, r;
	Rec(){}
	Rec(P l, P r) :l(l), r(r) {}
};
Rec recs[1000];
int N,ans,exist;
vector<int> adj[1000];
bool visit[1000];
bool notadj(Rec a, Rec b) {
	if(a.l.x > b.l.x) swap(a,b);
	if ((a.l.x < b.l.x && a.l.y < b.l.y && a.r.y > b.r.y && a.r.x > b.r.x)
		|| a.r.x < b.l.x
		|| a.r.y < b.l.y
		|| a.l.y > b.r.y) return 1;
	return 0;
}

void dfs(int cur) {
	visit[cur] = 1;
	for (int nxt : adj[cur]) {
		if (!visit[nxt]) dfs(nxt);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if ((x1 == 0|| x2==0) && (y1 <= 0 && 0 <= y2)) exist = 1;
		if ((y1 == 0 || y2 == 0) && (x1 <= 0 && 0 <= x2)) exist = 1;
		recs[i] = Rec({ x1,y1 }, { x2,y2 });
	}
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (!notadj(recs[i], recs[j])) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d", exist ? cnt-1 : cnt);
}
