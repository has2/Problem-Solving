#include <cstdio>

int main(void)
{
	long long T,L[4];
	scanf("%lld", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%lld%lld%lld", &L[1], &L[2], &L[3]);
		for (int j = 1; j <= 2; j++)
		{
			if (L[j] > L[j + 1])
			{
				long long temp = L[j];
				L[j] = L[j + 1];
				L[j + 1] = temp;
			}
		}
		printf("%lld", (L[1]+L[2])*(L[1]+L[2])+L[3]*L[3]);
	}
}