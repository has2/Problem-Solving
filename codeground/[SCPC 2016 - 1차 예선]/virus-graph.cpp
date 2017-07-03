#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int adj[101][101];
int cnt[101];
int K, L, M, N, a, b, V, deleted ,delcnt;

int main(int argc, char** argv)
{
	int T, test_case;


	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int ans = 0;
		deleted = true;
		vector<int> ansvec;
		cin >> K >> L >> N >> M;
		V = N;
		while (M--) {
			cin >> a >> b;
			adj[a][b] = adj[b][a] = 1;
			cnt[a]++; cnt[b]++;
		}
		while (true) {
			deleted = true;
			while (deleted) {
				deleted = false;
				for (int i = 1; i <= N; i++) {
					if (cnt[i] != -1 && cnt[i] < K) {
						deleted = true; V--;
						cnt[i] = -1;
						ansvec.push_back(i);
						for (int j = 1; j <= N; j++) {
							if (adj[i][j] == 1) {
								cnt[j]--;
								adj[j][i] = 0;
							}
						}
					}
				}	
			}

			deleted = true;
			delcnt = 0;
			while (deleted) {
				deleted = false;
				for (int i = 1; i <= N; i++) {
					if (cnt[i] != -1 && cnt[i] >= V - L) {
						deleted = true; V--; delcnt++;
						cnt[i] = -1;
						ansvec.push_back(i);
						for (int j = 1; j <= N; j++) {
							if (adj[i][j] == 1) {
								cnt[j]--;
								adj[j][i] = 0;
							}
						}
					}
				}
			}
	
			if (delcnt == 0) 
				break;
		}
		cout << "Case #" << test_case + 1 << endl;
		for (auto v : ansvec) {
			ans += v;
		}
		cout << ans << endl;
		memset(cnt, 0, sizeof(cnt));
		memset(adj, 0, sizeof(adj));
	}

	return 0;//Your program should return 0 on normal termination.
}