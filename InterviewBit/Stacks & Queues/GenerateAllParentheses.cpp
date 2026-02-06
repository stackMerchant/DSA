// https://www.interviewbit.com/problems/generate-all-parentheses/

bool isOpening(char a) {
    return a == '(' || a == '{' || a == '[';
}

bool isMatching(char a, char b) {
    return (a == ')' && b == '(') || 
            (a == '}' && b == '{') || 
            (a == ']' && b == '[');
}

int Solution::isValid(string A) {
    int N = A.size();
    stack<char> s;
    char top;
    
    for (int i=0; i<N; i++) {
        if (isOpening(A[i])) s.push(A[i]);
        else {
            top = s.empty() ? '-' : s.top();
            if (isMatching(A[i], top)) s.pop(); 
            else return 0;
        }
    }
    return s.empty() ? 1 : 0;
}
