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
        //copy the next val to curr value and point curr->next to curr->next->next;
        node -> val = node -> next ->val;
        node -> next = node -> next ->next;
    }
};