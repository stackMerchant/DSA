// https://www.interviewbit.com/problems/matrix-search/

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size();
    int m = A[0].size();
    int start=0, end = n*m - 1;
    while (start <= end) {
        int mid = (end + start) / 2;
        int x = mid / m;
        int y = mid % m;
        if (A[x][y] == B) return 1;
        if (B < A[x][y]) end = mid - 1;
        else start = mid + 1;
    }
    return 0;
}
