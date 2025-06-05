// https://www.interviewbit.com/problems/word-break-ii/

// Solution 1 => Without dp, gets accepted, normal backtracking

void trav(vector<vector<string>> &allWordList, vector<string> &currWordList,
    unordered_set<string> &dict, string &A, int index) {
    
    // If reached end of string, then currWordList is a valid breakup of string A
    if (index == A.size()) {
        allWordList.push_back(currWordList);
        return;
    }
    
    // Create word from index till end
    string currWord = "";
    for (int i=index; i<A.size(); i++) {
        currWord += A[i];
        
        // If word is found
        if (dict.find(currWord) != dict.end()) {
            currWordList.push_back(currWord); // Push current word
            trav(allWordList, currWordList, dict, A, i + 1);
            currWordList.pop_back(); // Pop current word
        }
    }
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    // Create set of dictionary words
    unordered_set<string> dict;
    for (auto b: B) dict.insert(b);
    
    // Initialize variables and traverse
    vector<vector<string>> allWordList;
    vector<string> currWordList;
    trav(allWordList, currWordList, dict, A, 0);
    
    // Convert list of strings to a space separated string
    vector<string> allWordListJoined;
    for (auto wordList: allWordList) {
        string currString = wordList[0];
        for (int i=1; i < wordList.size(); i++)
            currString += ' ' + wordList[i];
        allWordListJoined.push_back(currString);
    }
    return allWordListJoined;
}

// Solution 2 => With dp

vector<vector<string>> trav(string A, unordered_set<string> &dict, int a, 
    vector<vector<vector<string>>> &dp, vector<bool> &visited) {

    if (visited[a]) return dp[a]; // If already calculated
    
    int n = A.size();
    string currStr = "";
    for (int i=a; i<n; i++) {
        currStr = currStr + A[i];
        if (dict.find(currStr) != dict.end()) { // If current string generated from a is in dict
            if (i == n-1) dp[a].push_back({ currStr }); // If A is consumed, just push currStr in array
            else { // Else get all arrays from following sub string and push currStr at back
                for (auto &r: trav(A, dict, i+1, dp, visited)) {
                    r.push_back(currStr);
                    dp[a].push_back(r);
                }
            }
        }
    }
    visited[a] = true; // Mark visited
    return dp[a];
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    // Create set of dictionary words
    unordered_set<string> dict;
    for (auto b: B) dict.insert(b);
    
    // Initialize variables and traverse
    int n = A.size();
    vector<vector<vector<string>>> dp(n);
    vector<bool> visited(n, false);
    trav(A, dict, 0, dp, visited);
    
    // Convert dp to answer
    vector<string> ret;
    for (auto strings: dp[0]) {
        reverse(strings.begin(), strings.end()); // Because it was created in reverse
        string merged = strings[0];
        for (int i=1; i < strings.size(); i++) merged += ' ' + strings[i];
        ret.push_back(merged);
    }
    return ret;
}
