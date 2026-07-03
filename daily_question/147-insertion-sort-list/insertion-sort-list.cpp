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
    ListNode* insertionSortList(ListNode* head) 
    {   
        ListNode* temp=head;
        ListNode* dum = new ListNode(-1);
        while(temp!=NULL)
        {
            ListNode* prev = dum;
            ListNode* nxt =temp->next;
            while(prev->next!=NULL && prev->next->val<temp->val)
            {
                prev=prev->next;
            }
            temp->next=prev->next;
            prev->next=temp;
            temp=nxt;
           
        }
        return dum->next;
    }
};