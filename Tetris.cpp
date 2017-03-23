#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define ESC 27
#define BX 5
#define BY 1
#define BW 12
#define BH 20

typedef struct _Point {
	int x, y;
}Point;
Point Shape[][4][4] = {
	{ { 0,0,1,0,2,0,-1,0 },{ 0,0,0,1,0,-1,0,-2 },{ 0,0,1,0,2,0,-1,0 },{ 0,0,0,1,0,-1,0,-2 } },
	{ { 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 } },
	{ { 0,0,-1,0,0,-1,1,-1 },{ 0,0,0,1,-1,0,-1,-1 },{ 0,0,-1,0,0,-1,1,-1 },{ 0,0,0,1,-1,0,-1,-1 } },
	{ { 0,0,-1,-1,0,-1,1,0 },{ 0,0,-1,0,-1,1,0,-1 },{ 0,0,-1,-1,0,-1,1,0 },{ 0,0,-1,0,-1,1,0,-1 } },
	{ { 0,0,-1,0,1,0,-1,-1 },{ 0,0,0,-1,0,1,-1,1 },{ 0,0,-1,0,1,0,1,1 },{ 0,0,0,-1,0,1,1,-1 } },
	{ { 0,0,1,0,-1,0,1,-1 },{ 0,0,0,1,0,-1,-1,-1 },{ 0,0,1,0,-1,0,-1,1 },{ 0,0,0,-1,0,1,1,1 } },
//	{ { 0,0,-1,0,1,0,0,1 },{ 0,0,0,-1,0,1,1,0 },{ 0,0,-1,0,1,0,0,-1 },{ 0,0,-1,0,0,-1,0,1 } },
	{ { 0,0,-1,0,1,0,0,-1 },{ 0,0,-1,0,0,-1,0,1 },{ 0,0,-1,0,1,0,0,1 },{ 0,0,0,-1,0,1,1,0 } },
};
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;    //커서 없애기 
enum{START,RUNNING,DEAD};
enum { EMPTY, BRICK, WALL };

char *arTile[] = { ". ","■","□" };
int board[BW + 2][BH + 2];
int nx, ny;
int brick, rot,lv=1,pt,flag,next_brick;
int game_state = RUNNING;
clock_t delay;
clock_t t_old, t_cur;
clock_t delay_old, delay_cur, time_cur, time_old;

void gotoxy(int x, int y);
void DrawScreen();
void DrawBoard();
void PrintBrick(int draw);
void setcursortype(CURSOR_TYPE c);
void createNewBrick();
void init();
bool check_side_coll(int R_L);
bool check_down_coll();
bool check_rot_coll();
void line_coll();
void spaceinput();
void DEAD_STATE();
void PrintNextBrick();

int main(void)
{
	srand(time(NULL));
	init();
	while (1) {
		PrintNextBrick();
		flag = 0;
		if (!check_down_coll())
			DEAD_STATE();

		DrawBoard();
		PrintBrick(BRICK);

		while (game_state == RUNNING) {
					time_cur = clock();
					gotoxy(BX + BW * 2 + 10, BY + 4); printf(" %d", (time_cur - time_old) / 1000);

					delay_cur = clock();
					if ((delay_cur - delay_old > 20000) && delay > 200) {
						delay -= 50;
						delay_old = clock();
						gotoxy(BX + BW * 2 + 10, BY + 5); printf(" %d", ++lv);
					}

					t_cur = clock();
					if (kbhit()) {
						int	ch = getch();
						switch (ch) {
						case SPACE:
							spaceinput();
							createNewBrick();
							flag = 1;
							break;
						case LEFT:
							if (check_side_coll(LEFT)) {
								PrintBrick(EMPTY);
								nx = nx - 1;
								PrintBrick(BRICK);
							}
							break;
						case RIGHT:
							if (check_side_coll(RIGHT)) {
								PrintBrick(EMPTY);
								nx = nx + 1;
								PrintBrick(BRICK);
							}
							break;
						case UP:
							if (check_rot_coll()) {
								PrintBrick(EMPTY);
								rot = (rot + 1) % 4;
								PrintBrick(BRICK);
							}
							break;
						case DOWN:
							if (check_down_coll()) {
								PrintBrick(EMPTY);
								ny = ny + 1;
								PrintBrick(BRICK);
							}
							else {
								createNewBrick();
								flag = 1;
							}
							break;
						}
					}

					if (flag == 1)
						break;
					if (t_cur - t_old > delay) {
						PrintBrick(EMPTY);
						if (check_down_coll()) {
							ny++;
						}
						else {
							createNewBrick();
							break;
						}
						t_old = clock();
						PrintBrick(BRICK);
					}
				}
		}
	}

		
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcursortype(CURSOR_TYPE c) {                                    //커서 없애기 
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}


void DrawScreen()
{
	int x, y;
	setcursortype(NOCURSOR);
	for (x = 0; x<BW + 2; x++) {
		for (y = 0; y<BH + 2; y++) {
			gotoxy(BX + x * 2, BY + y);
			puts(arTile[board[x][y]]);
		}
	}
	gotoxy(BX + BW*2 + 4, BY + 4); puts(" Time  ");
	gotoxy(BX + BW*2 + 4, BY + 5); puts(" Level ");
	gotoxy(BX + BW*2 + 4, BY + 6); puts(" Point ");
	gotoxy(50, 3); puts("Tetris Ver 1.0");
	gotoxy(50, 5); puts("좌우:이동, 위:회전, 아래:내림");
	gotoxy(50, 6); puts("SPACE:전부 내림");
	gotoxy(BX + BW*2 + 10, BY + 5); printf(" %d", lv);
	gotoxy(BX + BW*2 + 10, BY + 6); printf(" %d", pt);
	gotoxy(BX + BW * 2 + 4, BY + 15); puts("     NEXT      ");
	gotoxy(BX + BW * 2 + 4, BY + 16); puts("□□□□□□□");
	gotoxy(BX + BW * 2 + 4, BY + 17); puts("□          □");
	gotoxy(BX + BW * 2 + 4, BY + 18); puts("□          □");
	gotoxy(BX + BW * 2 + 4, BY + 19); puts("□          □");
	gotoxy(BX + BW * 2 + 4, BY + 20); puts("□          □");
	gotoxy(BX + BW * 2 + 4, BY + 21); puts("□□□□□□□");

}

void DrawBoard()
{
	for(int x=1;x<BW+1;x++){
		for (int y = 1; y < BH + 1; y++) {
			gotoxy(BX + x * 2, BY + y);
			puts(arTile[board[x][y]]);
		}
	}

}

void PrintBrick(int draw)
{
	for (int i = 0; i < 4; i++)
	{
		gotoxy(BX + (nx + Shape[brick][rot][i].x) * 2, BY + ny + Shape[brick][rot][i].y);
		puts(arTile[draw]);
	}
}

void createNewBrick()
{

	brick = next_brick;
	next_brick = rand() % 7;

	rot = 0;
	nx = 5;
	ny = 2;
	if (brick == 0)
		ny = 1;
	DrawBoard();
	PrintBrick(BRICK);
}

void init()
{
	int x, y;
	delay_old = clock(); time_old = clock();
	delay = 500; pt = 0;
	lv = 1;
	for (x = 0; x<BW + 2; x++) {
		for (y = 0; y<BH + 2; y++) {
			board[x][y] = (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) ? WALL : EMPTY;
		}
	}
	DrawScreen();
	createNewBrick();
	t_old = clock();
}


bool check_side_coll(int R_L)
{
	int tempx;
	if (R_L == LEFT)
	{
		tempx = nx - 1;
		for (int i = 0; i < 4; i++) {
			if (board[tempx + Shape[brick][rot][i].x][ny + Shape[brick][rot][i].y] != EMPTY)
				return false;
		}
	}
	if (R_L == RIGHT)
	{
		tempx = nx + 1;
		for (int i = 0; i < 4; i++) {
			if (board[tempx + Shape[brick][rot][i].x][ny + Shape[brick][rot][i].y] != EMPTY)
				return false;
		}
	}
	return true;
}

bool check_down_coll()
{
	int tempy = ny + 1;
	for (int i = 0; i < 4; i++) {
		if (board[nx + Shape[brick][rot][i].x][tempy + Shape[brick][rot][i].y] != EMPTY) {
			for (int j = 0; j<4; j++)
				board[nx + Shape[brick][rot][j].x][ny + Shape[brick][rot][j].y] = BRICK;
			line_coll();
			return false;
		}
	}
	return true;
}

void line_coll()
{
	for (int y = -2; y < 2; y++)
	{
		if (ny + y > BH)
			break;

		for (int x = 1; x < BW + 1; x++) {
			if (board[x][ny + y] != BRICK)
				break;
			if (x == BW) {
				for (int ty = ny + y; ty > 1; ty--)
					for (int tx = 1; tx < BW; tx++)
						board[tx][ty] = board[tx][ty - 1];
				pt=pt+100;
			}
		}
	}
	gotoxy(BX + BW * 2 + 10, BY + 6); printf(" %d", pt);
}

bool check_rot_coll()
{
	int temprot = (rot+1) % 4 ;
	for (int i = 0; i < 4; i++) {
		if (board[nx + Shape[brick][temprot][i].x][ny + Shape[brick][temprot][i].y] != EMPTY) {
			return false;
		}
	}
	return true;
}

void spaceinput()
{
	for (int tempy = ny; tempy <BH+1; tempy++) {
		for (int i = 0; i < 4; i++) {
			if (board[nx + Shape[brick][rot][i].x][tempy+1 + Shape[brick][rot][i].y] != EMPTY) {
					for (int j = 0; j < 4; j++) 
						board[nx + Shape[brick][rot][j].x][tempy + Shape[brick][rot][j].y] = BRICK;
					
					ny = tempy;
					line_coll();
					return ;				
			}
		}
	}
}

void DEAD_STATE()
{

			game_state = DEAD;
			for (int x = 0; x < BW + 2; x++) {
				for (int y = 0; y < BH + 2; y++) {
					board[x][y] = (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) ? WALL : EMPTY;
				}
			}
			gotoxy(BX + 1, BY + 8); puts("다시 하시겠습니까?(Y/N)");
			int ch;
			while (1) {
				ch = getch();
				if (ch == 'Y' || ch == 'y') {
					game_state = RUNNING;
					init();
					break;
				}
				else if (ch == 'N' || ch == 'n')
					exit(1);
			}
		
}

void PrintNextBrick()
{
	int tx = BX + BW * 2 + 10;
	int ty = BY + 19;
	if (brick == 1) { ty--; tx--; }
	if (brick == 0) tx--;
	
	for (int i = 0; i < 4; i++)
	{
		gotoxy(tx + Shape[brick][0][i].x*2, ty + Shape[brick][0][i].y);
		puts("  ");
	}

	tx = BX + BW * 2 + 10;
	ty = BY + 19;

	if (next_brick == 1) { ty--; tx--; }
	if (next_brick == 0) tx--;

	for (int i = 0; i < 4; i++)
	{
		gotoxy(tx + Shape[next_brick][0][i].x * 2, ty + Shape[next_brick][0][i].y);
		puts(arTile[BRICK]);
	}
}



