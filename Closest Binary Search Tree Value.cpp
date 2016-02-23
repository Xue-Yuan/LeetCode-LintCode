/*
    Given a non-empty binary search tree and a target value, find the value 
        in the BST that is closest to the target.

    Note:
        Given target value is a floating point.
        You are guaranteed to have only one unique value in the BST that is 
            closest to the target.
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
    int closestValue(TreeNode* root, double target) {
        if (!root) return 0;
        int ret = root->val;
        closestValue(root, target, ret, fabs(root->val - target));
        return ret;
    }
private:
    void closestValue(TreeNode *root, double target, int &ret, double diff)
    {
        if (!root) return;
        double tmp = fabs(root->val - target);
        if (tmp < diff)
        {
            ret = root->val;
            diff = tmp;
        }
        if (root->val > target) closestValue(root->left, target, ret, diff);
        else closestValue(root->right, target, ret, diff);
    }
};