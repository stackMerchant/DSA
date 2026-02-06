// https://www.interviewbit.com/problems/capture-regions-on-board/

// Status definitions
// X, O => given
// Connecting points from O are visited and marked V, we ignore V in further dfs
// If point is surrounded, all connecting points are marked X
// If point is unsurrounded, all connecting points are marked U temporarily
// At the end U is marked O, this is done to differentiate between explored O & unexplored O

class Point {
    public:
        int x;
        int y;
        Point (int _x, int _y) {
            x = _x;
            y = _y;
        };
};

// Prepares list of adjacent points to point p
vector<Point> getAdjacentPoints(Point p) {
    vector<Point> ret;
    ret.push_back(Point(p.x - 1, p.y));
    ret.push_back(Point(p.x + 1, p.y));
    ret.push_back(Point(p.x, p.y - 1));
    ret.push_back(Point(p.x, p.y + 1));
    return ret;
}

int dfs(vector<vector<char>> &A, int m, int n, int i, int j) {
    // If outside bounds then unsurrounded
    if (i < 0 || i >= m || j < 0 || j >= n) return 1;
    
    // Status X, U, V points should not be explored
    if (A[i][j] == 'X' || A[i][j] == 'U' || A[i][j] == 'V') return 0;
    
    A[i][j] = 'V';
    vector<Point> points = getAdjacentPoints(Point(i, j));
    for (auto p: points) if (dfs(A, m, n, p.x, p.y)) return 1;
    return 0;
}

void updateValues(vector<vector<char>> &A, int m, int n, int i, int j, char c) {
    if (i < 0 || i >= m || j < 0 || j >= n) return;
    if (A[i][j] == 'X' || A[i][j] == 'U') return;
    
    A[i][j] = c;
    vector<Point> points = getAdjacentPoints(Point(i, j));
    for (auto p: points) updateValues(A, m, n, p.x, p.y, c);
    return;
}

void Solution::solve(vector<vector<char> > &A) {
    int m = A.size(), n = A[0].size();
     
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (A[i][j] == 'O') {
                // If unsurrounded
                if (dfs(A, m, n, i, j)) updateValues(A, m, n, i, j, 'U');
                // If surrounded
                else updateValues(A, m, n, i, j, 'X');
            }
    
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (A[i][j] == 'U') A[i][j] = 'O';
    
    return;
}
