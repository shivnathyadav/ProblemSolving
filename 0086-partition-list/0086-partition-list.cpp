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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode(0);
        ListNode* l2 = new ListNode(0);
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(head){
            if(head->val >= x){
                temp2 -> next = new ListNode(head->val);
                temp2 = temp2->next;
            }
            else if(head -> val < x){
                temp1 -> next = new ListNode(head -> val);
                temp1 = temp1->next;
            }
            head = head ->next;
        }
        temp1->next = l2->next;
        return l1->next;
    }
};