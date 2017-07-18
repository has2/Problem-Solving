//#include <iostream>
//#include <vector>
//#include <stdio.h>
//
//using namespace std;
//
//vector<int> G[101];
//int visited[101];
//int cnt;
//
//void dfs(int n) {
//	visited[n] = 1;
//	
//	for (int i = 0; i < G[n].size(); i++) {
//		if (visited[G[n][i]] == 0) {
//			cnt++;
//			dfs(G[n][i]);
//		}
//	}
//}
//
//int main() {
//	int N, M, a, b;
//
//	cin >> N; cin >> M;
//	for (int i = 1; i <= M; i++) {
//		scanf("%d %d", &a, &b);
//		//cin >> a; cin >> b;
//		G[a].push_back(b);
//		G[b].push_back(a);
//	}
//
//	for (int i = 1; i <= N; i++) {
//		dfs(1);
//	}
//	
//	cout << cnt << endl;
//}