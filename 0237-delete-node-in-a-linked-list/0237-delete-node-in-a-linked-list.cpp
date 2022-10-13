/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
         ListNode* curr=node,*nxt=node->next;
        curr->val=nxt->val;
        curr->next=nxt->next;
        delete nxt;
    }
};