/*
    Given a binary tree, return the inorder traversal of its nodes' values.

    For example:
        Given binary tree {1,#,2,3},
           1
            \
             2
            /
           3
        return [1,3,2].
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
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        vector<int> ret;
        while (cur || !stk.empty())
        {
            if (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else if (!stk.empty())
            {
                cur = stk.top(); stk.pop();
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ret;
    }
};
