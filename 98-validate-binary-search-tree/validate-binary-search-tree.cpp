/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        int i=1;
        while(i<ans.size()){
            if(ans[i]<=ans[i-1]){
                return false;
            }
            i++;
        }
        return true;
    }
    void inorder(TreeNode* node,vector<int>& ans){
        if(node==NULL){
            return;
        }
        inorder(node->left,ans);
        ans.push_back(node->val);
        inorder(node->right,ans);
    }
};