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
    unordered_map<int,int>Inorder;
     int Preorder=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
   
     for(int i=0;i<inorder.size();i++){
        Inorder[inorder[i]]=i;
     }
     return build(preorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int left,int right){
        if(left>right){
            return nullptr;
        }
        int value=preorder[Preorder++];
        TreeNode* root=new TreeNode(value);
        int index=Inorder[value];
        root->left=build(preorder,left,index-1);
        root->right=build(preorder,index+1,right);
        return root;
    }
    
};