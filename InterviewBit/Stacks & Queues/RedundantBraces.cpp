// https://www.interviewbit.com/problems/redundant-braces/

int Solution::braces(string A) {
    stack<char> s;
    int N = A.size();

    for (int i=0; i<N; i++) {
        char c = A[i];
        if (c == '(' || c == '+' || c == '*' || c == '-' || c == '/') s.push(c);
        else if (c == ')') {
            int flag = 0;
            while (!s.empty() && s.top() != '(') {
                flag = 1;
                s.pop();
            }
            if (flag == 0) return 1;
            s.pop();
        }
    }
    return 0;
}