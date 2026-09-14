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
    ListNode* sortList(ListNode* head) {
        multiset<int>st;
        ListNode*curr=head;
        while(curr!=nullptr){
            st.insert(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr!=nullptr){
          curr->val=(*st.begin());
          st.erase(st.begin());
          curr=curr->next;
        }
        return head;
    }
};