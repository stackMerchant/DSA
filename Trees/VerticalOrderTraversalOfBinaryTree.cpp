// https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/

class NodeWithLevel {
    public:
        TreeNode* node;
        int level;
        
        NodeWithLevel(TreeNode* n, int l) {
            node = n;
            level = l;
        }
};

void put(map<int, vector<int>> &m, int level, int val) {
    if(m.find(level) == m.end()) m[level] = vector<int>();
    m[level].push_back(val);
    return;
}

vector<vector<int>> Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>> ret;
    if (!A) return ret;
    
    queue<NodeWithLevel> q;
    q.push(NodeWithLevel(A, 0));
    
    map<int, vector<int>> map;
    NodeWithLevel front(NULL, 0);
    TreeNode* currNode;
    int currLevel;
    while (!q.empty()) {
        front = q.front(); q.pop(); // pop front element from queue
        currNode = front.node; currLevel = front.level; // deconstruct values
        put(map, currLevel, currNode -> val); // put front values in map
        
        if (currNode -> left) q.push(NodeWithLevel(currNode -> left, currLevel - 1));
        if (currNode -> right) q.push(NodeWithLevel(currNode -> right, currLevel + 1));
    }

    for (auto m: map) ret.push_back(m.second);
    return ret;
}