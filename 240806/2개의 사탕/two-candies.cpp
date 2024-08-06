#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 11
using namespace std;

struct p {
    int rx, ry, bx, by, cnt = 0;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, min1 = INT_MAX;
int visited[MAXN][MAXN][MAXN][MAXN];
char arr[MAXN][MAXN];
p ball;

int isRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int bfs(int rx, int ry, int bx, int by) {
    queue<p> q;
    q.push({rx, ry, bx, by});
    visited[rx][ry][bx][by] = 1;

    while (!q.empty()) {
        p t = q.front();
        q.pop();

        if (t.cnt > 10) continue;
        if (arr[t.rx][t.ry] == 'O' && arr[t.bx][t.by] != 'O') {
            min1 = min(min1, t.cnt);
            break;
        }

        loop(i, 0, 3) {
            int nrx = t.rx, nry = t.ry, rcnt = 0;
            int nbx = t.bx, nby = t.by, bcnt = 0;

            while (isRange(nrx + dx[i], nry + dy[i]) && arr[nrx + dx[i]][nry + dy[i]] != '#' && arr[nrx][nry] != 'O') {
                nrx += dx[i];
                nry += dy[i];
                rcnt++;
            }

            while (isRange(nbx + dx[i], nby + dy[i]) && arr[nbx + dx[i]][nby + dy[i]] != '#' && arr[nbx][nby] != 'O') {
                nbx += dx[i];
                nby += dy[i];
                bcnt++;
            }

            if (arr[nbx][nby] == 'O') continue;

            if (nrx == nbx && nry == nby) {
                if (arr[nrx][nry] != 'O') {
                    if (rcnt > bcnt) {
                        nrx -= dx[i];
                        nry -= dy[i];
                    } else {
                        nbx -= dx[i];
                        nby -= dy[i];
                    }
                }
            }

            if (!visited[nrx][nry][nbx][nby]) {
                q.push({nrx, nry, nbx, nby, t.cnt + 1});
                visited[nrx][nry][nbx][nby] = 1;
            }
        }
    }

    if (min1 == INT_MAX) return -1;
    else return min1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    loop(i, 1, n) {
        loop(j, 1, m) {
            cin >> arr[i][j];
            if (arr[i][j] == 'B') {
                ball.bx = i;
                ball.by = j;
            } else if (arr[i][j] == 'R') {
                ball.rx = i;
                ball.ry = j;
            }
        }
    }

    cout << bfs(ball.rx, ball.ry, ball.bx, ball.by) << endl;
    return 0;
}