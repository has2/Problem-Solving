//#include <iostream>
//
//using namespace std;
//
//int number,cur;
//int map[100][100],visit[100],check[100][100];
//
//void dfs(int n) {
//	
//	for (int i = 0; i < number; i++) {
//		if (map[n][i] == 1 && visit[i] == 0) {
//			visit[i] = 1;
//			check[cur][i] = 1;
//			dfs(i);
//		}
//	}
//	return;
//}
//
//int main() {
//	cin >> number;
//	for (int i = 0; i < number; i++) {
//		for (int j = 0; j < number; j++)
//			cin >> map[i][j];
//	}
//
//	for (int i = 0; i < number; i++) {
//		cur = i;
//		dfs(i);
//		for(int j=0;j<number;j++)
//			visit[j]=0;
//	}
//
//	for (int i = 0; i < number; i++) {
//		for (int j = 0; j < number; j++) {
//			cout << check[i][j] <<" ";
//		}
//		cout << endl;
//	}
//	
//}
