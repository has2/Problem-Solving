#include <iostream>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define INIT 4

using namespace std;
char map[10][10];
int min_cost = 99999999;

int loc[][5] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 },{ 0,0 } };

class Point {
public:
	int x;
	int y;
public:
	Point() {
	}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}


	bool operator ==(const Point &p) const
	{
		return (this->x == p.x&&this->y == p.y);
	}

	void set(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

Point Gp;

char getMap(Point P) {
	return map[P.x][P.y];
}

void search(Point R_p, Point B_p, int cost,int dir) {

	cout << "[R]" << "x : " << R_p.x << "y : "<<R_p.y<<endl;
	cout << "[B]" << "x : " << B_p.x << "y : " << B_p.y << endl;
	cout << "Gp"<< "x : " << Gp.x << "y : " << Gp.y << endl;

	if (cost >= 10 || cost >= min_cost)
		return;

	Point R_left(R_p.x + loc[LEFT][0], R_p.y + loc[LEFT][1]);
	Point R_right(R_p.x + loc[RIGHT][0], R_p.y + loc[RIGHT][1]);
	Point R_up(R_p.x + loc[UP][0], R_p.y + loc[UP][1]);
	Point R_down(R_p.x + loc[DOWN][0], R_p.y + loc[DOWN][1]);
	Point B_left(B_p.x + loc[LEFT][0], B_p.y + loc[LEFT][1]);
	Point B_right(B_p.x + loc[RIGHT][0], B_p.y + loc[RIGHT][1]);
	Point B_up(B_p.x + loc[UP][0], B_p.y + loc[UP][1]);
	Point B_down(B_p.x + loc[DOWN][0], B_p.y + loc[DOWN][1]);

	if ((getMap(R_left) == '.' || getMap(B_left) == '.')
		&& (dir == DOWN || dir == UP || dir == INIT)) {
		int temp_cost = cost + 1;
		int flag1 = 0;
		int flag2 = 0;
		int i = 0;
		Point R_temp = R_p;
		Point B_temp = B_p;


	
		while (getMap(B_temp) == '.') {
			B_temp.x --;
			if (B_temp == Gp) {
				flag1 = 1;
				break;
			}
		}
		B_temp.x++;

		if (flag1 == 0) {
			while (getMap(R_temp) == '.') {
				R_temp.x--;
				if (R_temp == Gp) {
					if (temp_cost < min_cost) {
						flag2 = 1;
						min_cost = temp_cost;
						cout << "min_cost" << min_cost << endl;
					}
					break;
				}
			}
			R_temp.x++;
			if (flag2 == 0) {
				if (B_temp == R_temp) {
					if (R_p.x > B_p.x)
						R_temp.x++;
					else
						B_temp.x++;
				}
				search(R_temp, B_temp, temp_cost, LEFT);
			}
		}
	}

	if ((getMap(R_right) == '.' || getMap(B_right) == '.') 
		&& (dir==UP || dir==DOWN|| dir == INIT)) {
		cout << "여기는" << endl;
		int temp_cost = cost + 1;
		int flag1 = 0;
		int flag2 = 0;
		Point R_temp = R_p;
		Point B_temp = B_p;

		while (getMap(B_temp) == '.') {
			B_temp.x++;
			if (B_temp == Gp) {
				flag1 = 1;
				break;
			}
		}
		B_temp.x--;

		if (flag1 == 0) {
			while (getMap(R_temp) == '.') {
				R_temp.x++;
				if (R_temp == Gp) {
					if (temp_cost < min_cost) {
						flag2 = 1;
						min_cost = temp_cost;
						cout << "코스트" << min_cost << endl;
						break;
					}
				}
			}
			R_temp.x--;
			if (flag2 == 0) {
				if (B_temp == R_temp) {
					if (R_p.x > B_p.x)
						B_temp.x--;
					else
						R_temp.x--;
				}
				search(R_temp, B_temp, temp_cost, RIGHT);
			}
		}
		
	}

	if ((getMap(R_up) == '.' || getMap(B_up) == '.') 
		&& (dir ==LEFT || dir==RIGHT || dir == INIT)) {
		int temp_cost = cost + 1;
		int flag1 = 0;
		int flag2 = 0;
		Point R_temp = R_p;
		Point B_temp = B_p;

		cout << "asdfasdf1";

		while (getMap(B_temp) == '.') {
			cout << "asdfasdf2";
			B_temp.y--;
			if (B_temp == Gp) {
				cout << "asdfasdf3";
				flag1 = 1;
				break;
			}
		}
		B_temp.y++;
		if (flag1 == 0) {
			while (getMap(R_temp) == '.') {
				R_temp.y--;
				if (R_temp == Gp) {
					if (temp_cost < min_cost) {
						min_cost = temp_cost;
						flag2 = 1;
						break;
					}
				}
			}
			R_temp.y++;
			if (flag2 == 0) {
				if (B_temp == R_temp) {
					if (R_p.y > B_p.y)
						R_temp.y++;
					else
						B_temp.y++;
				}
				search(R_temp, B_temp, temp_cost, UP);
			}
		}
	}

	if ((getMap(R_down) == '.' || getMap(B_down) == '.') 
		&& (dir==LEFT || dir==RIGHT || dir == INIT)) {
		cout << "여기 들어와?" << endl;
		int temp_cost = cost + 1;
		int flag1 = 0;
		int flag2 = 0;
		Point R_temp = R_p;
		Point B_temp = B_p;

		while (getMap(B_temp) == '.') {
			if (B_temp == Gp) {
				flag1 = 1;
				break;
			}
			B_temp.y++;
		}
		B_temp.y--;
		if (flag1 == 0) {
			while (getMap(R_temp) == '.') {
				R_temp.y++;
				if (R_temp == Gp) {
					if (temp_cost < min_cost) {
						min_cost = temp_cost;
						flag2 = 1;
						break;
					}
				}
			}
			R_temp.y--;
			if (flag2 == 0) {
				if (B_temp == R_temp) {
					if (R_p.y > B_p.y)
						B_temp.y--;
					else
						R_temp.y--;
				}
				search(R_temp, B_temp, temp_cost, DOWN);
			}
		}
	}



}

int main(void) {

	int N, M;
	Point Rp, Bp;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[j][i];
			if (map[j][i] == 'R') {
				Rp.set(j, i);
				map[j][i] = '.';
			}
			if (map[j][i] == 'B') {
				Bp.set(j, i);
				map[j][i] = '.';
			}
			if (map[j][i] == 'O') {
				Gp.set(j, i);
				map[j][i] = '.';
			}
		}

	search(Rp, Bp, 0,INIT);

	if (min_cost == 99999999) {
		cout << -1;
		return 0;
	}
	cout << min_cost;

}
