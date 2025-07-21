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
    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        int min_diff = INT_MAX;
        for (int i = 1; i < ans.size(); ++i) {
            min_diff = min(min_diff, ans[i] - ans[i-1]);
        }
        return min_diff;
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