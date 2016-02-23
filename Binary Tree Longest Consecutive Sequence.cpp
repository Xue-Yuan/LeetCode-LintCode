/*
    Given a binary tree, find the length of the longest consecutive sequence path.

    The path refers to any sequence of nodes from some starting node to any node 
        in the tree along the parent-child connections. The longest consecutive 
        path need to be from parent to child (cannot be the reverse).

    For example,
           1
            \
             3
            / \
           2   4
                \
                 5
        Longest consecutive sequence path is 3-4-5, so return 3.
           2
            \
             3
            / 
           2    
          / 
         1
        Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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
    int longestConsecutive(TreeNode* root) {
        longest = 0;
        longestConsecutive(nullptr, root, 1);
        return longest;
    }
private:
    void longestConsecutive(TreeNode *parent, TreeNode *node, int cur)
    {
        if (!node) return;
        if (parent && parent->val+1 == node->val)
            cur++;
        else cur = 1;
        longest = max(longest, cur);
        longestConsecutive(node, node->left, cur);
        longestConsecutive(node, node->right, cur);
    }
private:
    int longest;
};