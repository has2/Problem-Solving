#include <cstdio>
#include <cstring>

using namespace std;

int n;
int cache[100][100];
int board[100][100];

int sol(int x, int y) {

	if (x >= n || y >= n) return 0;
	if (x == n - 1 && y == n - 1) return 1;

	int& ret = cache[x][y];
	
	if (ret != -1) return ret;
	int jump = board[x][y];
	return ret = sol(x + jump, y) || sol(x, y + jump);

}


int main(int argc, char** argv)
{
	int T, test_case;

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		memset(cache, -1, sizeof(cache));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &board[i][j]);

		if (sol(0, 0) == 1) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}