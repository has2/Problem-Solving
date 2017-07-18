#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int A[1001], B[1001];
bool visited[1001];
vector<int> adj[1001];

bool dfs(int from) {
	
	if (visited[from]) return false;
	visited[from] = true;
	for (int to : adj[from]) {
		if (B[to] == -1 || dfs(B[to])) {
			A[from] = to;
			B[to] = from;
			return true;
		}
	}
	return false;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(A, -1, sizeof(A));
		memset(B, -1, sizeof(B));
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= M; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[i].clear();
			for (int j = a; j <= b; j++)
				adj[i].push_back(j);
		}

		int total = 0;
		for (int i = 1; i <= M; i++) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i))
				total++;
		}
		printf("%d\n", total);
	}
}