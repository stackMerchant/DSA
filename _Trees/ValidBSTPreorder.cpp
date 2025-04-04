// https://www.interviewbit.com/problems/valid-bst-from-preorder/

int Solution::solve(vector<int> &A) {
    int n = A.size();
    
    stack<int> st;
    int maxYet = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        int ai = A[i];
        
        while (!st.empty() && ai >= st.top()) {
            maxYet = st.top();
            st.pop();
        }
        
        if (ai <= maxYet) return 0;
        
        st.push(ai);
    }
    
    return 1;
}