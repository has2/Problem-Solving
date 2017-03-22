//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> G[101];
//bool visited[101];
//
//void dfs(int n)
//{
//	printf("%d ", n);
//	visited[n] = true;
//	for (int i = 0; i < G[n].size(); i++) {
//		if (!visited[G[n][i]])
//		{
//			visited[G[n][i]] = true;
//			dfs(G[n][i]);
//		}
//	}
//	return;
//
//}
//
//int main() {
//	int n, m, a, b;
//	cin >> n; cin >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> a; cin >> b;
//		G[a].push_back(b);
//		G[b].push_back(a);
//	}
//	dfs(1);
//
//}