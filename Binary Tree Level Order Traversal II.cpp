/*
    Given a binary tree, return the bottom-up level order traversal 
        of its nodes' values. (ie, from left to right, level by level 
        from leaf to root).

    Example
        Given binary tree {3,9,20,#,#,15,7},

            3
           / \
          9  20
            /  \
           15   7
         

        return its bottom-up level order traversal as:

        [
          [15,7],
          [9,20],
          [3]
        ]
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
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        vector<vector<int>> ret;
        queue<TreeNode *> q;
        if (root) q.push(root);
        while (!q.empty())
        {
            size_t sz = q.size();
            ret.push_back({});
            for (size_t i = 0; i < sz; ++i)
            {
                TreeNode *t = q.front(); q.pop();
                ret.back().push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return {ret.rbegin(), ret.rend()};
    }
};
