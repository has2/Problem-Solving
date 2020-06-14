
#include <vector>
using namespace std;
class CustomFunction {
  public:
      // Returns f(x, y) for any given positive integers x and y.
      // Note that f(x, y) is increasing with respect to both x and y.
      // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
      int f(int x, int y);
};
 

class Solution {
public:
	vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
		vector<vector<int>> ans;
		
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				if (customfunction.f(i, j) == z) {
					vector<int> a(2);
					a[0] = i;
					a[1] = j;
					ans.push_back(a);
					break;
				}
			}
		}
		return ans;
	}
};