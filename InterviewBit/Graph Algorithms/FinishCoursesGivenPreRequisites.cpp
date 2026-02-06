// https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    // Prepare adjacency matrix and in-degrees
    vector<vector<int>> adj(A+1);
    vector<int> inDegrees(A+1, 0);
    int preReq, course;
    for (int i=0; i<B.size(); i++) {
        preReq = B[i];
        course = C[i];
        adj[preReq].push_back(course);
        inDegrees[course]++;
    }
    
    // Prepare queue with 0 in-degree nodes
    queue<int> q;
    for (int i=1; i<=A; i++) if (inDegrees[i] == 0) q.push(i);
    
    int front;
    while (!q.empty()) {
        front = q.front(); q.pop();
        // Decrease in-degree of adjavent nodes
        for (auto _adj: adj[front]) {
            inDegrees[_adj]--;
            // If in-degree becomes 0, push to queue
            if (inDegrees[_adj] == 0) q.push(_adj);
        }
    }
    
    // If any node is present with non 0 in-degree, then there is a cycle
    for (auto deg: inDegrees) if (deg != 0) return 0;
    return 1;
}

// Below code also gets accepted but is incorrect
int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    return B.size()>=A ? 0 : 1;
}
