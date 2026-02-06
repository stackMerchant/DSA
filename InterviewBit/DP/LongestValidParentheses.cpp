// https://www.interviewbit.com/problems/longest-valid-parentheses/

int Solution::longestValidParentheses(string A) {
    int n = A.size();
    int ret = 0;
    stack<int> stk; stk.push(-1);
    for (int i=0; i<n; i++) {
        if (A[i] == '(')
            stk.push(i);
        else if (stk.size()==1) {
            stk.pop();
            stk.push(i);
        } else {
            stk.pop();
            ret = max(ret, i - stk.top());
        }
    }
    return ret;
}