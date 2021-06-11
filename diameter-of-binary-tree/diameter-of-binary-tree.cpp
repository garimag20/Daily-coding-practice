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
    
    pair<int, int> heightDiameter(TreeNode* root){
        pair<int,int> p;
        
        if(root == NULL){
            p.first = 0;
            p.second = 0;
            return p;
        }
        
        pair<int,int> left = heightDiameter(root->left);
        pair<int,int> right = heightDiameter(root->right);
        
        p.first = max(left.first, right.first)+1;
        
        int d1 = left.first + right.first;
        int d2 = left.second;
        int d3 = right.second;
        
        p.second = max(d1, max(d2, d3));
        
        return p;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> p = heightDiameter(root);
        return p.second;
    }
};