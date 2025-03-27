// https://www.interviewbit.com/problems/disjoint-intervals/

bool comp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end(), comp);
    
    vector<int> temp = A[0];
    int count = 1;
    for (int i=1; i<A.size(); i++) {
        if (temp[1] < A[i][0]) {
            count++;
            temp = A[i];
        }
    }
    return count;
}
