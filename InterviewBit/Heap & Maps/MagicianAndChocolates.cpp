// https://www.interviewbit.com/problems/magician-and-chocolates/

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int, vector<int>> pq;
    for (auto b: B) pq.push(b);

    long long int ret = 0;
    int divi = pow(10, 9) + 7;
    while (A > 0 && !pq.empty()) {
        int top = pq.top(); pq.pop();
        ret = ((ret + top) % divi);
        pq.push(top/2);
        A--;
    }
    return ret;
}