//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//
//vector<int> adj[1001];
//int visited[1001];
//int finished[1001],cnt=0,order[1001];
//int suc=1;
//
//void dfs(int n) {
//
//	visited[n] = 1;
//
//	for (int i = 0; i < adj[n].size(); i++) {
//		if (visited[adj[n][i]] == 0) {
//			dfs(adj[n][i]);
//		}
//		else if (finished[adj[n][i]] == 0) {
//			suc = -1;
//			break;
//		}
//	}
//	if (suc == -1) {
//		return;
//	}
//	
//	order[cnt] = n;
//	finished[n] = 1;
//	cnt++;
//}
//
//int main() {
//	int N, M,start;
//	scanf("%d %d", &N, &M);
//	for (int i = 0; i < M; i++) {
//		int K,prev;
//		scanf("%d %d", &K,&prev);
//		for (int j = 0; j < K-1; j++) {
//			int curr;
//			scanf("%d", &curr);
//			adj[prev].push_back(curr);
//			prev = curr;
//		}
//	}
//
//	for (int i = 1; i <= N; i++) {
//		if (visited[i] == 0) {
//			suc = 1;
//			dfs(i);
//				if (suc == -1) {
//					printf("0\n");
//					return 0;
//				}
//		}
//	}
//
//	for (int i = N - 1; i >= 0; i--)
//		printf("%d\n", order[i]);
//}
