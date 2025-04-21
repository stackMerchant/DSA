// https://www.interviewbit.com/problems/copy-list/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    // Map of old node to new node
    unordered_map<RandomListNode*, RandomListNode*> oldToNew;
    
    // Create copy of all nodes
    RandomListNode *curr = A, *newNode;
    while (curr != NULL) {
        oldToNew[curr] = new RandomListNode(curr -> label);
        curr = curr -> next;
    }
    
    // Reset pointer
    curr = A;
    // Traverse again to setup next and random pointers
    while (curr != NULL) {
        // Get new node
        newNode = oldToNew[curr];
        // If next/random is not null, get corresponding new node and set
        newNode -> next = (curr -> next == NULL) ? NULL : oldToNew[curr -> next]; 
        newNode -> random = (curr -> random == NULL) ? NULL : oldToNew[curr -> random];
        curr = curr -> next;
    }
    return oldToNew[A];
}
