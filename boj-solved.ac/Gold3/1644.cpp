#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int N;
bool a[4000001];
int main()
{
	scanf("%d", &N);
	vector<int> prime;
	for (int i = 2; i <= N; i++) {
		if (!a[i]) prime.push_back(i);
		for (int j = 2*i; j <= N; j += i) a[j] = 1;
	}
	
	int sum=0,cnt = 0, l = 0;
	for (int i = 0; i < prime.size(); i++) {
		sum += prime[i];
		if (sum == N) cnt++;
		else if (sum > N) {
			while (sum > N) {
				sum -= prime[l++];
			}
			if (sum == N)cnt++;
		}
	}
	printf("%d", cnt);
}