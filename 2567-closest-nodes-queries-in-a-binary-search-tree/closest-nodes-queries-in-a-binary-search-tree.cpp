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
 void dfs(TreeNode*node,vector<int> & inorder){
    if(node==NULL) return ;
    dfs(node->left,inorder);
    inorder.push_back(node->val);
    dfs(node->right, inorder);
 }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>inorder;
        dfs(root,inorder);
        vector<vector<int>> ans;
        for(int i=0;i<queries.size();i++){
            int target=queries[i];
            int fast=-1;
            int slow=-1;

            int low=0;
            int high=inorder.size()-1;
          while(low<=high){
            int mid=low+(high-low)/2;
            if(inorder[mid]==target){
                fast=slow=inorder[mid];
                break;
            }
            else if(inorder[mid]<target){
                fast=inorder[mid];
                low=mid+1;
            }
            else{
                slow=inorder[mid];
                high=mid-1;
            }
          }
          ans.push_back({fast,slow});
           
        }
        return ans;
    }
};