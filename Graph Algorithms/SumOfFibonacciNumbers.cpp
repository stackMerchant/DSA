// https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

int Solution::fibsum(int A) {
    vector<int> fibs;
    fibs.push_back(1);
    fibs.push_back(1);
    
    while (fibs[fibs.size() - 1] < A)
        fibs.push_back(fibs[fibs.size() - 1] + fibs[fibs.size() - 2]);
    
    int ret = 0;
    int i = fibs.size() - 1;
    while (A > 0 && i >= 0) {
        if (fibs[i] <= A) {
            A -= fibs[i];
            ret++;
        }
        i--;
    }
    return ret;
}