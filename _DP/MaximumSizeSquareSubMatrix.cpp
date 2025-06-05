// https://www.interviewbit.com/problems/maximum-size-square-sub-matrix/

// Same as biggest rectangle in matrix, with a small change in calculating area

int maxSq(vector<int> &A) {
    int n = A.size(), top, newTop, ret = 0, edge;
    stack<int> st; // Stores indexes
    for (int i=0; i<n; i++) {
        while (!st.empty() && A[st.top()] >= A[i]) {
            top = st.top(); st.pop(); // top is height
            newTop = st.empty() ? -1 : st.top(); // (i - newTop - 1) is width
            edge = min(A[top], i - newTop - 1); // The difference from rectangle one
            ret = max(ret, edge * edge);
        }
        st.push(i);
    }
    
    while (!st.empty()) {
        top = st.top(); st.pop(); // top is height
        newTop = st.empty() ? -1 : st.top(); // (i - newTop - 1) is width
        edge = min(A[top], n - newTop - 1);
        ret = max(ret, edge * edge);
    }
    
    return ret;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    
    for (int i=1; i<n; i++)
        for (int j=0; j<m; j++)
            if (A[i][j] == 1) A[i][j] += A[i-1][j]; 
    
    int ret = 0;
    for (auto a: A) ret = max(ret, maxSq(a));
    return ret;
}