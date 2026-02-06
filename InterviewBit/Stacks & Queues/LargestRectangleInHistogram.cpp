// https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

int Solution::largestRectangleArea(vector<int> &A) {
    // Count of elements
    int n = A.size();
    // Store index of closest strictly smaller element on either side
    vector<int> left(n), right(n);
    
    // Initialize stack
    stack<int> st;
    for (int i=0; i<n; i++) {
        // Pop till strictly smaller element is found on left
        while (!st.empty() && A[st.top()] >= A[i]) st.pop();
        // Store index of strictly smaller element on left
        left[i] = st.empty() ? -1 : st.top();
        // Push it self on stack
        st.push(i);
    }
    
    // Clear stack
    st = stack<int>();
    for (int i=n-1; i>=0; i--) {
        // Pop till strictly smaller element is found on right
        while (!st.empty() && A[st.top()] >= A[i]) st.pop();
        // Store index of strictly smaller element on right
        right[i] = st.empty() ? n : st.top();
        // Push it self on stack
        st.push(i);
    }
    
    int maxArea = 0;
    for (int i=0; i<n; i++) {
        // Calculate area of rectangle, restricted by height of current element
        int currArea = A[i] * (right[i] - left[i] -1);
        maxArea = max(maxArea, currArea);
    }
    
    return maxArea;
}
