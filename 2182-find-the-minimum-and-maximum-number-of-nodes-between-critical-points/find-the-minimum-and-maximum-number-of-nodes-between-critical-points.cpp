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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans={-1,-1};
      
        vector<int>local;
        ListNode* curr=head->next;
        ListNode*prev=head;
        int idx=1;
        int first=-1;
        int previdx=-1;
        int minidx=INT_MAX;
        int maxidx=-1;
        while(curr->next){
           bool critical=(curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val);
            if(critical){
                if(first==-1) first=idx;
                else{
                    minidx=min(minidx,idx-previdx);
                    maxidx=max(maxidx,idx-first);
                }
                previdx=idx;
            }
            prev=curr;
            curr=curr->next;
            idx++;
        }
        if(minidx!=INT_MAX) ans[0]=minidx;
        else ans[0]=-1;
        ans[1]=maxidx;
        return ans;
    }
};