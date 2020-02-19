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

    int maxLevelSum(TreeNode* root) {
        if (!root) return NULL; 
        
        int curr_level = 1;
        int max_level = curr_level;
        int max_sum = 0;

        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            int num_nodes = q.size();
            int curr_sum = 0;
            
            while (num_nodes > 0) {
                TreeNode* node = q.front();

                curr_sum += node->val;
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
                
                q.pop();
                num_nodes--;
            }

            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                max_level = curr_level;
            }
            
            curr_level++;
        }
        
        return max_level;
    }
};