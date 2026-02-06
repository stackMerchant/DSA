// https://www.interviewbit.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<int> pq;
    for(auto a: A){
        ListNode *temp = a;
        while (temp != NULL) {
            pq.push(temp->val);
            temp = temp->next;
        }
    }
    
    ListNode *cur = NULL;
    int top;
    while(!pq.empty()) {
        top = pq.top(); pq.pop();
        ListNode *temp = new ListNode(top);
        temp -> next = cur;
        cur = temp;
    }
    return cur;
}