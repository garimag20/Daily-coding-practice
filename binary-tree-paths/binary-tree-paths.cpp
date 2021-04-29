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
    vector<string> paths;
public:
    void allpaths(TreeNode* root, string path){
        if(!root)
            return;
        if(!root->left && !root->right){//leaf node
            paths.push_back(path+ to_string(root->val));
        }
        path += to_string(root->val)+"->";
        allpaths(root->left, path);
        allpaths(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return {};
        string path = "";
        allpaths(root, path);
        return paths;
    }
};