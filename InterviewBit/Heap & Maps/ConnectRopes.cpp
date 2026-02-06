// https://www.interviewbit.com/problems/connect-ropes/

int Solution::solve(vector<int> &A) {
    int N = A.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i<N; i++) {
        pq.push(A[i]);
    }
    
    int sum = 0, a, b;
    while (pq.size() > 1) {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        sum += a + b;
        pq.push(a + b);
    }
    return sum;
}
