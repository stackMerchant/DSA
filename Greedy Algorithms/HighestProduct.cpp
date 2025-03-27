/* https://www.interviewbit.com/problems/highest-product/ */

int Solution::maxp3(vector<int> &A) {
    sort(A.begin(), A.end());
    int N = A.size();
    int allPos = A[N-1] * A[N-2] * A[N-3];
    int twoNeg = A[0] * A[1] * A[N-1];
    return max(allPos, twoNeg);
}
