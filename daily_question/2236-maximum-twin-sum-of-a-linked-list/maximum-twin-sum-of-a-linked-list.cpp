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
ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;   
        ListNode* curr = head;      
        ListNode* nextNode = nullptr; 

        while (curr != nullptr) {
            nextNode = curr->next; 
            curr->next = prev;     
            prev = curr;          
            curr = nextNode;       
        }

        return prev; 
    }
    int pairSum(ListNode* head) {
     ListNode* first=head;
     ListNode* second;
     ListNode*fast=head;
     ListNode* slow=head;
     while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
     }
    
  second=slow;
   second = reverseList(second);
     int maxi=INT_MIN;
     while(first && second){
        maxi=max(maxi,first->val+second->val);
        first=first->next;
        second=second->next;
     }
     return maxi;
    }
};