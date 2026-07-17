/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   
   void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &par, TreeNode* target){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();

        if(curr->left){
            par[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            par[curr->right]=curr;
            q.push(curr->right);
        }
    }
   }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==NULL) return ans;
        unordered_map<TreeNode*,TreeNode*>par;
        parent(root,par,target);
        
        unordered_map<TreeNode*,bool>vis;

        vis[target]=true;
        queue<TreeNode*>q;
        q.push(target);

        int count=0;
        while(!q.empty()){
            int size=q.size();
            
            if(count==k) break;
            count++;

            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(par[curr] && !vis[par[curr]]){
                    q.push(par[curr]);
                    vis[par[curr]]=true;
                }
            }
        }
            while(!q.empty()){
                TreeNode* curr=q.front();
                q.pop();
                ans.push_back(curr->val);
        }
        return ans;


    }
};