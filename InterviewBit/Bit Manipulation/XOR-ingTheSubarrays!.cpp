// https://www.interviewbit.com/problems/xor-ing-the-subarrays/

// In even case, everything is symmetrical, everything gets cancelled out
// In odd case, all patterns around middle pattern gets cancelled out
// And in middle pattern, items at odd position remains (1-indexed)

int Solution::solve(vector<int> &A) {
    if (A.size() % 2 == 0) return 0;

    int num = 0;
    for (int i=0; i<A.size(); i+=2)
        num ^= A[i];
    return num;
}
