// https://www.interviewbit.com/problems/word-ladder-ii/

// This is a combination of bfs and dfs
// Like BFS, some words (oneJumpAwayWords) are taken away from consideration
// But like DFS, we go deep into each word then only go back to next word in oneJumpAwayWords

// Calculates distance between words
int isOneJumpAway(string a, string b) {
    int n = a.size();
    int dist = 0;
    for (int i=0; i<n; i++) {
        if (a[i] != b[i]) {
            dist++;
            if (dist > 1) return false;
        }
    }
    if (dist == 0) false;
    return true;
}

void trav(unordered_set<string> &words, vector<vector<string>> &ladders, int &minLadderSize, vector<string> &currLadder, string end) {
    if (currLadder.size() > minLadderSize) return; // Bigger ladders will not be in answer
    string currWord = currLadder.back(); // Last word of ladder is current word for this call
    if (currWord == end) { // If reached
         // If currLadder ladder is smaller, update minLadderSize and clear all ladders
        if (currLadder.size() < minLadderSize) {
            minLadderSize = currLadder.size();
            ladders.clear();
        }
        ladders.push_back(currLadder); // Put currLadder in ladders
        return;
    }
    
    // Find words which are one jump away
    unordered_set<string> oneJumpAwayWords;
    for (auto w: words) if (isOneJumpAway(currWord, w)) oneJumpAwayWords.insert(w);
    
    for (auto w: oneJumpAwayWords) words.erase(w); // Remove oneJumpAwayWords to words set
    for (auto w: oneJumpAwayWords) { // For each word
        currLadder.push_back(w); // Push the word in currLadder
        trav(words, ladders, minLadderSize, currLadder, end); // Recurse
        currLadder.pop_back(); // Pop the word from currLadder
    }
    for (auto w: oneJumpAwayWords) words.insert(w); // Add oneJumpAwayWords to words set
}

vector<vector<string>> Solution::findLadders(string start, string end, vector<string> &dict) {
    unordered_set<string> words; for (auto d: dict) words.insert(d); // Set of all dictionary words
    vector<vector<string>> ladders; // All the min size word ladders (this will be answer)
    int minLadderSize = words.size(); // Min ladder size
    vector<string> currLadder; currLadder.push_back(start); // Ladder of call stack elements 
    trav(words, ladders, minLadderSize, currLadder, end); // Traverse and fill values
    return ladders;
}
