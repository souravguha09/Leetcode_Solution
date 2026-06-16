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
    ListNode *detectCycle(ListNode *head) {
      ListNode* fast=head;  
      ListNode* slow=head;
      while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) {
         ListNode* ptr=head;
         while(ptr!=slow){
            slow=slow->next;
            ptr=ptr->next;
         }
         return slow;
        }
      }
      return nullptr;
    }
};