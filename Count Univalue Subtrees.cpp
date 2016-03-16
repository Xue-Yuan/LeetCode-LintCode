/*
    Given a binary tree, count the number of uni-value subtrees.

    A Uni-value subtree means all nodes of the subtree have the same value.

    For example:
    Given binary tree,
                  5
                 / \
                1   5
               / \   \
              5   5   5
    return 4.
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
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) 
    {
        cnt = 0;
        isUnivalSubtrees(root);
        return cnt;
    }
private:
    bool isUnivalSubtrees(TreeNode *node)
    {
        if (!node) return true;
            
        bool l = isUnivalSubtrees(node->left);
        bool r = isUnivalSubtrees(node->right);
        if (l && r && (!node->left || node->val == node->left->val) && 
            (!node->right || node->val == node->right->val))
            return ++cnt;
        else return false;
    }
private:
    int cnt;
};
