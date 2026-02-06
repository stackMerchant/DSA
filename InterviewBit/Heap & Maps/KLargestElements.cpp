// https://www.interviewbit.com/problems/k-largest-elements/

vector<int> Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end(), greater<int>());
    vector<int> vec = {A.begin(), A.begin() + B};
    return vec;
}