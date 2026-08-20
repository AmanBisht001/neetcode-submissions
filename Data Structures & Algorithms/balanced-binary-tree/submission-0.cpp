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
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=1+solve(root->left);
        int right=1+solve(root->right);
        return max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        bool leftBalanced=isBalanced(root->left);
        bool rightBalanced=isBalanced(root->right);

        int leftHeight=solve(root->left);
        int rightHeight=solve(root->right);
        int heightDiff=abs(leftHeight-rightHeight);
        bool heightAns=heightDiff>1?false:true;
        
        return leftBalanced&&rightBalanced&&heightAns;

    }
};
