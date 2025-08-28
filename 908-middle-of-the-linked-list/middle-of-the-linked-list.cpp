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
    ListNode* middleNode(ListNode* head) {
        if(!head) return nullptr;
         vector<ListNode*> ans;
        ListNode* curr= head;
        while(curr){
            ans.push_back(curr);
            curr=curr->next;

        }
        // curr=head;
        // for(int val:ans){

        // }
        return ans[ans.size()/2];
    }
};