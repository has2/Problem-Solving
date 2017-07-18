#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int A[4001], B[4001], C[4001], D[4001];
int AB[16000000];

int main(void)
{
	int n,nsqtr=1,cnt=0,k=1;
	vector<int> CD;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			AB[nsqtr++] = A[i] + B[j];
		}
	}
	CD.push_back(-999999999);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			CD.push_back(C[i] + D[j]);
		}
	}
	
	sort(CD.begin(), CD.end());

	for (int i = 1; i <= n*n; i++)
	{
		int low = 1, high = n*n;
		int idx = (low + high) / 2;
		int sum = AB[i] + CD[idx];
	
		
		while (low<=high)
		{

			if (sum == 0) {
				cnt++;
				int tempidx = idx;
				while (1) {
					tempidx++;
					if (tempidx > n*n)
						break;
					if (AB[i] + CD[tempidx] != 0)
						break;
					cnt++;
				}
				tempidx = idx;
				while (1) {
					tempidx--;
					if (tempidx < 0)
						break;
					if (AB[i] + CD[tempidx] != 0)
						break;
					cnt++;
				}
				break;
			}


			if (sum < 0) 
			{
				low = idx + 1;
				//sum = AB[i] + CD[idx];
			}
			else 
			{
				high = idx - 1;
				//sum = AB[i] + CD[idx];
			}

			idx = (low + high) / 2;
			sum = AB[i] + CD[idx];
			printf("%d,%d\n",sum,idx);

		}
	}

	printf("%d", cnt);

}