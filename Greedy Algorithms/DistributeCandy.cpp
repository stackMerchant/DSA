// https://www.interviewbit.com/problems/distribute-candy/

int Solution::candy(vector<int> &A) {
    int n = A.size(), candies = 0;
    
    vector<int> fromLeft(n, 1);
    vector<int> fromRight(n, 1);

    for (int i=1;i<n;i++) if (A[i-1] < A[i]) fromLeft[i] = fromLeft[i-1] + 1;
    for (int i=n-2;i>=0;i--) if (A[i] > A[i+1]) fromRight[i] = fromRight[i+1] + 1;
    
    for (int i=0;i<n;i++) candies += max(fromLeft[i], fromRight[i]);
    return candies;
}
