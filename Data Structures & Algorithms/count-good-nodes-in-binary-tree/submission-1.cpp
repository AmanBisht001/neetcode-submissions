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

    int solve(TreeNode* root,int maxi){
        if(root==NULL){
            return 0;
        }
        if(root->val>=maxi){
            maxi=root->val;
            return 1+(solve(root->left,maxi)+solve(root->right,maxi));
        }
        int left=solve(root->left,maxi);
        int right=solve(root->right,maxi);
        return left+right;

    }

    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN;
        return solve(root,maxi);
    }
};