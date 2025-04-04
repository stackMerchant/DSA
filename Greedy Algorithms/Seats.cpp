// https://www.interviewbit.com/problems/seats/

// The idea is that everyone will come close to middle x

int Solution::seats(string A) {
    int n = A.size();
    vector<int> pos;
    for (int i=0; i<n; i++) if (A[i]=='x') pos.push_back(i);
    
    int l = pos.size(); if (l==0) return 0;
    int med = pos[l/2];
    
    long long sum=0;
    int pt = med;
    for (int i=pt; i>=0; i--) {
        if (A[i]=='x') {
            sum += (pt-i)%10000003;
            sum = sum%10000003;
            pt--;
        }
    }
    pt = med+1;
    for (int i=pt; i<n; i++) {
        if (A[i]=='x') {
            sum += (i-pt)%10000003;
            sum = sum%10000003;
            pt++;
        }
    }
    return int(sum);
}