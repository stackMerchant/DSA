// https://www.interviewbit.com/problems/paint-house/

// Write a better clearer solution
vector<int> calc(vector<vector<int> > &A, int i) {
    if (i<0) return vector<int>{0, 0, 0};
    
    vector<int> uptil = calc(A, i - 1);
    vector<int> ret;
    ret.push_back(A[i][0] + min(uptil[1], uptil[2]));
    ret.push_back(A[i][1] + min(uptil[0], uptil[2]));
    ret.push_back(A[i][2] + min(uptil[0], uptil[1]));
    return ret;    
}

int Solution::solve(vector<vector<int> > &A) {
    vector<int> t = calc(A, A.size() - 1);
    return min(t[0], min(t[1], t[2]));
}