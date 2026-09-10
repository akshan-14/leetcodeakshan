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
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev=nullptr;
    
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }
        if(fast==nullptr){
            ListNode*temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        while(fast!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        prev->next=prev->next->next;
        delete(slow);
        return head;
    }
};