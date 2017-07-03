#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const long long inf = 98765432198765;

long long gcd(long long a, long long b) {
	long long div;
	while (a % b) {
		div = a % b;
		a = b;
		b = div;
	}
	return b;
}


int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, minidx, ans = 0,check=0; 
		long long minv = inf, g = 0;
		cin >> N;

		vector<long long> seq(N + 1);
		vector<long long> d(N + 1);
		for (int i = 1; i <= N; i++)
			cin >> seq[i];

		for (int i = 1; i < N; i++) {
			d[i] = seq[i + 1] - seq[i];
			if (minv > d[i]) {
				minv = d[i];
				minidx = i;
			}
			if (d[i] != 0) check == 1;
		}

		if (minv != 0) {
			g = minv;
			for (int i = 1; i < N; i++) 
				g = gcd(d[i], g);

			cout << g << "최대고약수" << endl;
			for (long long i = 1;i <= g/2; i++)
				if (g%i == 0) ans++;
			ans++;
		}
		else {
			if (!check) ans++;
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << ans << endl;
	}
	return 0;
	return 0;
}