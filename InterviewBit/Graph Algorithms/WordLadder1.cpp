// https://www.interviewbit.com/problems/word-ladder-i/

/************ Solution 1 ************/
// Here we generate adjacent words, instead of iterating over dictionary
// We should do this when word size is less and dictionary size is more

int Solution::solve(string A, string B, vector<string> &C) {
    // Rename and initialize
    string src = A, dest = B;    
    unordered_set<string> words; 
    for (auto c: C) words.insert(c);
    
    // Queue for bfs
    queue<string> q; q.push(src);
    int jumps = 1, currSize;
    while (!q.empty()) {
        // We will pop currSize times, after that jumps increases by 1
        currSize = q.size();
        while (currSize > 0) {
            // Check if front string is dest
            string frontString = q.front(); q.pop();
            if (frontString == dest) return jumps;
            
            // Generate all words which are one jump away
            for (int i=0; i<frontString.size(); i++) {
                for (int j=0; j<26; j++) {
                    string newWord = frontString;
                    newWord[i] = 'a' + j;
                    
                    // If they are in dictionary, push them and erase from set
                    if (words.find(newWord) != words.end()) {
                        q.push(newWord);
                        words.erase(newWord);
                    }
                }
            }
            currSize--;
        }
        jumps++;
    }
    return 0;
}

/************ Solution 2 ************/
// This will not work on interviewbit
// This will work when word size is huge and dictionary size is small

int getDist(string a, string b) {
    int n = a.size();
    int dist = 0;
    for (int i=0; i<n; i++) {
        if (a[i] != b[i]) {
            dist++;
            if (dist > 1) return dist;
        }
    }
    return dist;
}

int Solution::solve(string A, string B, vector<string> &C) {
    // Rename and initialize
    string src = A, dest = B;    
    vector<string> words; 
    for (auto c: C) words.push_back(c);
    
    // Queue for bfs
    queue<string> q; q.push(src);
    int jumps = 1, currSize;
    while (!q.empty()) {
        // We will pop currSize times, after that jumps increases by 1
        currSize = q.size();
        while (currSize > 0) {
            // Check if front string is dest
            string frontString = q.front(); q.pop();
            if (frontString == dest) return jumps;
            
            // Insert all unvisited words which are one jump away, and remove them
            for (int i=0; i < words.size(); i++) {
                if (getDist(frontString, words[i]) == 1) {
                    q.push(words[i]);
                    words.erase(words.begin() + i);
                    i--;
                }
            }
            currSize--;
        }
        jumps++;
    }
    return 0;
}
