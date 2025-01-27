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
    int maxPath(TreeNode *root, int &res){
        if(!root) return 0;
        int x = maxPath(root->left, res);
        int y = maxPath(root->right,res);
        
        int temp = max(max(x,y) + root->val, root->val);
        int ans = max(temp, x+y+root->val);
        res = max(res,ans);
        return temp;
        
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPath(root, res);
        return res;
    }
};