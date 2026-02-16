// https://www.interviewbit.com/problems/implement-power-function/

int Solution::pow(int x, int n, int d) {
    if (x == 1 || x == 0) return x;
    
    long long int ret = 1, base = x % d;
    if (base < 0) base += d;
    while (n > 0) {
        if (n % 2 == 1) {
            ret = (ret * base) % d;
            n--;
        } else {
            base = (base * base) % d;
            n /= 2;
        }
    }
    return ret;
}
