#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int final_max;

void copy(int src[20][20], int dest[20][20]) {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			dest[i][j] = src[i][j];
}
void re_left(int bd[20][20],int N,int count);
void re_right(int bd[20][20], int N, int count);
void re_up(int bd[20][20],int N, int count);
void re_down(int bd[20][20], int N, int count);


void re_left(int bd[20][20],int N, int count) {
	int prev[20][20];
	int check[20][20] = { 0, };
	copy(bd, prev);

	queue<int> Q1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (prev[i][j] != 0) {
				Q1.push(prev[i][j]);
			}
		}

		if (Q1.empty())
			continue;

		int k = 0;
		int val;
		int ck;

	    prev[i][k] = Q1.front();	
		Q1.pop();
	
		while (!Q1.empty()) {
			val = Q1.front();

			if (val == prev[i][k] && check[i][k] == 0) {
				prev[i][k] *= 2; check[i][k] = 1;
			}
			else {
				prev[i][++k] = val;
			}
			Q1.pop();
		}

		for (int m = k + 1; m < N; m++) {
			prev[i][m] = 0;
		}
	}

	count++;
	if (count == 5) {
		int m=0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				m = max(m, prev[i][j]);
		}
		if (m > final_max)
			final_max = m;

		return;
	}

	re_left(prev, N, count);
	re_right(prev, N, count);
	re_up(prev, N, count);
	re_down(prev, N, count);
}

void re_right(int bd[20][20], int N, int count) {
	int prev[20][20];
	int check[20][20] = { 0, };
	copy(bd, prev);
	
	queue<int> Q1;

	for (int i = 0; i < N; i++) {
		for (int j = N-1; j >= 0 ; j--) {
			if (prev[i][j] != 0) {
				Q1.push(prev[i][j]);

			}
		}

		if (Q1.empty())
			continue;

		int k = N-1;
		int val;


		prev[i][k] = Q1.front();
		Q1.pop();


		while (!Q1.empty()) {
			val = Q1.front();

			if (val == prev[i][k] && check[i][k] == 0) {
				prev[i][k] *= 2; check[i][k] = 1;
			}
			else {
				prev[i][--k] = val;
			}
			Q1.pop();
		}

		for (int m = k - 1; m >= 0; m--) {
			prev[i][m] = 0;
		}
	}

	count++;
	if (count == 5) {
		int m = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				m = max(m, prev[i][j]);
		}
		if (m > final_max)
			final_max = m;

		return;
	}

	re_left(prev, N, count);
	re_right(prev, N, count);
	re_up(prev, N, count);
	re_down(prev, N, count);
}

void re_up(int bd[20][20], int N, int count) {
	int prev[20][20];
	int check[20][20] = { 0, };
	copy(bd, prev);
	
	queue<int> Q1;

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (prev[i][j] != 0) {
				Q1.push(prev[i][j]);
			}
		}

		if (Q1.empty())
			continue;

		int k = 0;
		int val;

		prev[k][j] = Q1.front();
		Q1.pop();

		while (!Q1.empty()) {
			val = Q1.front();
			if (val == prev[k][j] && check[k][j] == 0) {
				prev[k][j] *= 2; check[k][j] = 1;
			}
			else {
				prev[++k][j] = val;
			}
			Q1.pop();
		}

		for (int m = k + 1; m < N; m++) {
			prev[m][j] = 0;
		}
	}

	count++;
	if (count == 5) {
		int m = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				m = max(m, prev[i][j]);
		}
		if (m > final_max)
			final_max = m;

		return;
	}

	re_left(prev, N, count);
	re_right(prev, N, count);
	re_up(prev, N, count);
	re_down(prev, N, count);
}

void re_down(int bd[20][20], int N, int count) {
	int prev[20][20];
	int check[20][20] = { 0, };
	copy(bd, prev);
	
	queue<int> Q1;
	
	for (int j = 0; j < N; j++) {
		for (int i = N-1; i >= 0; i--) {
			if (prev[i][j] != 0) {
				Q1.push(prev[i][j]);
			}
		}

		if (Q1.empty())
			continue;

		int k = N-1;
		int val;


		prev[k][j] = Q1.front();
		Q1.pop();

		while (!Q1.empty()) {
			val = Q1.front();
			if (val == prev[k][j] && check[k][j] == 0) {
				prev[k][j] *= 2; check[k][j] = 1;
			}
			else {
				prev[--k][j] = val;
			}
			Q1.pop();
		}

		for (int m = k - 1; m >= 0; m--) {
			prev[m][j] = 0;
		}
	}

	count++;
	if (count == 5) {
		int m = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				m = max(m, prev[i][j]);
		}
		if (m > final_max)
			final_max = m;

		return;
	}

	re_left(prev, N, count);
	re_right(prev, N, count);
	re_up(prev, N, count);
	re_down(prev, N, count);
}


int main(void)
{

	int board[20][20] = { 0,};
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	
	re_left(board,N,0);
	re_right(board,N,0);
	re_up(board,N,0);
	re_down(board,N,0);

	cout << final_max;
	
}