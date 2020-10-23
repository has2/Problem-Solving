#include <cstdio>
#include <vector>

using namespace std;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int N, M,T,INF = -987654321;
vector<int> circle[51];
bool noNum;
void rotate(int x, int d, int k) {

	vector<int> cur = circle[x];
	vector<int> tmp(M);

	if (d == 0) {
		for (int i = 0; i < M; i++) {
			int idx = (i + k) % M;
			tmp[idx] = cur[i];
		}
	}
	else {
		for (int i = 0; i < M; i++) {
			int idx = (M + i - k) % M;
			tmp[idx] = cur[i];
		}
	}
	circle[x] = tmp;
}

void update(double avg) {

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (circle[i][j] != INF) {
				if (circle[i][j] > avg) {
					circle[i][j]--;
				}
				else if(circle[i][j] < avg){
					circle[i][j]++;
				}
			}
		}
	}
}

int getSum() {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (circle[i][j] != INF) {
				sum += circle[i][j];
			}
		}
	}
	return sum;
}

void rmvAdj() {

	vector<vector<bool>> erase(N + 1, vector<bool>(M));
	bool erased = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				if (circle[i][j] == INF) continue;
				int ni = i + dy[k];
				int nj = j + dx[k];
				if (ni < 1 || ni > N || nj < 0 || nj >= M) continue;
				if (circle[ni][nj] == circle[i][j]) {
					erase[ni][nj] = erase[i][j] = 1;
					erased = 1;
				}
			}
		}
		if (circle[i][0] == circle[i][M - 1]) erase[i][0] = erase[i][M - 1] = 1;
	}
	for (int i = 1; i <= N; i++) 
		for (int j = 0; j < M; j++) if (erase[i][j]) circle[i][j] = INF;

	if (!erased) {
		int sum = 0;
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				if (circle[i][j] != INF) {
					cnt++;
					sum += circle[i][j];
				}
			}
		}
		if (cnt == 0) {
			noNum = 1;
			return;
		}
		double avg = (double)sum / cnt;
		update(avg);
	}
}

void print() {
	puts("");
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", circle[i][j]);
		}
		puts("");
	}

}

int main() {
	scanf("%d%d%d", &N, &M, &T);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			scanf("%d", &a);
			circle[i].push_back(a);
		}
	}
	//print();
	while (T--) {
		int x, d, k;
		scanf("%d%d%d", &x, &d, &k);
		if (noNum) continue;
		for(int i=x;i<=N;i+=x) rotate(i, d, k);
		rmvAdj();
		//print();
	}
	printf("%d", getSum());
}