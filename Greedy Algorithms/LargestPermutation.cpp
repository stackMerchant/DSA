// https://www.interviewbit.com/problems/largest-permutation/

vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> m;
    for (int i=0; i<n; i++) m[A[i]] = i;

    int i = 0, num, numAt;
    while (B > 0 && i < n) {
        num = n - i;
        numAt = m[num];
        if (numAt != i) {
            m[num] = i;
            m[A[i]] = numAt;
            swap(A[i], A[numAt]);
            B--;
        }
        i++;
    }
    
    return A;
}
