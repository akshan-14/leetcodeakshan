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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=k;
      ListNode*slow=head;
      ListNode*bkc=head;
      ListNode*fast=head;
      for(int i=1;i<n;i++){
        slow=slow->next;
      }
      int a=slow->val;
      for(int i=1;i<n;i++){
        fast=fast->next;
      }

      while(fast->next!=nullptr){
        bkc=bkc->next;
        fast=fast->next;
      }
      int b=bkc->val;
      slow->val=b;
      bkc->val=a;
      return head;
    }
};