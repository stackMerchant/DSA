// https://www.interviewbit.com/problems/majority-element/

int Solution::majorityElement(const vector<int> &A) {
    
    int maj = A[0], count = 1, N = A.size();
    
    for (int i=1; i<N; i++) {
        if (A[i] == maj) count++;
        else {
            count--;
            if (count == 0) {
                maj = A[i];
                count = 1;
            }
        }
    }
    return maj;
}
