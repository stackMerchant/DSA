// https://www.interviewbit.com/problems/maxspprod/

#define ll long long

int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    vector<ll> left(n, 0), right(n, 0);
    stack<ll> st;
    
    for (int i=0; i<n; i++) {
        while (!st.empty() && A[st.top()] <= A[i]) st.pop(); // Pop while small
        left[i] = st.empty() ? 0 : st.top(); // Calculate left value
        st.push(i); // Push current
    }
    
    st = stack<ll>(); // Clear stack
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && A[st.top()] <= A[i]) st.pop(); // Pop while small
        right[i] = st.empty() ? 0 : st.top(); // Calculate right value
        st.push(i); // Push current
    }
    
    ll ret = 0;
    for (int i=0; i<n; i++) ret = max(ret, left[i]*right[i]);
    return ret % 1000000007;
}
