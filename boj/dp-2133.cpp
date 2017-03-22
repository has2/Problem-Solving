//#include <iostream>
//
//using namespace std;
//
//int tile(int n) {
//	if (n % 2 == 1)
//		return 0;
//	else if (n == 0)
//		return 1;
//	else if (n == 2)
//		return 3;
//	else {
//		int result=3*tile(n-2);
//		for (int i = 4; i <= n; i=i+2) {
//			result += 2 * tile(n - i);
//		}
//		return result;
//	}
//}
//
//int main() {
//	int N;
//	cin >> N;
//	cout << tile(N) << endl;
//}
//
