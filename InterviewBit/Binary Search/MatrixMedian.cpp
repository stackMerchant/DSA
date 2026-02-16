// https://www.interviewbit.com/problems/matrix-median/

// Solution 1, preferred

int getOnLeft(vector<vector<int>> &A, int bound) {
    int less = 0;
    for (auto &a: A)
        less += (upper_bound(a.begin(), a.end(), bound) - a.begin());
    
    return less;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size(), l = A[0][0], h = 0;
    for (auto &row: A) l = min(l, row[0]);
    for (auto &row: A) h = max(h, row[m-1]);
    
    int onLeftTarget = (n * m + 1) / 2, mid, ans;
    while (l <= h) {
        mid = (l + h) / 2;
        if (getOnLeft(A, mid) >= onLeftTarget) {
            ans = mid;
            h = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

// Solution 2

int check(vector<vector<int> > &A, int mid) {
    int M = A.size(), N = A[0].size();
    int lb = 0, ub = 0, lbi, ubi;
    int small = 0, large = INT_MAX;
    for (int i=0; i<M; i++) {
        lbi = lower_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        ubi = upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        
        if(lbi > 0) small = max(small, A[i][lbi - 1]);
        if(ubi < N) large = min(small, A[i][ubi]);
        
        lb += lbi;
        ub += ubi;
    }
    
    ub = M*N - ub;
    
    if (lb > M*N / 2) return -1;
    else if (ub > M*N / 2) return 1;
    else if (lb + ub < M*N) return 0;
    else {
        if (small + large < 2*mid) return -1;
        else if(small + large > 2*mid) return 1;
        else return 0;
    }
}

int Solution::findMedian(vector<vector<int> > &A) {
    int M = A.size(), N = A[0].size();
    int l = INT_MAX, h = 0;
    
    for (int i=0; i<M; i++) {
        l = min(l, A[i][0]);
        h = max(h, A[i][N-1]);
    }
    
    int isCheck, mid;
    while(l <= h) {
        mid = l + (h - l) / 2;
        
        isCheck = check(A, mid);
        if(isCheck == 0) return mid;
        else if (isCheck == -1) h = mid - 1;
        else l = mid + 1;
    }
    return -1;
}
