//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> G[1001];
//int visited[1001];
//int visited2[1001];
//
//void dfs(int n) {
//	visited[n] = 1;
//	cout << n << " ";
//
//	for (int i = 0; i < G[n].size(); i++) {
//		if (visited[G[n][i]] == 0) 
//			dfs(G[n][i]);
//	}
//}
//
//void bfs(int n) {
//	queue<int> Q;
//	Q.push(n);
//	cout << n << " ";
//	visited2[n] = 1;
//	while (!Q.empty()) {
//		int cur = Q.front();
//		Q.pop();
//		for (int i = 0; i < G[cur].size(); i++) {
//			if (visited2[G[cur][i]] == 0) {
//				visited2[G[cur][i]] = 1;
//				Q.push(G[cur][i]);
//				cout << G[cur][i] << " ";
//			}
//		}
//	}
//}
//
//int main() {
//
//	int N, M, S, a, b;
//	
//	cin >> N; cin >> M; cin >> S;
//	for (int i = 0; i < M; i++) {
//		cin >> a; cin >> b;
//		G[a].push_back(b);
//		G[b].push_back(a);
//	}
//	for (int i = 0; i <= N; i++)
//		sort(G[i].begin(), G[i].end());
//
//	dfs(S);
//	for (int i = 1; i <= N; i++) {
//		if (visited[i] == 0)
//			dfs(i);
//	}
//
//	cout << endl;
//	
//
//	bfs(S);
//	for (int i = 1; i <= N; i++) {
//		if (visited2[i] == 0) 
//			bfs(i);
//	}
//
//	
//}
