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
    int sumRootToLeaf(TreeNode* root) {

      return dfs(root,0);
    }
     int dfs(TreeNode*node,int curr){

    if(node==NULL)
    return 0;

    curr= curr*2 + node->val;
    if(node->left ==0 && node->right ==0){
     return curr;
    }
     int left_val= dfs(node->left,curr);
     int right_val=dfs(node->right,curr);
    
      return left_val + right_val;
    }
};