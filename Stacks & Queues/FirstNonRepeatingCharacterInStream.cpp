// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

/************ Solution 1 ************/

// Using pointer

string Solution::solve(string A) {
    int n = A.size();
    unordered_map<char, int> m;
    int pt = 0;
    string ret = "";
    
    for (int i=0; i<n; i++) {
        char e = A[i];
        
        if (m.find(e) == m.end()) m[e] = 1;
        else m[A[i]]++;
        
        while (pt < i && m[A[pt]] > 1) pt++;
        ret += m[A[pt]] == 1 ? A[pt] : '#';
    }
    return ret;
}

/************ Solution 2 ************/

// Using queue, can also use vector

string Solution::solve(string A) {
    int n = A.size();
    unordered_map<char, int> m;
    queue<char> q;
    string ret = "";
    
    for (int i=0; i<n; i++) {
        char e = A[i];
        
        if (m.find(e) == m.end()) {
            m[e] = 1;
            q.push(e);
        } else m[e]++;
        
        while(!q.empty() && m[q.front()] > 1) q.pop();
        
        ret += (q.empty() ? '#' : q.front());
    }
    return ret;
}
