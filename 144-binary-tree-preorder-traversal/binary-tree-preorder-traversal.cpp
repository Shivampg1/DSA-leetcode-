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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        Preorder(root,result);
        return result;
    }
     void Preorder(TreeNode* node, vector<int>& result){
        if(node==NULL){
            return ;
         }
            result.push_back(node->val);
            Preorder(node->left, result);
            Preorder(node->right, result);

        }
};