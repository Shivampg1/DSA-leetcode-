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
    int sumOfLeftLeaves(TreeNode* root) {
       
       if(root==NULL){
        return 0;
       }
     int sum=0;
     if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL){
            sum= sum + root->left->val;
    }
    sum=sum + sumOfLeftLeaves(root->left);
    sum=sum + sumOfLeftLeaves(root->right);
    return sum;
    }
};