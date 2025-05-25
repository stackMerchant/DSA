// https://www.interviewbit.com/problems/shortest-unique-prefix/

class TrieNode {
    public:
        int count;
        vector<TrieNode*> links;
        
        TrieNode () {
            count = 1;
            links = vector<TrieNode*>(26, NULL);
        }
        
        void addLink(char c) {
            int i = c - 'a';
            if (links[i] == NULL) links[i] = new TrieNode();
            else links[i] -> count++;
        }
        
        TrieNode* getLink(char c) {
            int i = c - 'a';
            return links[i];
        }
        
        bool isLinkUnique(char c) {
            int i = c - 'a';
            return links[i] -> count == 1;
        }
};

void addWord(TrieNode* trieRoot, string word) {
    TrieNode* curr = trieRoot;
    for (auto w: word) {
        curr -> addLink(w);
        curr = curr -> getLink(w);
    }
}

string findPrefix(TrieNode* trieRoot, string word) {
    TrieNode* curr = trieRoot;
    string prefix = "";
    for (auto w: word) {
        prefix += w;
        if (curr -> isLinkUnique(w)) return prefix;
        curr = curr -> getLink(w);
    }
    return prefix;
}

vector<string> Solution::prefix(vector<string> &A) {
    // Add all elements to trie
    TrieNode* trieRoot = new TrieNode();
    for (auto a: A) addWord(trieRoot, a);
    
    // Find unique prefix for each of them
    vector<string> ret;
    for (auto a: A) ret.push_back(findPrefix(trieRoot, a));
    return ret;
}
