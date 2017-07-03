#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000001];


int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	
	vector<int> temp(1, arr[0]);
	for (int i = 1; i < N; i++) {
		if (temp.back() < arr[i]) {
			temp.push_back(arr[i]);
		}
		else {
			auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
			*it = arr[i];
		}
	}
	printf("%d\n", temp.size());

}