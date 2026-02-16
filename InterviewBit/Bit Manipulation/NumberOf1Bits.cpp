// https://www.interviewbit.com/problems/number-of-1-bits/

// Solution 1, preferred

int Solution::numSetBits(unsigned int A) {
    int count = 0;
    while (A > 0) {
        if (A & 1) count++;
        A = A>>1;
    }
    return count;
}

// Solution 2, wild

int Solution::numSetBits(unsigned int A) {
    int count = 0;
    while(A > 0) {
        count++;
        A = A & (A - 1);
    }
    return count;
}
