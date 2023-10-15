#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell {
    int x, y;
};

bool isSafe(int x, int y, int n) {
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

bool isCheck(int ax, int ay, int bx, int by) {
    return (ax == bx || ay == by || abs(ax - bx) == abs(ay - by));
}

bool canBobWinBFS(int n, int ax, int ay, int bx, int by, int cx, int cy) {
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    queue<Cell> q;

    q.push({bx, by});
    visited[bx][by] = true;

    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();

        int currX = curr.x;
        int currY = curr.y;

        if (currX == cx && currY == cy)
            return true;

        // Check all 8 possible moves of the king
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < 8; i++) {
            int newX = currX + dx[i];
            int newY = currY + dy[i];

            if (isSafe(newX, newY, n) && !visited[newX][newY] && !isCheck(ax, ay, newX, newY)) {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }

    return false;
}

int main() {
    int n, ax, ay, bx, by, cx, cy;
    cout << "Enter the dimensions of the chessboard (n x n): ";
    cin >> n;
    cout << "Enter the position of Alice's queen (ax, ay): ";
    cin >> ax >> ay;
    cout << "Enter the position of Bob's king (bx, by): ";
    cin >> bx >> by;
    cout << "Enter the destination position (cx, cy): ";
    cin >> cx >> cy;

    bool bfsResult = canBobWinBFS(n, ax, ay, bx, by, cx, cy);

    if (bfsResult)
        cout << "Bob can win!" << endl;
    else
        cout << "Bob cannot win!" << endl;

    return 0;
}
