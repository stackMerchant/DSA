// https://www.interviewbit.com/problems/clone-graph/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

 UndirectedGraphNode* clone(unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &oldToNewMap, UndirectedGraphNode* node) {
    if (oldToNewMap.find(node) != oldToNewMap.end()) return oldToNewMap[node];
    
    UndirectedGraphNode* newNode = new UndirectedGraphNode(node -> label);
    oldToNewMap[node] = newNode;
    
    vector<UndirectedGraphNode*> newNodeNeighbors;
    for (auto n: (node -> neighbors)) {
        newNodeNeighbors.push_back(clone(oldToNewMap, n));
    }
    newNode -> neighbors = newNodeNeighbors;
    return newNode;
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> oldToNewMap;
    return clone(oldToNewMap, node);
}