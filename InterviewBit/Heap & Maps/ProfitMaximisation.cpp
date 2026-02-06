// https://www.interviewbit.com/problems/profit-maximisation/

int Solution::solve(vector<int> &A, int B) {
    int N = A.size();
    priority_queue<int> pq;
    
    for(int i=0; i < N; i++) {
        pq.push(A[i]);
    }
    
    int sum = 0, top;
    while(B>0) {
        top = pq.top(); pq.pop();
        sum += top;
        pq.push(top - 1);
        B--;
    }
    return sum;
}
