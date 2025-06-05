// https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/

int Solution::chordCnt(int A) {
    if (A==0 || A==1) return 1;
    
    int mod = pow(10, 9)+7;
    vector<long long int> ways(A+1, 0);
    ways[0] = 1; ways[1] = 1;
    
    for (int i=2; i<=A; i++)
        for (int j=0; j<i; j++)
            ways[i] = (ways[i] + (ways[j] * ways[i-1-j]) % mod) % mod;

    return ways.back();
}