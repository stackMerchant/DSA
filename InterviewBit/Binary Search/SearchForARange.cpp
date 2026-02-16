// https://www.interviewbit.com/problems/search-for-a-range/

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int min = lower_bound(A.begin(), A.end(), B) - A.begin();
    int max = upper_bound(A.begin(), A.end(), B) - A.begin() - 1;
    
    if (A[min] != B) min = -1;
    if (A[max] != B) max = -1;
    
    return {min, max};
}
