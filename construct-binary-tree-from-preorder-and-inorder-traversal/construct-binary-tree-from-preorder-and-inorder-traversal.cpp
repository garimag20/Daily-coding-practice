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
    int preIndex = 0;
    unordered_map<int,int> mp;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start > end)
            return NULL;
        
        TreeNode* temp = new TreeNode(preorder[preIndex++]);
        int inIndex = mp[temp->val];
        
        temp->left = build(preorder, inorder, start, inIndex-1);
        temp->right = build(preorder, inorder, inIndex+1, end);
        return temp;
     }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return build(preorder, inorder, 0, inorder.size()-1);
    }
};