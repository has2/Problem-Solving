#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstdio>

#define MAX_endTime 9876543212345
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

using namespace std;

typedef tuple<long long, long long, long long> tp;

long long cur_x, cur_y;
int dir;
long long t[1001];
long long endTime;
char d[1001];

long long find(vector<tp> ver, vector<tp> hor, int L, int N) {

	long long temp_x, temp_y1, temp_y2;
	long long temp_y, temp_x1, temp_x2;
	
	vector<tp>::iterator iter;
	dir = UP;
	for (int i = 0; i <= N; i++) {
		    long long endTime_tp = MAX_endTime;

			if (dir == RIGHT) {
				if (d[i] == 'R') {
					dir = DOWN;
				}
				else
					dir = UP;
			}
			else if (dir == LEFT) {
				if (d[i] == 'R') {
					dir = UP;
				}
				else
					dir = DOWN;
			}
			else if (dir == UP) {
				if (d[i] == 'R')
					dir = RIGHT;
				else
					dir = LEFT;
			}
			else {
				if (d[i] == 'R')
					dir = LEFT;
				else
					dir = RIGHT;
			}
		

		switch (dir) 
		{
		case RIGHT:
			temp_y = cur_y;
			temp_x1 = cur_x;
			temp_x2 = cur_x + t[i];

			for (iter = ver.begin(); iter != ver.end(); iter++) {
				temp_x = get<0>(*iter);
				temp_y1 = get<1>(*iter);
				temp_y2 = get<2>(*iter);
				if (temp_x1 != temp_x && temp_x1 <= temp_x && temp_x <= temp_x2 && temp_y1 <= temp_y && temp_y <= temp_y2) {
					endTime_tp = min(endTime_tp, temp_x - temp_x1);
				}
			}

			for (iter = hor.begin(); iter != hor.end(); iter++) {
				if (temp_x1 <= get<1>(*iter) &&get<1>(*iter) <= temp_x2 && temp_y == get<0>(*iter)) {
					endTime_tp = min(endTime_tp, get<1>(*iter) - temp_x1);
				}
			}

			if (endTime_tp != MAX_endTime) {
				endTime += endTime_tp;
				return endTime;
			}

			if (temp_x2 > L) {
				endTime += (L + 1 - temp_x1);
				return endTime;
			}

			hor.push_back(make_tuple(temp_y, temp_x1, temp_x2));

			endTime += t[i];
			cur_x = temp_x2;
			break;

		case LEFT:

			temp_y = cur_y;
			temp_x1 = cur_x - t[i];
			temp_x2 = cur_x;

			for (iter = ver.begin(); iter != ver.end(); iter++) {
				temp_x = get<0>(*iter);
				temp_y1 = get<1>(*iter);
				temp_y2 = get<2>(*iter);
				if ( temp_x2 != temp_x && temp_x1 <= temp_x && temp_x <= temp_x2 && temp_y1 <= temp_y && temp_y <= temp_y2) {
					endTime_tp = min(endTime_tp, temp_x2 - temp_x);			
				}	
			}

			for (iter = hor.begin(); iter != hor.end(); iter++) {
				if (temp_x2 >= get<2>(*iter)&&get<2>(*iter) >= temp_x1 && temp_y == get<0>(*iter)) {
					endTime_tp = min(endTime_tp, temp_x2 - get<2>(*iter));
				}
			}

			if (endTime_tp != MAX_endTime) {
				endTime += endTime_tp;
				return endTime;
			}

			if (temp_x1 < -L) {
				endTime += (temp_x2-(-L)+1);
				return endTime;
			}

			hor.push_back(make_tuple(temp_y, temp_x1, temp_x2));

			endTime += t[i];
			cur_x = temp_x1;
		
			break;		

		case UP:
			temp_x = cur_x;
			temp_y1 = cur_y;
			temp_y2 = cur_y + t[i];

			for (iter = hor.begin(); iter != hor.end(); iter++) {
			
				temp_y = get<0>(*iter);
				temp_x1 = get<1>(*iter);
				temp_x2 = get<2>(*iter);
				
				if (temp_y!=temp_y1 && temp_y1 <= temp_y && temp_y <= temp_y2 && temp_x1 <= temp_x && temp_x <= temp_x2) {
					endTime_tp = min(endTime_tp, temp_y - temp_y1);
	
				}
			}

			for (iter = ver.begin(); iter != ver.end(); iter++) {
				if ( temp_y1 <= get<1>(*iter) && get<1>(*iter) <= temp_y2 && temp_x == get<0>(*iter)) {
					endTime_tp = min(endTime_tp, get<1>(*iter) - temp_y1);
				}
			}

			if (endTime_tp != MAX_endTime) {
				endTime += endTime_tp;
				return endTime;
			}

			if (temp_y2 > L) {
				endTime += (L-temp_y1 + 1);
				return endTime;
			}

			ver.push_back(make_tuple(temp_x, temp_y1, temp_y2));
			endTime += t[i];
			cur_y = temp_y2;
	
			break;

		case DOWN:
			temp_x = cur_x;
			temp_y1 = cur_y - t[i];
			temp_y2 = cur_y;

			for (iter = hor.begin(); iter != hor.end(); iter++) {
				temp_y = get<0>(*iter);
				temp_x1 = get<1>(*iter);
				temp_x2 = get<2>(*iter);
			
		
				if (temp_y2 != temp_y && temp_y1 <= temp_y && temp_y <= temp_y2 && temp_x1 <= temp_x && temp_x <= temp_x2) {
					
					endTime_tp = min(endTime_tp, temp_y2 - temp_y);
				}
			}

			for (iter = ver.begin(); iter != ver.end(); iter++) {
				if ( temp_y2 >= get<2>(*iter) && get<2>(*iter) >= temp_y1 && temp_x == get<0>(*iter)) {
					endTime_tp = min(endTime_tp, temp_y2 - get<2>(*iter));
				}
			}

			if (endTime_tp != MAX_endTime) {
				
				endTime += endTime_tp;
				return endTime;
			}

			if (temp_y1 < -L) {
				endTime += (temp_y2 - (-L) + 1);
				return endTime;
			}

			ver.push_back(make_tuple(temp_x, temp_y1, temp_y2));
			endTime += t[i];
			cur_y = temp_y1;
		
			break;
		}
	}
	

}


int main(void) {
	int l, n;
	long long res;
	cin >> l >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> d[i + 1];
	}
	d[0] = 'R'; t[n] = 3 * l;

	vector<tp> ver;
	vector<tp> hor;
	res = find(ver, hor, l, n);
	printf("%lld", res);

}