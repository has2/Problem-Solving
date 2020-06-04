#include <cstdio>
#include <cmath>
using namespace std;

long long solution(int w, int h) {
	long long answer;

	int arr[2];
	if (w > h) {
		arr[0] = h;
		arr[1] = w;
	}
	else {
		arr[0] = w;
		arr[1] = h;
	}
	int a, b, r;

	a = arr[1];
	b = arr[0];
	
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	arr[0] /= a;
	arr[1] /= a;

	int start, end;
	int cnt = 0;

	for (int i = 1; i <= arr[0]; i++) {
		start = floor((long long)(i - 1) * arr[1] / (double) arr[0]);
		end = ceil((long long)i*arr[1] / (double)arr[0]);
		cnt += end - start;
	}
	answer = (long long) w * h - (long long) cnt * a;
	return answer;
}

int main() {

	int w, h;
	scanf("%d%d", &w, &h);
	printf("%lld", solution(w, h));
}