// https://www.interviewbit.com/problems/water-flow/

class Point {
    public:
        int x;
        int y;
        Point(int _x, int _y) {
            x = _x;
            y = _y;
        }
};

vector<Point> getNextPoints(Point &p, int n, int m) {
    vector<Point> ret;
    if (p.x + 1 < n) ret.push_back(Point(p.x + 1, p.y));
    if (p.x - 1 >= 0) ret.push_back(Point(p.x - 1, p.y));
    if (p.y + 1 < m) ret.push_back(Point(p.x, p.y + 1));
    if (p.y - 1 >= 0) ret.push_back(Point(p.x, p.y - 1));
    return ret;
}

int Solution::solve(vector<vector<int> > &A) {
    // get n, m
    int n = A.size(), m = A[0].size();
    
    // initialize connectivity to lakes
    vector<vector<bool>> blue(n, vector<bool>(m, false));
    vector<vector<bool>> red(n, vector<bool>(m, false));
    
    // q for bfs
    queue<Point> q;
    
    // on the left edge
    for (int i=0; i<n; i++) {
        blue[i][0] = true;
        q.push(Point(i, 0));
    }
    // on the top edge
    for (int j=1; j<m; j++) {
        blue[0][j] = true;
        q.push(Point(0, j));
    }
    
    while (!q.empty()) {
        Point currPoint = q.front(); q.pop();
        vector<Point> nextPoints = getNextPoints(currPoint, n, m);
        for (auto &nextPoint: nextPoints) {
            if (!blue[nextPoint.x][nextPoint.y] && A[nextPoint.x][nextPoint.y] >= A[currPoint.x][currPoint.y]) {
                blue[nextPoint.x][nextPoint.y] = true;
                q.push(nextPoint);
            }
        }
    }
    
    // q is empty now
    
    // on the right edge
    for (int i=0; i<n; i++) {
        red[i][m-1] = true;
        q.push(Point(i, m-1));
    }
    // on the bottom edge
    for (int j=0; j<m-1; j++) {
        red[n-1][j] = true;
        q.push(Point(n-1, j));
    }
    
    while (!q.empty()) {
        Point currPoint = q.front(); q.pop();
        vector<Point> nextPoints = getNextPoints(currPoint, n, m);
        for (auto &nextPoint: nextPoints) {
            if (!red[nextPoint.x][nextPoint.y] && A[nextPoint.x][nextPoint.y] >= A[currPoint.x][currPoint.y]) {
                red[nextPoint.x][nextPoint.y] = true;
                q.push(nextPoint);
            }
        }
    }
    
    int ret = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (blue[i][j] && red[i][j]) ret++;
        }
    }
    return ret;
}
