// https://www.interviewbit.com/problems/median-of-array/

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int na = A.size(), nb = B.size();
    if (na > nb) return findMedianSortedArrays(B, A);
    
    int low = 0, high = na;
    
    while (low <= high) {
        int pa = (low + high) / 2; // partition of A
        int pb = (na + nb + 1) / 2 - pa; // partition of B
        
        double leftA = pa > 0 ? A[pa-1]: INT_MIN;
        double leftB = pb > 0 ? B[pb-1]: INT_MIN;
        double rightA = pa < na ? A[pa]: INT_MAX;
        double rightB = pb < nb ? B[pb]: INT_MAX;
        
        if (leftA > rightB) high = pa - 1; // move left
        else if (leftB > rightA) low = pa + 1; // move right
        else { // found
            if ((na + nb) & 1) return max(leftA, leftB);
            else return (max(leftA, leftB) + min(rightA, rightB)) / 2;
        }
    }
    
    return -1;
}