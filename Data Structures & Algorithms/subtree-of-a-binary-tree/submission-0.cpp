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
    bool solve(TreeNode* p,TreeNode* q){
        if(!q&&!p){
            return true;
        }
        if(!q||!p){
            return false;
        }
        bool left=solve(p->left,q->left);
        bool right=solve(p->right,q->right);

        return p->val==q->val&&left&&right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL){
            return false;
        }
        bool subLeft=isSubtree(root->left,subRoot);
        bool subRight=isSubtree(root->right,subRoot);
        bool isHere=false;
        if(root->val==subRoot->val){
            isHere=solve(root,subRoot);
        }
        return subLeft||subRight||isHere;
    }
};
