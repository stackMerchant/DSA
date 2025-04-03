// https://www.interviewbit.com/problems/knight-on-chess-board/

class Point {
    public:
        int x;
        int y;
        int steps;
        Point (int _x, int _y, int _steps) {
            x = _x;
            y = _y;
            steps = _steps;
        }
};

bool isInside(int &A, int &B, int &x, int &y) {
    return !(x<0 || x>=A || y<0 || y>=B);
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    // Rename variables
    int srcX = C-1, srcY = D-1, destX = E-1, destY = F-1;
    
    // Initialize board with all unvisitd
    vector<vector<int>> board(A, vector<int>(B, 0));
    
    // Queue for BFS, and insert starting point and mark it visited
    queue<Point> q;
    if (isInside(A, B, srcX, srcY)) {
        q.push(Point(srcX, srcY, 0));
        board[srcX][srcY] = 1;
    }
    
    vector<int> dx = {-2, -1, 1, 2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    
    Point front(0, 0, 0);
    int nextX, nextY;
    while (!q.empty()) {
        front = q.front(); q.pop();
        // If reached return steps
        if (front.x == destX && front.y == destY) return front.steps;
        
        // Traverse next 8 points
        for (int h=0; h<8; h++) {
            // Get next point
            nextX = front.x + dx[h];
            nextY = front.y + dy[h];
            
            // If inside and unvisited, mark it visited and push to queue
            if (isInside(A, B, nextX, nextY) && board[nextX][nextY] == 0) {
                q.push(Point(nextX, nextY, front.steps + 1));
                board[nextX][nextY] = 1;
            }
        }
    }
    return -1;
}

// Notes:
// Instead of saving steps, we can also put 2 nested while loops
// Inside loop will go till queue's size reduces to zero
