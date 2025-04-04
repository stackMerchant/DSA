// https://www.interviewbit.com/problems/evaluate-expression/

int Solution::evalRPN(vector<string> &A) {
    int N = A.size(), a, b, res;
    stack<int> s;
    
    for (int i=0; i<N; i++) {
        if(A[i] == "+" || A[i] == "-" || A[i] == "/" || A[i] == "*") {
            b = s.top(); s.pop();
            a = s.top(); s.pop();
            
            res = 
            A[i] == "+" ? a + b : 
            A[i] == "-" ? a - b :
            A[i] == "*" ? a * b :
            a / b;
            
            s.push(res);
        } else s.push(stoi(A[i]));
    }
    return s.top();
}
