// https://www.interviewbit.com/problems/xor-between-two-arrays/

// Trie node class
class TrieNode {
    public:
        vector<TrieNode*> bits;
        
        TrieNode () {
            bits = vector<TrieNode*>(2, NULL);
        }
        
        bool isBitEmpty(int bit) {
            return bits[bit] == NULL;
        }
};

// Add num to trie
void addNum(int n, TrieNode* root) {
    TrieNode* currNode = root;
    for (int i=31; i>=0; i--) {
        int currBit = (n >> i) & 1;
        // If currBit is not present in trie, add it
        if (currNode -> isBitEmpty(currBit)) currNode -> bits[currBit] = new TrieNode();
        currNode = currNode -> bits[currBit];
    }
}

// Find max xor of n with elements in trie
int findMaxXor(int n, TrieNode* root) {
    TrieNode* currNode = root;
    int maxXor = 0;
    for (int i=31; i>=0; i--) {
        int currBit = (n >> i) & 1;
        int oppositeBit = 1 - currBit;
        
        maxXor = maxXor << 1; // Move maxXor to left
        // If oppositeBit is present, add 1 else add 0, and move currNode accordingly
        if (currNode -> isBitEmpty(oppositeBit)) {
            maxXor += 0;
            currNode = currNode -> bits[currBit];
        } else {
            maxXor += 1;
            currNode = currNode -> bits[oppositeBit];
        }
    }
    return maxXor;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    // Add all elements of A to Trie in binary
    TrieNode* root = new TrieNode();
    for (auto a: A) addNum(a, root);
    
    // Find maxXor for each element of B
    int maxXor = 0;
    for (auto b: B) maxXor = max(maxXor, findMaxXor(b, root));
    return maxXor;
}
