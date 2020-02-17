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
    vector<TreeNode*> matches;
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p && q || p && !q) {
            return false;
        } 
           
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }
    
    void get_matches (TreeNode* s, TreeNode *t) {
        if (!s) return;
        if (s->val == t->val) {
            matches.push_back(s);
        } 
        get_matches(s->left, t);
        get_matches(s->right, t);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && t || s && !t) return false;
        else if (!s && !t) return true;
        
        get_matches(s, t);  // Find nodes of potential subtrees
        
        for (int i = 0; i < matches.size(); i++) {  // Check each node if it is same as t
            if (isSameTree(matches[i], t)) return true;
        }
        
        // No identical subtrees if we get here
        return false;
    }
};