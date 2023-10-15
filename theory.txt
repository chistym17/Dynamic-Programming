#include<bits/stdc++.h>
using namespace std;

bool is_Safe(int x, int y, int n) {
    if (x >= 1 && x <= n && y >= 1 && y <= n)
        return true;

return false;

}

bool is_Check(int ax, int ay, int bx, int by) {
    if(ax == bx || ay == by || abs(ax - bx) == abs(ay - by))
     return true;

return false;
}

bool can_win(int n, int ax, int ay, int bx, int by, int cx, int cy, vector<vector<bool>>& visited) {
    if (bx == cx && by == cy)
        return true;

    visited[bx][by] = true;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        int newX = bx + dx[i];
        int newY = by + dy[i];

        if (is_Safe(newX, newY, n) && !visited[newX][newY] && !is_Check(ax, ay, newX, newY)) {
            if (can_win(n, ax, ay, newX, newY, cx, cy, visited))
                return true;
        }
    }

    return false;
}

int main() {
    int n, ax, ay, bx, by, cx, cy;
    cin >> n;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;

    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

    bool dfsResult = can_win(n, ax, ay, bx, by, cx, cy, visited);

    if (dfsResult)
        cout << "Yes";
    else
        cout << "No" ;

    return 0;
}
