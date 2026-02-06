// https://www.interviewbit.com/problems/window-string/

string Solution::minWindow(string A, string B) {
    // Create map of chars of B, and a copy with count 0
    unordered_map<char, int> mb, _mb;
    for (auto &b: B) {
        mb[b]++;
        _mb[b] = 0;
    }
    
    int na = A.size(), nb = B.size(), wc = 0;
    int i = 0, j = 0, minSize = INT_MAX, index = -1;
    
    // While all words are NOT in curr sub string move i forward
    while (i < na) {
        if (mb.find(A[i]) != mb.end()) { // if char is in B
            if (_mb[A[i]] < mb[A[i]]) wc++; // if curr < required, increase wc
            _mb[A[i]]++; // increase current count
            
            // While all words are in curr sub string move j forward
            while (wc == nb) { // if all words are found
                int currSize = i-j+1; // curr sub string size
                if (minSize > currSize) { // update size and index
                    minSize = currSize;
                    index = j;
                }
                
                if (mb.find(A[j]) != mb.end()) { // if char is in B
                    if (_mb[A[j]] <= mb[A[j]]) wc--; // if curr <= required, decrease wc
                    _mb[A[j]]--; // decrease current count
                }
                j++;
            }
        }
        i++;
    }
    
    if (index == -1) return ""; // if no such string
    return A.substr(index, minSize);
}
