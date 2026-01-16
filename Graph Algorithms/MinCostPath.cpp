// https://www.interviewbit.com/problems/min-cost-path/

// This is with Dijkstra, can also do with deque

class Point {
    public:
        int x;
        int y;
        int c;
        Point (int _x, int _y, int _c) {
            x = _x;
            y = _y;
            c = _c;
        }
};

class PointCompare {
    public:
        bool operator()(const Point &p1, const Point &p2) {
            return p1.c >= p2.c;
        }
};

int Solution::solve(int n, int m, vector<string> &C) {
    vector<vector<int>> visited(n, vector<int>(m, 0));
    priority_queue<Point, vector<Point>, PointCompare> pq;
    
    pq.push(Point(0, 0, 0));
    int cost, i, j;
    while (!pq.empty()) {
        Point point = pq.top(); pq.pop();
        i = point.x;
        j = point.y;
        
        if (i == n-1 && j == m-1) return point.c;
        if (visited[i][j] == 1) continue;
        visited[i][j] = 1;
        
        if (i + 1 < n && visited[i+1][j] == 0) {
            cost = point.c + (C[i][j] == 'D' ? 0 : 1);
            pq.push(Point(i+1, j, cost));
        }
        if (i - 1 >= 0 && visited[i-1][j] == 0) {
            cost = point.c + (C[i][j] == 'U' ? 0 : 1);
            pq.push(Point(i-1, j, cost));
        }
        if (j + 1 < m && visited[i][j+1] == 0) {
            cost = point.c + (C[i][j] == 'R' ? 0 : 1);
            pq.push(Point(i, j+1, cost));
        }
        if (j - 1 >= 0 && visited[i][j-1] == 0) {
            cost = point.c + (C[i][j] == 'L' ? 0 : 1);
            pq.push(Point(i, j-1, cost));
        }
    }
    
    return -1;
}
