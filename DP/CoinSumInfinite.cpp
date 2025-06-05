// http://interviewbit.com/problems/coin-sum-infinite/

int Solution::coinchange2(vector<int> &A, int B){
    int n = A.size();
    sort(A.begin(), A.end());
    vector<int> vec(B+1, 0);
    vec[0] = 1;
    
    for (auto a: A)
        for (int j=a; j<=B; j++)
            vec[j] = (vec[j] + vec[j-a]) % 1000007;

    return vec[B];
}