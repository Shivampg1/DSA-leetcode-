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
    int minDepth(TreeNode* root) {
     if(root==NULL){
        return 0;
     }
     int left_node=minDepth(root->left);
    
     int right_node=minDepth(root->right);
     if(left_node==NULL || right_node==NULL){
        return max(left_node,right_node)+1;
     }
     return min(left_node,right_node)+1;
    }
};