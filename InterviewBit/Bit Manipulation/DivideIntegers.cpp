// https://www.interviewbit.com/problems/divide-integers/

int Solution::divide(int A, int B) {
    long long int dividend = A, divisor = B, q = 0, temp = 0;
    
    for (int i = 31; i>=0; i--) {
        if (temp + (divisor << i) <= dividend) {
            temp += (divisor << i);
            q = q | (1LL << i);
        }
    }
    
    return q;
}
