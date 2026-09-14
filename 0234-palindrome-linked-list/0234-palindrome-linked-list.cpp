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
    bool isPalindrome(ListNode* head) {
        vector<int>a;
        ListNode*curr=head;
        while(curr!=nullptr){
            a.push_back(curr->val);
            curr=curr->next;
        }
        int low=0;
        int high=a.size()-1;
        while(low<=high){
            if(a[low]==a[high]){
                low++;
                high--;
            }
            else{
            return false;
            }
        }
        return true;
    }
};