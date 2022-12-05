/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        int count = 0, mid;
        while(temp!= NULL){
            temp = temp->next;
            count++;
        }
        mid = (count/2);
        while(mid!= 0){
            head = head->next;
            mid--;
        }
        return head;
    }
};