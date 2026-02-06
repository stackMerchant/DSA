// https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

// Find max reactangle in a vector, standard stack problem
int findMaxRect(vector<int> A) {    
    int ret = 0;
    int n = A.size();
    stack<int> st; // Contains indexes
    for (int i=0; i<n; i++) {
        while (!st.empty() && A[st.top()] >= A[i]) {
            int top = st.top(); st.pop();
            int newTop = st.empty() ? -1 : st.top();
            ret = max(ret, A[top] * (i - newTop - 1));
        }
        st.push(i);
    }
    while (!st.empty()) {
        int top = st.top(); st.pop();
        int newTop = st.empty() ? -1 : st.top();
        ret = max(ret, A[top] * (n - newTop - 1));
    }
    return ret;
}

int Solution::maximalRectangle(vector<vector<int>> &A) {
    int n = A.size(), m = A[0].size();
    
    // Aggregate in each row the height of ones above it
    for (int i=1; i<n; i++)
        for (int j=0; j<m; j++)
            if (A[i][j] == 1) A[i][j] += A[i-1][j];

    int ret = 0;
    for (auto a: A) ret = max(ret, findMaxRect(a));
    return ret;
}
