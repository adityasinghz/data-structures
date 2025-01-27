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
    vector<int>res;
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>stk;
        vector<int>ans;
        TreeNode *curr = root;
        while(curr || !stk.empty()){
            while(curr){
              ans.push_back(curr->val);
              stk.push(curr);
              curr=curr->right;
            }
            curr = stk.top();
            stk.pop();
            curr=curr->left;
        } 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};