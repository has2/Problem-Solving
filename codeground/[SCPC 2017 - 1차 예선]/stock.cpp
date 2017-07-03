#include <cstdio>
#include <algorithm>
using namespace std;

int stock[200000];

int main(void)
{
	int T, test_case;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int N,cnt=0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &stock[i]);

		for (int i = 0; i < N; i++) {

			bool ok = false;
			int val = stock[i];
			int j;
			for(j=i+1;j<N,val < stock[j];j++){
				val = stock[j];
				ok = true;
			}
			if (ok) {
				cnt += 2;
				i = j-1;
			}
		}
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", cnt);
	}

	return 0;
}