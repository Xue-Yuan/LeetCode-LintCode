/*
    Given a binary tree, find its minimum depth.

    The minimum depth is the number of nodes along the shortest 
        path from the root node down to the nearest leaf node.

    Example
        Given a binary tree as follow:

          1
         / \ 
        2   3
           / \
          4   5
        The minimum depth is 2.
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        queue<TreeNode *> q;
        if (root) q.push(root);
        int cnt = 0;
        while (!q.empty())
        {
            cnt++;
            size_t sz = q.size();
            for (size_t i = 0; i < sz; ++i)
            {
                TreeNode *cur = q.front(); q.pop();
                if (!cur->left && !cur->right) return cnt;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return cnt;
    }
};
