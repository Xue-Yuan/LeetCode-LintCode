/*
    Given a binary tree, determine if it is height-balanced.

    For this problem, a height-balanced binary tree is defined 
        as a binary tree in which the depth of the two subtrees 
        of every node never differ by more than 1.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
private:
    int height(TreeNode *root)
    {
        if(!root) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        if(left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
            
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) 
    {
        return height(root) != -1;
    }
};