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
    vector<int> inorder(TreeNode* root, vector<int> vals) {
        if (!root) return vals;
        
        vals = inorder(root->left, vals);
        vals.push_back(root->val);
        vals = inorder(root->right, vals);
 
        return vals;
    }
    
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        vector<int> vals, inorder_vals;
        
        inorder_vals = inorder(root, vals);
        
        vector<int>::iterator p = inorder_vals.begin();
        vector<int>::iterator q = inorder_vals.begin() + 1;
             
        for (; q != inorder_vals.end(); p++, q++) {
            if (*p >= *q) {
                return false;
            }
        }
        
        return true;
    }
};