// https://www.interviewbit.com/problems/maximum-edge-removal/

// Solution 1

int Solution::solve(int A, vector<vector<int>> &B) {
    sort(B.begin(), B.end());
    
    vector<int> subTreeSum(A + 1, 1); // number of elements items subtree has
    for (int i=B.size() - 1; i >= 0; i--)
        subTreeSum[B[i][0]] += subTreeSum[B[i][1]];
    
    int ans = 0;
    for (int i=2; i<=A; i++) // 2 because, 1 indexed, and root node will not be cut from its parent
        if (subTreeSum[i] % 2 == 0) ans++;

    return ans;
}

// Solution 2 => https://www.youtube.com/watch?v=Ku7biEzLUvc&t
