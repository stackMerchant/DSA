// https://www.interviewbit.com/problems/stepping-numbers/

vector<int> Solution::stepnum(int A, int B) {
    queue<int> q;
    for (int i=1; i<=9; i++) q.push(i);
    
    vector<int> ret;
    if (A == 0) ret.push_back(0);
    int t, t1, t2;
    while (!q.empty()) {
        t = q.front(); q.pop();
        
        if (A <= t && t <= B) ret.push_back(t);
        if (B < t) continue;

        t1 = t % 10 - 1; t2 = t % 10 + 1;
        if (0 <= t1 && t1 < 10) q.push(t * 10 + t1);
        if (0 <= t2 && t2 < 10) q.push(t * 10 + t2);
    }
    return ret;
}