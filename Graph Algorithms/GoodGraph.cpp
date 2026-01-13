// https://www.interviewbit.com/problems/good-graph/

// Algo:
// 1. first node is good/visited by definition
// 2. if we keep going deeper following pointers from other nodes, we will land on of following two:
//    - a good/visited node, then all in call stack are good/visited by definition
//    - a node in call stack, then the last pointer can be changed to first node, count this instance

void dfs(int i, vector<int> &visited, vector<int> &A, int &ret) {
    if (visited[i] == 2) return; // found visited node
    if (visited[i] == 1) { // in call stack
        ret++; // so this last pointer can be changed to node 1
        return;
    }

    visited[i] = 1; // put in call stack
    dfs(A[i]-1, visited, A, ret);
    visited[i] = 2; // mark completely visited
}

int Solution::solve(vector<int> &A) {
    int n = A.size(), ret = 0;
    
    // 0 = unvisited
    // 1 = in call stack
    // 2 = visited
    vector<int> visited(n, 0);
    visited[0] = 2; // 1st node is already good by definition, so visited

    for (int i=0; i<n; i++) {
        if (visited[i] == 0) {
            dfs(i, visited, A, ret);
        }
    }
    
    return ret;
}
