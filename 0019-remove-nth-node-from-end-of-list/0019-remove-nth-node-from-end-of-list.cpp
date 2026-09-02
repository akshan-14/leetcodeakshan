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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode*fast=head;
        ListNode*curr=nullptr;
        if(head->next==nullptr){
            return nullptr;
        }
        for(int i=0;i<n;i++){
          fast=fast->next;
            }
            while(fast!=nullptr){
                fast=fast->next;
                curr=slow;
                slow=slow->next;
            }
           if(slow==head){
            return head->next;
           }
           else if(slow->next!=nullptr){
           curr->next=slow->next;
           return head;
           }
           else{
            curr->next=nullptr;
           }
           return head;
        }
};