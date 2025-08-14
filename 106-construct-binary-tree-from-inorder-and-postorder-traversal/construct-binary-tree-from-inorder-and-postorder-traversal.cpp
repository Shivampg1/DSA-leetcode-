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
     int Postorder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
           for(int i=0;i<inorder.size();i++){
        Inorder[inorder[i]]=i;
        Postorder=postorder.size() - 1;
     }
     return build(postorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& postorder,int left,int right){
        if(left>right){
            return nullptr;
        }
        int value=postorder[Postorder--];
        TreeNode* root=new TreeNode(value);
        int index=Inorder[value];
        
        root->right=build(postorder,index+1,right);
        root->left=build(postorder,left,index-1);
        return root;
    }
};