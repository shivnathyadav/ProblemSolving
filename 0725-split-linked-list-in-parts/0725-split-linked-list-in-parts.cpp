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
    int size(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            count += 1;
            temp = temp -> next;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       int len = size(head);
       int rem = len%k;
       int que = len/k;
       vector<ListNode*> ans(k);
       for(int i = 0;i < k; i++){
           ans[i]=new ListNode(0);
       }
       ListNode* temp = head;
       int i = 0;
       while(i < k){
            int j = 0;
            ListNode* headi = ans[i];
            ListNode* tempi = headi;
            while(j < que && temp!=NULL){
                tempi -> next = temp;
                temp = temp -> next;
                tempi = tempi -> next;
                j += 1;
            }
            if(rem>0 && temp!=NULL){
                tempi -> next = temp;
                temp = temp -> next;
                tempi = tempi -> next;
                rem -= 1;
            }
            
            tempi->next = NULL;
            ans[i] = headi->next;
            i+=1;
       }
          
       return ans;

    }
};