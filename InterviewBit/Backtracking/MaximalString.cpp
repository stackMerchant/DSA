// https://www.interviewbit.com/problems/maximal-string/

void getMax(int i, string &A, int B, string &max) {
    int n = A.size();
    if (i >= n || B <= 0) return;
    
    char maxChar = A[i];
    for (int j=i+1; j<n; j++)
        if (A[j] > maxChar)
            maxChar = A[j];

    // if current char is max char, no swap
    if (maxChar == A[i]) {
        getMax(i+1, A, B, max);
        return;
    }
    
    // swap one by one with all max chars and trav deeper
    for (int j=i+1; j<n; j++) {
        if (A[j] == maxChar) {
            swap(A[i], A[j]);
            getMax(i+1, A, B-1, max);
            if (A.compare(max) > 0) max = A; // preserve max string
            swap(A[i], A[j]);
        }
    }        
}

string Solution::solve(string A, int B) {
    string max = A;
    getMax(0, A, B, max);
    return max;
}