// boj 1298
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int A[100], B[5000];
bool visited[100];
vector<int> adj[100];

bool dfs(int i) {

	if (visited[i]) return false;
	visited[i] = true;

	for (int to : adj[i]) {
		if (B[to] == -1 || dfs(B[to])) {
			B[to] = i;
			A[i] = to;
			return true;
		}
	}

	return false;
}

int main() {

	scanf("%d%d", &n,&m);
	
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int total = 0;
	for (int i = 0; i < n; i++) {

		memset(visited, 0, sizeof(visited));
		if (dfs(i)) total++;
	}

	printf("%d\n", total);
}