// https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/

// Algo: Do bfs from remainder 1 to remainder 0, then trace back the path from 0 to 1

string Solution::multiple(int A) {
    if(A == 1) return "1";
    
    vector<int> parentRem(A, -1); // link to parent
    vector<int> stepToParent(A, -1); // link to parent
    
    // BFS from remainder 1 to 0
    queue<int> q;
    q.push(1);
    int rem, nextRem;
    while (!q.empty()) {
        rem = q.front(); q.pop();
        if (rem == 0) break;
        for (int step: {0, 1}) {
            nextRem = (rem * 10 + step) % A;
            if (parentRem[nextRem] == -1) { // if it is a new remainder
                parentRem[nextRem] = rem;
                stepToParent[nextRem] = step;
                q.push(nextRem);
            }
        }
    }
    
    // build reversed string, starting from 0 till 1
    string ans;
    for (int rem=0; rem!=1; rem = parentRem[rem])
        ans.push_back('0' + stepToParent[rem]);
    
    ans.push_back('1');
    reverse(ans.begin(), ans.end());
    return ans;
}
