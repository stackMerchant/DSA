// https://www.interviewbit.com/problems/ways-to-form-max-heap/

int comb(int n, int r) {
    long long int ll = 1e9+7;
    
    r = min(r, n-r);
    vector<long long int> vec(r+1, 0);
    vec[0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(i, r);j>0;j--)
        {
            vec[j] = (vec[j] + vec[j-1])%ll;
        }
    }
    return vec[r];
}

int Solution::solve(int A)
{
    if(A==3) return 2;
    if(A==2) return 1;
    if(A==1) return 1;
    if(A==0) return 1;
    
    long long int ll = 1e9+7;
    int n = A;
    int h = log2(n);
    long long int m = pow(2, h);
    long long int p = n - (m-1);
    int l;
    if(p>=m/2) l = m - 1;
    else l = n - m/2;
    int r = n - 1 - l;
    
    long long int a = comb(n-1, l);
    long long int b = solve(l);
    long long int c = solve(r);
    long long int d = (((a*b)%ll)*c)%ll;
    return d;
}
