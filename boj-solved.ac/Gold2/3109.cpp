#include <string>
#include <iostream>
using namespace std;
int R, C;
bool dp[10000][500];
string map[10000];
bool sol(int y, int x)
{
    if (x == C - 1)
        return 1;
    if (dp[y][x])
        return 0;
    dp[y][x] = 1;
    for (int i = -1; i < 2; i++)
    {
        int ny = y + i, nx = x + 1;
        if (ny < 0 || nx < 0 || ny >= R || nx >= C || map[ny][nx] == 'x' || dp[ny][nx])
            continue;
        if (sol(ny, nx))
            return 1;
    }
    return 0;
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> map[i];
    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        if (sol(i, 0))
            ans++;
    }
    printf("%d", ans);
}