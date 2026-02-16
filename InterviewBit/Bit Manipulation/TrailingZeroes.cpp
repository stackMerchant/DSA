// https://www.interviewbit.com/problems/trailing-zeroes/

// Solution 1, preferred

int Solution::solve(int A) {
    int count = 0;
    while ((A^1) & 1) {
        count++;
        A = A>>1;
    }
    return count;
}

// Solution 2, wild

int Solution::solve(int A) {
    int a = A & (~(A - 1));
    return log2(a);
}
