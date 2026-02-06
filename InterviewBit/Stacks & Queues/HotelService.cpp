// https://www.interviewbit.com/problems/hotel-service/

/************ Solution 1 ************/

// Using BFS, do not optimize for code repetition, as time limit is strict

vector<int> Solution::nearestHotel(vector<vector<int>> &A, vector<vector<int>> &B) {
    // Initialize sizes
    int n = A.size(), m = A[0].size();
    
    // Store distance of nearest hotel for each node
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    // Initialize queue 
    queue<pair<int, int>> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (A[i][j] == 1) {
                q.push({i, j}); // Push hotel nodes
                dist[i][j] = 0; // Put hotel distance 0
            }
        }
    }

    while (!q.empty()) {
        // Get front node co-ordinates
        pair<int, int> front = q.front(); q.pop();
        int i = front.first;
        int j = front.second;
        
        // Explore all 4 directions
        // If unvisited (distance == -1), assign distance and push it to queue
        if (i-1 >= 0 && dist[i-1][j] == -1) {
            dist[i-1][j] = dist[i][j] + 1;
            q.push({i-1, j});
        }
        
        if (i+1 < n && dist[i+1][j] == -1) {
            dist[i+1][j] = dist[i][j] + 1;
            q.push({i+1, j});
        }
        
        if (j-1 >= 0 && dist[i][j-1] == -1) {
            dist[i][j-1] = dist[i][j] + 1;
            q.push({i, j-1});
        }
        
        if (j+1 < m && dist[i][j+1] == -1) {
            dist[i][j+1] = dist[i][j] + 1;
            q.push({i, j+1});
        }
    }
    
    // Get distance for each query and return
    vector<int> ret;
    for (auto b: B) ret.push_back(dist[b[0]-1][b[1]-1]);
    return ret;
}

/************ Solution 2 ************/

// Two simple diagonal traversals in opposite direction
// As closest points will be direct horizontal and vertical steps
// Should not work, should need both diagonal travel in both directions

vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    // Initialize sizes
    int n = A.size(), m = A[0].size();
    
    // Store distance of nearest hotel for each node
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    
    // Put hotel distance 0
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (A[i][j] == 1) dist[i][j] = 0;

    // Go diagonally from top left to bottom right
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i > 0 && dist[i-1][j] != INT_MAX)
                dist[i][j] = min(dist[i][j], dist[i-1][j] + 1);
            if (j > 0 && dist[i][j-1] != INT_MAX)
                dist[i][j] = min(dist[i][j], dist[i][j-1] + 1);
        }
    }

    // Go diagonally from bottom right to top left
    for (int i = n-1; i>=0; i--) {
        for (int j = m-1; j>=0; j--) {
            if (i < n - 1 && dist[i+1][j] != INT_MAX)
                dist[i][j] = min(dist[i][j], dist[i+1][j] + 1);                
            if (j < m - 1 && dist[i][j+1] != INT_MAX)
                dist[i][j] = min(dist[i][j], dist[i][j+1] + 1);
        }
    }

    // Get distance for each query and return
    vector<int> ret;
    for (auto b: B) ret.push_back(dist[b[0]-1][b[1]-1]);
    return ret;
}
