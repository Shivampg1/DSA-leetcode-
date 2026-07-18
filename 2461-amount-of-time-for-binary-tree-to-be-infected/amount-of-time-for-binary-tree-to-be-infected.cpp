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

int burning(map<TreeNode*,TreeNode*> &par,TreeNode* targetNode){
      unordered_map<TreeNode*,bool>visit;
        
        queue<TreeNode*>q;
        q.push(targetNode);
        visit[targetNode]=true;
        
        int maxi=0;
        
        while(!q.empty()){
            int size=q.size();
            
            int fl=0;
            for(int i=0;i<size;i++){
                TreeNode*curr=q.front();
                q.pop();
                
                if(curr->left && !visit[curr->left]){
                    q.push(curr->left);
                    visit[curr->left]=true;
                    fl=1;
                }
                 if(curr->right && !visit[curr->right]){
                    q.push(curr->right);
                    visit[curr->right]=true;
                    fl=1;
                }
                if(par[curr] && !visit[par[curr]]){
                    q.push(par[curr]);
                    visit[par[curr]]=true;
                    fl=1;
                }
            }
            if(fl)maxi++;
        }
        return maxi;
  }
  
TreeNode* parent(TreeNode*root,map<TreeNode*,TreeNode*> &par,int start){
    queue<TreeNode*>q;
    q.push(root);
     TreeNode* targetNode = NULL;
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
         if(curr->val == start)
            targetNode = curr;
        if(curr->left){
            par[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            par[curr->right]=curr;
            q.push(curr->right);
        }
    }
    return targetNode;
}
    int amountOfTime(TreeNode* root, int start) {
         map<TreeNode*,TreeNode*>par;
        TreeNode* targetNode =parent(root,par,start);
        int maxi=burning(par,targetNode);
        return maxi;
        
    }
};