
#include <vector>
#include <algorithm>
using namespace std;
class SubrectangleQueries {
public:
	vector<vector<int>> rec;
	SubrectangleQueries(vector<vector<int>>& rectangle) {
		rec = rectangle;
	}

	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
		for (int i = row1; i <= row2; i++) {
			fill(rec[i].begin()+col1, rec[i].begin()+col2+1, newValue);
		}
	}

	int getValue(int row, int col) {
		return rec[row][col];
	}
};