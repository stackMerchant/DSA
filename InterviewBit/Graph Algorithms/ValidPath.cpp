// https://www.interviewbit.com/problems/valid-path/

class Point {
    public:
        int x;
        int y;
        Point (int _x, int _y) {
            x = _x;
            y = _y;
        }
};

bool isPointInside(Point center, Point currPoint, double radius) {
    double distance = pow(currPoint.x - center.x, 2) + pow(currPoint.y - center.y, 2);
    distance = sqrt(distance);
    return distance <= radius;
}

bool isPointInBounds(Point p, int rows, int cols) {
    return !(p.x < 0 || p.x >= rows || p.y < 0 || p.y >= cols);
}

vector<Point> getAdjacentPoints(Point p, int rows, int cols) {
    vector<int> dx = {1, 1, 1, -1, -1, -1, 0, 0};
    vector<int> dy = {0, 1, -1, 0, 1, -1, 1, -1};
    
    vector<Point> adjPoints;
    for (int h=0; h<8; h++) {
        Point adjPoint = Point(p.x + dx[h], p.y + dy[h]);
        if (isPointInBounds(adjPoint, rows, cols))
            adjPoints.push_back(adjPoint);
    }
    return adjPoints;
}

string bfs(vector<vector<int>> &board, int rows, int cols) {
    // Hold visited points
    queue<Point> q;
    
    // Push the starting point in queue, only if it is vali
    if (board[0][0] == 0) {
        q.push(Point(0, 0));
        board[0][0] = 1;
    }

    // BFS
    while (!q.empty()) {
        // Get front point
        Point front = q.front(); q.pop();
        // Get adjacent points
        vector<Point> adjacentPoints = getAdjacentPoints(front, rows, cols);
        // Push unvisited and visitable points to queue; visitable => in-bounds and not inside circle
        for (auto p: adjacentPoints) {
            if (board[p.x][p.y] == 0) {
                q.push(p);
                board[p.x][p.y] = 1; // Mark visited
            }
        }
    }

    return board[rows -1][cols - 1] == 1 ? "YES" : "NO";
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    // Rename variables
    int rows = A+1, cols = B+1;
    int circleCount = C;
    double radius = D;
    
    // Initialize board and mark points invalid if inside any circle
    vector<vector<int>> board(rows, vector<int>(cols, 0));
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            for (int c=0; c<circleCount; c++) {
                Point circleCenter = Point(E[c], F[c]);
                Point currPoint = Point(i, j);
                if (isPointInside(circleCenter, currPoint, radius)) board[i][j] = -1;
            }
        }
    }
    
    return bfs(board, rows, cols);
}

