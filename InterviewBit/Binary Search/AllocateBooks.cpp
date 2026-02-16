// https://www.interviewbit.com/problems/allocate-books/

bool check(vector<int> &A, int B, int limit) {
    int n = A.size(), sumTill = 0, bagsUsed = 1;
    for (auto &a: A) {
        if (a > limit) return false;
        
        if (sumTill + a <= limit)
            sumTill += a;
        else {
            bagsUsed++;
            sumTill = a;
        }
    }
    return bagsUsed <= B;
}

int Solution::books(vector<int> &A, int B) {
    int N = A.size();
    if (B > N) return -1;
    
    int l = 0, h = 0, mid, ans = -1;
    for (int i=0; i<N; i++) {
        l = max(l, A[i]);
        h += A[i];
    }

    bool isValid;
    while (l<=h) {
        mid = (h + l) / 2;
        isValid = check(A, B, mid);
        
        if (isValid) {
            ans = mid;
            h = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}