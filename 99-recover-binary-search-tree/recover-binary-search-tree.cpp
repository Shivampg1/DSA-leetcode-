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
    void recoverTree(TreeNode* root) {
        vector<TreeNode* > ans;
        inorder(root, ans);
      TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        for (int i = 1; i < ans.size(); i++) {
            if (ans[i]->val < ans[i - 1]->val) {
                if (!first) {
                    first = ans[i - 1];
                }
                second = ans[i];  
            }
        }

        if (first && second) {
            swap(first->val, second->val);
        }
    }
    void inorder(TreeNode* node,vector<TreeNode*>& ans){
        if(node==NULL){
            return;
        }
        inorder(node->left,ans);
        ans.push_back(node);
        inorder(node->right,ans);
    }
};