#include <iostream>
#include <cmath>
using namespace std;

int s[1000001];

int main(void)
{
	int N, B, C,st;
	long long t=0;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> s[i];

	cin >> B >> C;

	for (int i = 1; i <= N; i++) {
		t++;
		st = s[i] - B;
		if (st <= 0)
			continue;

		t += (long long)ceil((double)st / C);
	}
	cout << t;
}

