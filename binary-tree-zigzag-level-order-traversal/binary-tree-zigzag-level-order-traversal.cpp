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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            while(n--){
                TreeNode* curr = q.front();
                
                level.push_back(curr->val);
                if(curr->right) q.push(curr->right);
                if(curr->left) q.push(curr->left);
                q.pop();
            }
            
            if(flag){
                reverse(level.begin(), level.end());
                flag = false;
            }
            else{
                flag = true;
            }
            res.push_back(level);
        }
        return res;
    }
};