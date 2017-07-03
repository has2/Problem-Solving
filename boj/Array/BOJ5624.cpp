#include <iostream>

using namespace std;
const int base = 200000;
int arr[5000];
bool ab[400001];

int main(int argc, char** argv)
{
	int N,ans=0;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < i; j++) {
			if (ab[arr[i] - arr[j] + base]) {
				ans++; break;
			}
		}

		for (int j = 0; j <= i; j++) 
			ab[arr[j] + arr[i] + base] = true;
	}
	cout << ans << endl;
	
	return 0;
}