// https://www.interviewbit.com/problems/hotel-reviews/

class TrieNode {
    public:
        bool isLeaf;
        vector<TrieNode*> links;
        
        TrieNode() {
            isLeaf = false;
            links = vector<TrieNode*>(26, NULL);
        }
        
        void addLink(char c) {
            int i = c - 'a';
            if (links[i] == NULL) links[i] = new TrieNode();
        }
        
        void makeLeaf() {
            isLeaf = true;
        }
        
        TrieNode* getLink(char c) {
            int i = c - 'a';
            return links[i];
        }
};

// Add all good words to trie
void addGoodWords(string A, TrieNode *root) {
    TrieNode *curr = root;
    for (auto a: A) {
        if (a == '_') { // If word is completed
            curr -> makeLeaf(); // Make current node a leaf
            curr = root; // Start from root to add new word
        } else {
            curr -> addLink(a); // Add link for current char
            curr = curr -> getLink(a); // Move to added link
        }
    }
    curr -> makeLeaf(); // For last word
}

// Count good words in a string
int countGoodWords(string A, TrieNode *root) {
    int count = 0;
    TrieNode *curr = root;
    for (auto a: A) {
        if (a == '_') { // If word is completed
            if (curr != NULL && curr -> isLeaf) count++; // Word was present
            curr = root; // Start from root for next word
        } else if (curr != NULL) {
            curr = curr -> getLink(a); // Move to next link
        }
    }
    if (curr != NULL && curr -> isLeaf) count++; // For last word
    return count;
}

// Helper class
class ReviewData {
    public:
        int index;
        int goodCount;
        ReviewData(int i, int c) {
            index = i;
            goodCount = c;
        }
};

bool comp(const ReviewData &a, const ReviewData &b) {
    if (a.goodCount == b.goodCount) return a.index < b.index;
    return a.goodCount > b.goodCount;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    TrieNode *root = new TrieNode(); // Initialize trie
    addGoodWords(A, root); // Add all good words to trie

    // Calculate review metadata
    vector<ReviewData> reviewDataList;
    for (int i=0; i<B.size(); i++)
        reviewDataList.push_back(ReviewData(i, countGoodWords(B[i], root)));
    
    sort(reviewDataList.begin(), reviewDataList.end(), comp); // Sort review data
    
    // Prepare return value
    vector<int> ret;
    for (auto rd: reviewDataList) ret.push_back(rd.index);
    return ret;
}