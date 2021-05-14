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
    bool isvalid(TreeNode* root, long mi, long ma){
        if(!root)
            return true;
        if(root->val < mi || root->val > ma)
            return false;
        long val = root->val;
        bool leftans = isvalid(root->left, mi, val-1);
        bool rightans = isvalid(root->right, val+1, ma);
        return (leftans && rightans);
    }
    
    bool isValidBST(TreeNode* root) {
        return isvalid(root, INT_MIN, INT_MAX);
    }
};