// https://www.interviewbit.com/problems/word-break-ii/

void trav(vector<vector<string>> &allWordList, vector<string> &currWordList,
    unordered_set<string> &dict, string &A, int index) {
    // If reached end of string, then currWordList is a valid breakup of string A
    if(index >= A.size()) {
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
