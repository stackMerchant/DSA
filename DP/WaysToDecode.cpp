// https://www.interviewbit.com/problems/ways-to-decode/

bool isSingleValid(char o) {
    int num = o - '0';
    return num > 0;
}

bool isDoubleValid(char o, char t) {
    int ones = o - '0';
    int tens = t - '0';
    int num = tens * 10 + ones;
    return 10 <= num && num <= 26;
}

int Solution::numDecodings(string A) {
    int n = A.size();
    if (n == 0) return 0;
    
    int last = 1, secondLast = 1, temp, mod = 1e9 + 7;
    for (int i=0; i<n; i++) {
        temp = 0;
        if (isSingleValid(A[i]))
            temp = (temp + last) % mod;
        if (i > 0 && isDoubleValid(A[i], A[i-1]))
            temp = (temp + secondLast) % mod;
        
        secondLast = last; last = temp;
    }
    return last;
}
