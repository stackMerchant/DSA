// https://www.interviewbit.com/problems/reverse-bits/

unsigned int Solution::reverse(unsigned int A) {
    vector<int> bin(32, 0);
    
    int i = 0;
    while (A > 0) {
        int rem = A % 2;
        A /= 2;
        
        bin[i] = rem;
        i++;
    }
    
    unsigned int retNum = 0;
    for (i=0; i<bin.size(); i++)
        retNum = retNum * 2 + bin[i];
        
    return retNum;
}
