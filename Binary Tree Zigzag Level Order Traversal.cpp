/*
    Given a binary tree, return the zigzag level order traversal 
        of its nodes' values. (ie, from left to right, then right 
        to left for the next level and alternate between).

    Example
        Given binary tree {3,9,20,#,#,15,7},

            3
           / \
          9  20
            /  \
           15   7
         

        return its zigzag level order traversal as:

        [
          [3],
          [20,9],
          [15,7]
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
 

class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) 
    {
        stack<TreeNode *> stk1, stk2;
        if (root) stk1.push(root);
        vector<vector<int>> ret;
        while (!stk1.empty() || !stk2.empty())
        {
            vector<int> tmp;
            if (stk2.empty())
                while (!stk1.empty())
                {
                    auto cur = stk1.top(); stk1.pop();
                    tmp.push_back(cur->val);
                    if (cur->left) stk2.push(cur->left);
                    if (cur->right) stk2.push(cur->right);
                }
            else
                while (!stk2.empty())
                {
                    auto cur = stk2.top(); stk2.pop();
                    tmp.push_back(cur->val);
                    if (cur->right) stk1.push(cur->right);
                    if (cur->left) stk1.push(cur->left);
                }
            ret.push_back(tmp);
        }
        return ret;
    }
};
