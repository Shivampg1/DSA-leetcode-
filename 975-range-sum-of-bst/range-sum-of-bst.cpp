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
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> result;
        inorder(root,result);
       int sum = 0;
        for(int val : result) {
            if(val >= low && val <= high) {
                sum += val;
            }
        }
        return sum;
    }
    void inorder(TreeNode*node,vector<int>& result){
      if(node==NULL) return;
     
     inorder(node->left,result);
    result.push_back(node->val);
    inorder(node->right,result);
    }
};