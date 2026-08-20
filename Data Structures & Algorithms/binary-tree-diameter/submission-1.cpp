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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=1+height(root->left);
        int right=1+height(root->right);
        return max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leftDia=diameterOfBinaryTree(root->left);
        int rightDia=diameterOfBinaryTree(root->right);

        int heightAdd=height(root->left)+height(root->right);

        return max({leftDia,rightDia,heightAdd});
    }
};
