// https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/

int Solution::solve(int A) {
    if (A==0) return 0;
    long long int di = 1000000007, tc3, tc2;
    long long int c3 = 24;
    long long int c2 = 12;
    for (int i=1; i<A; i++) {
        tc3 = c3; tc2 = c2;
        c3 = (11 * tc3) % di + (10 * tc2) % di; c3 %= di;
        c2 = (5 * tc3) % di + (7 * tc2) % di; c2 %= di;
    }
    return int((c2 + c3) % di);
}
