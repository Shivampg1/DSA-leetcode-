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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){ 
            return true;
        }
        return ismirror(root->left,root->right);
           
    } 
        bool ismirror(TreeNode* leftNode,TreeNode* rightNode){
            if(leftNode==NULL && rightNode==NULL){
                return true;
            }
            if(leftNode==NULL || rightNode==NULL){
                return false;
            }
            if(leftNode->val==rightNode->val){
                return ismirror(leftNode->left,rightNode->right) && ismirror(leftNode->right,rightNode->left);

            }
            else{
                return false;
            }
        }
    };
